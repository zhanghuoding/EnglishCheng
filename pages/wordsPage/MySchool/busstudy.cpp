#include "busstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

BusStudy::BusStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("BusStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("SchoolStudy");
    }

    picPath=picRoot+QString("/words/words/MySchool/scene/bus/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setVisible(false);

    labels->at(0)->setFixedSize(Tool::size(230,250));
    labels->at(0)->setGeometry(Tool::rect(420,440,230,250));

    labels->at(1)->setFixedSize(Tool::size(240,520));
    labels->at(1)->setGeometry(Tool::rect(634,370,240,520));

    labels->at(2)->setFixedSize(Tool::size(240,520));
    labels->at(2)->setGeometry(Tool::rect(920,370,240,520));

    sentenceLabel->setText("go to school");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);

    init();
}
BusStudy::~BusStudy()
{

}
void BusStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","go to school","去上学"},
        {"schoolbag","书包","a black schoolbag","一个黑色的书包","bag1.gif","bagBorder.gif","","","bag1.gif"},
        {"meet","相遇","","","kid1.gif","kid1Border.gif","kid2.gif","kid2Border.gif"},
        {"take","拿","take a bus","乘公共汽车"}
    };
}
