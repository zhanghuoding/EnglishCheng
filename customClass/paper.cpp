#include "paper.h"
#include "customClass/tool.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

Paper::Paper(QWidget *parent):QWidget(parent)
{
    background=new QLabel(this);
    background->setScaledContents(true);
    background->setPixmap(QPixmap(picRoot+QString("/public/editbox.gif")));
    background->setFixedSize(*editBoxSize);
    background->setGeometry(0,0,editBoxSize->width(),editBoxSize->height());

    setGeometry((screenSize->width()-editBoxSize->width())/2+0.5,
                           screenSize->height()-keyBoardMaxSize->height()-editBoxSize->height(),
                           editBoxSize->width(),editBoxSize->height());
    referString=new QString("#");
    currentLetter=0;
    doReset=true;//默认情况下重置对象

    editArea=new QLabel(this);
    QString str("QLabel{font-family:'Century Schoolbook';font-size:");
    str.append(QString::number(Tool::fontSize(paperFontSize)).toLatin1().data()).append("px;color:#000000;}");
    editArea->setStyleSheet(str);
    editArea->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//设置输入的文本上下左右居中显示
    editArea->setFixedSize(editBoxSize->width()-50,editBoxSize->height()-13);
    editArea->setGeometry(25,5,editBoxSize->width(),editBoxSize->height());

    connect(((KeyBoard*)(&Singleton<KeyBoard>::instance())),SIGNAL(enterKeyWasPressed()),this,SLOT(completeWrite()));
    connect(((KeyBoard*)(&Singleton<KeyBoard>::instance())),SIGNAL(keyBoardOpened(QWidget*)),this,SLOT(openPaper(QWidget*)));
    connect(((KeyBoard*)(&Singleton<KeyBoard>::instance())),SIGNAL(keyBoardClosed(bool)),this,SLOT(closePaper(bool)));
}
Paper::~Paper()
{
    delete background;
    delete referString;
    delete editArea;
}
void Paper::writeChar(keytype_ keyType)
{
    if(!referString)
        return;//如果参照字符串不存在，则返回
    if((currentLetter>=referString->length() || referString->at(currentLetter)!=keyType) && keyType!=8 || !editArea)
    {//当输入的字母不符合并且不是退格键，或者显示字符串的label不存在的时候，什么都不做，返回
        return;//当输入的字母不符合或者显示字符串的label不存在或者输入的字母已经够数的时候，什么都不做，返回
    }

    char ch=keyType;//将新的字符转换成字符形式

    if(currentLetter==0)
    {//当当前输入的是第一个字母的时候，清空以前的输入（即从“纸”上擦除文本）
        editArea->setText("");
    }

    QString tmp(editArea->text());
    if(keyType==8)
    {//当键是退格键的时候，删除刚刚输入的一个字符
        if(tmp.length()<=0)
        {
            return;//如果label中当前没有字符串存在，则返回
        }
        tmp=tmp.remove(--currentLetter,1);//移除最后一个字母
    }else
    {//如果不是退格键的时候，将新输入的字母显示在提示框里
        if(currentLetter==referString->length())
        {
            return;//当输入的字母已经够数的时候，不能再继续输入，返回
        }
        tmp.append(ch);
        currentLetter++;

        while(true)
        {
            if(currentLetter<referString->length() && punctuation->contains(referString->at(currentLetter)))
            {//如果接下来要输入的是普通标点符号的时候，自动跳过标点符号
                tmp.append(referString->at(currentLetter));
                currentLetter++;
            }else
                break;
        }
    }

    editArea->setText(tmp);
}
void Paper::setReferString(char *referString)
{
    reset();
    this->referString=new QString(referString);
}
void Paper::reset()
{
    if(referString)
    {
        delete referString;
        referString=new QString("#");
    }
    currentLetter=0;
    editArea->setText("");
}
void Paper::openPaper(QWidget *parent)
{
    setParent(parent);
    this->setVisible(true);
}
void Paper::closePaper(bool needReset)
{
    this->setVisible(false);
    if(doReset && needReset)
        reset();
}
void Paper::setDoReset(bool doReset)
{
    this->doReset=doReset;
}
void Paper::completeWrite()
{
    QString str(referString->toLatin1().data());
    emit haveWrite(str);
    reset();
}

