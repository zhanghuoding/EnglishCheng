#include "mypushbutton.h"
#include "customClass/tool.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    setStatusTip(tr("汉和文鼎"));
    setIconSize(Tool::size(250,250));
    setFixedSize(Tool::size(250,250));
    setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20)));
    setFlat(true);//设置按钮透明
}
MyPushButton::~MyPushButton()
{

}
void MyPushButton::mousePressEvent(QMouseEvent *event)
{
    // 如果单击了就触发clicked信号
    if ( event->button() == Qt::LeftButton )
    {
        emit hadClicked(this);
    }
    // 将该事件传给父类处理
    QPushButton::mousePressEvent(event);
}
