#ifndef PHRASEPANEL_H
#define PHRASEPANEL_H

#include <QWidget>
#include <QPixmap>

#include "customClass/mylabel.h"
#include "customClass/tool.h"

class PhrasePanel : public QWidget
{
    Q_OBJECT
public:
    explicit PhrasePanel(QWidget *parent = 0);
    ~PhrasePanel();

private:
    MyLabel *showPhraseLabel;
    MyLabel *picLabel;
    MyLabel *closeLabel;
    MyLabel *background;
    char *tmpEnName;//这两个变量用来在使用closeThisPanel函数关闭该面板时，使reader继续在打开该面板之前进行的音频的播放
    char *tmpChName;//这两个变量的值，由openThisPanel函数在打开该面板时设置

signals:
    void thisPanelClosed();//发出信号，说明自己已经关闭了
    void sendPanelText(char *text);//在打开面板的时候，发出自己面板中当前显示的的字符串
    void setKeyBorderAccordReset(bool flag);//由键盘对象接收该信号，设置键盘是否进行重置操作，在键盘打开或关闭的时候发出该信号
    void inputRemind(bool remind);//发出信号，表明从现在开始，键盘输入的时候需要提示。在该面板打开的时候发送该信号
public slots:
    virtual void setPhrase(char *phrase);
    virtual void setPixmap(QPixmap pixmap);
    virtual void closeThisPanel(MyLabel *label=NULL,bool isEnter=false);//接收closeLabel的点击信号，关闭自己
    virtual void openThisPanel(char *tmpEnName,char *tmpChName);//设置显示该组件，并设置键盘不再响应输入事件

};

#endif // PHRASEPANEL_H
