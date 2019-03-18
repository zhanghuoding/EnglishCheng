#include "clothingstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

ClothingStudy::ClothingStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("ClothingStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("FruitAndVegetableStudy");
    }

    picPath=picRoot+QString("/words/words/HappyDay/scene/clothesShop/");

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

    sentenceLabel->setText("clothes shop");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);

    init();
}
ClothingStudy::~ClothingStudy()
{

}
void ClothingStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","clothes shop","服装店"},
        {"dress","连衣裙","","","getUp.gif","getUpBorder.gif","","",""},
        {"put","放","put on clothes","穿上衣服","getUp.gif","getUpBorder.gif","","","getUp.gif"},
        {"brush","刷","brush teeth","刷牙","background2.jpg","background2.jpg","brush.gif","brushBorder.gif","brush.gif"},
        {"cook","煮","cook the meals","煮饭","background3.jpg","background3.jpg","cook.gif","cookBorder.gif","cookPra.png"},
        {"wash","洗涤","wash the clothes","洗衣服","wash.gif","washBorder.gif","","","washPra.png"},
        {"eat","吃","eat breakfast","吃早饭","eat.gif","eatBorder.gif","","","eatPra.png"},
        {"hamburger","汉堡","","","hanburger.gif","hanburgerBorder.gif","","","hanburgerPra.png"},
        {"hot dog","热狗","","","hotDog.gif","hotDogBorder.gif","","","hotDogPra.png"},
        {"jam","果酱","a glass of jam","一瓶果酱","jam.gif","jamBorder.gif","","","jamPra.png"},
        {"sandwich","三明治","a sandwich","一块三明治","sandwich.gif","sandwichBorder.gif","","","sandwichPra.png"}
    };
}
