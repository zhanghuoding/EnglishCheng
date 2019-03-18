#include "parkstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

ParkStudy::ParkStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("ParkStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("SeaStudy");
    }

    picPath=picRoot+QString("/words/words/HappyDay/scene/park/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlLeft.gif")));
    girlLabel->setFixedSize(Tool::size(130,330));
    girlLabel->setGeometry(Tool::rect(1250,480,130,330));

    labels->at(0)->setFixedSize(Tool::size(1600,470));
    labels->at(0)->setGeometry(Tool::rect(0,303,1600,470));

    labels->at(1)->setFixedSize(Tool::size(1600,300));
    labels->at(1)->setGeometry(Tool::rect(0,440,1600,300));

    labels->at(2)->setFixedSize(Tool::size(160,160));
    labels->at(2)->setGeometry(Tool::rect(410,485,160,160));

    labels->at(3)->setFixedSize(Tool::size(700,390));
    labels->at(3)->setGeometry(Tool::rect(900,30,700,390));

    labels->at(4)->setFixedSize(Tool::size(550,230));
    labels->at(4)->setGeometry(Tool::rect(1050,180,550,230));

    labels->at(5)->setFixedSize(Tool::size(150,110));
    labels->at(5)->setGeometry(Tool::rect(900,480,150,110));

    labels->at(6)->setFixedSize(Tool::size(120,65));
    labels->at(6)->setGeometry(Tool::rect(915,470,120,65));

    labels->at(7)->setFixedSize(Tool::size(200,180));
    labels->at(7)->setGeometry(Tool::rect(250,690,200,180));

    labels->at(8)->setFixedSize(Tool::size(390,460));
    labels->at(8)->setGeometry(Tool::rect(286,377,390,460));

    labels->at(9)->setFixedSize(Tool::size(60,100));
    labels->at(9)->setGeometry(Tool::rect(1027,410,60,100));

    sentenceLabel->setText("park");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(Tool::rect(150,110,400,205));

    init();
}
ParkStudy::~ParkStudy()
{

}
void ParkStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","park","公园"},
        {"plant","植物","many plants","许多植物","plant.gif","plantBorder.gif","","","plantPra.png"},
        {"lake","湖泊","","","lake.gif","lakeBorder.gif","","","lakePra.png"},
        {"bridge","桥","a small bridge","一座小桥","bridge.gif","bridgeBorder.gif","","","bridgePra.png"},
        {"hill","小山","two hills","两座小山","hill.gif","hillBorder.gif","","","hillPra.png"},
        {"rainbow","彩虹","a rainbow","一条彩虹","rainbow.gif","rainbowBorder.gif","","","rainbowPra.png"},
        {"boat","小船","a boat","一艘小船","boat.gif","boatBorder.gif","","","boatPra.png"},
        {"kid","小孩","cute kids","可爱的小孩","boatKid.gif","boatKidBorder.gif","kiteKid.gif","kiteKidBorder.gif","kidPra.png","kidPra.png","some kids","一些小孩"},
        {"kite","风筝","fly kites","放风筝","kite.gif","kiteBorder.gif","","","kitePra.png"},
        {"balloon","气球","a red balloon","一个红色的气球","balloon.gif","balloonBorder.gif","","","balloonPra.png"}
    };
}
