#ifndef WORDSPAGE_H
#define WORDSPAGE_H

#include <QPushButton>
#include <QWidget>

#include "customClass/mywidget.h"
#include "customClass/backbutton.h"

class WordsPage : public MyWidget
{
public:
    WordsPage(QWidget *parent=0);
    ~WordsPage();
};

#endif // WORDSPAGE_H
