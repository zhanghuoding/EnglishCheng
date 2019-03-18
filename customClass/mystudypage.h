#ifndef MYSTUDYPAGE_H
#define MYSTUDYPAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QList>
#include <QStack>

#include "customClass/mylabel.h"
#include "via.h"
#include "typestruct.h"
#include "customClass/tool.h"
#include "customClass/mypushbutton.h"
#include "customClass/triggerthread.h"
#include "customClass/wordscard.h"
#include "customClass/phrasepanel.h"

class MyStudyPage : public QWidget
{
    Q_OBJECT
public:
    explicit MyStudyPage(QWidget *parent = 0);
    virtual ~MyStudyPage();

protected:
    QLabel *background;//每个页面中的背景图片
    TriggerThread triggerThread;//每个页面中的触发器，使页面自动运行起来，开始页面中的第一个单词

    chpotr *wordsPhrase;//每个页面中将要学习的单词和对应的句子的数组，该数组0号位置上存放的是本页面中的总结性短语以及翻译
    unsigned short wordsNum;//每个页面中所要学习的单词的数量
    unsigned short currentWord;//当前正在学习的单词在wordsPhrase数组中的下标

    QList<MyLabel*> *labels;//所有label的对象列表

    MyLabel *girlLabel;
    MyLabel *lastWordLabel;
    MyLabel *nextWordLabel;
    MyLabel *sentenceLabel;
    WordsCard *wordsCard;//单词版
    MyPushButton *nextBarrButton;
    MyPushButton *repeatButton;
    PhrasePanel *phrasePanel;

    MyLabel *additionalLabel1;//附件标签
    MyLabel *additionalLabel2;
    MyLabel *additionalLabel3;

    short labelCounter;//目前已经显示了的label的计数器
    short wordsPicCounter;//由于每个单词可能有多于一个图片，该变量用于记录每个单词已经显示的图片数量
    MyLabel *tmpLabel1;//在进行动作的时候，这两个变量用于存储当前的单词所涉及的label的指针
    MyLabel *tmpLabel2;
    QStack<ptrPair*> *learnedHistory;//学过的单词的图片显示历史
    QString picPath;//每个页面中的图片资源的相对路径
    char *tmpEnName;//暂存刚刚添加到reader中的英文文件名
    char *tmpChName;//暂存刚刚添加到reader中的中文文件名
    bool processFlag;//用于记录当前到了哪个阶段。未显示描边的图片，值为false，显示了描边图片，值为true，显示了正常图片，值为false
    short tableNum;//用于从labels列表的尾部向头部指引

    MyLabel *getLabelAt(int index);//返回labels中的指定下标处的label的指针，如果越界，则返回空
    virtual void init()=0;//这个函数中对每个页面中的单词的情况进行初始化
    QString *nextPageName;//下一个关卡页面的名字
    QString hasEntered;//已经输对了的单词存放的地方
public:
    virtual QLabel *getBackgroundLabel();
    virtual char *getString(unsigned short index,char *name);//根据传入的下标值和要取的类型名称，从wordsPhrase传出指针
    virtual short getDigit(unsigned short index,char *name);//根据传入的下标值和要取的类型名称，从wordsPhrase传出数值
    virtual TriggerThread *getTriggerThread();//获取本对象中的trigger对象的指针
    PhrasePanel *getPhrasePanel();

signals:
    void sendReferString(char *referString);//发出信号，修改键盘对象中保存的参照字符串
    void enterKeyWasPressed(MyLabel *label=NULL, bool isEnter=false);//该信号用来转发回车键被按下的信号
public slots:
    virtual void startPage();//每个页面刚开始的时候，都通过这个槽函数接收trigger线程发出的开始信号
    virtual void runPage(MyLabel *label=NULL, bool isEnter=false);

    virtual void startLastWord(MyLabel *label=NULL,bool isEnter=false);//返回上一个单词
    virtual void startNextWord(MyLabel *label=NULL,bool isEnter=false);//进入下一个单词
    virtual void startSentence(MyLabel *label=NULL,bool isEnter=false);//左上角的句子
    virtual void startRepeat();//从第一个单词进行重复
    virtual void startNextBarr();//进入下一个关卡

    virtual void whetherEnterKeyWasPressed();//接收键盘中的回车键被按下的信号
    virtual void setLabelVisibleFalse();//设置所有label不可见
    virtual void reset();//对页面参数进行重置
    virtual void cleanLabelsIsClickedOutside();//清除组件们的被点击标记
    virtual void setLabelVisibleTrue();//设置所有label可见
    virtual void reSendReferString();//重新发送当前所学的单词，该槽用于接收短语面板发出的短语面板已关闭的信号
};

#endif // MYSTUDYPAGE_H
