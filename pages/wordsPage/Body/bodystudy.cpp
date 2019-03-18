#include "bodystudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

BodyStudy::BodyStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("BodyStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("over");
    }

    picPath=picRoot+QString("/words/words/Body/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setVisible(false);

    labels->at(0)->setFixedSize(Tool::size(180,160));
    labels->at(0)->setGeometry(Tool::rect(630,390,180,160));

    labels->at(1)->setFixedSize(Tool::size(120,120));
    labels->at(1)->setGeometry(Tool::rect(734,480,120,120));

    labels->at(2)->setFixedSize(Tool::size(170,170));
    labels->at(2)->setGeometry(Tool::rect(840,430,170,170));

    labels->at(3)->setFixedSize(Tool::size(180,180));
    labels->at(3)->setGeometry(Tool::rect(430,400,180,180));

    sentenceLabel->setText("My Body");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);

    init();
}
BodyStudy::~BodyStudy()
{

}
void BodyStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","My Body","我的身体"},
        {"body","身体","","","getUp.gif","getUpBorder.gif","","",""},
        {"arm","手臂","put on clothes","穿上衣服","getUp.gif","getUpBorder.gif","","","getUp.gif"},
        {"ear","耳朵","brush teeth","刷牙","background2.jpg","background2.jpg","brush.gif","brushBorder.gif","brush.gif"},
        {"eye","眼睛","cook the meals","煮饭","background3.jpg","background3.jpg","cook.gif","cookBorder.gif","cookPra.png"},
        {"face","脸","wash the clothes","洗衣服","wash.gif","washBorder.gif","","","washPra.png"},
        {"finger","手指","eat breakfast","吃早饭","eat.gif","eatBorder.gif","","","eatPra.png"},
        {"foot","脚","","","hanburger.gif","hanburgerBorder.gif","","","hanburgerPra.png"},
        {"hand","手","","","hotDog.gif","hotDogBorder.gif","","","hotDogPra.png"},
        {"hair","头发","black hair","黑发","jam.gif","jamBorder.gif","","","jamPra.png","","brown hair","棕色的头发"},
        {"head","头","a sandwich","一块三明治","sandwich.gif","sandwichBorder.gif","","","sandwichPra.png"},
        {"leg","腿","","","hotDog.gif","hotDogBorder.gif","","","hotDogPra.png"},
        {"mouth","嘴","black hair","黑发","jam.gif","jamBorder.gif","","","jamPra.png","","brown hair","棕色的头发"},
        {"nose","鼻子","a sandwich","一块三明治","sandwich.gif","sandwichBorder.gif","","","sandwichPra.png"}
    };
}
