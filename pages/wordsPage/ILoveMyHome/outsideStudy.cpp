#include "outsideStudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

OutsideStudy::OutsideStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("outsidestudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("HomeStudy");
    }

    picPath=picRoot+QString("/words/words/ILoveMyHome/scene/scene1/");

    background->setPixmap(QPixmap(picPath+QString("background.png")));

    labels->at(0)->setFixedSize(Tool::size(156,357));
    labels->at(0)->setGeometry(Tool::rect(200,370,100,310));
    labels->at(0)->setParent(NULL);
    labels->at(0)->setParent(this);

    labels->at(1)->setFixedSize(Tool::size(569,320));
    labels->at(1)->setGeometry(Tool::rect(290,205,569,320));

    labels->at(2)->setFixedSize(Tool::size(190,240));
    labels->at(2)->setGeometry(Tool::rect(153,197,190,240));

    labels->at(3)->setFixedSize(Tool::size(220,160));
    labels->at(3)->setGeometry(Tool::rect(657,167,220,160));

    labels->at(6)->setFixedSize(Tool::size(50,50));
    labels->at(6)->setGeometry(Tool::rect(630,218,50,50));

    labels->at(7)->setFixedSize(Tool::size(50,50));
    labels->at(7)->setGeometry(Tool::rect(910,100,50,50));

    labels->at(4)->setFixedSize(Tool::size(1600,159));
    labels->at(4)->setGeometry(Tool::rect(0,741,1600,159));

    labels->at(5)->setFixedSize(Tool::size(1600,159));
    labels->at(5)->setGeometry(Tool::rect(0,701,1600,159));

    sentenceLabel->setText("I love my home.");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));

    init();
}
OutsideStudy::~OutsideStudy()
{

}
void OutsideStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","I love my home.","我爱我家。"},
        {"girl","女孩","I am a girl.","我是女孩。","girl.gif","girlBorder.gif","","","girlPhrase.gif"},
        {"home","家","This is my home.","这是我的家。","home.gif","homeBorder.gif","","","home.gif"},
        {"tree","树","tow trees","两棵树","tree1.gif","tree1Border.gif","tree2.gif","tree2Border.gif","tree.gif","trees.gif"},
        {"grass","草","green grass","绿色的草","grass1.gif","grassBorder.gif","","","grass2.gif",""},
        {"flower","花","many flowers","许多花","flowers.gif","flowersBorder.gif","","","flower.gif",""},
        {"bird","鸟","two birds","两只小鸟","birds1.gif","birds1Border.gif","birds2.gif","birds2Border.gif","bird.gif",""},
        {"cloud","云"},
        {"sky","天空","blue sky","蓝天"}
    };
}

