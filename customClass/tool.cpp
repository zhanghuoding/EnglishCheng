#include "tool.h"
#include "via.h"

#include "mainwindow.h"
#include "Singleton/singleton.h"
#include "pages/home.h"
#include "pages/dailywordspage.h"
#include "pages/letterpage.h"
#include "pages/wordspage.h"
#include "pages/manmachineconversationpage.h"
#include "pages/englishstorypage.h"
#include "customClass/quitbutton.h"
#include "customClass/mywidget.h"
#include "pages/letterPage/letterchoicepage.h"
#include "pages/letterPage/letterfightchoicepage.h"
#include "pages/wordsPage/wordschoicepage.h"
#include "pages/wordsPage/ILoveMyHome/ilovemyhome.h"
#include "customClass/keyboard.h"
#include "pages/wordsPage/ILoveMyHome/outsideStudy.h"
#include "pages/wordsPage/ILoveMyHome/homestudy.h"
#include "pages/wordsPage/ILoveMyHome/livingroomstudy.h"
#include "pages/wordsPage/ILoveMyHome/kitchenstudy.h"
#include "pages/wordsPage/ILoveMyHome/breakfaststudy.h"
#include "pages/wordsPage/ILoveMyHome/lunchstudy.h"
#include "pages/wordsPage/ILoveMyHome/dinnerstudy.h"
#include "pages/wordsPage/ILoveMyHome/bedroomstudy.h"
#include "pages/wordsPage/ILoveMyHome/studystudy.h"
#include "pages/wordsPage/ILoveMyHome/familystudy.h"
#include "pages/wordsPage/MySchool/myschool.h"
#include "pages/wordsPage/MySchool/athomestudy.h"
#include "pages/wordsPage/MySchool/busstudy.h"
#include "pages/wordsPage/MySchool/classroomstudy.h"
#include "pages/wordsPage/MySchool/dreamstudy.h"
#include "pages/wordsPage/MySchool/intereststudy.h"
#include "pages/wordsPage/MySchool/schoolstudy.h"
#include "pages/wordsPage/HappyDay/happyday.h"
#include "pages/wordsPage/HappyDay/meadowstudy.h"
#include "pages/wordsPage/HappyDay/grasslandstudy.h"
#include "pages/wordsPage/HappyDay/foreststudy.h"
#include "pages/wordsPage/HappyDay/restaurantstudy.h"
#include "pages/wordsPage/HappyDay/seastudy.h"
#include "pages/wordsPage/HappyDay/parkstudy.h"
#include "pages/wordsPage/HappyDay/clothingstudy.h"
#include "pages/wordsPage/HappyDay/fruitandvegetablestudy.h"
#include "pages/wordsPage/Body/bodystudy.h"

#include <QMessageBox>
#include <QPushButton>

#include <QDebug>

Tool::Tool()
{

}

char * const Tool::prompter="熊大偷偷告诉你：";
char * const Tool::barrNotOpen="\n光头强禁止了你的权限，赶快加油吧！    \n";
char * const Tool::functionNotDeveloped="\n嘘! 熊二正在加油开发该功能，一般人我不告诉他哦！^_^    \n";

