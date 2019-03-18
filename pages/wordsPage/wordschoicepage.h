#ifndef WORDSCHOICEPAGE_H
#define WORDSCHOICEPAGE_H

#include "customClass/mywidget.h"

class WordsChoicePage : public MyWidget
{
public:
    WordsChoicePage(QWidget *parent = 0);
    ~WordsChoicePage();

public slots:
    void startButton1Page();//该槽函数并不会被调用，因为没有被连接
    void startButton6Page();//该槽函数并不会被调用，因为没有被连接
};

#endif // WORDSCHOICEPAGE_H
