#include "mystudypage.h"
#include "customClass/tool.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"
#include "mainwindow.h"

#include <QUrl>

MyStudyPage::MyStudyPage(QWidget *parent) : QWidget(parent)
{
    background=new QLabel(this);
    background->setScaledContents(true);
    background->setFixedSize(*screenSize);
    background->setGeometry(Tool::rect(0,0,1600,900));

    wordsPhrase=NULL;
    wordsNum=0;
    currentWord=1;
    labels=new QList<MyLabel*>;
    labelCounter=0;
    wordsPicCounter=0;
    tmpLabel1=NULL;
    tmpLabel2=NULL;
    learnedHistory=new QStack<ptrPair*>;
    tmpEnName=NULL;
    tmpChName=NULL;
    processFlag=false;
    nextPageName=new QString;
    tableNum=labelNumInStudyPage-1;

    MyLabel *tmp=NULL;
    QString str("label");
    for(int i=0;i<labelNumInStudyPage;i++)
    {
        tmp=new MyLabel(this);
        tmp->setVisible(false);//设置不显示该组件
        tmp->setObjectName(str+QString::number(i));
        labels->append(tmp);
        connect(tmp,SIGNAL(clicked(MyLabel*,bool)),this,SLOT(runPage(MyLabel*,bool)));
        tmp=NULL;
    }

    girlLabel=new MyLabel(this);
    girlLabel->setObjectName(QString("girlLabel"));
    additionalLabel1=new MyLabel(this);
    additionalLabel1->setObjectName("additionalLabel1");
    additionalLabel1->setVisible(false);
    additionalLabel2=new MyLabel(this);
    additionalLabel2->setObjectName("additionalLabel2");
    additionalLabel2->setVisible(false);
    additionalLabel3=new MyLabel(this);
    additionalLabel3->setObjectName("additionalLabel3");
    additionalLabel3->setVisible(false);
    lastWordLabel=new MyLabel(this);
    lastWordLabel->setObjectName(QString("lastWordLabel"));
    nextWordLabel=new MyLabel(this);
    nextWordLabel->setObjectName(QString("nextWordLabel"));
    sentenceLabel=new MyLabel(this);
    sentenceLabel->setObjectName(QString("sentenceLabel"));
    wordsCard=new WordsCard(this);
    nextBarrButton=new MyPushButton(this);
    repeatButton=new MyPushButton(this);
    phrasePanel=new PhrasePanel(this);

    girlLabel->setGeometry(Tool::rect(screenSize->width(),screenSize->height(),0,0));//设置不显示该组件
    wordsCard->setVisible(true);//显示单词板
    phrasePanel->setVisible(false);

    connect(this,SIGNAL(sendReferString(char*)),wordsCard,SLOT(setWords(char*)));
    connect(phrasePanel,SIGNAL(thisPanelClosed()),this,SLOT(cleanLabelsIsClickedOutside()));

    connect(&triggerThread,SIGNAL(finished()),this,SLOT(startPage()));//将触发器和学习页面的开始槽函数链接

    connect(lastWordLabel,SIGNAL(clicked(MyLabel*,bool)),this,SLOT(startLastWord(MyLabel *,bool)));
    connect(nextWordLabel,SIGNAL(clicked(MyLabel*,bool)),this,SLOT(startNextWord(MyLabel *,bool)));
    connect(sentenceLabel,SIGNAL(clicked(MyLabel*,bool)),this,SLOT(startSentence(MyLabel *,bool)));
    connect(nextBarrButton,SIGNAL(clicked()),this,SLOT(startNextBarr()));
    connect(repeatButton,SIGNAL(clicked()),this,SLOT(startRepeat()));

    connect(&Singleton<KeyBoard>::instance(),SIGNAL(enterKeyWasPressed()),this,SLOT(whetherEnterKeyWasPressed()));
    connect(this,SIGNAL(enterKeyWasPressed(MyLabel*,bool)),this,SLOT(runPage(MyLabel*,bool)));
    connect(phrasePanel,SIGNAL(thisPanelClosed()),this,SLOT(reSendReferString()));
    connect(this,SIGNAL(sendReferString(char*)),((KeyBoard*)(&Singleton<KeyBoard>::instance())),SLOT(setReferString(char*)));
    connect(this,SIGNAL(sendReferString(char*)),paper,SLOT(setReferString(char*)));
    connect(phrasePanel,SIGNAL(sendPanelText(char*)),&Singleton<KeyBoard>::instance(),SLOT(setReferString(char*)));
    connect(phrasePanel,SIGNAL(sendPanelText(char*)),paper,SLOT(setReferString(char*)));
    connect(phrasePanel,SIGNAL(setKeyBorderAccordReset(bool)),&Singleton<KeyBoard>::instance(),SLOT(setAccordPhraseReset(bool)));
    connect(phrasePanel,SIGNAL(inputRemind(bool)),&Singleton<KeyBoard>::instance(),SLOT(setInputRemind(bool)));

    lastWordLabel->setPixmap(QPixmap(picRoot+QString("/public/leftArrow.gif")));
    lastWordLabel->setFixedSize(Tool::size(90,60));
    lastWordLabel->setGeometry(Tool::rect(70,780,90,60));

    nextWordLabel->setPixmap(QPixmap(picRoot+QString("/public/rightArrow.gif")));
    nextWordLabel->setFixedSize(Tool::size(90,60));
    nextWordLabel->setGeometry(Tool::rect(1440,780,90,60));

    sentenceLabel->setPixmap(QPixmap(picRoot+QString("/words/words/ILoveMyHome/scene/scene1/titleBackground.gif")));
    QString sentenceLabelStyle("QLabel{font-family:'Century Schoolbook';font-size:");
    sentenceLabelStyle.append(QString::number(Tool::fontSize(sentenceLabelFontSize)).toLatin1().data()).append("px;color:#000000;background-color:#ffffff}");
    sentenceLabel->setStyleSheet(sentenceLabelStyle);
    sentenceLabel->setFixedSize(Tool::size(350,60));
    sentenceLabel->setGeometry(Tool::rect(80,30,350,60));

    repeatButton->setIcon(QPixmap(picRoot+QString("/public/passResource/replay.png")));
    repeatButton->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20),-1,-1,-1,"#fdf7d8","#fdf4c7","#fbefb4"));
    repeatButton->setIconSize(Tool::size(45,45));
    repeatButton->setFixedSize(Tool::size(40,40));
    repeatButton->setGeometry(Tool::rect(1487,12,40,40));

    nextBarrButton->setIcon(QPixmap(picRoot+QString("/public/passResource/next.png")));
    nextBarrButton->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20),-1,-1,-1,"#fcfae3","#fcf8ce","#f9f3b3"));
    nextBarrButton->setIconSize(Tool::size(45,45));
    nextBarrButton->setFixedSize(Tool::size(40,40));
    nextBarrButton->setGeometry(Tool::rect(1442,12,40,40));
}
MyStudyPage::~MyStudyPage()
{
    delete background;
    for(int i=0;i<labelNumInStudyPage;i++)
        delete labels->at(i);
    delete labels;
    delete girlLabel;
    delete lastWordLabel;
    delete nextWordLabel;
    delete wordsCard;
    delete sentenceLabel;
    delete nextBarrButton;
    delete repeatButton;
    delete phrasePanel;
    while(learnedHistory->length()>0)
    {
        delete (ptrPair*)(learnedHistory->top());
        learnedHistory->pop_back();
    }
    delete learnedHistory;
    if(nextPageName)
        delete nextPageName;
    if(additionalLabel1)
        delete additionalLabel1;
    if(additionalLabel2)
        delete additionalLabel2;
    if(additionalLabel3)
        delete additionalLabel3;
}
MyLabel *MyStudyPage::getLabelAt(int index)
{
    if(index>=labels->length() || index<0)
        return NULL;
    return labels->at(index);
}
void MyStudyPage::startPage()
{
    if(!phrasePanel->isVisible())
        runPage(NULL,false);//只有短语面板没有正在显示，才响应操作
}

