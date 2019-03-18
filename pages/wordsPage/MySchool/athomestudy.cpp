#include "athomestudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

AtHomeStudy::AtHomeStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("AtHomeStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("BusStudy");
    }

    picPath=picRoot+QString("/words/words/MySchool/scene/home/");

    background->setPixmap(QPixmap(picPath+QString("background1.jpg")));

    girlLabel->setVisible(false);

    labels->at(0)->setFixedSize(Tool::size(350,350));
    labels->at(0)->setGeometry(Tool::rect(570,340,350,350));

    labels->at(1)->setFixedSize(Tool::size(350,350));
    labels->at(1)->setGeometry(Tool::rect(570,340,350,350));

    labels->at(2)->setFixedSize(Tool::size(1600,900));
    labels->at(2)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(3)->setFixedSize(Tool::size(290,580));
    labels->at(3)->setGeometry(Tool::rect(900,200,290,580));

    labels->at(4)->setFixedSize(Tool::size(1600,900));
    labels->at(4)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(5)->setFixedSize(Tool::size(290,680));
    labels->at(5)->setGeometry(Tool::rect(1180,200,290,680));

    labels->at(6)->setFixedSize(Tool::size(350,380));
    labels->at(6)->setGeometry(Tool::rect(600,400,350,380));

    labels->at(7)->setFixedSize(Tool::size(140,195));
    labels->at(7)->setGeometry(Tool::rect(105,425,140,195));

    labels->at(8)->setFixedSize(Tool::size(100,80));
    labels->at(8)->setGeometry(Tool::rect(125,655,100,80));

    labels->at(9)->setFixedSize(Tool::size(110,80));
    labels->at(9)->setGeometry(Tool::rect(10,535,110,80));

    labels->at(10)->setFixedSize(Tool::size(70,80));
    labels->at(10)->setGeometry(Tool::rect(52,595,70,80));

    labels->at(11)->setFixedSize(Tool::size(100,80));
    labels->at(11)->setGeometry(Tool::rect(0,665,100,80));

    sentenceLabel->setText("home");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(Tool::rect(400,100,400,205));

    init();
}
AtHomeStudy::~AtHomeStudy()
{

}
void AtHomeStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","home","家"},
        {"get up","起床","","","getUp.gif","getUpBorder.gif","","",""},
        {"put","放","put on clothes","穿上衣服","getUp.gif","getUp.gif","","","getUp.gif"},
        {"brush","刷","brush teeth","刷牙","background2.jpg","background2.jpg","brush.gif","brushBorder.gif","brushPra.png"},
        {"cook","煮","cook the meals","煮饭","background3.jpg","background3.jpg","cook.gif","cookBorder.gif","cookPra.png"},
        {"wash","洗涤","wash the clothes","洗衣服","wash.gif","washBorder.gif","","","washPra.png"},
        {"eat","吃","eat breakfast","吃早饭","eat.gif","eatBorder.gif","","","eatPra.png"},
        {"hamburger","汉堡","","","hamburger.gif","hamburgerBorder.gif","","","hamburgerPra.png"},
        {"hot dog","热狗","","","hotDog.gif","hotDogBorder.gif","","","hotDogPra.png"},
        {"jam","果酱","a glass of jam","一瓶果酱","jam.gif","jamBorder.gif","","","jamPra.png"},
        {"sandwich","三明治","a sandwich","一块三明治","sandwich.gif","sandwichBorder.gif","","","sandwichPra.png"}
    };
}
