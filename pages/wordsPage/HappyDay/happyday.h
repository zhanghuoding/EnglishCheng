#ifndef HAPPYDAY_H
#define HAPPYDAY_H

#include "customClass/mywidget.h"

class HappyDay : public MyWidget
{
    Q_OBJECT
public:
    HappyDay(QWidget *parent=0);
    ~HappyDay();

public slots:
};
#endif // HAPPYDAY_H
