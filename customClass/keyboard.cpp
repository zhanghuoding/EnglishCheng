#include "keyboard.h"
#include "via.h"
#include "customClass/tool.h"
#include "customClass/mywidget.h"

#include <QDebug>

unsigned KeyBoard::clickNum=0;
QQueue<keytype_> *KeyBoard::keyClickedQueue=new QQueue<keytype_>;

KeyBoard::KeyBoard(QWidget *parent) : QWidget(parent)
{
    open=false;
    shiftIO=false;
    currentKeyType=0;
    clickedKeyGroupNum=0;
    referString=new QString("#");
    lastReferString=new QString("#");
    clickNum=0;
    keyBoardIsUpperOrLower=false;
    currentWord.clear();
    lastCurrentWord.clear();
    whetherResponse=true;
    allowedOpen=true;//默认情况下是允许对键盘进行打开操作的
    accordPhraseReset=true;

    this->setFixedSize(*keyBoardMinSize);

    background=new QLabel(this);
    background->setScaledContents(true);
    background->setPixmap(QPixmap(picRoot+QString("/public/minKeyboard.png")));
    background->setFixedSize(*keyBoardMinSize);
    background->setGeometry(Tool::rect(0,0,keyBoardMinSize->width(),keyBoardMinSize->height()));

    setGeometry((screenSize->width()-keyBoardMinSize->width())/2+0.5,
                           screenSize->height()-keyBoardMinSize->height(),
                           keyBoardMinSize->width(),keyBoardMinSize->height());

    initKeys();
    initKeyGroup();
    hiddenKeys();//不让按键显示在小键盘上，只有打开小键盘时才显示按键
}
KeyBoard::~KeyBoard()
{
    delete background;
    delete keyClickedQueue;
    for(int i=0;i<30;i++)
        delete keys[i];
    if(referString)
        delete referString;
}
QLabel *KeyBoard::getBackground()
{
    return background;
}
bool KeyBoard::isOpen()
{
    return open;
}
void KeyBoard::setOpen(bool open)
{
    this->open=open;
}
void KeyBoard::openKeyBoard()
{
    if(isOpen() || !allowedOpen)
        return;//如果键盘已经被打开，或者键盘当前不允许被打开，则返回
    this->setFixedSize(*keyBoardMaxSize);

    background->setPixmap(QPixmap(picRoot+QString("/public/keyboardBackground.png")));
    background->setFixedSize(*keyBoardMaxSize);
    background->setGeometry(Tool::rect(0,0,keyBoardMaxSize->width(),keyBoardMaxSize->height()));

    setGeometry((screenSize->width()-keyBoardMaxSize->width())/2+0.5,
                           screenSize->height()-keyBoardMaxSize->height(),
                           keyBoardMaxSize->width(),keyBoardMaxSize->height());
    setOpen(true);
    if(shiftIO)
    {
        convUpperLowerCase(false);//将键盘恢复为小写
        shiftIO=false;
    }
    currentKeyType=0;//将上次按键的记录清零
    putKeys();//将按键加载到键盘上
    showKeys();//将按键显示出来
    changeKeysColor();//将每个按键的颜色恢复为默认

    emit keyBoardOpened(parentWidget());//发出键盘已经被打开的信号

    if(inputRemind && referString)
    {
        if(clickNum>=referString->length())
        {//当单词已经输完整了，则提示回车键
            changeKeyColor(13,KEY_BACKCOL_NORMAL_REMIND,KEY_BACKCOL_ENTER_REMIND,KEY_BACKCOL_PRESSED_REMIND,false);
            return;
        }
        keytype_ remindKey=referString->at(clickNum).toLatin1();
        if(remindKey>='A' && remindKey<='Z')
        {
            if(!shiftIO)
            {//当接下来需要输入的是大写，并且上档键并未打开的时候，设置上档键颜色
                changeKeyColor(14,KEY_BACKCOL_NORMAL_REMIND,KEY_BACKCOL_ENTER_REMIND,KEY_BACKCOL_PRESSED_REMIND,false);
                changeKeyColor(15,KEY_BACKCOL_NORMAL_REMIND,KEY_BACKCOL_ENTER_REMIND,KEY_BACKCOL_PRESSED_REMIND,false);
                return;
            }
            remindKey=remindKey-'A'+'a';//转换成对应的小写
        }
        changeKeyColor(remindKey,KEY_BACKCOL_NORMAL_REMIND,KEY_BACKCOL_ENTER_REMIND,KEY_BACKCOL_PRESSED_REMIND,false);
    }
}
void KeyBoard::closeKeyBoard(bool needReset)
{
    emit keyBoardClosed(needReset);//发出键盘已经被关闭的信号

    if(!isOpen())
        return;//如果键盘已经是关闭状态，则返回
    this->setFixedSize(*keyBoardMinSize);

    //关闭软键盘时调整软键盘的尺寸和背景图片，以及显示位置
    background->setPixmap(QPixmap(picRoot+QString("/public/minKeyboard.png")));
    background->setFixedSize(*keyBoardMinSize);
    background->setGeometry(Tool::rect(0,0,keyBoardMinSize->width(),keyBoardMinSize->height()));

    setGeometry((screenSize->width()-keyBoardMinSize->width())/2+0.5,
                           screenSize->height()-keyBoardMinSize->height(),
                           keyBoardMinSize->width(),keyBoardMinSize->height());

    currentKeyType=0;//将上次按键的记录清零
    hiddenKeys();//删除所有按键
    setOpen(false);
    if(needReset)
        reset();//重置键盘
}
keytype_ KeyBoard::deKeyQueue()
{
    if(keyClickedQueue->length()>0)
        return keyClickedQueue->dequeue();
    else
        return 0;
}
void KeyBoard::initKeyGroup()
{
    keyGroup[0][0]='q';
    keyGroup[0][1]='w';
    keyGroup[0][2]='e';
    keyGroup[0][3]='a';
    keyGroup[0][4]='s';
    keyGroup[0][5]='d';
    keyGroup[0][6]='z';
    keyGroup[0][7]='x';
    keyGroup[0][8]='c';

    keyGroup[1][0]='r';
    keyGroup[1][1]='t';
    keyGroup[1][2]='y';
    keyGroup[1][3]='u';
    keyGroup[1][4]='f';
    keyGroup[1][5]='g';
    keyGroup[1][6]='h';
    keyGroup[1][7]='v';
    keyGroup[1][8]='b';

    keyGroup[2][0]='i';
    keyGroup[2][1]='o';
    keyGroup[2][2]='p';
    keyGroup[2][3]='j';
    keyGroup[2][4]='k';
    keyGroup[2][5]='l';
    keyGroup[2][6]='n';
    keyGroup[2][7]='m';

    keyGroup[2][8]=0;
}
void KeyBoard::increaseClickNum()
{
    this->clickNum++;
}
void KeyBoard::enKeyQueue(keytype_ keyType)
{
    if(keyType != 8 && keyType != 13 && keyType != 32)
    {//当按下的键不是退格键，不是回车键，也不是空格键的时候，按照普通字母处理
        if(shiftIO)
        {
            keyClickedQueue->enqueue(keyType-'a'+'A');//将小写字母转换成大写字母。然后入队列
        }
        else
        {
            keyClickedQueue->enqueue(keyType);//直接将小写字母入队列
        }
    }
    else
    {//当按下的键是以上三者中任何一种的时候，直接将该按键入队列
        keyClickedQueue->enqueue(keyType);//直接将控制字符入队列
    }
}
void KeyBoard::setShiftIO()
{
    if(shiftIO)
        shiftIO=false;
    else
        shiftIO=true;
}

