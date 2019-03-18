#ifndef READ_H
#define READ_H

#include <QObject>
#include <QMediaPlayer>
#include <QUrl>

#include "customClass/triggerthread.h"

class Read : public QObject
{
    Q_OBJECT
public:
    explicit Read(QObject *parent = 0);
    ~Read();
    void addTask(char *EnName,char *ChName);//通过这个函数将需要进行诵读的文件名传送过来（文件名中不包括后缀名）
    QMediaPlayer::State readerState();//获取当前播放器的状态
private:
    QMediaPlayer::State playerState;//记录当前的播放状态
    QMediaPlayer *player;//播放器
    QString fileEnName;//目前需要播放的英文音频文件的名字
    QString fileChName;//目前需要播放的中文音频文件的名字
    bool sendSignal;//标记是否重读刚才的音频文件，以及是否在这次读完之后，发出读完成的信号
    int volume;//播放器的音量
    TriggerThread_1 trigger;//用来使播放器每隔一秒，重复播放文件的触发器
    bool loopFlag;//用于标记是否需要继续循环的标志，当该值为false时，不继续循环
signals:
    void closeOrOpenKeyBoard(bool flag);//当第一次读完成之后，发出信号，以打开键盘进行相关输入操作
    void haveRead(QString referString);//每读完一遍的时候，将刚刚读完的词句广播出去

public slots:
    void readerStateChanged(QMediaPlayer::State state);//监听播放器的状态
    void stop();//结束播放
    void setVolume(int volume);//设置媒体音量
    void play();//开始播放
    void setMedia(QUrl file);//设置待播放文件
    void startNextAudio();//接收trigger触发器完成的信号，使播放器播放下一个文件
    void startAudio(char *fileName);//用于开始播放新传入的文件名所指向的文件
    void setLoopFlag(bool loopFlag);//设置是否继续进行循环播放的标记
};

#endif // READ_H
