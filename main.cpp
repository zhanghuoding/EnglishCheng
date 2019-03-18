#include "mainwindow.h"
#include "Singleton/singleton.h"
#include "customClass/quitbutton.h"
#include "customClass/tool.h"
#include "via.h"
#include "customClass/read.h"
#include "customClass/paper.h"
#include "customClass/recorder.h"

#include <QApplication>
#include <QSize>
#include <QDesktopWidget>
#include <QString>
#include <QTextCodec>
#include <cmath>
#include <QDebug>


QSize *screenSize;
QString picRoot;
QSize *keyBoardMaxSize;
QSize *keyBoardMinSize;
QSize *keysAreaSize;
QSize *editBoxSize;
QString audioPath;
QString audioSuffix(".mp3");
Read *reader;
Paper *paper;
QString *punctuation;
short labelNumInStudyPage=24;

short phrasePanelFontSize=48;
short paperFontSize=44;
short wordsCardFontSize=48;
short sentenceLabelFontSize=48;
short keyBorderFontSize=24;

void init(QApplication *a);

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");
    QApplication a(argc, argv);
    init(&a);
    MainWindow *w=&Singleton<MainWindow>::instance();

    w->init(&a);
    w->show();

    return a.exec();
}

void init(QApplication *a)
{
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));//解决程序中中文乱码问题

    punctuation=new QString("!@#$%^&*()_+-={}[]|\:;\"'<,>.?/！@#￥%……&×（）——+-={}【】|、\“：；‘《，》。？/～`~`");//所有可能遇到的普通标点符号

    int width=QApplication::desktop()->width();
    int height=QApplication::desktop()->height();

    screenSize=new QSize(width,height);//初始化屏幕尺寸记录变量
    keysAreaSize=new QSize(Tool::size(800,305));//键盘中按键区域的尺寸
    QSize qs1(600,230);
    QSize qs2(220,133);
    keyBoardMaxSize=new QSize(Tool::size(qs1.width(),qs1.height()));//初始化软键盘打开时的尺寸记录变量
    keyBoardMinSize=new QSize(Tool::size(qs2.width(),qs2.height()));//初始化软键盘关闭时的尺寸记录变量
    editBoxSize=new QSize(Tool::size(qs1.width()-160,qs1.height()-120));//初始化输入框的尺寸记录变量

    /*以下根据屏幕比例选择图片根目录*/
    double a4_3=4/3.0, a16_9=16/9.0, b=width/(double)height;
    double s1=fabs(b-a4_3), s2=fabs(b-a16_9);
    if(s1<s2)
        picRoot=QString("../EnglishDoctorCheng/image/screenRate4.3");
    else
        picRoot=QString("../EnglishDoctorCheng/image/screenRate16.9") ;

    audioPath=QString("../EnglishDoctorCheng/audio/");//("/home/zhanghuoding/Program/C.C++/Qt/hanhewending/EnglishDoctorCheng/audio/");

    Singleton<QuitButton>::instance().initQuitButton(a);


    reader=new Read;
    paper=new Paper;

    Singleton<Recorder>::instance();//创建recorder的对象，用于记录单词读写情况
}

int pageWordsNum(char *pageName)
{
    QString tmp(pageName);
    for(int i=0;i<STUDY_PAGE_NUM;i++)
    {
        if(tmp.compare(eachPageWordsNum[i].key,Qt::CaseInsensitive)==0)//不区分大小写
            return eachPageWordsNum[i].value;
    }
    return 0;
}
short sizeOfCharPtr(char *ptr)
{
    short i=0;
    if(ptr)
    {
        for(i=0;*ptr!='\0';i++,ptr++);
    }
    return i;
}

inchpa eachPageWordsNum[STUDY_PAGE_NUM]={
    {"outsidestudy",9},{"homestudy",3},{"LivingRoomStudy",15},{"KitchenStudy",7},
    {"BreakfastStudy",5},{"LunchStudy",6},{"DinnerStudy",6},{"BedroomStudy",5},
    {"StudyStudy",11},{"FamilyStudy",8},
    {"AtHomeStudy",11},{"BusStudy",4},{"SchoolStudy",7},{"ClassroomStudy",14},
    {"DreamStudy",11},{"InterestStudy",7},
    {"MeadowStudy",12},{"GrasslandStudy",8},{"ForestStudy",9},{"RestaurantStudy",16},
    {"ParkStudy",10},{"SeaStudy",10},{"ClothingStudy",11},{"FruitAndVegetableStudy",15},
    {"BodyStudy",14}
};
