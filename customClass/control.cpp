#include "control.h"

#include <QDebug>

Control::Control()
{

}
Control::~Control()
{

}
void Control::settingVoice(bool flag)
{
    /*
     * 此处添加设置软件是否可以发声的代码，当flag为真时，开启软件音效，反之亦然
     */
    if(flag)
    {
        qDebug()<<"trumpet";
    }else
    {
        qDebug()<<"mute";
    }
}

