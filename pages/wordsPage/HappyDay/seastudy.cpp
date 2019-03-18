#include "seastudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

SeaStudy::SeaStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("SeaStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("ClothingStudy");
    }

    picPath=picRoot+QString("/words/words/HappyDay/scene/sea/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(130,330));
    girlLabel->setGeometry(Tool::rect(250,180,130,330));

    labels->at(0)->setFixedSize(Tool::size(280,220));
    labels->at(0)->setGeometry(Tool::rect(350,480,280,220));

    labels->at(1)->setFixedSize(Tool::size(110,200));
    labels->at(1)->setGeometry(Tool::rect(1404,230,110,200));

    labels->at(2)->setFixedSize(Tool::size(280,220));
    labels->at(2)->setGeometry(Tool::rect(350,480,280,220));

    labels->at(3)->setFixedSize(Tool::size(120,300));
    labels->at(3)->setGeometry(Tool::rect(90,460,120,300));

    labels->at(4)->setFixedSize(Tool::size(100,200));
    labels->at(4)->setGeometry(Tool::rect(1470,530,100,200));

    labels->at(5)->setFixedSize(Tool::size(100,200));
    labels->at(5)->setGeometry(Tool::rect(1470,530,100,200));

    labels->at(6)->setFixedSize(Tool::size(700,450));
    labels->at(6)->setGeometry(Tool::rect(870,450,700,450));

    labels->at(7)->setFixedSize(Tool::size(150,400));
    labels->at(7)->setGeometry(Tool::rect(670,230,150,400));

    labels->at(8)->setFixedSize(Tool::size(700,450));
    labels->at(8)->setGeometry(Tool::rect(870,450,700,450));

    sentenceLabel->setText("sea");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(Tool::rect(960,90,400,205));

    init();
}
SeaStudy::~SeaStudy()
{

}
void SeaStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","sea","海"},
        {"collect","收集","collect  shells","捡贝壳","collect.gif","collectBorder.gif","","","collectPra.png"},
        {"swim","游泳","go swimming","去游泳","swim.gif","swimBorder.gif","","","swimPra.png"},
        {"talk","谈话","have a talk","谈话","collect.gif","collectBorder.gif","","","collectPra.png"},
        {"walk","走","take a walk","散步","oldWoman.gif","oldWomanBorder.gif","","","oldWomanPra.png"},
        {"Cola","可乐","Coca-Cola","可口可乐","drinkCola.gif","drinkColaBorder.gif","","","drinkColaPra.png"},
        {"drink","喝","drink cola","喝可乐","drinkCola.gif","drinkColaBorder.gif","","","drinkColaPra.png"},
        {"woman","女人","an old woman","一个老婆婆","woman.gif","womanBorder.gif","","","oldWomanPra.png"},
        {"man","男人","a tall man","一个高大的男子","man.gif","manBorder.gif","","","manPra.png"},
        {"sleep","睡","","","woman.gif","womanBorder.gif","","","womanPra.png"}
    };
}
