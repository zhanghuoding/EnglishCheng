#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    virtual ~MyLabel();
    bool isclickedOutside;//记录该label是否被单击的按钮
    short indexInWordsPhrase;//记录该label在MyStudy中的单词数组中对应的单词的下标
    short picNum;//MyStudy页面中所学习的单词对应的图片数量不定，本变量记录此label是对应的第几张图片

signals:
    void clicked(MyLabel *me=NULL,bool isEnter=false);
    void mouseMoved(bool);

protected:
    virtual void mousePressEvent ( QMouseEvent * event )Q_DECL_OVERRIDE;
    virtual void mouseMoveEvent( QMouseEvent * event );
};

#endif // MYLABEL_H
