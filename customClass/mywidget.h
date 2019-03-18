#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>


#include "customClass/quitbutton.h"
#include "customClass/backbutton.h"
#include "customClass/mypushbutton.h"
#include "via.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    virtual ~MyWidget();
    virtual MyWidget *init(QWidget *parent = 0);

    virtual QLabel *getBackgroundLabel();

protected:
    QLabel *background;//每个页面中的背景图片

    MyPushButton *button1;
    MyPushButton *button2;
    MyPushButton *button3;
    MyPushButton *button4;
    MyPushButton *button5;
    MyPushButton *button6;
    MyPushButton *button7;
    MyPushButton *button8;
    MyPushButton *button9;
    MyPushButton *button10;
    MyPushButton *button11;
    MyPushButton *button12;
    MyPushButton *button13;
    MyPushButton *button14;
    /*MyPushButton *button15;
    MyPushButton *button16;
    MyPushButton *button17;
    MyPushButton *button18;
    MyPushButton *button19;
    MyPushButton *button20;
    MyPushButton *button21;
    MyPushButton *button22;
    MyPushButton *button23;
    MyPushButton *button24;*/

signals:

public slots:
    virtual void startPage(MyPushButton *me=NULL);
};

#endif // MYWIDGET_H
