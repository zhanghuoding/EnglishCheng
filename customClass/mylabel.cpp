#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    setScaledContents(true);
    isclickedOutside=false;
    indexInWordsPhrase=0;
    picNum=0;
}
MyLabel::~MyLabel()
{

}
void MyLabel::mousePressEvent(QMouseEvent *event)
{
    // 如果单击了就触发clicked信号
    if ( event->button() == Qt::LeftButton )
    {
        isclickedOutside=true;
        emit clicked(this,false);
    }
    // 将该事件传给父类处理
    QLabel::mousePressEvent(event);
}
void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseMoved(true);

    // 将该事件传给父类处理
    QLabel::mouseMoveEvent(event);
}
