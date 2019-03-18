#include "phrasepanel.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"
#include "via.h"

PhrasePanel::PhrasePanel(QWidget *parent) :
    QWidget(parent)
{
    background=new MyLabel(this);
    picLabel=new MyLabel(this);
    showPhraseLabel=new MyLabel(this);
    closeLabel=new MyLabel(this);
    tmpEnName=NULL;
    tmpChName=NULL;

    setFixedSize(Tool::size(632,592));
    setGeometry(Tool::rect(480,133,632,592));

    background->setPixmap(QPixmap(picRoot+QString("/public/phraseBackground.gif")));
    background->setFixedSize(Tool::size(632,592));
    background->setGeometry(Tool::rect(0,0,632,592));
    background->setVisible(true);


    showPhraseLabel->setFixedSize(Tool::size(480,100));
    showPhraseLabel->setGeometry(Tool::rect(76,10,480,100));
    QString str("QLabel{font-family:'Century Schoolbook';font-size:");
    str.append(QString::number(Tool::fontSize(phrasePanelFontSize)).toLatin1().data()).append("px;color:#000000;background-color:#ffffff;}");
    showPhraseLabel->setStyleSheet(str);
    showPhraseLabel->setText("");
    showPhraseLabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//设置输入的文本上下左右居中显示
    showPhraseLabel->setVisible(true);//设置显示该组件

    closeLabel->setFixedSize(Tool::size(30,30));
    closeLabel->setGeometry(Tool::rect(572,20,30,30));
    closeLabel->setPixmap(QPixmap(picRoot+QString("/public/cross.gif")));
    closeLabel->setVisible(true);

    picLabel->setFixedSize(Tool::size(480,414));
    picLabel->setGeometry(Tool::rect(76,134,480,414));
    picLabel->setVisible(true);//设置显示该组件

    connect(closeLabel,SIGNAL(clicked(MyLabel*,bool)),this,SLOT(closeThisPanel(MyLabel*,bool)));
}
PhrasePanel::~PhrasePanel()
{
    delete picLabel;
    delete showPhraseLabel;
    delete closeLabel;
    delete background;
}
void PhrasePanel::setPhrase(char *phrase)
{
    showPhraseLabel->setText(phrase);
}
void PhrasePanel::setPixmap(QPixmap pixmap)
{
    picLabel->setPixmap(pixmap);
}
void PhrasePanel::closeThisPanel(MyLabel *label,bool isEnter)
{
    Singleton<KeyBoard>::instance().setWhetherResponse(true);
    Singleton<KeyBoard>::instance().setAllowedOpen(true);//设置键盘可打开
    Singleton<KeyBoard>::instance().openKeyBoard();//打开键盘
    paper->setDoReset(true);//设置自此以后，“纸”对象可以被重置
    this->setVisible(false);
    reader->addTask(tmpEnName,tmpChName);//恢复之前正在播放的音频
    tmpEnName=NULL;//将指针置零
    tmpChName=NULL;
    emit setKeyBorderAccordReset(true);
    emit thisPanelClosed();
    emit inputRemind(false);
}
void PhrasePanel::openThisPanel(char *tmpEnName,char *tmpChName)
{
    this->tmpEnName=tmpEnName;
    this->tmpChName=tmpChName;
    paper->setDoReset(false);//设置自此以后“纸”对象不可以被重置
    Singleton<KeyBoard>::instance().setWhetherResponse(false);
    Singleton<KeyBoard>::instance().setAllowedOpen(false);//设置键盘不可打开
    Singleton<KeyBoard>::instance().closeKeyBoard(false);//关闭键盘，但是不重置键盘

    emit sendPanelText(showPhraseLabel->text().toLatin1().data());
    emit setKeyBorderAccordReset(false);
    emit inputRemind(true);

    this->setVisible(true);
}
