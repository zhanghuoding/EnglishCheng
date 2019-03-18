#include "triggerthread.h"

TriggerThread::TriggerThread(QObject *parent) : QThread(parent)
{

}
TriggerThread::~TriggerThread()
{

}
void TriggerThread::run()
{
    sleep(1);
}



TriggerThread_1::TriggerThread_1(QObject *parent) : QThread(parent)
{

}
TriggerThread_1::~TriggerThread_1()
{

}
void TriggerThread_1::run()
{
    sleep(2);
}