void *Tool::creatClassByStringWithSingleton(QString className)
{
    if(className.isEmpty())
    {
        Tool::showDialog();
        return NULL;
    }
    if(className.compare("over",Qt::CaseInsensitive)==0)
    {
        return NULL;
    }

    if(className.compare("Home")==0)
        return & Singleton<Home>::instance();
    else if(className.compare("DailyWordsPage")==0)
        return & Singleton<DailyWordsPage>::instance();
    else if(className.compare("LetterPage")==0)
        return & Singleton<LetterPage>::instance();
    else if(className.compare("WordsPage")==0)
        return & Singleton<WordsPage>::instance();
    else if(className.compare("ManMachineConversationPage")==0)
        return & Singleton<ManMachineConversationPage>::instance();
    else if(className.compare("EnglishStoryPage")==0)
        return & Singleton<EnglishStoryPage>::instance();
    else if(className.compare("QuitButton")==0)
        return & Singleton<QuitButton>::instance();
    else if(className.compare("LetterChoicePage")==0)
        return & Singleton<LetterChoicePage>::instance();
    else if(className.compare("LetterFightChoicePage")==0)
        return & Singleton<LetterFightChoicePage>::instance();
    else if(className.compare("WordsChoicePage")==0)
        return & Singleton<WordsChoicePage>::instance();
    else if(className.compare("ILoveMyHome")==0)
        return & Singleton<ILoveMyHome>::instance();
    else if(className.compare("KeyBoard")==0)
        return & Singleton<KeyBoard>::instance();
    else if(className.compare("OutsideStudy")==0)
        return & Singleton<OutsideStudy>::instance();
    else if(className.compare("HomeStudy")==0)
        return & Singleton<HomeStudy>::instance();
    else if(className.compare("LivingRoomStudy")==0)
        return & Singleton<LivingRoomStudy>::instance();
    else if(className.compare("KitchenStudy")==0)
        return & Singleton<KitchenStudy>::instance();
    else if(className.compare("BreakfastStudy")==0)
        return & Singleton<BreakfastStudy>::instance();
    else if(className.compare("LunchStudy")==0)
        return & Singleton<LunchStudy>::instance();
    else if(className.compare("DinnerStudy")==0)
        return & Singleton<DinnerStudy>::instance();
    else if(className.compare("BedroomStudy")==0)
        return & Singleton<BedroomStudy>::instance();
    else if(className.compare("StudyStudy")==0)
        return & Singleton<StudyStudy>::instance();
    else if(className.compare("FamilyStudy")==0)
        return & Singleton<FamilyStudy>::instance();
    else if(className.compare("MySchool")==0)
        return & Singleton<MySchool>::instance();
    else if(className.compare("HappyDay")==0)
        return & Singleton<HappyDay>::instance();
    else if(className.compare("AtHomeStudy")==0)
        return & Singleton<AtHomeStudy>::instance();
    else if(className.compare("BusStudy")==0)
        return & Singleton<BusStudy>::instance();
    else if(className.compare("SchoolStudy")==0)
        return & Singleton<SchoolStudy>::instance();
    else if(className.compare("ClassroomStudy")==0)
        return & Singleton<ClassroomStudy>::instance();
    else if(className.compare("DreamStudy")==0)
        return & Singleton<DreamStudy>::instance();
    else if(className.compare("InterestStudy")==0)
        return & Singleton<InterestStudy>::instance();
    else if(className.compare("MeadowStudy")==0)
        return & Singleton<MeadowStudy>::instance();
    else if(className.compare("GrasslandStudy")==0)
        return & Singleton<GrasslandStudy>::instance();
    else if(className.compare("ForestStudy")==0)
        return & Singleton<ForestStudy>::instance();
    else if(className.compare("RestaurantStudy")==0)
        return & Singleton<RestaurantStudy>::instance();
    else if(className.compare("SeaStudy")==0)
        return & Singleton<SeaStudy>::instance();
    else if(className.compare("ParkStudy")==0)
        return & Singleton<ParkStudy>::instance();
    else if(className.compare("ClothingStudy")==0)
        return & Singleton<ClothingStudy>::instance();
    else if(className.compare("FruitAndVegetableStudy")==0)
        return & Singleton<FruitAndVegetableStudy>::instance();
    else if(className.compare("BodyStudy")==0)
        return & Singleton<BodyStudy>::instance();
    else
    {
        Tool::showDialog();
        return NULL;
    }
}
void Tool::initNullArray(void *pointer, int size)
{
    if(pointer==NULL || size<=0)
        return;

    int *tmp=(int*)pointer;
    while(--size>=0)
    {
        tmp[size]=NULL;
    }
}
QSize Tool::size(int width, int height)
{
    int w=0,h=0;
    w=width*(screenSize->width()/1600.0)+0.5;//加0.5就是做四舍五入的运算
    h=height*(screenSize->height()/900.0)+0.5;
    return QSize(w,h);
}
int Tool::width(int width)
{
    return width*(screenSize->width()/1600.0)+0.5;
}
int Tool::height(int height)
{
    return height*(screenSize->height()/900.0)+0.5;
}
char *Tool::styleSheetNormalAndPressed(int leftUponRadius, int rightUponRadius, int leftBottomRadius,
                                       int rightBottomRadius, char *rgb1, char *rgb2, char *rgb3, char *rgb,int fontSi)
{
    /*
     * 其中rgb1是按钮正常状态下的颜色
     * rgb2是按钮被按下时的颜色
     * rgb3是鼠标进入按钮，但没有按下时的颜色
     * rgb是按钮的前景色，即当按钮中有文字时，文字的颜色
     */
    QString str("QPushButton{border:2px;border-radius:");
    int i=0;
    if(leftUponRadius>=0)
    {
        i++;
        str.append(QString::number(leftUponRadius).toLatin1().data());
    }
    if(rightUponRadius>=0)
    {
        i++;
        str.append("px ");
        str.append(QString::number(rightUponRadius).toLatin1().data());
    }
    if(leftBottomRadius>=0)
    {
        i++;
        str.append("px ");
        str.append(QString::number(leftBottomRadius).toLatin1().data());
    }
    if(rightBottomRadius>=0)
    {
        i++;
        str.append("px ");
        str.append(QString::number(rightBottomRadius).toLatin1().data());
    }
    if(i<=0)
        str.append("0px;");
    else
        str.append("px;");
    str.append("font-family:'Century Schoolbook';font-size:");
    str.append(QString::number(fontSize(fontSi)).toLatin1().data()).append("px;color:");
    str.append(rgb).append(";background-color:");
    str.append(rgb1).append(";}QPushButton:hover:!pressed{background-color:");
    str.append(rgb2).append(";}QPushButton:hover:pressed{background-color:");
    str.append(rgb3).append(";}");

    return str.toLatin1().data();
}

