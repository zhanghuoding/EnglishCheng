#include "key.h"
#include "customClass/tool.h"
#include "via.h"

#include <QString>

Key::Key(keytype_ typeOfKey, QWidget *parent) :
    QPushButton(parent)
{
    this->typeOfKey=typeOfKey;
    defaultColor=new QColor(255,255,255);

    setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(6),-1,-1,-1,
                                                   KEY_BACKCOL_NORMAL,KEY_BACKCOL_ENTER,KEY_BACKCOL_PRESSED,KEY_FONT_COLOR,keyBorderFontSize));

    connect(this,SIGNAL(clicked(bool)),this,SLOT(sendClickedSignal()));
}
Key::~Key()
{

}
keytype_ Key::getTypeOfKey()
{
    return typeOfKey;
}
void Key::setBackGroundColor(char *rgb1, char *rgb2, char *rgb3, char *rgb)
{
    setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(6),-1,-1,-1,rgb1,rgb2,rgb3,rgb,keyBorderFontSize));
}
void Key::setSize(QSize size)
{
    setMaximumSize(size);
    setMinimumSize(size);
    setFixedSize(size);
}
void Key::sendClickedSignal()
{
    emit clickedSignal(this);
}
