#ifndef KEY_H
#define KEY_H

#include "via.h"

#include <QPushButton>
#include <QColor>
#include <QSize>

class Key : public QPushButton
{
    Q_OBJECT
public:
    explicit Key(keytype_ typeOfKey, QWidget *parent = 0);
    ~Key();
    keytype_ getTypeOfKey();//返回该按键的类型typeOfKey的值
    void setBackGroundColor(char *rgb1=KEY_BACKCOL_NORMAL,char *rgb2=KEY_BACKCOL_ENTER,char *rgb3=KEY_BACKCOL_PRESSED,char *rgb=KEY_FONT_COLOR);//设置本按钮的背景色
    void setSize(QSize size);//设置该键的尺寸，该函数应具有默认值

private:
    keytype_ typeOfKey;//该值用来标记该按键所代表的键盘上对应的键值
    QColor *defaultColor;//按钮默认的颜色

signals:
    void clickedSignal(Key *me);//该函数在自己被点击时，发出自己的指针。由sendClickedSignal()槽函数发出该信号

public slots:
    void sendClickedSignal();//该槽函数接收该按键的clicked信号，并发出一个信号，说自己被点击了

};

#endif // KEY_H
