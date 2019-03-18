#include "classroomstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

ClassroomStudy::ClassroomStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("ClassroomStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("DreamStudy");
    }

    picPath=picRoot+QString("/words/words/MySchool/scene/classroom/");

    background->setPixmap(QPixmap(picPath+QString("background1.jpg")));

    girlLabel->setVisible(false);

    labels->at(0)->setFixedSize(Tool::size(600,300));
    labels->at(0)->setGeometry(Tool::rect(640,50,800,300));

    labels->at(1)->setFixedSize(Tool::size(150,150));
    labels->at(1)->setGeometry(Tool::rect(1300,20,150,150));

    labels->at(2)->setFixedSize(Tool::size(100,250));
    labels->at(2)->setGeometry(Tool::rect(550,320,100,250));

    labels->at(3)->setFixedSize(Tool::size(100,250));
    labels->at(3)->setGeometry(Tool::rect(650,320,100,250));

    labels->at(4)->setFixedSize(Tool::size(170,280));
    labels->at(4)->setGeometry(Tool::rect(840,82,170,280));

    labels->at(5)->setFixedSize(Tool::size(1600,900));
    labels->at(5)->setGeometry(Tool::rect(0,0,1600,900));

    labels->at(6)->setFixedSize(Tool::size(900,750));
    labels->at(6)->setGeometry(Tool::rect(350,100,900,750));

    labels->at(7)->setFixedSize(Tool::size(400,550));
    labels->at(7)->setGeometry(Tool::rect(550,280,400,550));

    labels->at(8)->setFixedSize(Tool::size(200,200));
    labels->at(8)->setGeometry(Tool::rect(1010,120,200,200));

    labels->at(9)->setFixedSize(Tool::size(200,180));
    labels->at(9)->setGeometry(Tool::rect(710,30,200,180));

    labels->at(10)->setFixedSize(Tool::size(80,60));
    labels->at(10)->setGeometry(Tool::rect(540,120,80,60));

    labels->at(11)->setFixedSize(Tool::size(40,120));
    labels->at(11)->setGeometry(Tool::rect(520,200,40,120));

    labels->at(12)->setFixedSize(Tool::size(40,120));
    labels->at(12)->setGeometry(Tool::rect(560,200,40,120));

    labels->at(13)->setFixedSize(Tool::size(90,120));
    labels->at(13)->setGeometry(Tool::rect(450,200,90,120));

    labels->at(14)->setFixedSize(Tool::size(90,90));
    labels->at(14)->setGeometry(Tool::rect(650,180,90,90));

    sentenceLabel->setText("classroom");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);

    init();
}
ClassroomStudy::~ClassroomStudy()
{

}
void ClassroomStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","classroom","教室"},
        {"blackboard","黑板","blackboard eraser","黑板擦","blackboard.gif","blackboardBorder.gif","","","blackboarderaserPra.png"},
        {"clock","挂钟","a clock","一个挂钟","clock.gif","clockBorder.gif","","","clockPra.png"},
        {"student","学生","two students","两个学生","student1.gif","student1Border.gif","student2.gif","student2Border.gif","twostudentsPra.png"},
        {"teacher","教师","a strict teacher","一位严格的老师","teacher.gif","teacherBorder.gif","","","teacherPra.png"},
        {"desk","课桌","a desk","一张课桌","background2 .jpg","background2 .jpg","desk.gif","deskBorder.gif","deskPra.png"},
        {"chair","椅子","a chair","一把椅子","chair.gif","chairBorder.gif","","","chairPra.png"},
        {"bag","书包","a red bag","一个红色的书包","bag.gif","bagBorder.gif","","","bagPra.png"},
        {"book","书","four books","四本书","book.gif","bookBorder.gif","","","bookPra.png"},
        {"eraser","橡皮檫","an eraser","一块橡皮擦","eraser.gif","eraserBorder.gif","","","eraserPra.png"},
        {"pencil","铅笔","a pencil","一支铅笔","pencil.gif","pencilBorder.gif","","","pencilPra.png"},
        {"pen","钢笔","a pen","一支钢笔","pen.gif","penBorder.gif","","","penPra.png"},
        {"ruler","尺子","a ruler","一把尺子","ruler.gif","rulerBorder.gif","","","rulerPra.png"},
        {"sharpener","卷笔刀","a sharpener","一个卷笔刀","sharpener.gif","sharpenerBorder.gif","","","sharpenerPra.png"}
    };
}
