#ifndef LETTERPAGE_H
#define LETTERPAGE_H

#include <QPushButton>
#include <QWidget>

#include "customClass/mywidget.h"
#include "customClass/backbutton.h"

class LetterPage : public MyWidget
{
public:
    LetterPage(QWidget *parent=0);
    ~LetterPage();
private:

public slots:
};

#endif // LETTERPAGE_H
