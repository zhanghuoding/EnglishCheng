#include "wordscard.h"

WordsCard::WordsCard(QWidget *parent) :
    QWidget(parent)
{

    wordsCardLabel=new MyLabel(this);
    showWordsLabel=new MyLabel(this);

    setFixedSize(Tool::size(350,180));
    setGeometry(Tool::rect(1150,250,350,180));

    showWordsLabel->setFixedSize(Tool::size(230,120));
    showWordsLabel->setGeometry(Tool::rect(15,10,230,120));
    QString str("QLabel{font-family:'Century Schoolbook';font-size:");
    str.append(QString::number(Tool::fontSize(wordsCardFontSize)).toLatin1().data()).append("px;color:#000000;background-color:#ffffff;}");
    showWordsLabel->setStyleSheet(str);
    showWordsLabel->setText("");
    showWordsLabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//设置输入的文本上下左右居中显示
    showWordsLabel->setVisible(true);//设置显示该组件

    wordsCardLabel->setFixedSize(Tool::size(350,180));
    wordsCardLabel->setGeometry(Tool::rect(0,0,350,180));
    wordsCardLabel->setVisible(true);//设置显示该组件
}
WordsCard::~WordsCard()
{
    delete wordsCardLabel;
    delete showWordsLabel;
}
void WordsCard::setWords(char *referString)
{
    showWordsLabel->setText(referString);
}
void WordsCard::setPixmap(QPixmap pixmap)
{
    wordsCardLabel->setPixmap(pixmap);
}
void WordsCard::close()
{
    showWordsLabel->setText("");
}
void WordsCard::setSize(int bw, int bh, int pw, int ph)
{
    setFixedSize(Tool::size(bw,bh));
    setGeometry(Tool::rect(1150,250,bw,bh));

    showWordsLabel->setFixedSize(Tool::size(pw,ph));
    showWordsLabel->setGeometry(Tool::rect(15,10,pw,ph));

    wordsCardLabel->setFixedSize(Tool::size(bw,bh));
    wordsCardLabel->setGeometry(Tool::rect(0,0,bw,bh));
}
