#include "breakfaststudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

BreakfastStudy::BreakfastStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("BreakfastStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("LunchStudy");
    }

    picPath=picRoot+QString("/words/words/ILoveMyHome/scene/scene5/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(170,390));
    girlLabel->setGeometry(Tool::rect(280,200,170,390));

    labels->at(0)->setFixedSize(Tool::size(180,160));
    labels->at(0)->setGeometry(Tool::rect(630,390,180,160));

    labels->at(1)->setFixedSize(Tool::size(120,120));
    labels->at(1)->setGeometry(Tool::rect(734,480,120,120));

    labels->at(2)->setFixedSize(Tool::size(170,170));
    labels->at(2)->setGeometry(Tool::rect(840,430,170,170));

    labels->at(3)->setFixedSize(Tool::size(180,180));
    labels->at(3)->setGeometry(Tool::rect(430,400,180,180));

    sentenceLabel->setText("breakfast");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);

    init();
}
BreakfastStudy::~BreakfastStudy()
{

}
void BreakfastStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","breakfast","早餐,早饭"},
        {"bread","面包","","","bread.gif","breadBorder.gif","","","bread.gif"},
        {"egg","鸡蛋","two eggs","两个鸡蛋","egg.gif","eggBorder.gif","","","egg.gif"},
        {"apple","苹果","a big apple","一个大苹果","apple.gif","appleBorder.gif","","","apple.gif"},
        {"milk","牛奶","a glass of milk","一杯牛奶","milk.gif","milkBorder.gif","","","milk.gif"}
    };
}