void KeyBoard::whitchKeyClicked(Key *key)
{
    if(!whetherResponse)
        return;//当前不响应输入事件
    keytype_ tmp=key->getTypeOfKey();

    if(tmp==13)
    {//当按下的键是回车键的时候，进行如下操作
        if(currentWord.compare(referString,Qt::CaseSensitive)!=0)
        {
            return;//如果当前输入的字符串并不符合单词，则不响应回车键
        }

        //以下两句顺序不可颠倒
        closeKeyBoard(false);//关闭并重置键盘
        emit enterKeyWasPressed();//发出“回车键已被按下”的信号
        goto mustExcute;//不需要再做其他操作
    }

    if(!referString)
    {//当键盘中的参照字符串还没有被设置的时候，不响应键盘点击事件
        return;
    }

    if(tmp==14 || tmp == 15)
    {//当按下的是shift键的时候，改变转换大小写的标记
        setShiftIO();
        convUpperLowerCase(shiftIO);//根据需求，将键盘转换大小写
        goto remind;
    }

    if(tmp==8)
    {//当按下的是退格键的时候
        if(clickNum<=0)
            return;//当当前还没有输入任何字符的时候，不进行退格操作

        currentWord.remove(--clickNum,1);
        deKeyQueue();//退格操作
        changeKeysColor();//将所有按键全部设置为默认颜色
        paper->writeChar(tmp);//从“纸”上擦去一个字符
        goto mustExcute;
    }

    //当输入的是字符时，进行如下操作
    if(clickNum>=referString->length())
    {//当字母已经输够了的时候，不能再继续输入
        return;
    }


    if(tmp>='a' && tmp<='z' && shiftIO)
    {//如果当前输入的是大写字母的话
        tmp=tmp-'a'+'A';//将该字母转换成大写字母
    }

    if(((unsigned short)(referString->at(clickNum).toLatin1()))!=tmp)
        return;//如果输入的字母不是本单词或词组中接下来应该输入的字母，则返回

    clickNum++;

    currentWord.append(tmp);
    enKeyQueue(tmp);
    changeKeyColor(key->getTypeOfKey(),KEY_BACKCOL_NORMAL_AFTCLI,KEY_BACKCOL_ENTER_AFTCLI,KEY_BACKCOL_PRESSED_AFTCLI);//恢复之前按下的键的颜色，并设置当前按下的键的颜色
    currentKeyType=key->getTypeOfKey();//记录下当前按的是哪个键

    paper->writeChar(tmp);//将该字符写入“纸”中

    while(true)
    {
        if(clickNum<referString->length() && punctuation->contains(referString->at(clickNum)))
        {//如果接下来要输入的是普通标点符号的时候，自动跳过标点符号
            currentWord.append(referString->at(clickNum));
            enKeyQueue( (keytype_)(referString->at(clickNum).toLatin1()) );
            clickNum++;
        }else
            break;
    }


    mustExcute:
    if(shiftIO)
    {//如果键盘目前是大写，则转换成小写
        setShiftIO();
        convUpperLowerCase(shiftIO);//根据需求，将键盘转换大小写
    }
    remind:
    if(inputRemind)
    {
        if(clickNum>=referString->length())
        {//当单词已经输完整了，则提示回车键
            changeKeyColor(13,KEY_BACKCOL_NORMAL_REMIND,KEY_BACKCOL_ENTER_REMIND,KEY_BACKCOL_PRESSED_REMIND,false);
            return;
        }
        keytype_ remindKey=referString->at(clickNum).toLatin1();
        if(remindKey>='A' && remindKey<='Z')
        {
            if(!shiftIO)
            {//当接下来需要输入的是大写，并且上档键并未打开的时候，设置上档键颜色
                changeKeyColor(14,KEY_BACKCOL_NORMAL_REMIND,KEY_BACKCOL_ENTER_REMIND,KEY_BACKCOL_PRESSED_REMIND,false);
                changeKeyColor(15,KEY_BACKCOL_NORMAL_REMIND,KEY_BACKCOL_ENTER_REMIND,KEY_BACKCOL_PRESSED_REMIND,false);
                return;
            }else
            {//当上档键已经被点击过了，则恢复其颜色
                changeKeyColor(14,KEY_BACKCOL_NORMAL,KEY_BACKCOL_ENTER,KEY_BACKCOL_PRESSED,false);
                changeKeyColor(15,KEY_BACKCOL_NORMAL,KEY_BACKCOL_ENTER,KEY_BACKCOL_PRESSED,false);
            }
            remindKey=remindKey-'A'+'a';//转换成对应的小写
        }
        changeKeyColor(remindKey,KEY_BACKCOL_NORMAL_REMIND,KEY_BACKCOL_ENTER_REMIND,KEY_BACKCOL_PRESSED_REMIND,false);
    }
}
void KeyBoard::initKeys()
{
    char a[2]={'a','\0'};
    for(int i=0;i<26;i++)
    {
        keys[i]=new Key('a'+i,this);
        keys[i]->setText(a);
        keyIndex[i]=keys[i]->getTypeOfKey();
        a[0]++;
    }
    keys[26]=new Key(8,this);//退格键
    keys[26]->setIcon(QPixmap(picRoot+QString("/public/backspace.gif")));
    keys[26]->setIconSize(Tool::size(50,37));
    keyIndex[26]=8;
    keys[27]=new Key(13,this);//回车键
    keys[27]->setText("Enter");
    //QLabel ql(keys[27]);
    //ql.setPixmap(QPixmap(picRoot+QString("/public/enter.gif")));
    keys[27]->setIcon(QPixmap(picRoot+QString("/public/enter.gif")));
    keys[27]->setIconSize(Tool::size(15,45));
    //ql.setGeometry(80,10,20,47);
    keyIndex[27]=13;
    keys[28]=new Key(14,this);//shift键
    keys[28]->setText("Shift");
    keys[28]->setIcon(QPixmap(picRoot+QString("/public/shift(white).gif")));//设置shift按键中的箭头图片为无填充色的
    keys[28]->setIconSize(Tool::size(20,44));
    keyIndex[28]=14;
    keys[29]=new Key(32,this);//空格键
    keyIndex[29]=32;
    for(int j=0;j<30;j++)
        connect(keys[j],SIGNAL(clickedSignal(Key*)),this,SLOT(whitchKeyClicked(Key*)));
}
void KeyBoard::changeKeyColor(keytype_ keyNO, char *rgb1,char *rgb2, char *rgb3,bool setLastKeyColor)
{//当setLastKeyColor为真时，设置上一次按键和本次按键的颜色，当为假时，只设置传入的按键的颜色

   Key *p=findKeyPointer(keyNO);
   if(p)
   {//把当前按过的键设置为rgb色
       p->setBackGroundColor(rgb1,rgb2,rgb3);
   }

   if(!setLastKeyColor)
       return;

   p=findKeyPointer(currentKeyType);
   if(p)
   {//把前面按过的键恢复为白色
       p->setBackGroundColor(KEY_BACKCOL_NORMAL);
   }
}
Key *KeyBoard::findKeyPointer(keytype_ keyType)
{//如果该按键存在，则返回该按键的指针，否则，返回空
    int i=0;
    for(i=0;i<30&&keyIndex[i]!=keyType;i++);
    if(i<30&&i>=0)
    {
        return keys[i];
    }
    else
    {
        return NULL;
    }
}
void KeyBoard::changeKeysColor(short groupNum, char *rgb1, char *rgb2, char *rgb3, char *rgb)
{
    Key *p=NULL;
    int i=0;
    if(groupNum==2)
        i=7;
    else
        if(groupNum==0||groupNum==1)
            i=8;
    else
            return;
    while(i>=0)
    {
        p=findKeyPointer(keyGroup[groupNum][i--]);
        p->setBackGroundColor(rgb1,rgb2,rgb3,rgb);
    }
}
void KeyBoard::changeKeysColor()
{
    int i=0;
    for(i=0;i<30;i++)
    {
        keys[i]->setBackGroundColor();//将所有按键的颜色恢复为默认颜色
    }
}
void KeyBoard::setReferString(char *referString)
{
    if(referString)
        delete referString;
    reset();
    this->referString=new QString(referString);
}
void KeyBoard::reset()
{
    if(!accordPhraseReset)
        return;//不进行重置
    clickNum=0;
    currentKeyType=0;
    clickedKeyGroupNum=0;
    currentWord.clear();
    whetherResponse=true;
    allowedOpen=true;
    accordPhraseReset=true;

    if(referString)
    {
        delete referString;
        referString=new QString("#");
    }
    changeKeysColor();//恢复键盘中所有按键为默认的颜色
    convUpperLowerCase(false);//将键盘恢复为小写
    if(keyClickedQueue)
    {
        keyClickedQueue->clear();
        delete keyClickedQueue;
        keyClickedQueue=new QQueue<keytype_>;
    }
}

