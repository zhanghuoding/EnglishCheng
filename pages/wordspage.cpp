#include "wordspage.h"
#include "mainwindow.h"
#include "Singleton/singleton.h"
#include "customClass/tool.h"
#include "via.h"

WordsPage::WordsPage(QWidget *parent) : MyWidget(parent)
{
    background->setPixmap(QPixmap(picRoot+QString("/words/home/background.jpg")));

    button1->setIcon(QPixmap(picRoot+QString("/words/home/learnWords.png")));
    button1->setObjectName("WordsChoicePage");
    button1->setIconSize(Tool::size(280,280));
    button1->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20),-1,-1,-1,"#f7f7f7","#efeded","#e4e0e0"));
    button1->setVisible(true);

    button2->setIcon(QPixmap(picRoot+QString("/words/home/wordsFight.png")));
    button2->setObjectName("");//("fightChoicePage");
    button2->setIconSize(Tool::size(280,280));
    button2->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20),-1,-1,-1,"#f7f7f7","#efeded","#e4e0e0"));
    button2->setVisible(true);

    button1->setGeometry(Tool::rect(444,378,250,250));
    button2->setGeometry(Tool::rect(924,378,250,250));
}
WordsPage::~WordsPage()
{
}

