#include "bedroomstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

BedroomStudy::BedroomStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("BedroomStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("StudyStudy");
    }

    picPath=picRoot+QString("/words/words/ILoveMyHome/scene/scene8/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(230,490));
    girlLabel->setGeometry(Tool::rect(260,360,230,490));

    labels->at(0)->setFixedSize(Tool::size(180,180));
    labels->at(0)->setGeometry(Tool::rect(147,310,180,180));

    labels->at(1)->setFixedSize(Tool::size(180,120));
    labels->at(1)->setGeometry(Tool::rect(600,445,180,120));

    labels->at(2)->setFixedSize(Tool::size(120,200));
    labels->at(2)->setGeometry(Tool::rect(1234,275,120,200));

    sentenceLabel->setText("bedroom");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(Tool::rect(820,150,400,205));

    init();
}
BedroomStudy::~BedroomStudy()
{

}
void BedroomStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","bedroom","卧室"},
        {"bed","床","bed table","床头柜","","","","",""},
        {"computer","电脑","a computer","一台电脑","computer.gif","computerBorder.gif","","","computer.gif"},
        {"doll","玩具娃娃","","","doll.gif","dollBorder.gif","","","doll.gif"},
        {"lamp","台灯","a lamp","一个台灯","lamp.gif","lampBorder.gif","","","lamp.gif"}
    };
}