void KeyBoard::closeOrOpenKeyBoard(bool flag)
{
    if(flag)
    {
        openKeyBoard();
    }
    else
    {
        closeKeyBoard();
    }
}

void KeyBoard::convUpperLowerCase(bool flag)
{//当flag为真时，将键盘设置为大写，否则，将键盘设置为小写
    char a[2]={'a','\0'};
    if(flag)
    {//将键盘转换成大写
        if(keyBoardIsUpperOrLower)
            return;//如果键盘当前已经是大写，则不用转换，直接返回
        a[0]='A';
        keys[0]->setText(a);
        for(int i=1;i<26;i++)
        {
            a[0]++;
            keys[i]->setText(a);
        }
        keys[28]->setIcon(QPixmap(picRoot+QString("/public/shift(black).gif")));//设置shift按键中的箭头图片为无填充色的
        keyBoardIsUpperOrLower=true;//记录键盘的大小写状态
    }
    else
    {//将键盘转换成小写
        if(!keyBoardIsUpperOrLower)
            return;//如果键盘已经是小写，则不用转换，直接返回
        a[0]='a';
        keys[0]->setText(a);
        for(int i=1;i<26;i++)
        {
            a[0]++;
            keys[i]->setText(a);
        }
        keys[28]->setIcon(QPixmap(picRoot+QString("/public/shift(white).gif")));//设置shift按键中的箭头图片为黑色填充色的
        keyBoardIsUpperOrLower=false;
    }
}
bool KeyBoard::isUpper()
{
    return keyBoardIsUpperOrLower;
}

