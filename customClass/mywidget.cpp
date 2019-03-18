#include "mywidget.h"
#include "Singleton/singleton.h"
#include "via.h"
#include "customClass/tool.h"
#include "mainwindow.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    background=new QLabel(this);
    background->setScaledContents(true);
    background->setFixedSize(*screenSize);
    background->setGeometry(Tool::rect(0,0,1600,900));

    button1=new MyPushButton(this);
    button1->setVisible(false);
    button2=new MyPushButton(this);
    button2->setVisible(false);
    button3=new MyPushButton(this);
    button3->setVisible(false);
    button4=new MyPushButton(this);
    button4->setVisible(false);
    button5=new MyPushButton(this);
    button5->setVisible(false);
    button6=new MyPushButton(this);
    button6->setVisible(false);
    button7=new MyPushButton(this);
    button7->setVisible(false);
    button8=new MyPushButton(this);
    button8->setVisible(false);
    button9=new MyPushButton(this);
    button9->setVisible(false);
    button10=new MyPushButton(this);
    button10->setVisible(false);
    button11=new MyPushButton(this);
    button11->setVisible(false);
    button12=new MyPushButton(this);
    button12->setVisible(false);
    button13=new MyPushButton(this);
    button13->setVisible(false);
    button14=new MyPushButton(this);
    button14->setVisible(false);

    connect(button1,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button2,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button3,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button4,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button5,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button6,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button7,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button8,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button9,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button10,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button11,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button12,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button13,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
    connect(button14,SIGNAL(hadClicked(MyPushButton*)),this,SLOT(startPage(MyPushButton*)));
}
MyWidget::~MyWidget()
{
    if(background)
        delete background;
    if(button1)
        delete button1;
    if(button2)
        delete button2;
    if(button3)
        delete button3;
    if(button4)
        delete button4;
    if(button5)
        delete button5;
    if(button6)
        delete button6;
    if(button7)
        delete button7;
    if(button8)
        delete button8;
    if(button9)
        delete button9;
    if(button10)
        delete button10;
    if(button11)
        delete button11;
    if(button12)
        delete button12;
    if(button13)
        delete button13;
    if(button14)
        delete button14;
}

MyWidget *MyWidget::init(QWidget *parent)
{
    this->setParent(parent);
    return this;
}
QLabel *MyWidget::getBackgroundLabel()
{
    return background;
}
void MyWidget::startPage(MyPushButton *me)
{
    if(me)
    {
        Singleton<MainWindow>::instance().creatPage(me->objectName(),true);//根据页面名创建页面对象
    }
}

