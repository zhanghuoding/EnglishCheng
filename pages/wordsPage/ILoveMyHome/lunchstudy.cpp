#include "lunchstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

LunchStudy::LunchStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("LunchStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("DinnerStudy");
    }

    picPath=picRoot+QString("/words/words/ILoveMyHome/scene/scene6/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(170,390));
    girlLabel->setGeometry(Tool::rect(280,200,170,390));

    labels->at(0)->setFixedSize(Tool::size(70,70));
    labels->at(0)->setGeometry(Tool::rect(600,440,70,70));

    labels->at(1)->setFixedSize(Tool::size(90,90));
    labels->at(1)->setGeometry(Tool::rect(500,510,90,90));

    labels->at(2)->setFixedSize(Tool::size(100,90));
    labels->at(2)->setGeometry(Tool::rect(1020,450,100,90));

    labels->at(3)->setFixedSize(Tool::size(160,100));
    labels->at(3)->setGeometry(Tool::rect(880,480,160,100));

    labels->at(4)->setFixedSize(Tool::size(208,160));
    labels->at(4)->setGeometry(Tool::rect(675,420,208,160));

    sentenceLabel->setText("lunch");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);

    init();
}
LunchStudy::~LunchStudy()
{

}
void LunchStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","lunch","午餐"},
        {"tea","茶","a cup of tea","一杯茶","tea.gif","teaBorder.gif","","","tea.gif"},
        {"rice","米饭","a bowl of rice","一碗米饭","rice.gif","riceBorder.gif","","","rice.gif"},
        {"salad","色拉","vegetable salad","蔬菜沙拉","salad.gif","saladBorder.gif","","","salad.gif"},
        {"beef","牛肉","fresh beef","新鲜的牛肉","beef.gif","beefBorder.gif","","","beef.gif"},
        {"chicken","鸡肉","","","chicken.gif","chickenBorder.gif","","","chicken.gif"}
    };
}
