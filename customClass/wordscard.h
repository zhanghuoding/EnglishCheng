#ifndef WORDSCARD_H
#define WORDSCARD_H

#include <QWidget>
#include <QPixmap>

#include "customClass/mylabel.h"
#include "customClass/tool.h"
#include "via.h"

class WordsCard : public QWidget
{
    Q_OBJECT
public:
    explicit WordsCard(QWidget *parent = 0);
    ~WordsCard();
    virtual void setSize(int bw,int bh,int pw,int ph);//设置该组件的以及其内部组件的尺寸

private:
    MyLabel *showWordsLabel;
    MyLabel *wordsCardLabel;

signals:

public slots:
    virtual void setWords(char *referString);
    virtual void setPixmap(QPixmap pixmap);
    virtual void close();//关闭本组件，并重置内容

};

#endif // WORDSCARD_H
