#include "homestudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

HomeStudy::HomeStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("HomeStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("LivingRoomStudy");
    }

    picPath=picRoot+QString("/words/words/ILoveMyHome/scene/scene2/");

    background->setPixmap(QPixmap(picPath+QString("houseCloseDoor.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlLeft.gif")));
    girlLabel->setFixedSize(Tool::size(120,274));
    girlLabel->setGeometry(Tool::rect(1280,600,120,274));

    labels->at(0)->setFixedSize(Tool::size(130,250));
    labels->at(0)->setGeometry(Tool::rect(370,490,130,250));

    labels->at(1)->setFixedSize(Tool::size(230,250));
    labels->at(1)->setGeometry(Tool::rect(690,490,230,250));

    sentenceLabel->setText("home");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);

    init();
}
HomeStudy::~HomeStudy()
{

}
void HomeStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","home","家"},
        {"window","窗户","","","window1.gif","windowBorder1.gif","window2.gif","windowBorder2.gif"},
        {"door","门","open the door","开门"}
    };
}