void MyStudyPage::runPage(MyLabel *label, bool isEnter)
{
    if(phrasePanel->isVisible())
        return;//如果短语面板正在显示，或者当前页面规定的单词已经学习完了，则不响应操作
    if(label)
        goto click;

    if(currentWord>=wordsNum)
        return;//如果当前页面规定的单词已经学习完了，则不响应除了显示短语以外的其他操作

    if(!isEnter)
    {//如果不是因为回车键被按下而执行此函数，则执行以下动作
        if(getString(currentWord,"pic1Border")!=NULL && sizeOfCharPtr(getString(currentWord,"pic1Border"))>0)
        {//如果该单词有至少一张图片，则显示第一张图片
            tmpLabel1=getLabelAt(labelCounter++);
            if(!tmpLabel1)
                return;//如果下标越界，或者其他原因导致没有获得label的指针，则不做任何事
            tmpLabel1->setPixmap(QPixmap(picPath+QString(getString(currentWord,"pic1Border"))));
            tmpLabel1->indexInWordsPhrase=currentWord;//该label对应的单词下标
            tmpLabel1->picNum=1;//该label是该单词的第一张图片
            tmpLabel1->setVisible(true);
        }else
        {
            tmpLabel1=NULL;//时刻注意该临时存储的指针清零
        }

        if(getString(currentWord,"pic2Border")!=NULL && sizeOfCharPtr(getString(currentWord,"pic2Border"))>0)
        {//如果该单词有不止一张图片，则显示第二张图片
            tmpLabel2=getLabelAt(labelCounter++);
            if(!tmpLabel2)
                return;//如果下标越界，或者其他原因导致没有获得label的指针，则不做任何事
            tmpLabel2->setPixmap(QPixmap(picPath+QString(getString(currentWord,"pic2Border"))));
            tmpLabel2->indexInWordsPhrase=currentWord;//该label对应的单词下标
            tmpLabel2->picNum=2;//该label是该单词的第二张图片
            tmpLabel2->setVisible(true);
        }else
        {
            tmpLabel2=NULL;//时刻注意该临时存储的指针清零
        }
        processFlag=true;//表示当前单词已经显示过了描边的图片
        tmpEnName=getString(currentWord,"words");
        tmpChName=getString(currentWord,"wChi");
        reader->addTask(tmpEnName,tmpChName);//将该单词的音频进行播放操作
        emit sendReferString(getString(currentWord,"words"));//将信号发送给键盘、“纸”和单词板对象
        return;
    }else
    {//如果是因为回车键被按下而调用此函数，则执行以下操作
        if(tmpLabel1)
            tmpLabel1->setPixmap(QPixmap(picPath+QString(getString(currentWord,"pic1"))));//恢复未描边的图片
        if(tmpLabel2)
            tmpLabel2->setPixmap(QPixmap(picPath+QString(getString(currentWord,"pic2"))));
        //记录下上一个单词所涉及的图片的指针
        ptrPair *ptr=new ptrPair{tmpLabel1,tmpLabel2};
        learnedHistory->push(ptr);//入栈，记录
        tmpLabel1=NULL;//将四个临时指针清零
        tmpLabel2=NULL;
        tmpEnName=NULL;
        tmpChName=NULL;
        currentWord++;//当前学习的单词指针后移
        processFlag=false;//用于标记当前单词是否已经显示过了描边的图片
        if(!triggerThread.isRunning())
            triggerThread.start();//启动页面中的触发器，使页面自动运行起来，开始页面中的下一个单词
        return;
    }

    click://如果因为有某个组件被点击而执行此函数，则从这里开始执行
    QString str(""),str_Phrase(""),str_pChi("");
    if(label->picNum==1)
    {//如果该label是该单词对应的第一张图片
        if(getString(label->indexInWordsPhrase,"phrasePic1")!=NULL && sizeOfCharPtr(getString(label->indexInWordsPhrase,"phrasePic1"))>0)
        {//如果第一张短语图片存在的话，则显示第一张
            str=picPath+QString(getString(label->indexInWordsPhrase,"phrasePic1"));
        }else if(getString(label->indexInWordsPhrase,"phrasePic2")!=NULL && sizeOfCharPtr(getString(label->indexInWordsPhrase,"phrasePic2"))>0)
        {//如果第一张短语图片不存在，第二张短语图片存在的话，则显示第二张
            str=picPath+QString(getString(label->indexInWordsPhrase,"phrasePic2"));
        }
        if(getString(label->indexInWordsPhrase,"phrase_1")!=NULL && sizeOfCharPtr(getString(label->indexInWordsPhrase,"phrase_1"))>0)
        {
            str_Phrase+=QString(getString(label->indexInWordsPhrase,"phrase_1"));//如果第一条短语存在，则显示第一条短语
            str_pChi+=QString(getString(label->indexInWordsPhrase,"pChi_1"));//显示第一条短语的汉语翻译
        }
        else if(getString(label->indexInWordsPhrase,"phrase_2")!=NULL && sizeOfCharPtr(getString(label->indexInWordsPhrase,"phrase_2"))>0)
        {
            str_Phrase+=QString(getString(label->indexInWordsPhrase,"phrase_2"));//如果第一条短语不存在，第二条短语存在，则显示第二条短语
            str_pChi+=QString(getString(label->indexInWordsPhrase,"pChi_2"));//显示第二条短语的汉语翻译
        }
    }else if(label->picNum==2)
    {//如果该label是该单词对应的第二张图片
        if(getString(label->indexInWordsPhrase,"phrasePic2")!=NULL && sizeOfCharPtr(getString(label->indexInWordsPhrase,"phrasePic2"))>0)
        {//如果第二张短语图片存在的话，则显示第二张
            str=picPath+QString(getString(label->indexInWordsPhrase,"phrasePic2"));
        }else if(getString(label->indexInWordsPhrase,"phrasePic1")!=NULL && sizeOfCharPtr(getString(label->indexInWordsPhrase,"phrasePic1"))>0)
        {//如果第二张短语图片不存在，第一张短语图片存在的话，则显示第一张
            str=picPath+QString(getString(label->indexInWordsPhrase,"phrasePic1"));
        }
        if(getString(label->indexInWordsPhrase,"phrase_2")!=NULL && sizeOfCharPtr(getString(label->indexInWordsPhrase,"phrase_2"))>0)
        {
            str_Phrase+=QString(getString(label->indexInWordsPhrase,"phrase_2"));//如果第二条短语存在，则显示第二条短语
            str_pChi+=QString(getString(label->indexInWordsPhrase,"pChi_2"));//显示第二条短语的汉语翻译
        }
        else if(getString(label->indexInWordsPhrase,"phrase_1")!=NULL && sizeOfCharPtr(getString(label->indexInWordsPhrase,"phrase_1"))>0)
        {
            str_Phrase+=QString(getString(label->indexInWordsPhrase,"phrase_1"));//如果第二条短语不存在，第一条短语存在，则显示第一条短语
            str_pChi+=QString(getString(label->indexInWordsPhrase,"pChi_1"));//显示第一条短语的汉语翻译
        }
    }
    if(!str.isEmpty())
    {//如果短语图片存在的话，则显示短语图片
        phrasePanel->setPixmap(QPixmap(str));
        if(str_Phrase.isEmpty())//如果短语不存在的话，则显示单词
        {
            str_Phrase+=QString(getString(label->indexInWordsPhrase,"words"));//如果短语不存在，则显示单词
            str_pChi+=QString(getString(label->indexInWordsPhrase,"wChi"));//显示单词的汉语翻译
        }
        phrasePanel->setPhrase(str_Phrase.toLatin1().data());//显示短语或者单词
        phrasePanel->openThisPanel(tmpEnName,tmpChName);
        reader->addTask(str_Phrase.toLatin1().data(),str_pChi.toLatin1().data());//读短语或者单词
    }
}

