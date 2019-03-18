#ifndef VOICEBUTTON_H
#define VOICEBUTTON_H

#include <QPushButton>
#include <QPixmap>


class VoiceButton : public QPushButton
{
    Q_OBJECT
public:
    explicit VoiceButton(QWidget *parent = 0);
    virtual ~VoiceButton();


signals:

public slots:
    void settingVoice();


private:
    bool phonic;//静音标志，当该值为假时，软件设置为静音，反之亦然
    QPixmap *trumpetPic;//音效开启时右上角音效管理按钮中的图片
    QPixmap *mutePic;//音效关闭时右上角音效管理按钮中的图片

};

#endif // VOICEBUTTON_H
