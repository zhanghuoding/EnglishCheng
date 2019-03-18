#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QQueue>
#include <QColor>

#include "customClass/key.h"
#include "via.h"


/*
 *本键盘中，默认是小写
 */

class KeyBoard : public QWidget
{
    Q_OBJECT
public:
    explicit KeyBoard(QWidget *parent = 0);
    ~KeyBoard();
    QLabel *getBackground();
    bool isOpen();//返回键盘是否被打开的标记
    keytype_ deKeyQueue();//获取键盘的输入队列中的下一个字符
    keytype_ keyGroup[3][9];//对键盘区域的分组，一共分为三组

    void convUpperLowerCase(bool flag);//根据传入的Bool值，转换键盘上显示的字符的大小写，当为真时是大写，否则小写
    bool isUpper();//返回当前键盘的大小写标记keyBoardIsUpperOrLower的值，true表示大写
    bool isResponse();//返回whetherResponse标记，表示键盘当前是否响应输入事件
    void openKeyBoard();//打开软键盘，并做相应设置
    void closeKeyBoard(bool needReset=true);//关闭软键盘，并做相应设置
    void setAllowedOpen(bool allowedOpen);//设置是否允许对键盘进行打开操作的标记allowedOpen的值
private :
    bool keyBoardIsUpperOrLower;//记录键盘当前是大写还是小写，true表示大写
    QLabel *background;//软键盘的背景
    bool open;//记录软键盘是否被打开的标记。true表示键盘已经被打开
    static unsigned clickNum;//记录键盘中当次单词时按键被点击的次数
    bool shiftIO;//上档键shift是否打开的标记，true时表示上档键已经打开，当前应输入的是大写字母。默认为false
    static QQueue<keytype_> *keyClickedQueue;//按过的键的队列
    Key *keys[30];//键盘上的30个按键
    keytype_ keyIndex[30];//键盘上30个按键在keys数组中对应的指针的下标
    keytype_ currentKeyType;//刚刚按过的键的值
    short clickedKeyGroupNum;//刚刚按过的键所在的键盘区域的组号
    QString *referString;//键盘中输入内容的参照单词
    QString *lastReferString;//键盘中上次输入的参照内容
    QString currentWord;//当前输入的单词
    QString lastCurrentWord;//上次输入的单词
    bool whetherResponse;//键盘是否响应输入事件。为true表示响应
    bool allowedOpen;//当前键盘是否允许进行打开操作的标记。当值为true时，允许打开

    Key *findKeyPointer(keytype_ keyType);//根据传入的按键的ASCII码值，找到对应的按键的指针
    void initKeys();//初始化键盘中的按键
    void initKeyGroup();//初始化键盘分组数组
    void setOpen(bool open);//设置键盘打开标记
    void increaseClickNum();//自增键盘中按键被点击的次数
    void setShiftIO();//反转shift标记
    void enKeyQueue(keytype_ keyType);//被whitchKeyClicked()槽函数调用，根据shiftIO的值，按大小写将按过的键入队列
    void putKeys();//摆放软键盘上的30个按键
    void setKeys(Key *k,int x,int y,int w, int h);//根据传入的值，设置对应按键在键盘中的位置以及尺寸
    void hiddenKeys();//从键盘上将所有按键移除，使其不显示
    void showKeys();//显示所有按键
    void setKeysParent(keytype_ keytype=0,QWidget *parent=0);//设置指定按键的父组件，省略参数时将所有按键父组件都设置为键盘
    bool accordPhraseReset;//设置根据该变量决定是否重置键盘。该变量为true时进行重置
    bool inputRemind;//是否进行输入提示的标记。当该值为真时，进行输入提示

    virtual void mousePressEvent ( QMouseEvent * event )Q_DECL_OVERRIDE;

signals:
    void enterKeyWasPressed();//当回车键被按下时，键盘发出此次信号
    void keyBoardOpened(QWidget *parent=0);//当键盘打开时，发出此信号
    void keyBoardClosed(bool needReset=true);//当键盘关闭时，发出此信号
public slots:
    void whitchKeyClicked(Key *key);//槽函数，监听键盘中被按下的按键
    void closeOrOpenKeyBoard(bool flag);//槽函数，监听并执行是否打开软键盘的信号，当flag为真时，打开软键盘
    void changeKeyColor(keytype_ keyNO, char *rgb1=KEY_BACKCOL_NORMAL,char *rgb2=KEY_BACKCOL_PRESSED,char *rgb3=KEY_BACKCOL_ENTER,bool setLastKeyColor=true);//根据传入的keyNO，设置对应按键的颜色为color
    void changeKeysColor(short groupNum, char *rgb1, char *rgb2, char *rgb3, char *rgb);//设置该组键的颜色为传入的颜色，传入的参数为该组键的组号
    void changeKeysColor();//重载的槽函数，接收信号，当单词输入完成的时候，设置所有按键的颜色为默认的颜色
    void setReferString(char *referString);//监听器，传入键盘输入单词过程中的正确的单词或词组
    void reset();//重置键盘中的所有参数
    void setWhetherResponse(bool flag=true);//设置键盘是否响应输入事件
    void setAccordPhraseReset(bool flag=true);//接收短语面板的信号，当短语面板打开时，该变量设置为false
    void setInputRemind(bool inputRemind);//设置是否进行输入提示的inputRemind标记
};

#endif // KEYBOARD_H