void KeyBoard::setKeys(Key *k, int x, int y, int w, int h)
{
    int ax=Tool::width(x)*(keyBoardMaxSize->width()/(double)(keysAreaSize->width()))+0.5;
    int ay=Tool::height(y)*(keyBoardMaxSize->height()/(double)(keysAreaSize->height()))+0.5;
    int aw=Tool::width(w)*(keyBoardMaxSize->width()/(double)(keysAreaSize->width()))+0.5;
    int ah=Tool::height(h)*(keyBoardMaxSize->height()/(double)(keysAreaSize->height()))+0.5;
    k->setGeometry(ax,ay,aw,ah);
    k->setFixedSize(aw,ah);
}

void KeyBoard::putKeys()
{//设置键盘中的按键的位置
    /*
     * 该键盘中，字母按键的尺寸均为56*56
     * 按键与按键之间的间距为7
     * 按键与键盘上下边框距离为30，左右边框的距离为40
     */
    setKeys(findKeyPointer('a'),60,93,56,56);
    setKeys(findKeyPointer('b'),332,156,56,56);
    setKeys(findKeyPointer('c'),206,156,56,56);
    setKeys(findKeyPointer('d'),186,93,56,56);
    setKeys(findKeyPointer('e'),166,30,56,56);
    setKeys(findKeyPointer('f'),249,93,56,56);
    setKeys(findKeyPointer('g'),312,93,56,56);
    setKeys(findKeyPointer('h'),375,93,56,56);
    setKeys(findKeyPointer('i'),481,30,56,56);
    setKeys(findKeyPointer('j'),438,93,56,56);
    setKeys(findKeyPointer('k'),501,93,56,56);
    setKeys(findKeyPointer('l'),564,93,56,56);
    setKeys(findKeyPointer('m'),458,156,56,56);
    setKeys(findKeyPointer('n'),395,156,56,56);
    setKeys(findKeyPointer('o'),544,30,56,56);
    setKeys(findKeyPointer('p'),607,30,56,56);
    setKeys(findKeyPointer('q'),40,30,56,56);
    setKeys(findKeyPointer('r'),229,30,56,56);
    setKeys(findKeyPointer('s'),123,93,56,56);
    setKeys(findKeyPointer('t'),292,30,56,56);
    setKeys(findKeyPointer('u'),418,30,56,56);
    setKeys(findKeyPointer('v'),269,156,56,56);
    setKeys(findKeyPointer('w'),103,30,56,56);
    setKeys(findKeyPointer('x'),143,156,56,56);
    setKeys(findKeyPointer('y'),355,30,56,56);
    setKeys(findKeyPointer('z'),80,156,56,56);


    setKeys(findKeyPointer(8),670,30,90,56);//退格
    setKeys(findKeyPointer(13),627,93,133,56);//回车
    setKeys(findKeyPointer(14),521,156,239,56);//shift
    setKeys(findKeyPointer(32),183,219,434,56);//空格
}
void KeyBoard::hiddenKeys()
{
    for(int i=0;i<30;i++)
        keys[i]->setVisible(false);
}
void KeyBoard::showKeys()
{
    for(int i=0;i<30;i++)
        keys[i]->setVisible(true);
}

