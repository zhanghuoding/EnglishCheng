#include "studystudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

StudyStudy::StudyStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("StudyStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("FamilyStudy");
    }

    picPath=picRoot+QString("/words/words/ILoveMyHome/scene/scene9/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setPixmap(QPixmap(picRoot+QString("/words/public/girlLeft.gif")));
    girlLabel->setFixedSize(Tool::size(180,404));
    girlLabel->setGeometry(Tool::rect(900,400,180,404));

    labels->at(0)->setFixedSize(Tool::size(500,370));
    labels->at(0)->setGeometry(Tool::rect(430,410,500,370));

    labels->at(1)->setFixedSize(Tool::size(80,100));
    labels->at(1)->setGeometry(Tool::rect(1170,540,80,100));

    labels->at(2)->setFixedSize(Tool::size(250,75));
    labels->at(2)->setGeometry(Tool::rect(442,430,250,75));

    labels->at(3)->setFixedSize(Tool::size(250,60));
    labels->at(3)->setGeometry(Tool::rect(445,520,250,60));

    labels->at(4)->setFixedSize(Tool::size(250,75));
    labels->at(4)->setGeometry(Tool::rect(443,592,250,75));

    labels->at(5)->setFixedSize(Tool::size(230,150));
    labels->at(5)->setGeometry(Tool::rect(283,752,230,150));

    labels->at(6)->setFixedSize(Tool::size(240,240));
    labels->at(6)->setGeometry(Tool::rect(209,615,240,240));

    labels->at(7)->setFixedSize(Tool::size(130,270));
    labels->at(7)->setGeometry(Tool::rect(289,610,130,270));

    labels->at(8)->setFixedSize(Tool::size(20,85));
    labels->at(8)->setGeometry(Tool::rect(388,770,20,85));

    labels->at(9)->setFixedSize(Tool::size(450,300));
    labels->at(9)->setGeometry(Tool::rect(535,70,450,300));

    sentenceLabel->setText("study");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));

    init();
}
StudyStudy::~StudyStudy()
{

}
void StudyStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","study","书房"},
        {"shelf","书架","","","shelf.gif","shelfBorder.gif","","","shelf.gif"},
        {"notebook","笔记本","a notebook","一本笔记本","notebook.gif","notebookBorder.gif","","","notebook.gif"},
        {"Chinese","语文","Chinese book","语文书","chinese.gif","chineseBorder.gif","","","chineseBook.gif"},
        {"math","数学","math book","数学书","math.gif","mathBorder.gif","","","mathBook.gif"},
        {"English","英语","English book","英语书","english.gif","englishBorder.gif","","","englishBook.gif"},
        {"picture","图画","draw a picture","画画","picture1.gif","pictureBorder.gif","","","picture2.gif"},
        {"child","孩子","a child","一个小孩","child.gif","childBorder.gif","","","child.gif"},
        {"music","音乐","listen to music","听音乐","walkman1.gif","walkmanBorder.gif","","","walkman1.gif"},
        {"crayon","蜡笔","a red crayon","一支红色的蜡笔","crayon.gif","crayonBorder.gif","","","redCrayon.gif"},
        {"map","地图","a map of China","一张中国地图","map.gif","mapBorder.gif","","","map.gif"}
    };
}
