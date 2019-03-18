#include "read.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>
#include <QTime>

Read::Read(QObject *parent) : QObject(parent)
{
    playerState=QMediaPlayer::StoppedState;
    player=new QMediaPlayer;
    sendSignal=true;//默认情况下，发出读完成的信号
    volume=100;
    loopFlag=true;//表示需要继续进行循环

    player->setVolume(volume);

    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(readerStateChanged(QMediaPlayer::State)));
    connect(&trigger,SIGNAL(finished()),this,SLOT(startNextAudio()));
    connect(this,SIGNAL(closeOrOpenKeyBoard(bool)),((KeyBoard*)(&Singleton<KeyBoard>::instance())),SLOT(closeOrOpenKeyBoard(bool)));
}
Read::~Read()
{
    if(player->state() !=QMediaPlayer::StoppedState)
        player->stop();
    delete player;
}
void Read::addTask(char *EnName,char *ChName)
{//每次传入两个文件名，分别为英文音频文件和中文音频文件名
    fileEnName.clear();
    fileEnName.append(EnName);

    fileChName.clear();
    fileChName.append(ChName);

    sendSignal=true;
    setMedia(QUrl::fromLocalFile(audioPath+fileChName+audioSuffix));
}
void Read::readerStateChanged(QMediaPlayer::State state)
{//当音频读完时，发送信号，信号参数为所读音频的名字

    playerState=state;//记录当前播放器的状态

    if(state==QMediaPlayer::StoppedState)
    {
        if(player->mediaStatus()==QMediaPlayer::EndOfMedia)
        {
            if(!sendSignal)
            {
                QString str(fileEnName.toLatin1().data());
                emit haveRead(str);
            }
        }else if(player->mediaStatus()==QMediaPlayer::InvalidMedia)
        {
            if(!sendSignal)
            {//如果英文语音文件没有找到，则不继续循环
                loopFlag=false;
            }
        }
        if(!loopFlag)
            return;//如果不继续循环，则不进行任何操作，直接返回

        trigger.start();//等待两秒后开始下一个文件的播放
    }
}
void Read::stop()
{
    setLoopFlag(false);//不再继续进行循环

    player->stop();

    fileEnName.clear();
    fileChName.clear();

}
void Read::setVolume(int volume)
{
    if(volume>100)
        this->volume=100;
    else
        this->volume=volume;
    player->setVolume(this->volume);
}
void Read::play()
{
    player->play();
}
void Read::setMedia(QUrl file)
{
    player->setMedia(file);
    play();//开始播放音频
}
void Read::startNextAudio()
{
    if(sendSignal)
    {//如果刚刚读过的是中文，则打开键盘
        sendSignal=false;
        emit closeOrOpenKeyBoard(true);//打开键盘
    }

    setMedia(QUrl::fromLocalFile(audioPath+fileEnName+audioSuffix));
}
void Read::startAudio(char *fileName)
{
    fileEnName.clear();
    fileEnName.append(fileName);
}
void Read::setLoopFlag(bool loopFlag)
{
    this->loopFlag=loopFlag;
}
QMediaPlayer::State Read::readerState()
{
    return playerState;
}