void KeyBoard::setKeysParent(keytype_ keytype, QWidget *parent)
{
    if(keytype!=0&&parent==0)
        findKeyPointer(keytype)->setParent(this);
    if(keytype==0&&parent!=0)
        for(int i=0;i<30;i++)
            keys[i]->setParent(parent);
    if(keytype!=0&&parent!=0)
        findKeyPointer(keytype)->setParent(parent);
    if(keytype==0&&parent==0)
        for(int i=0;i<30;i++)
            keys[i]->setParent(this);
}
void KeyBoard::setWhetherResponse(bool flag)
{
    whetherResponse=flag;
}
void KeyBoard::setAllowedOpen(bool allowedOpen)
{
    this->allowedOpen=allowedOpen;
}
void KeyBoard::mousePressEvent(QMouseEvent *event)
{
    // 如果单击并且键盘是收起的，则打开键盘
    if ( event->button() == Qt::LeftButton )
    {
        if(!isOpen())
        {
            setWhetherResponse(true);
            setAllowedOpen(true);//设置键盘可打开
            openKeyBoard();
        }else
        {
            setWhetherResponse(false);
            setAllowedOpen(false);//设置键盘可打开
            closeKeyBoard(false);
        }
    }
    // 将该事件传给父类处理
    QWidget::mousePressEvent(event);
}
void KeyBoard::setAccordPhraseReset(bool flag)
{
    accordPhraseReset=flag;
}
void KeyBoard::setInputRemind(bool inputRemind)
{
    this->inputRemind=inputRemind;
}
