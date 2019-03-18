#include "wordschoicepage.h"

#include "mainwindow.h"

WordsChoicePage::WordsChoicePage(QWidget *parent) : MyWidget(parent)
{
    background->setPixmap(QPixmap(picRoot+QString("/words/WordsChoice/background.jpg")));

    button1->setIcon(QPixmap(picRoot+QString("/words/WordsChoice/leftArrows.png")));
    button1->setIconSize(Tool::size(100,100));
    button1->setFixedSize(Tool::size(80,80));
    button1->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20),-1,-1,-1,"#ffffff","#ffffff","#ffffff"));
    button1->setVisible(true);

    button2->setIcon(QPixmap(picRoot+QString("/words/WordsChoice/ILoveMyHome.png")));
    button2->setObjectName("ILoveMyHome");
    button2->setIconSize(Tool::size(280,280));
    button2->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20)));
    button2->setVisible(true);

    button3->setIcon(QPixmap(picRoot+QString("/words/WordsChoice/MySchool.png")));
    button3->setObjectName("MySchool");
    button3->setIconSize(Tool::size(280,280));
    button3->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20)));
    button3->setVisible(true);

    button4->setIcon(QPixmap(picRoot+QString("/words/WordsChoice/happyDay.png")));
    button4->setObjectName("HappyDay");
    button4->setIconSize(Tool::size(280,280));
    button4->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20)));
    button4->setVisible(true);

    button5->setIcon(QPixmap(picRoot+QString("/words/WordsChoice/body.png")));
    button5->setObjectName("BodyStudy");
    button5->setIconSize(Tool::size(280,280));
    button5->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20)));
    button5->setVisible(true);

    button6->setIcon(QPixmap(picRoot+QString("/words/WordsChoice/rightArrows.png")));
    button6->setIconSize(Tool::size(100,100));
    button6->setFixedSize(Tool::size(80,80));
    button6->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20),-1,-1,-1,"#ffffff","#ffffff","#ffffff"));
    button6->setVisible(true);

    button1->setGeometry(Tool::rect(48,450,80,80));
    button2->setGeometry(Tool::rect(168,366,250,250));
    button3->setGeometry(Tool::rect(516,366,250,250));
    button4->setGeometry(Tool::rect(848,366,250,250));
    button5->setGeometry(Tool::rect(1180,366,250,250));
    button6->setGeometry(Tool::rect(1472,450,80,80));
}
WordsChoicePage::~WordsChoicePage()
{

}
void WordsChoicePage::startButton1Page()
{
    //((MainWindow*)(this->parentWidget()->parentWidget()))->creatPage("DailyWordsPage",true);
    Tool::showDialog();
}
void WordsChoicePage::startButton6Page()
{
    //((MainWindow*)(this->parentWidget()->parentWidget()))->creatPage("EnglishStoryPage",true);
    Tool::showDialog();
}