QLabel *MyStudyPage::getBackgroundLabel()
{
    return background;
}
char *MyStudyPage::getString(unsigned short index, char *name)
{
    if(index<0 || index>=wordsNum)
        return NULL;
    if(QString(name).compare("words",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].words);
    if(QString(name).compare("wChi",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].wChi);
    if(QString(name).compare("phrase_1",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].phrase_1);
    if(QString(name).compare("pChi_1",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].pChi_1);
    if(QString(name).compare("phrase_2",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].phrase_2);
    if(QString(name).compare("pChi_2",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].pChi_2);
    if(QString(name).compare("pic1",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].pic1);
    if(QString(name).compare("pic1Border",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].pic1Border);
    if(QString(name).compare("pic2",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].pic2);
    if(QString(name).compare("pic2Border",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].pic2Border);
    if(QString(name).compare("phrasePic1",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].phrasePic1);
    if(QString(name).compare("phrasePic2",Qt::CaseInsensitive)==0)
        return (char*)(wordsPhrase[index].phrasePic2);
    return NULL;
}
short MyStudyPage::getDigit(unsigned short index,char *name)
{
    if(index<0 || index>=wordsNum)
        return NULL;
    if(QString(name).compare("ax",Qt::CaseInsensitive)==0)
        return (wordsPhrase[index].ax);
    if(QString(name).compare("ay",Qt::CaseInsensitive)==0)
        return (wordsPhrase[index].ay);
    if(QString(name).compare("aw",Qt::CaseInsensitive)==0)
        return (wordsPhrase[index].aw);
    if(QString(name).compare("ah",Qt::CaseInsensitive)==0)
        return (wordsPhrase[index].ah);
    return 0;
}

