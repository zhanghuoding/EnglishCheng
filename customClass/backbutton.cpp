#include "backbutton.h"
#include "Singleton/singleton.h"
#include "mainwindow.h"
#include "via.h"

BackButton::BackButton(QWidget* parent) : QPushButton(parent)
{
    setStatusTip(tr("&Back"));
    //setText(tr("&Back"));
    setIcon(QPixmap(picRoot+QString("/public/back.png")));
    setIconSize(Tool::size(80,80));
    setFixedSize(Tool::size(60,60));
    setFlat(true);//设置按钮透明
    setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(30),-1,-1,-1,"#f7f1cd","#f9ea91","#f5ebb1"));
    setGeometry(Tool::rect(1492,825,60,60));

    connect(this,SIGNAL(clicked(bool)),& Singleton<MainWindow>::instance(),SLOT(enterLastPage()));
}
BackButton::~BackButton()
{

}
