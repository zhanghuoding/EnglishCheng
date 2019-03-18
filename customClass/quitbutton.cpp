#include "quitbutton.h"
#include "customClass/tool.h""
#include "via.h"

QuitButton::QuitButton(QWidget *parent) : QPushButton(parent)
{
    setStatusTip(tr("&Quit"));
    //setText(tr("&Quit"));
    setIcon(QPixmap(picRoot+QString("/public/close.png")));
    setIconSize(Tool::size(68,68));
    setFixedSize(Tool::size(40,40));
    setFlat(true);//设置按钮透明
    setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20),-1,-1,-1,"#fee9c7","#fadcac","#f9d497"));
    setGeometry(Tool::rect(1532,12,40,40));
}
QuitButton* QuitButton::initQuitButton(QApplication *a)
{
    connect(this,SIGNAL(clicked()),(QObject*)a,SLOT(quit()));
    return this;
}
QuitButton::~QuitButton()
{

}
