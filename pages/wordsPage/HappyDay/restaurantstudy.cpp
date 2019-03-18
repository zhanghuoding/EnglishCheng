#include "restaurantstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

RestaurantStudy::RestaurantStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("RestaurantStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("ParkStudy");
    }

    picPath=picRoot+QString("/words/words/HappyDay/scene/restaurant/");

    background->setPixmap(QPixmap(picPath+QString("background1.jpg")));

    additionalLabel1->setPixmap(QPixmap(picPath+QString("bubble.gif")));
    additionalLabel1->setFixedSize(Tool::size(300,180));
    additionalLabel1->setGeometry(Tool::rect(600,215,300,180));
    additionalLabel1->setVisible(false);

    additionalLabel2->setParent(0);
    additionalLabel2->setParent(this);
    additionalLabel3->setParent(0);
    additionalLabel3->setParent(this);

    additionalLabel2->setPixmap(QPixmap(picPath+QString("left.png")));
    additionalLabel2->setFixedSize(Tool::size(40,80));
    additionalLabel2->setGeometry(Tool::rect(627,265,40,80));
    additionalLabel2->setVisible(false);
    additionalLabel3->setPixmap(QPixmap(picPath+QString("right.png")));
    additionalLabel3->setFixedSize(Tool::size(40,80));
    additionalLabel3->setGeometry(Tool::rect(827,265,40,80));
    additionalLabel3->setVisible(false);

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setParent(0);
    girlLabel->setParent(this);
    girlLabel->setFixedSize(Tool::size(200,480));
    girlLabel->setGeometry(Tool::rect(155,280,200,480));

    labels->at(0)->setFixedSize(Tool::size(1580,430));
    labels->at(0)->setGeometry(Tool::rect(0,470,1580,430));

    labels->at(1)->setFixedSize(Tool::size(380,550));
    labels->at(1)->setGeometry(Tool::rect(10,80,380,550));

    labels->at(2)->setFixedSize(Tool::size(800,650));
    labels->at(2)->setGeometry(Tool::rect(800,5,800,650));

    labels->at(3)->setFixedSize(Tool::size(140,480));
    labels->at(3)->setGeometry(Tool::rect(10,280,140,480));

    //以下内容换背景
    labels->at(4)->setFixedSize(Tool::size(220,650));
    labels->at(4)->setGeometry(Tool::rect(1380,250,220,650));

    sentenceLabel->setText("restaurant");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(Tool::rect(430,160,400,205));

    connect(additionalLabel2,SIGNAL(clicked(MyLabel*,bool)),this,SLOT(lastWord(MyLabel*,bool)));
    connect(additionalLabel3,SIGNAL(clicked(MyLabel*,bool)),this,SLOT(nextWord(MyLabel*,bool)));

    hasEntered.clear();

    init();
}
RestaurantStudy::~RestaurantStudy()
{

}
void RestaurantStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","restaurant","餐厅"},
        {"street","街道","a street","一条街道","street.gif","streetBorder.gif","","","streetPra.png"},
        {"tree","树","a tree","一棵树","tree.gif","treeBorder.gif","","","treePra.png"},
        {"restaurant","餐厅","","","restaurant.gif","restaurantBorder.gif","","","restaurantPra.png"},
        {"friend","朋友","a good friend","一个好朋友","friend.gif","friendBorder.gif","","","friendPra.png"},
        {"waiter","服务员","","","waiter.gif","waiterBorder.gif"},
        {"food","食物"},
        {"cake","蛋糕","","","cakeBox.gif","cakeTab.gif","","","cakePra.png","","","",1160,600,80,100},
        {"dumpling","饺子","a bowl of dumplings","一碗饺子","dumplingBox.gif","dumplingTab.gif","","","dumplingPra.png","","","",1080,470,100,100},
        {"ice cream","冰淇淋","an ice-cream","一个冰淇淋","iceCreamBox.gif","iceCreamTab.gif","","","iceCreamPra.png","","","",1200,470,60,120},
        {"juice","果汁","a glass of orange juice","一杯橙汁","juiceBox.gif","juiceTab.gif","","","juicePra.png","","","",900,480,60,120},
        {"noodles","面条","a bowl of noodles","一碗面","noodlesBox.gif","noodlesTab.gif","","","noodlesPra.png","","","",970,510,80,60},
        {"pizza","比萨饼","tasty pizza","美味的比萨","pizzaBox.gif","pizzaTab.gif","","","pizzaPra.png","","","",1230,560,100,100},
        {"soup","汤","chicken soup","鸡汤","chickenSoupBox.gif","chickenSoupTab.gif","","","chickenSoupPra.png","","","",1050,570,110,80},
        {"tofu","豆腐","","","tofuBox.gif","tofuTab.gif","","","tofuPra.png","","","",860,590,100,90},
        {"plate","盘子","fruit  plate","果盘","fruitPlateBox.gif","fruitPlateTab.gif","","","fruitPlatePra.png","","","",1020,640,110,90}
    };
}
void RestaurantStudy::runPage(MyLabel *label, bool isEnter)
{
    if(phrasePanel->isVisible())
        return;//如果短语面板正在显示，或者当前页面规定的单词已经学习完了，则不响应操作
    if(label)
        goto click;

    if(currentWord>=wordsNum)
        return;//如果当前页面规定的单词已经学习完了，则不响应除了显示短语以外的其他操作

    if(currentWord<4)
    {//学前4个单词的时候，是另一种场景
        background->setPixmap(QPixmap(picPath+QString("background1.jpg")));
        girlLabel->setGeometry(Tool::rect(155,280,200,480));
        labels->at(3)->setGeometry(Tool::rect(10,280,140,480));
        wordsCard->setGeometry(Tool::rect(430,160,400,205));
    }
    if(currentWord==4)
    {//学前4个单词的时候，是另一种场景
        background->setPixmap(QPixmap(picPath+QString("background1.jpg")));
        labels->at(0)->setVisible(true);
        labels->at(1)->setVisible(true);
        labels->at(2)->setVisible(true);
        girlLabel->setGeometry(Tool::rect(155,280,200,480));
        labels->at(3)->setGeometry(Tool::rect(10,280,140,480));
        wordsCard->setGeometry(Tool::rect(430,160,400,205));
    }
    if(currentWord==5)
    {//从第5个单词开始是另一种场景
        background->setPixmap(QPixmap(picPath+QString("background2.jpg")));
        labels->at(0)->setVisible(false);
        labels->at(1)->setVisible(false);
        labels->at(2)->setVisible(false);
        girlLabel->setGeometry(Tool::rect(555,400,200,480));
        labels->at(3)->setGeometry(Tool::rect(410,400,140,480));
        wordsCard->setGeometry(Tool::rect(990,100,400,205));
    }
    if(currentWord<=6)
    {//第六个单词以及以前是没有泡泡的，食物不出现在泡泡内
        additionalLabel1->setVisible(false);
        additionalLabel2->setVisible(false);
        additionalLabel3->setVisible(false);
    }
    if(currentWord==7)
    {//第七个单词以及以后的单词都出现在泡泡内
        additionalLabel1->setVisible(true);
        additionalLabel2->setVisible(true);
        additionalLabel3->setVisible(true);
    }
    if(currentWord>=7)
    {//第七个以及以后的单词用另一种方法
        goto bubble;
    }


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

    bubble:
    if(!isEnter)
    {//如果不是因为回车键被按下而执行此函数，则执行以下动作
        //设置上一个单词不可见
        if(tmpLabel1)
        {
            tmpLabel1->setVisible(false);
            tmpLabel1=NULL;
        }
        if(getString(currentWord,"pic1")!=NULL && sizeOfCharPtr(getString(currentWord,"pic1"))>0)
        {//如果该单词有至少一张图片，则显示第一张图片
            tmpLabel1=getLabelAt(labelCounter++);
            if(!tmpLabel1)
                return;//如果下标越界，或者其他原因导致没有获得label的指针，则不做任何事
            tmpLabel1->setParent(0);
            tmpLabel1->setParent(this);
            tmpLabel1->setPixmap(QPixmap(picPath+QString(getString(currentWord,"pic1"))));
            tmpLabel1->indexInWordsPhrase=currentWord;//该label对应的单词下标
            tmpLabel1->picNum=1;//该label是该单词的第一张图片
            tmpLabel1->setFixedSize(Tool::size(140,150));
            tmpLabel1->setGeometry(Tool::rect(679,232,140,150));
            tmpLabel1->setVisible(true);
        }else
        {
            tmpLabel1=NULL;//时刻注意该临时存储的指针清零
        }
        processFlag=true;//表示当前单词已经显示过了描边的图片
        tmpEnName=getString(currentWord,"words");
        tmpChName=getString(currentWord,"wChi");
        reader->addTask(tmpEnName,tmpChName);//将该单词的音频进行播放操作
        emit sendReferString(getString(currentWord,"words"));//将信号发送给键盘、“纸”和单词板对象
        return;
    }else
    {//如果是因为回车键被按下而调用此函数，则执行以下操作
        QString tmpStr(QString("#")+QString(getString(currentWord,"words"))+QString("#"));

        if(labelCounter>=tableNum)
            return;//如果label已经被用完了。则什么都不做，返回
        if(!hasEntered.contains(tmpStr,Qt::CaseSensitive))
        {

            hasEntered.append(tmpStr);//如果该单词没有被输入过，则记录该单词

            if(getLabelAt(labelCounter-1) && currentWord<wordsNum-1)
                getLabelAt(labelCounter-1)->setVisible(false);//设置当前label不可见
            tmpLabel2=getLabelAt(tableNum--);
            if(tmpLabel2)
            {
                tmpLabel2->setPixmap(QPixmap(picPath+QString(getString(currentWord,"pic1Border"))));
                tmpLabel2->setFixedSize(Tool::size(getDigit(currentWord,"aw"),getDigit(currentWord,"ah")));
                tmpLabel2->setGeometry(Tool::rect(getDigit(currentWord,"ax"),getDigit(currentWord,"ay"),
                                                getDigit(currentWord,"aw"),getDigit(currentWord,"ah")));
                tmpLabel2->setVisible(true);
                tmpLabel2->picNum=1;
                tmpLabel2->indexInWordsPhrase=currentWord;
            }
            //记录下上一个单词所涉及的图片的指针
            ptrPair *ptr=new ptrPair{tmpLabel1,tmpLabel2};
            learnedHistory->push(ptr);//入栈，记录
        }
        tmpLabel2=NULL;//将临时指针清零
        tmpEnName=NULL;
        tmpChName=NULL;
        if(currentWord<wordsNum-1)
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
        phrasePanel->setParent(0);
        phrasePanel->setParent(this);
        Singleton<KeyBoard>::instance().setParent(0);
        Singleton<KeyBoard>::instance().setParent(this);
        Singleton<KeyBoard>::instance().setVisible(true);
        phrasePanel->openThisPanel(tmpEnName,tmpChName);
        reader->addTask(str_Phrase.toLatin1().data(),str_pChi.toLatin1().data());//读短语或者单词
    }
}
void RestaurantStudy::startRepeat()
{
    if(phrasePanel->isVisible())
        return;//如果短语面板正在显示，则不响应操作
    ((KeyBoard*)(&Singleton<KeyBoard>::instance()))->closeKeyBoard();//关闭键盘
    this->reset();//重置该页面
    this->setLabelVisibleFalse();//设置所有组件不显示

    background->setPixmap(QPixmap(picPath+QString("background1.jpg")));
    girlLabel->setGeometry(Tool::rect(155,280,200,480));
    wordsCard->setGeometry(Tool::rect(430,160,400,205));
    additionalLabel1->setVisible(false);
    additionalLabel2->setVisible(false);
    additionalLabel3->setVisible(false);
    if(!triggerThread.isRunning())
        triggerThread.start();//启动页面启动器
}
void RestaurantStudy::startLastWord(MyLabel *label,bool isEnter)
{
    if(phrasePanel->isVisible() || currentWord==1)
        return;//如果短语面板正在显示，或者当前已经是第一个单词，则不响应操作

    if(tableNum<labelNumInStudyPage-1)
    {
        if(currentWord!=getLabelAt(tableNum+1)->indexInWordsPhrase)
            getLabelAt(labelCounter-1)->setVisible(false);//先设置当前显示的图片不可见
        currentWord=getLabelAt(tableNum+1)->indexInWordsPhrase;
    }

    if(currentWord<4)
    {//学前4个单词的时候，是另一种场景
        background->setPixmap(QPixmap(picPath+QString("background1.jpg")));
        girlLabel->setGeometry(Tool::rect(155,280,200,480));
        labels->at(3)->setGeometry(Tool::rect(10,280,140,480));
        wordsCard->setGeometry(Tool::rect(430,160,400,205));
    }if(currentWord==4)
    {//学前4个单词的时候，是另一种场景
        background->setPixmap(QPixmap(picPath+QString("background1.jpg")));
        labels->at(0)->setVisible(true);
        labels->at(1)->setVisible(true);
        labels->at(2)->setVisible(true);
        girlLabel->setGeometry(Tool::rect(155,280,200,480));
        labels->at(3)->setGeometry(Tool::rect(10,280,140,480));
        wordsCard->setGeometry(Tool::rect(430,160,400,205));
    }
    if(currentWord<=6)
    {//第六个单词以及以前是没有泡泡的，食物不出现在泡泡内
        additionalLabel1->setVisible(false);
        additionalLabel2->setVisible(false);
        additionalLabel3->setVisible(false);
    }
    if(currentWord>=7)
    {//第七个以及以后的单词用另一种方法
        goto bubble;
    }

    //对于第七个以及以前的单词，如下操作
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
    currentWord--;//单词计数器后退
    goto mustExecute;

    bubble:
    //设置当前学习的单词的图标不可见
    if(tmpLabel1)
    {
        tmpLabel1->setVisible(false);
        tmpLabel1=NULL;
        labelCounter--;//label计数器相应后退
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
            currentWord=((MyLabel*)(learnedHistory->top()->ptr2))->indexInWordsPhrase;
            tableNum++;
        }else
        {
            if(currentWord>1)
                currentWord--;
        }
        learnedHistory->pop();//移除该元素
        QString tmpStr(QString("#")+QString(getString(currentWord,"words"))+QString("#"));
        hasEntered.remove(tmpStr,Qt::CaseSensitive);//记录该单词还没有被输入过
    }else
    {
        if(currentWord>1)
            currentWord--;
    }

    mustExecute:
    Singleton<KeyBoard>::instance().reset();//重置键盘
    paper->reset();//重置“纸”对象
    startPage();//学习上一个单词
}
void RestaurantStudy::startNextWord(MyLabel *label,bool isEnter)
{
    if(phrasePanel->isVisible() || currentWord>=wordsNum-1)
        return;//如果短语面板正在显示，或者当前已经是最后一个单词，则不响应操作

    if(currentWord>=5)
    {//从第5个单词开始是另一种场景
        background->setPixmap(QPixmap(picPath+QString("background2.jpg")));
        labels->at(0)->setVisible(false);
        labels->at(1)->setVisible(false);
        labels->at(2)->setVisible(false);
        girlLabel->setGeometry(Tool::rect(555,400,200,480));
        labels->at(3)->setGeometry(Tool::rect(410,400,140,480));
        wordsCard->setGeometry(Tool::rect(990,100,400,205));
    }\
    if(currentWord>=7)
    {//第七个单词以及以后的单词都出现在泡泡内
        additionalLabel1->setVisible(true);
        additionalLabel2->setVisible(true);
        additionalLabel3->setVisible(true);
    }
    /*if(currentWord>=7)
    {//第七个以及以后的单词用另一种方法
        goto bubble;
    }

    bubble:

    mustExecute:*/
    Singleton<KeyBoard>::instance().reset();//重置键盘
    paper->reset();//重置“纸”对象
    if(!processFlag)
        runPage(NULL,false);
    if(processFlag)
        runPage(NULL,true);
}
void RestaurantStudy::lastWord(MyLabel *label, bool isEnter)
{
    if(phrasePanel->isVisible() || currentWord<=7)
        return;//如果短语面板正在显示，或者当前已经是第一个单词，则不响应操作

    if(getLabelAt(--labelCounter))
        getLabelAt(labelCounter)->setVisible(false);//设置当前label不可见
    if(getLabelAt(labelCounter-1))
    {
        getLabelAt(labelCounter-1)->setVisible(true);
        currentWord=getLabelAt(labelCounter-1)->indexInWordsPhrase;
    }
    Singleton<KeyBoard>::instance().reset();//重置键盘
    paper->reset();//重置“纸”对象
    emit sendReferString(getString(currentWord,"words"));//将信号发送给键盘、“纸”和单词板对象
}
void RestaurantStudy::nextWord(MyLabel *label, bool isEnter)
{
    if(phrasePanel->isVisible() || currentWord>=wordsNum-1)
        return;//如果短语面板正在显示，或者当前已经是最后一个单词，则不响应操作

    currentWord++;

    if(getLabelAt(labelCounter-1))
        getLabelAt(labelCounter-1)->setVisible(false);//设置当前label不可见

    if(getString(currentWord,"pic1")!=NULL && sizeOfCharPtr(getString(currentWord,"pic1"))>0)
    {//如果该单词有至少一张图片，则显示第一张图片
        tmpLabel1=getLabelAt(labelCounter++);
        if(!tmpLabel1)
            return;//如果下标越界，或者其他原因导致没有获得label的指针，则不做任何事
        tmpLabel1->setParent(0);
        tmpLabel1->setParent(this);
        tmpLabel1->setPixmap(QPixmap(picPath+QString(getString(currentWord,"pic1"))));
        tmpLabel1->indexInWordsPhrase=currentWord;//该label对应的单词下标
        tmpLabel1->picNum=1;//该label是该单词的第一张图片
        tmpLabel1->setFixedSize(Tool::size(140,150));
        tmpLabel1->setGeometry(Tool::rect(679,232,140,150));
        tmpLabel1->setVisible(true);
    }else
    {
        tmpLabel1=NULL;//时刻注意该临时存储的指针清零
    }
    processFlag=true;//表示当前单词已经显示过了描边的图片
    tmpEnName=getString(currentWord,"words");
    tmpChName=getString(currentWord,"wChi");
    reader->addTask(tmpEnName,tmpChName);//将该单词的音频进行播放操作
    Singleton<KeyBoard>::instance().reset();//重置键盘
    paper->reset();//重置“纸”对象
    emit sendReferString(getString(currentWord,"words"));//将信号发送给键盘、“纸”和单词板对象
}
