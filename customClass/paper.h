#ifndef PAPER_H
#define PAPER_H

#include <QWidget>
#include <QLabel>

#include "typestruct.h"

class Paper : public QWidget
{
    Q_OBJECT
public:
    Paper(QWidget *parent=0);
    ~Paper();
    QString *referString;//键盘中输入内容的参照单词
    QLabel *editArea;//键盘中输入内容进行显示的标签
    void setDoReset(bool doReset);//设置是否重置“纸”对象的标记

private:
    QLabel *background;
    unsigned currentLetter;//当前输入字母在参照内容referString中的下标
    bool doReset;//是否重置“纸”对象的标记，当该标记为真时，重置对象，否则，不重置
signals:
    void haveWrite(QString referString);//将已经书写一遍的单词或词组广播出去

public slots:
    void writeChar(keytype_ keyType);//将软键盘输入的字母显示在四线三格中
    void setReferString(char *referString);//监听器，传入键盘输入单词过程中的正确的单词或词组
    void reset();//对“纸”进行重置
    void openPaper(QWidget *parent);//显示编辑框
    void closePaper(bool needReset=true);//隐藏编辑框
    void completeWrite();//当完成书写的时候，进行广播词组以及重置“纸”
};
#endif // PAPER_H