TriggerThread *MyStudyPage::getTriggerThread()
{
    return &triggerThread;
}
void MyStudyPage::whetherEnterKeyWasPressed()
{
    if(!phrasePanel->isVisible())
        emit enterKeyWasPressed(NULL,true);
}

void MyStudyPage::setLabelVisibleFalse()
{
    for(int i=0;i<labelNumInStudyPage;i++)
    {
        labels->at(i)->setVisible(false);//设置不显示该组件
        labels->at(i)->isclickedOutside=false;//恢复该组件是否被点击的标志
    }
    girlLabel->isclickedOutside=false;
    wordsCard->close();
    phrasePanel->setVisible(false);//设置短语面板不可见
}
void MyStudyPage::reset()
{//对页面中的参数进行重置
    currentWord=1;//单词计数是从1开始的
    cleanLabelsIsClickedOutside();
    labelCounter=0;
    wordsPicCounter=0;
    tmpLabel1=NULL;
    tmpLabel2=NULL;
    tmpEnName=NULL;
    tmpChName=NULL;
    processFlag=false;
    tableNum=labelNumInStudyPage-1;
    hasEntered.clear();

    for(int i=0;i<labelNumInStudyPage;i++)
    {
        labels->at(i)->indexInWordsPhrase=0;
        labels->at(i)->picNum=0;
    }
    girlLabel->indexInWordsPhrase=0;
    girlLabel->picNum=0;
    lastWordLabel->indexInWordsPhrase=0;
    lastWordLabel->picNum=0;
    nextWordLabel->indexInWordsPhrase=0;
    nextWordLabel->picNum=0;
    sentenceLabel->indexInWordsPhrase=0;
    sentenceLabel->picNum=0;
    while(learnedHistory->length()>0)
    {
        delete (ptrPair*)(learnedHistory->top());
        learnedHistory->pop_back();
    }
}
void MyStudyPage::cleanLabelsIsClickedOutside()
{
    for(int i=0;i<labelNumInStudyPage;i++)
    {
        labels->at(i)->isclickedOutside=false;
    }

    girlLabel->isclickedOutside=false;
    lastWordLabel->isclickedOutside=false;
    nextWordLabel->isclickedOutside=false;
    sentenceLabel->isclickedOutside=false;
}

