#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);
    virtual ~MyPushButton();
signals:
    void hadClicked(MyPushButton *me=NULL);

protected:
    virtual void mousePressEvent ( QMouseEvent * event )Q_DECL_OVERRIDE;
};

#endif // MYPUSHBUTTON_H
