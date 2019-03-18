#include "fruitandvegetablestudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

FruitAndVegetableStudy::FruitAndVegetableStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("FruitAndVegetableStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("over");
    }

    picPath=picRoot+QString("/words/words/HappyDay/scene/fruitAndVegetable/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    additionalLabel1->setPixmap(QPixmap(picPath+QString("messageBox.gif")));
    additionalLabel1->setFixedSize(Tool::size(300,250));
    additionalLabel1->setGeometry(Tool::rect(480,110,300,250));
    additionalLabel1->setVisible(true);

    additionalLabel2->setParent(0);
    additionalLabel2->setParent(this);
    additionalLabel3->setParent(0);
    additionalLabel3->setParent(this);

    additionalLabel2->setPixmap(QPixmap(picPath+QString("left.png")));
    additionalLabel2->setFixedSize(Tool::size(40,80));
    additionalLabel2->setGeometry(Tool::rect(510,175,40,80));
    additionalLabel2->setVisible(true);
    additionalLabel3->setPixmap(QPixmap(picPath+QString("right.png")));
    additionalLabel3->setFixedSize(Tool::size(40,80));
    additionalLabel3->setGeometry(Tool::rect(710,175,40,80));
    additionalLabel3->setVisible(true);

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(160,380));
    girlLabel->setGeometry(Tool::rect(120,410,160,380));

    sentenceLabel->setText("fruit and vegetable");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(Tool::rect(1150,500,400,205));

    connect(additionalLabel2,SIGNAL(clicked(MyLabel*,bool)),this,SLOT(startLastWord(MyLabel*,bool)));
    connect(additionalLabel3,SIGNAL(clicked(MyLabel*,bool)),this,SLOT(startNextWord(MyLabel*,bool)));

    init();
}
FruitAndVegetableStudy::~FruitAndVegetableStudy()
{

}
void FruitAndVegetableStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","fruit and vegetable","水果和蔬菜"},
        {"apple","苹果","a red apple","一个红苹果","redApple.gif","","","","redApplePra.png"},
        {"banana","香蕉","a yellow banana","一根黄色的香蕉","aBanana.gif","","","","aBananaPra.png"},
        {"carrot","胡萝卜","a carrot","一根胡萝卜","carrot.gif","","","","carrotPra.png"},
        {"eggplant","茄子","a purple eggplant","一个紫色的茄子","purpleEggplant.gif","","","","purpleEggplantPra.png"},
        {"grape","葡萄","purple grape","紫色的葡萄","purpleGrape.gif","","","","purpleGrapePra.png"},
        {"lemon","柠檬","a lemon","一个柠檬","lemon.gif","","","","lemonPra.png"},
        {"orange","橙子","an orange","一个橙子","orange.gif","","","","orangePra.png"},
        {"peach","桃子","a peach","一个桃子","peach.gif","","","","peachPra.png"},
        {"pear","梨子","a pear","一个梨子","pear.gif","","","","pearPra.png"},
        {"pineapple","菠萝","a pineapple","一个菠萝","pineapple.gif","","","","pineapplePra.png"},
        {"potato","土豆","a potato","一个土豆","potato.gif","","","","potatoPra.png"},
        {"strawberry","草莓","a strawberry","一颗草莓","strawberry.gif","","","","strawberryPra.png"},
        {"tomato","西红柿","a tomato","一个西红柿","tomato.gif","","","","tomatoPra.png"},
        {"watermelon","西瓜","a big watermelon","一个大西瓜","watermelon.gif","","","","watermelonPra.png"}
    };
}
void FruitAndVegetableStudy::runPage(MyLabel *label, bool isEnter)
{
    if(phrasePanel->isVisible())
        return;//如果短语面板正在显示，或者当前页面规定的单词已经学习完了，则不响应操作
    if(label)
        goto click;

    if(currentWord>=wordsNum)
        return;//如果当前页面规定的单词已经学习完了，则不响应除了显示短语以外的其他操作

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
            tmpLabel1->setGeometry(Tool::rect(560,140,140,150));
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
        //记录下上一个单词所涉及的图片的指针
        ptrPair *ptr=new ptrPair{tmpLabel1,tmpLabel2};
        learnedHistory->push(ptr);//入栈，记录
        tmpEnName=NULL;//将四个临时指针清零
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
