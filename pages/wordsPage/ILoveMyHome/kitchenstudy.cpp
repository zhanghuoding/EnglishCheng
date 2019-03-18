#include "kitchenstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

KitchenStudy::KitchenStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("KitchenStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("BreakfastStudy");
    }

    picPath=picRoot+QString("/words/words/ILoveMyHome/scene/scene4/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(170,390));
    girlLabel->setGeometry(Tool::rect(590,280,170,390));

    labels->at(0)->setFixedSize(Tool::size(95,180));
    labels->at(0)->setGeometry(Tool::rect(108,550,95,180));

    labels->at(1)->setFixedSize(Tool::size(85,100));
    labels->at(1)->setGeometry(Tool::rect(217,540,85,100));

    labels->at(2)->setFixedSize(Tool::size(50,160));
    labels->at(2)->setGeometry(Tool::rect(1340,360,50,160));

    labels->at(3)->setFixedSize(Tool::size(50,160));
    labels->at(3)->setGeometry(Tool::rect(1250,348,50,160));

    labels->at(4)->setFixedSize(Tool::size(140,150));
    labels->at(4)->setGeometry(Tool::rect(1310,550,140,150));

    labels->at(5)->setFixedSize(Tool::size(95,145));
    labels->at(5)->setGeometry(Tool::rect(1195,478,95,145));

    sentenceLabel->setText("kitchen");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(810,180,400,205);

    init();
}
KitchenStudy::~KitchenStudy()
{

}
void KitchenStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","kitchen","厨房"},
        {"glass","玻璃杯","a glass","一个玻璃杯","glassCup.gif","glassCupBorder.gif","","","glassCup.gif"},
        {"cup","杯子","a cup","一个杯子","cup.gif","cupBorder.gif","","","cup.gif"},
        {"fork","叉子","a fork","一把叉子","fork.gif","forkBorder.gif","","","fork.gif"},
        {"spoon","勺子","a spoon","一把勺子","spoon.gif","spoonBorder.gif","","","spoon.gif"},
        {"chopsticks","筷子","","","chopsticks.gif","chopsticksBorder.gif","","","chopsticks.gif"},
        {"bowl","碗","three bowls","三个碗","bowl.gif","bowlBorder.gif","","","bowl.gif"}
    };
}
