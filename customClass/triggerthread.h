#ifndef TRIGGERTHREAD_H
#define TRIGGERTHREAD_H

#include <QThread>
#include <QString>


/*
 * TiggerThread线程类所做的时只有沉睡1秒，不做其他工作
 */
class TriggerThread : public QThread
{
    Q_OBJECT
public:
    explicit TriggerThread(QObject *parent = 0);
    virtual ~TriggerThread();
    void run() Q_DECL_OVERRIDE ;
private:

signals:
public slots:
};

/*
 * TiggerThread_1线程类所做的时只有沉睡2秒，不做其他工作
 */
class TriggerThread_1 : public QThread
{
    Q_OBJECT
public:
    explicit TriggerThread_1(QObject *parent = 0);
    virtual ~TriggerThread_1();
    void run() Q_DECL_OVERRIDE ;
private:

signals:
public slots:
};

#endif // TRIGGERTHREAD_H
