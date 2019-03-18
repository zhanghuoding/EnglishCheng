#include "foreststudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

ForestStudy::ForestStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("ForestStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("RestaurantStudy");
    }

    picPath=picRoot+QString("/words/words/HappyDay/scene/forest/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(130,330));
    girlLabel->setGeometry(Tool::rect(420,480,130,330));

    labels->at(0)->setFixedSize(Tool::size(100,120));
    labels->at(0)->setGeometry(Tool::rect(30,740,100,120));

    labels->at(1)->setFixedSize(Tool::size(170,170));
    labels->at(1)->setGeometry(Tool::rect(180,285,170,170));

    labels->at(2)->setFixedSize(Tool::size(100,150));
    labels->at(2)->setGeometry(Tool::rect(1420,510,100,150));

    labels->at(3)->setFixedSize(Tool::size(100,150));
    labels->at(3)->setGeometry(Tool::rect(1320,560,100,150));

    labels->at(4)->setFixedSize(Tool::size(100,100));
    labels->at(4)->setGeometry(Tool::rect(475,275,100,100));

    labels->at(5)->setFixedSize(Tool::size(200,95));
    labels->at(5)->setGeometry(Tool::rect(1380,670,200,95));

    labels->at(6)->setFixedSize(Tool::size(250,250));
    labels->at(6)->setGeometry(Tool::rect(70,510,250,250));

    labels->at(7)->setFixedSize(Tool::size(200,250));
    labels->at(7)->setGeometry(Tool::rect(1060,460,200,250));

    labels->at(8)->setFixedSize(Tool::size(310,210));
    labels->at(8)->setGeometry(Tool::rect(490,465,310,210));

    labels->at(9)->setFixedSize(Tool::size(200,200));
    labels->at(9)->setGeometry(Tool::rect(620,550,200,200));

    labels->at(10)->setFixedSize(Tool::size(200,200));
    labels->at(10)->setGeometry(Tool::rect(900,510,200,200));

    sentenceLabel->setText("forest");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(Tool::rect(1100,80,400,205));

    init();
}
ForestStudy::~ForestStudy()
{

}
void ForestStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","forest","森林"},
        {"bird","鸟","two little black birds","两只小黑鸟","birds.gif","birdsBorder.gif","","","birdsPra.png"},
        {"monkey","猴子","three little monkeys","三只小猴","monkey.gif","monkeyBorder.gif","","","monkeyPra.png"},
        {"snake","蛇","a green snake","一条青蛇","greenSnake.gif","greenSnakeBorder.gif","blackSnake.gif","blackSnakeBorder.gif","greenSnakePra.png","blackSnakePra.png","a black snake","一条黑蛇"},
        {"squirrel","松鼠","a squirrel","一只松鼠","squirrel.gif","squirrelBorder.gif","threeSquirrels.gif","threeSquirrelsBorder.gif","squirrelPra.png","threeSquirrelsPra.png","three little squirrels","三只小松鼠"},
        {"tiger","老虎","a tiger","一头老虎","tiger.gif","tigerBorder.gif","","","tigerPra.png"},
        {"panda","熊猫","a panda","一只熊猫","panda.gif","pandaBorder.gif","","","pandaPra.png"},
        {"zebra","斑马","a zebra","一匹斑马","zebra.gif","zebraBorder.gif","","","zebraPra.png"},
        {"fox","狐狸","a white fox","一只白狐","whiteFox.gif","whiteFoxBorder.gif","redFox.gif","redFoxBorder.gif","whiteFoxPra.png","redFoxPra.png","a red fox","一只赤狐"}
    };
}
