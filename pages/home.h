#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QGridLayout>

#include "customClass/quitbutton.h"
#include "customClass/mywidget.h"

class Home : public MyWidget
{
    Q_OBJECT
public:
    explicit Home(QWidget *parent = 0);
    virtual ~Home();
};

#endif // HOME_H
