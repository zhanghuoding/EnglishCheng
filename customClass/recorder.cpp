#include "recorder.h"

#include <QDebug>

Recorder::Recorder(QObject *parent) : QObject(parent)
{
    connect(paper,SIGNAL(haveWrite(QString)),this,SLOT(haveWrite(QString)));
    connect(reader,SIGNAL(haveRead(QString)),this,SLOT(haveRead(QString)));
}
Recorder::~Recorder()
{

}
void Recorder::haveWrite(QString content)
{
    //本函数中传进来的是QString类型的对象，需要提取其中的内容，并且区分是中文还是英文，对中文不进行记录
    qDebug("刚才写了%s",content.toLatin1().data());
}
void Recorder::haveRead(QString content)
{
    //本函数中传进来的是QString类型的对象，需要提取其中的内容，并且区分是中文还是英文，对中文不进行记录
    qDebug("刚才读了%s",content.toLatin1().data());
}

