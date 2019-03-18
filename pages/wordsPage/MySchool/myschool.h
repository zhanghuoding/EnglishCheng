#ifndef MYSCHOOL_H
#define MYSCHOOL_H

#include "customClass/mywidget.h"

class MySchool : public MyWidget
{
    Q_OBJECT
public:
    MySchool(QWidget *parent=0);
    ~MySchool();

public slots:
};
#endif // MYSCHOOL_H
