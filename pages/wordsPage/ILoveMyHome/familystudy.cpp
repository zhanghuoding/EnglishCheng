#include "familystudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

FamilyStudy::FamilyStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("FamilyStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("over");
    }

    picPath=picRoot+QString("/words/words/ILoveMyHome/scene/scene10/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(200,504));
    girlLabel->setGeometry(Tool::rect(80,320,200,504));

    labels->at(0)->setFixedSize(Tool::size(210,600));
    labels->at(0)->setGeometry(Tool::rect(460,100,210,600));

    labels->at(1)->setFixedSize(Tool::size(210,600));
    labels->at(1)->setGeometry(Tool::rect(280,200,210,600));

    labels->at(2)->setFixedSize(Tool::size(210,560));
    labels->at(2)->setGeometry(Tool::rect(560,240,210,560));

    labels->at(3)->setFixedSize(Tool::size(210,600));
    labels->at(3)->setGeometry(Tool::rect(760,200,210,600));

    labels->at(4)->setFixedSize(Tool::size(200,590));
    labels->at(4)->setGeometry(Tool::rect(1060,210,200,590));

    labels->at(5)->setFixedSize(Tool::size(200,580));
    labels->at(5)->setGeometry(Tool::rect(900,220,200,580));

    labels->at(6)->setFixedSize(Tool::size(400,480));
    labels->at(6)->setGeometry(Tool::rect(440,400,400,480));

    sentenceLabel->setText("family");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(1100,500,400,205);

    init();
}
FamilyStudy::~FamilyStudy()
{

}
void FamilyStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","a big family","一个大家庭"},
        {"uncle","叔叔","","","uncle.gif","uncleBorder.gif","","","uncle.gif"},
        {"father","爸爸","","","father.gif","fatherBorder.gif","","","father.gif"},
        {"mother","妈妈","","","mother.gif","motherBorder.gif","","","mother.gif"},
        {"brother","兄弟","","","brother.gif","brotherBorder.gif","","","brother.gif"},
        {"grandfather","爷爷","","","grandfather.gif","grandfatherBorder.gif","","","grandfather.gif"},
        {"grandmother","奶奶","","","grandmother.gif","grandmotherBorder.gif","","","grandmother.gif"},
        {"sister","姐妹","twin sisters","孪生姐妹","twins.gif","twinsBorder.gif","","","twins.gif"}
    };
}
