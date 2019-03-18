#ifndef BACKBUTTON_H
#define BACKBUTTON_H

#include <QPushButton>
#include <QWidget>

#include "customClass/tool.h"

class BackButton : public QPushButton
{
public:
    BackButton(QWidget *parent=0);
    Q_INVOKABLE void invokableMethod();
    ~BackButton();
};

#endif // BACKBUTTON_H
