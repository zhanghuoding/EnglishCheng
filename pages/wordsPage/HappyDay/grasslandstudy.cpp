#include "grasslandstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

GrasslandStudy::GrasslandStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("GrasslandStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("ForestStudy");
    }

    picPath=picRoot+QString("/words/words/HappyDay/scene/grassland/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));
    background->setFixedSize(3200,900);
    background->setGeometry(Tool::rect(0,0,3200,900));

    girlLabel->setVisible(false);

    labels->at(0)->setFixedSize(Tool::size(180,160));
    labels->at(0)->setGeometry(Tool::rect(630,390,180,160));

    labels->at(1)->setFixedSize(Tool::size(120,120));
    labels->at(1)->setGeometry(Tool::rect(734,480,120,120));

    labels->at(2)->setFixedSize(Tool::size(170,170));
    labels->at(2)->setGeometry(Tool::rect(840,430,170,170));

    labels->at(3)->setFixedSize(Tool::size(180,180));
    labels->at(3)->setGeometry(Tool::rect(430,400,180,180));

    sentenceLabel->setText("grassland");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);

    init();
}
GrasslandStudy::~GrasslandStudy()
{

}
void GrasslandStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","grassland","草原"},
        {"deer","鹿","a deer","一只鹿","deer.gif","deerBorder.gif","","","deerPra.png"},
        {"zebra","斑马","a zebra","一只斑马","zebra.gif","zebraBorder.gif","","","zebraPra.png"},
        {"elephant","大象","a gray elephant","一头灰象","elephant.gif","elephantBorder.gif","","","elephantPra.png"},
        {"giraffe","长颈鹿","a giraffe","一头长颈鹿","giraffe.gif","giraffeBorder.gif","","","giraffePra.png"},
        {"fox","狐狸","a red fox","一只赤狐","fox.gif","foxBorder.gif","","","foxPra.png"},
        {"kangaroo","袋鼠","a kangaroo","一只袋鼠","kangaroo.gif","kangarooBorder.gif","","","kangarooPra.png"},
        {"lion","狮子","a lion","一头狮子","lion.gif","lionBorder.gif","","","lionPra.png"}
    };
}
