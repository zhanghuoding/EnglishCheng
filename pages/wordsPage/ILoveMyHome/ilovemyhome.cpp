#include "ilovemyhome.h"
#include "mainwindow.h"
#include "Singleton/singleton.h"

ILoveMyHome::ILoveMyHome(QWidget *parent) : MyWidget(parent)
{
    background->setPixmap(QPixmap(picRoot+QString("/words/words/ILoveMyHome/background.jpg")));

    button1->setIcon(QPixmap(picRoot+QString("/words/words/ILoveMyHome/icon(colours)/outside.png")));
    button1->setIconSize(Tool::size(180,180));
    button1->setFixedSize(Tool::size(148,148));
    button1->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(70),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button1->setObjectName(QString("OutsideStudy"));
    button1->setVisible(true);

    button2->setIcon(QPixmap(picRoot+QString("/words/words/ILoveMyHome/icon(colours)/home.png")));
    button2->setIconSize(Tool::size(180,180));
    button2->setFixedSize(Tool::size(160,160));
    button2->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(76),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button2->setObjectName(QString("HomeStudy"));
    button2->setVisible(true);

    button3->setIcon(QPixmap(picRoot+QString("/words/words/ILoveMyHome/icon(colours)/livingRoom.png")));
    button3->setIconSize(Tool::size(220,220));
    button3->setFixedSize(Tool::size(171,171));
    button3->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(81),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button3->setObjectName("LivingRoomStudy");
    button3->setVisible(true);

    button4->setIcon(QPixmap(picRoot+QString("/words/words/ILoveMyHome/icon(colours)/kitchen.png")));
    button4->setIconSize(Tool::size(220,220));
    button4->setFixedSize(Tool::size(190,190));
    button4->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(91),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button4->setObjectName("KitchenStudy");
    button4->setVisible(true);

    button5->setIcon(QPixmap(picRoot+QString("/words/words/ILoveMyHome/icon(colours)/breakfast.png")));
    button5->setIconSize(Tool::size(210,210));
    button5->setFixedSize(Tool::size(200,200));
    button5->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(96),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button5->setObjectName("BreakfastStudy");
    button5->setVisible(true);

    button6->setIcon(QPixmap(picRoot+QString("/words/words/ILoveMyHome/icon(colours)/lunch.png")));
    button6->setIconSize(Tool::size(220,220));
    button6->setFixedSize(Tool::size(210,210));
    button6->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(101),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button6->setObjectName("LunchStudy");
    button6->setVisible(true);

    button7->setIcon(QPixmap(picRoot+QString("/words/words/ILoveMyHome/icon(colours)/dinner.png")));
    button7->setIconSize(Tool::size(200,200));
    button7->setFixedSize(Tool::size(190,190));
    button7->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(91),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button7->setObjectName("DinnerStudy");
    button7->setVisible(true);

    button8->setIcon(QPixmap(picRoot+QString("/words/words/ILoveMyHome/icon(colours)/bedroom.png")));
    button8->setIconSize(Tool::size(210,210));
    button8->setFixedSize(Tool::size(200,200));
    button8->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(96),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button8->setObjectName("BedroomStudy");
    button8->setVisible(true);

    button9->setIcon(QPixmap(picRoot+QString("/words/words/ILoveMyHome/icon(colours)/study.png")));
    button9->setIconSize(Tool::size(200,200));
    button9->setFixedSize(Tool::size(190,190));
    button9->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(91),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button9->setObjectName("StudyStudy");
    button9->setVisible(true);

    button10->setIcon(QPixmap(picRoot+QString("/words/words/ILoveMyHome/icon(colours)/family.png")));
    button10->setIconSize(Tool::size(210,210));
    button10->setFixedSize(Tool::size(200,200));
    button10->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(96),-1,-1,-1,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL,KEY_BACKCOL_NORMAL));
    button10->setObjectName("FamilyStudy");
    button10->setVisible(true);

    button1->setGeometry(Tool::rect(235,355,148,148));
    button2->setGeometry(Tool::rect(36,271,160,160));
    button3->setGeometry(Tool::rect(120,57,171,171));
    button4->setGeometry(Tool::rect(360,117,190,190));
    button5->setGeometry(Tool::rect(610,43,200,200));
    button6->setGeometry(Tool::rect(869,66,210,210));
    button7->setGeometry(Tool::rect(1140,58,190,190));
    button8->setGeometry(Tool::rect(1363,175,200,200));
    button9->setGeometry(Tool::rect(1380,413,190,190));
    button10->setGeometry(Tool::rect(1165,563,200,200));
}
ILoveMyHome::~ILoveMyHome()
{

}
