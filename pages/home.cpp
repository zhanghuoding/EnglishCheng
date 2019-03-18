#include "home.h"
#include "customClass/tool.h"
#include "mainwindow.h"
#include "via.h"

#include <QPixmap>
#include <QImage>
#include <QPicture>

Home::Home(QWidget *parent) : MyWidget(parent)
{
    background->setPixmap(QPixmap(picRoot+QString("/home/backgroundIcon.jpg")));

    button1->setStatusTip(tr("DailyWords"));
    button1->setObjectName("DailyWordsPage");
    button1->setIcon(QPixmap(""));
    button1->setIconSize(Tool::size(128,160));
    button1->setFixedSize(Tool::size(128,160));
    button1->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(0),-1,-1,-1,"#c63434","#c32a2a","#c31d1d"));
    button1->setVisible(true);

    button2->setStatusTip(tr("Letter"));
    button2->setObjectName("LetterPage");
    button2->setIcon(QPixmap(picRoot+QString("/home/letterIcon.png")));
    button2->setIconSize(Tool::size(128,160));
    button2->setFixedSize(Tool::size(128,160));
    button2->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(0),-1,-1,-1,"#129dd4","#099dd8","#05a1df"));
    button2->setVisible(true);

    button3->setStatusTip(tr("Words"));
    button3->setObjectName("WordsPage");
    button3->setIcon(QPixmap(picRoot+QString("/home/wordIcon.png")));
    button3->setIconSize(Tool::size(128,160));
    button3->setFixedSize(Tool::size(128,160));
    button3->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(0),-1,-1,-1,"#f17a28","#f0731d","#f16c11"));
    button3->setVisible(true);

    button4->setStatusTip(tr("ManMachineConversation"));
    button4->setObjectName("ManMachineConversationPage");
    button4->setIcon(QPixmap(""));
    button4->setIconSize(Tool::size(128,160));
    button4->setFixedSize(Tool::size(128,160));
    button4->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(0),-1,-1,-1,"#92c232","#8bc021","#89c414"));
    button4->setVisible(true);

    button5->setStatusTip(tr("EnglishStory"));
    button5->setObjectName("EnglishStoryPage");
    button5->setIcon(QPixmap(""));
    button5->setIconSize(Tool::size(128,160));
    button5->setFixedSize(Tool::size(128,160));
    button5->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(0),-1,-1,-1,"#ed5f2f","#ed5421","#ee460d"));
    button5->setVisible(true);

    button1->setGeometry(Tool::rect(72,105,128,160));
    button2->setGeometry(Tool::rect(336,105,128,160));
    button3->setGeometry(Tool::rect(592,105,128,160));
    button4->setGeometry(Tool::rect(864,123,128,160));
    button5->setGeometry(Tool::rect(1156,123,128,160));
}
Home::~Home()
{
}
