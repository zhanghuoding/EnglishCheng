#include "intereststudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

InterestStudy::InterestStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("InterestStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("over");
    }

    picPath=picRoot+QString("/words/words/MySchool/scene/interest/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setVisible(false);

    labels->at(0)->setFixedSize(Tool::size(200,300));
    labels->at(0)->setGeometry(Tool::rect(580,200,200,300));

    labels->at(1)->setFixedSize(Tool::size(200,300));
    labels->at(1)->setGeometry(Tool::rect(844,200,200,300));

    labels->at(2)->setFixedSize(Tool::size(200,300));
    labels->at(2)->setGeometry(Tool::rect(956,190,200,300));

    labels->at(3)->setFixedSize(Tool::size(200,300));
    labels->at(3)->setGeometry(Tool::rect(1080,290,200,300));

    labels->at(4)->setFixedSize(Tool::size(270,300));
    labels->at(4)->setGeometry(Tool::rect(180,200,270,300));

    labels->at(5)->setFixedSize(Tool::size(270,300));
    labels->at(5)->setGeometry(Tool::rect(320,200,270,300));

    sentenceLabel->setText("I love sports.");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(1150,70,400,205);

    init();
}
InterestStudy::~InterestStudy()
{

}
void InterestStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","I love sports.","我爱运动。"},
        {"basketball","篮球","I like playing basketball","我喜欢打篮球","basketball.gif","basketballBorder.gif","","","basketballPra.png"},
        {"football","足球","I like playing football","我喜欢踢足球","football.gif","footballBorder.gif","","","footballPra.png"},
        {"table tennis","乒乓球","I like playing table tennis","我喜欢打乒乓球","tabletennis.gif","tabletennisBorder.gif","","","tabletennisPra.png"},
        {"high jump","跳高","I like high jump.","我喜欢跳高。","highjump.gif","highjumpBorder.gif","","","highjumpPra.png"},
        {"skate","滑冰","I like skating.","我喜欢滑冰。","skate.gif","skateBorder.gif","","","skatePra.png"},
        {"swim","游泳","I like swimming.","我喜欢游泳。","swim.gif","swim.gif","","","swimPra.png"}
    };
}