char *Tool::styleSheetPressed(int leftUponRadius, int rightUponRadius, int leftBottomRadius,
                                       int rightBottomRadius,char *rgb2, char *rgb3, char *rgb,int fontSi)
{
    /*
     * rgb2是按钮被按下时的颜色
     * rgb3是鼠标进入按钮，但没有按下时的颜色
     * rgb是按钮的前景色，即当按钮中有文字时，文字的颜色
     */

    QString str("QPushButton{border:2px;border-radius:");
    int i=0;
    if(leftUponRadius>=0)
    {
        i++;
        str.append(QString::number(leftUponRadius).toLatin1().data());
    }
    if(rightUponRadius>=0)
    {
        i++;
        str.append("px ");
        str.append(QString::number(rightUponRadius).toLatin1().data());
    }
    if(leftBottomRadius>=0)
    {
        i++;
        str.append("px ");
        str.append(QString::number(leftBottomRadius).toLatin1().data());
    }
    if(rightBottomRadius>=0)
    {
        i++;
        str.append("px ");
        str.append(QString::number(rightBottomRadius).toLatin1().data());
    }
    if(i<=0)
        str.append("0px;");
    else
        str.append("px;");
    str.append("font-family:'Century Schoolbook';font-size:");
    str.append(QString::number(fontSize(fontSi)).toLatin1().data()).append("px;color:");
    str.append(rgb).append(";}QPushButton:hover:!pressed{background-color:");
    str.append(rgb2).append(";}QPushButton:hover:pressed{background-color:");
    str.append(rgb3).append(";}");

    return str.toLatin1().data();
}
char *Tool::rateWidthToChar(int x)
{
    return QString::number(width(x)).toLatin1().data();
}
char *Tool::rateHeightToChar(int y)
{
    return QString::number(height(y)).toLatin1().data();
}

void Tool::showDialog(char *text, char *title)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(&Singleton<MainWindow>::instance(), QString(title), QString(text));
}
QRect Tool::rect(int ax, int ay, int aw, int ah)
{
    return QRect(width(ax),height(ay),width(aw),height(ah));
}
int Tool::fontSize(int size)
{
    return size*(screenSize->width()/1600.0)+0.5;
}

