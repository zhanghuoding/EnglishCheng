#include "meadowstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

MeadowStudy::MeadowStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("MeadowStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("GrasslandStudy");
    }

    picPath=picRoot+QString("/words/words/HappyDay/scene/meadow/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlRight.gif")));
    girlLabel->setFixedSize(Tool::size(160,380));
    girlLabel->setGeometry(Tool::rect(120,410,160,380));

    labels->at(0)->setFixedSize(Tool::size(100,100));
    labels->at(0)->setGeometry(Tool::rect(310,590,100,100));

    labels->at(1)->setFixedSize(Tool::size(150,150));
    labels->at(1)->setGeometry(Tool::rect(634,450,150,150));

    labels->at(2)->setFixedSize(Tool::size(60,60));
    labels->at(2)->setGeometry(Tool::rect(775,550,60,60));

    labels->at(3)->setFixedSize(Tool::size(230,140));
    labels->at(3)->setGeometry(Tool::rect(1350,300,230,140));

    labels->at(4)->setFixedSize(Tool::size(160,120));
    labels->at(4)->setGeometry(Tool::rect(300,380,160,120));

    labels->at(5)->setFixedSize(Tool::size(120,90));
    labels->at(5)->setGeometry(Tool::rect(980,720,120,90));

    labels->at(6)->setFixedSize(Tool::size(120,120));
    labels->at(6)->setGeometry(Tool::rect(900,500,120,120));

    labels->at(7)->setFixedSize(Tool::size(200,110));
    labels->at(7)->setGeometry(Tool::rect(620,290,200,110));

    labels->at(8)->setFixedSize(Tool::size(200,110));
    labels->at(8)->setGeometry(Tool::rect(820,290,200,110));

    labels->at(9)->setFixedSize(Tool::size(180,110));
    labels->at(9)->setGeometry(Tool::rect(1100,320,180,110));

    labels->at(10)->setFixedSize(Tool::size(280,210));
    labels->at(10)->setGeometry(Tool::rect(1190,570,280,210));

    labels->at(11)->setFixedSize(Tool::size(140,90));
    labels->at(11)->setGeometry(Tool::rect(1128,760,140,90));

    sentenceLabel->setText("meadow");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(Tool::rect(200,100,400,205));

    init();
}
MeadowStudy::~MeadowStudy()
{

}
void MeadowStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","meadow","牧场"},
        {"cat","猫","a black cat","一只黑猫","blackCat.gif","blackCatBorder.gif","","","blackCatPra.png"},
        {"cock","公鸡","a cock","一只公鸡","cock.gif","cockBorder.gif","","","cockPra.png"},
        {"chick","小鸡","a chick","一只小鸡","chick.gif","chickBorder.gif","","","chickPra.png"},
        {"cow","奶牛","a cow","一头奶牛","cow.gif","cowBorder.gif","","","cowPra.png"},
        {"dog","狗","a dog","一只狗","dog.gif","dogBorder.gif","","","dogPra.png"},
        {"duck","鸭子","a duck","一只鸭子","duck.gif","duckBorder.gif","","","duckPra.png"},
        {"hen","母鸡","a hen","一只母鸡","hen.gif","henBorder.gif","","","henPra.png"},
        {"horse","马","a white horse","一匹白马","whiteHorse.gif","whiteHorseBorder.gif","blackHorse.gif","blackHorseBorder.gif","whiteHorsePra.png","blackHorsePra.png","a black horse","一匹黑马"},
        {"ox","公牛","an ox","一头公牛","ox.gif","oxBorder.gif","","","oxPra.png"},
        {"pig","猪","a pig","一头猪","pig.gif","pigBorder.gif","","","pigPra.png"},
        {"rabbit","兔子","a white rabbit","一只小白兔","rabbit.gif","rabbitBorder.gif","","","rabbitPra.png"}
    };
}