void MyStudyPage::startLastWord(MyLabel *label,bool isEnter)
{
    if(phrasePanel->isVisible() || currentWord==1)
        return;//如果短语面板正在显示，或者当前已经是第一个单词，则不响应操作
    //设置当前学习的单词的图标不可见
    if(tmpLabel1)
    {
        tmpLabel1->setVisible(false);
        tmpLabel1=NULL;
        labelCounter--;//label计数器相应后退
    }
    if(tmpLabel2)
    {
        tmpLabel2->setVisible(false);
        tmpLabel2=NULL;
        labelCounter--;
    }
    if(!learnedHistory->isEmpty())
    {//栈不为空时，进行以下操作:设置上一个单词的图标不可见
        if(learnedHistory->top()->ptr1)
        {
            //currentWord=((MyLabel*)(learnedHistory->top()->ptr1))->indexInWordsPhrase;//设置单词进度为上一个单词
            ((MyLabel*)(learnedHistory->top()->ptr1))->setVisible(false);//不显示该图片
            labelCounter--;
        }
        if(learnedHistory->top()->ptr2)
        {
            //currentWord=((MyLabel*)(learnedHistory->top()->ptr2))->indexInWordsPhrase;//设置单词进度为上一个单词
            ((MyLabel*)(learnedHistory->top()->ptr2))->setVisible(false);//不显示该图片
            labelCounter--;
        }
        learnedHistory->pop();//移除该元素
    }
    Singleton<KeyBoard>::instance().reset();//重置键盘
    paper->reset();//重置“纸”对象
    currentWord--;//单词计数器后退
    startPage();//学习上一个单词
}
void MyStudyPage::startNextWord(MyLabel *label,bool isEnter)
{
    if(phrasePanel->isVisible() || currentWord>=wordsNum-1)
        return;//如果短语面板正在显示，或者当前已经是最后一个单词，则不响应操作
    Singleton<KeyBoard>::instance().reset();//重置键盘
    paper->reset();//重置“纸”对象
    if(!processFlag)
        runPage(NULL,false);
    if(processFlag)
        runPage(NULL,true);
}
void MyStudyPage::startRepeat()
{
    if(phrasePanel->isVisible())
        return;//如果短语面板正在显示，则不响应操作
    ((KeyBoard*)(&Singleton<KeyBoard>::instance()))->closeKeyBoard();//关闭键盘
    this->reset();//重置该页面
    this->setLabelVisibleFalse();//设置所有组件不显示
    if(!triggerThread.isRunning())
        triggerThread.start();//启动页面启动器
}
void MyStudyPage::startSentence(MyLabel *label,bool isEnter)
{
    if(phrasePanel->isVisible())
        return;//如果短语面板正在显示，则不响应操作
    reader->setMedia(QUrl::fromLocalFile(audioPath+QString(getString(0,"phrase_1"))+audioSuffix));
}
void MyStudyPage::startNextBarr()
{//进入下个关卡
    if(phrasePanel->isVisible())
        return;//如果短语面板正在显示，则不响应操作
    if(nextPageName->isEmpty())
    {
        Tool::showDialog();//显示提示信息
        return;//如果新的类名为空，则不创建页面，并返回空
    }
    if(nextPageName->compare("over",Qt::CaseInsensitive)==0)
    {
        return;
    }
    Singleton<MainWindow>::instance().creatPage(*nextPageName);
}
void MyStudyPage::setLabelVisibleTrue()
{
    for(int i=0;i<labelNumInStudyPage;i++)
    {
        labels->at(i)->setVisible(true);//设置不显示该组件
        labels->at(i)->isclickedOutside=false;//恢复该组件是否被点击的标志
    }
}
PhrasePanel *MyStudyPage::getPhrasePanel()
{
    return phrasePanel;
}
void MyStudyPage::reSendReferString()
{
    emit sendReferString(getString(currentWord,"words"));//将信号发送给键盘、“纸”和单词板对象
}
