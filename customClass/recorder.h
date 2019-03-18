#ifndef RECORDER_H
#define RECORDER_H

#include <QObject>
#include "via.h"

class Recorder : public QObject
{
    Q_OBJECT
public:
    explicit Recorder(QObject *parent = 0);
    ~Recorder();

signals:

public slots:
    void haveWrite(QString content);//接收来自paper对象的同名的信号，用于接收并记录已经写过的单词或词组
    void haveRead(QString content);//接收来自reader对象的同名的信号，用于接收并记录已经读过的单词或词组
};

#endif // RECORDER_H
