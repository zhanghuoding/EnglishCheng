#include "dinnerstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

DinnerStudy::DinnerStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("DinnerStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("BedroomStudy");
    }

    picPath=picRoot+QString("/words/words/ILoveMyHome/scene/scene7/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(170,390));
    girlLabel->setGeometry(Tool::rect(280,200,170,390));

    labels->at(0)->setFixedSize(Tool::size(90,90));
    labels->at(0)->setGeometry(Tool::rect(500,510,90,90));

    labels->at(1)->setFixedSize(Tool::size(200,140));
    labels->at(1)->setGeometry(Tool::rect(630,440,200,140));

    labels->at(2)->setFixedSize(Tool::size(180,110));
    labels->at(2)->setGeometry(Tool::rect(830,470,180,110));

    labels->at(3)->setFixedSize(Tool::size(90,140));
    labels->at(3)->setGeometry(Tool::rect(810,330,90,140));

    labels->at(4)->setFixedSize(Tool::size(100,90));
    labels->at(4)->setGeometry(Tool::rect(1020,460,100,90));

    sentenceLabel->setText("dinner");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);

    init();
}
DinnerStudy::~DinnerStudy()
{

}
void DinnerStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","dinner","晚餐"},
        {"rice","米饭","a bowl of rice","一碗米饭","rice.gif","riceBorder.gif","","","rice.gif"},
        {"fish","鱼","delicious fish","美味的鱼","fish.gif","fishBorder.gif","","","fish.gif"},
        {"meat","猪肉","","","meat.gif","meatBorder.gif","","","meat.gif"},
        {"drink","饮料","a glass of drink","一杯饮料","drink.gif","drinkBorder.gif","","","drink.gif"},
        {"salad","色拉","a salad","一份沙拉","salad.gif","saladBorder.gif","","","salad.gif"}
    };
}
