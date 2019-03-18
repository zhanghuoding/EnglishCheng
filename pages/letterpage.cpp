#include "letterpage.h"
#include "mainwindow.h"
#include "Singleton/singleton.h"
#include "customClass/tool.h"
#include "via.h"

LetterPage::LetterPage(QWidget *parent) : MyWidget(parent)
{
    background->setPixmap(QPixmap(picRoot+QString("/letter/home/background.jpg")));

    button1->setIcon(QPixmap(picRoot+QString("/letter/home/findLetter.png")));
    button1->setObjectName("LetterChoicePage");
    button1->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20),-1,-1,-1,"#f7f7f7","#efeded","#e4e0e0"));
    button1->setVisible(true);

    button2->setIcon(QPixmap(picRoot+QString("/letter/home/fightLetter.png")));
    button2->setObjectName("LetterFightChoicePage");
    button2->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20),-1,-1,-1,"#f7f7f7","#efeded","#e4e0e0"));
    button2->setVisible(true);

    button1->setGeometry(Tool::rect(444,378,250,250));
    button2->setGeometry(Tool::rect(924,378,250,250));
}
LetterPage::~LetterPage()
{
}
