#include "myschool.h"
#include "mainwindow.h"
#include "Singleton/singleton.h"
#include "macro.h"

MySchool::MySchool(QWidget *parent) : MyWidget(parent)
{
    background->setPixmap(QPixmap(picRoot+QString("/words/words/MySchool/background.jpg")));

    button1->setIcon(QPixmap(picRoot+QString("/words/words/MySchool/icon(colours)/home.png")));
    button1->setIconSize(Tool::size(200,200));
    button1->setFixedSize(Tool::size(150,150));
    button1->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(75),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button1->setObjectName(QString("AtHomeStudy"));
    button1->setVisible(true);
    button1->setGeometry(Tool::rect(105,370,150,150));

    button2->setIcon(QPixmap(picRoot+QString("/words/words/MySchool/icon(colours)/bus.png")));
    button2->setIconSize(Tool::size(200,200));
    button2->setFixedSize(Tool::size(160,160));
    button2->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(80),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button2->setObjectName(QString("BusStudy"));
    button2->setVisible(true);
    button2->setGeometry(Tool::rect(375,360,160,160));

    button3->setIcon(QPixmap(picRoot+QString("/words/words/MySchool/icon(colours)/school.png")));
    button3->setIconSize(Tool::size(200,200));
    button3->setFixedSize(Tool::size(170,170));
    button3->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(85),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button3->setObjectName("SchoolStudy");
    button3->setVisible(true);
    button3->setGeometry(Tool::rect(650,260,170,170));

    button4->setIcon(QPixmap(picRoot+QString("/words/words/MySchool/icon(colours)/classroom.png")));
    button4->setIconSize(Tool::size(190,190));
    button4->setFixedSize(Tool::size(170,170));
    button4->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(85),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button4->setObjectName("ClassroomStudy");
    button4->setVisible(true);
    button4->setGeometry(Tool::rect(920,275,170,170));

    button5->setIcon(QPixmap(picRoot+QString("/words/words/MySchool/icon(colours)/dream.png")));
    button5->setIconSize(Tool::size(190,190));
    button5->setFixedSize(Tool::size(170,170));
    button5->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(85),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button5->setObjectName("DreamStudy");
    button5->setVisible(true);
    button5->setGeometry(Tool::rect(1185,398,170,170));

    button6->setIcon(QPixmap(picRoot+QString("/words/words/MySchool/icon(colours)/interest.png")));
    button6->setIconSize(Tool::size(170,170));
    button6->setFixedSize(Tool::size(150,150));
    button6->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(75),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button6->setObjectName("InterestStudy");
    button6->setVisible(true);
    button6->setGeometry(Tool::rect(1368,575,150,150));
}
MySchool::~MySchool()
{

}
