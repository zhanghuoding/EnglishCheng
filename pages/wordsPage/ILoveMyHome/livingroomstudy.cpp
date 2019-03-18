#include "livingroomstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

LivingRoomStudy::LivingRoomStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("LivingRoomStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("KitchenStudy");
    }

    picPath=picRoot+QString("/words/words/ILoveMyHome/scene/scene3/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(120,274));
    girlLabel->setGeometry(Tool::rect(200,510,120,274));

    labels->at(0)->setFixedSize(Tool::size(1600,900));
    labels->at(0)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(1)->setFixedSize(Tool::size(1600,900));
    labels->at(1)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(2)->setFixedSize(Tool::size(1600,900));
    labels->at(2)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(3)->setFixedSize(Tool::size(1600,900));
    labels->at(3)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(4)->setFixedSize(Tool::size(1600,900));
    labels->at(4)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(5)->setFixedSize(Tool::size(1600,900));
    labels->at(5)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(6)->setFixedSize(Tool::size(1600,900));
    labels->at(6)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(7)->setFixedSize(Tool::size(1600,900));
    labels->at(7)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(8)->setFixedSize(Tool::size(250,250));
    labels->at(8)->setGeometry(Tool::rect(890,420,250,250));

    labels->at(9)->setFixedSize(Tool::size(200,200));
    labels->at(9)->setGeometry(Tool::rect(1350,700,200,200));

    labels->at(10)->setFixedSize(Tool::size(400,300));
    labels->at(10)->setGeometry(Tool::rect(300,450,400,300));

    labels->at(11)->setFixedSize(Tool::size(150,150));
    labels->at(11)->setGeometry(Tool::rect(50,700,150,150));    

    labels->at(12)->setFixedSize(Tool::size(280,160));
    labels->at(12)->setGeometry(Tool::rect(740,610,280,160));

    labels->at(13)->setFixedSize(Tool::size(250,250));
    labels->at(13)->setGeometry(Tool::rect(1100,560,250,250));

    sentenceLabel->setText("living room");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);

    init();
}
LivingRoomStudy::~LivingRoomStudy()
{

}
void LivingRoomStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","living room","卧室"},
        {"wall","墙壁","","","background.jpg","background.jpg"},
        {"purple","紫色","purple wall","紫色的墙","purple.jpg","purple.jpg","","","purpleWall.gif"},
        {"white","白色","white wall","白色的墙","white.jpg","white.jpg","","","whiteWall.gif"},
        {"green","绿色","green wall","绿色的墙","green.jpg","green.jpg","","","greenWall.gif"},
        {"gray","灰色","gray wall","灰色的墙","gray.jpg","gray.jpg","","","greyWall.gif"},
        {"blue","蓝色","blue wall","蓝色的墙","blue.jpg","blue.jpg","","","blueWall.gif"},
        {"yellow","黄色","yellow wall","黄色的墙","yellow.jpg","yellow.jpg","","","yellowWall.gif"},
        {"pink","粉色","pink wall","粉色的墙","pink.jpg","pink.jpg","","","pinkWall.gif"},
        {"sofa","沙发","","","sofa.gif","sofaBorder.gif","","","sofa.gif"},
        {"phone","电话","a phone","一台电话","phone.gif","phoneBorder.gif","","","phone.gif"},
        {"TV","电视","","","TV.gif","TVBorder.gif","","","TV.gif"},
        {"fan","电扇","two fans","两台风扇","fan.gif","fanBorder.gif","","","fans.gif"},
        {"table","桌子","a table","一张桌子","teaTable.gif","teaTableBorder.gif","","","teaTable.gif"},
        {"chair","椅子","a chair","一把椅子","Chair.gif","ChairBorder.gif","","","Chair.gif"}
    };
}
