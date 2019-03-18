#include "schoolstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

SchoolStudy::SchoolStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("SchoolStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("ClassroomStudy");
    }

    picPath=picRoot+QString("/words/words/MySchool/scene/school/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setVisible(false);

    labels->at(0)->setFixedSize(Tool::size(1600,900));
    labels->at(0)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(1)->setFixedSize(Tool::size(180,360));
    labels->at(1)->setGeometry(Tool::rect(1270,460,180,360));

    labels->at(2)->setFixedSize(Tool::size(150,270));
    labels->at(2)->setGeometry(Tool::rect(730,240,150,270));

    labels->at(3)->setFixedSize(Tool::size(150,270));
    labels->at(3)->setGeometry(Tool::rect(40,240,150,270));

    labels->at(4)->setFixedSize(Tool::size(270,270));
    labels->at(4)->setGeometry(Tool::rect(1330,70,270,270));

    labels->at(5)->setFixedSize(Tool::size(340,340));
    labels->at(5)->setGeometry(Tool::rect(1260,70,340,340));

    sentenceLabel->setText("school");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(Tool::rect(300,100,400,205));

    init();
}
SchoolStudy::~SchoolStudy()
{

}
void SchoolStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","school","学校"},
        {"school","学校","This is my school.","这是我的学校。","background.jpg","background.jpg","","","background.jpg"},
        {"play","玩","play sports","进行体育运动","playSports.gif","playSportsBorder.gif","","","playPra.png"},
        {"run","跑","","","run.gif","runBorder.gif","","",""},
        {"wave","(挥手)示意","wave the hand","挥手","wave.gif","waveBorder.gif"},
        {"supermarket","超市","","","supermarket.gif","supermarketBorder.gif","","",""},
        {"go to the supermarket","去超市","","","GTTSupermarket.gif","GTTSupermarketBorder.gif","","",""}
    };
}
