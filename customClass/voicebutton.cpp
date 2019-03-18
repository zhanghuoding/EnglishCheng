#include "voicebutton.h"

#include "customClass/control.h"
#include "via.h"
#include "customClass/tool.h"

VoiceButton::VoiceButton(QWidget *parent) : QPushButton(parent)
{
    phonic=true;

    trumpetPic=new QPixmap(picRoot+QString("/public/trumpet.png"));
    mutePic=new QPixmap(picRoot+QString("/public/mute.png"));

    setStatusTip(tr("&Voice"));
    //setText(tr("&Voice"));
    setIcon(*trumpetPic);
    setIconSize(Tool::size(43,43));
    setFixedSize(Tool::size(40,40));
    setFlat(true);//设置按钮透明
    setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(20),-1,-1,-1,"#fee9c7","#fadcac","#f9d497"));

    connect(this,SIGNAL(clicked()),(VoiceButton*)this,SLOT(settingVoice()));
}
VoiceButton::~VoiceButton()
{
    delete trumpetPic;
    delete mutePic;
}
void VoiceButton::settingVoice()
{
    if(phonic)
    {//当软件音效已经开启时，关闭音效，改变背景图片
        setStatusTip(tr("&mute"));
        setIcon(*mutePic);

        Control::settingVoice(false);//关闭音效

        phonic=false;
    }else
    {//当软件音效还没有开启时，开启软件音效，并改变背景图片
        setStatusTip(tr("&Phonic"));
        setIcon(*trumpetPic);
        Control::settingVoice(true);//开启音效

        phonic=true;
    }
}
