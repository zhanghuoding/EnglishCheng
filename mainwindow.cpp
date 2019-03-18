#include "mainwindow.h"
#include "customClass/tool.h"
#include "customClass/mywidget.h"
#include "via.h"
#include "pages/home.h"
#include "customClass/voicebutton.h"
#include "customClass/backbutton.h"
#include "customClass/quitbutton.h"
#include "Singleton/singleton.h"
#include "customClass/keyboard.h"
#include "customClass/mystudypage.h"

#include <QDesktopWidget>
#include <QSize>

#include <iterator>
#include <vector>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
}
MainWindow::~MainWindow()
{

}
void MainWindow::init(QApplication *qApplication)
{
    this->resize(*screenSize);
    this->setMaximumSize(*screenSize);
    this->setMaximumSize(*screenSize);
    this->setFixedSize(*screenSize);
    this->setWindowFlags(Qt::FramelessWindowHint);//取消窗口标题栏

    stackedWidget=new QStackedWidget;
    pageNameVector=new std::vector<QString>;
    pagePointerVector=new std::vector<QWidget*>;
    pageBrowsedHistroy=new std::stack<int>;

    this->creatPage("Home",true);
    this->setCentralWidget(stackedWidget);
}

void MainWindow::changePage(QString pageName,int pageIndex)
{//本函数根据传入的页面名称，进行页面的跳转
    if( (pageName==NULL || pageName.isEmpty()) && pageIndex<0 )
        return;//如果参数全部不可用，则返回

    int k=pageNameVector->size();
    if(pageIndex<0)
        for(pageIndex=0;pageIndex<k;pageIndex++)
        {
            if(pageNameVector->at(pageIndex).compare(pageName)==0)
                break;
        }

    if(pageIndex>=k)
        return;//如果该页面还没有被创建，则函数执行不成功,返回
    else
    {
        MyWidget *tmp=(MyWidget*)(pagePointerVector->at(pageIndex));

        if(!tmp)
            return;//如果页面指针为空，则函数返回

        tmp->init(stackedWidget);//对于需要在主框架下显示的页面，每张都设置它们的父组件为stackedWidget

        pageName=pageNameVector->at(pageIndex);
        if(!pageName.contains("selcectBarr",Qt::CaseInsensitive))
        {//当页面不是关卡选择页面的话，就添加退出和关闭音效按钮

            //对于不同类型的页面，音效控制按钮的位置是不同的
            ((QPushButton*)(&Singleton<VoiceButton>::instance()))->setParent(tmp);
            ((QPushButton*)(&Singleton<VoiceButton>::instance()))->setGeometry(Tool::rect(1487,12,40,40));

            ((QPushButton*)(&Singleton<QuitButton>::instance()))->setParent(tmp);
            if(pageIndex!=0)
            {//首页面不用加返回按钮，其他页面都要加返回按钮
                ((QPushButton*)(&Singleton<BackButton>::instance()))->setParent(tmp);
            }
        }
        if(pageName.contains("study",Qt::CaseInsensitive))
        {//当页面是学习页面的话，就添加键盘和输入框
            KeyBoard* k=((KeyBoard*)(&Singleton<KeyBoard>::instance()));
            k->setParent(tmp);
            k->setVisible(true);
            k->setAccordPhraseReset(true);//允许进行重置
            k->closeOrOpenKeyBoard(false);//无论软键盘之前是打开的还是关闭的，都关闭软键盘

            //设置在学习页面，音效控制按钮的位置
            ((QPushButton*)(&Singleton<VoiceButton>::instance()))->setGeometry(Tool::rect(1372,12,40,40));
            ((MyStudyPage*)tmp)->setLabelVisibleFalse();//移除页面上的组件
            ((MyStudyPage*)tmp)->reset();//对页面中的参数进行重置
            ((MyStudyPage*)tmp)->getTriggerThread()->start();//启动页面中的触发器，使页面自动运行起来，开始页面中的第一个单词
        }

        pageBrowsedHistroy->push(pageIndex);
        stackedWidget->setCurrentIndex(pageIndex);
    }
}
QWidget *MainWindow::creatPage(QString pageName,bool showFlag)
{//根据传入的类名，创建新的页面，默认创建后显示该页面
    if(pageName.isEmpty())
    {
        Tool::showDialog();//显示提示信息
        return NULL;//如果新的类名为空，则不创建页面，并返回空
    }
    if(pageName.compare("over",Qt::CaseInsensitive)==0)
    {
        return NULL;
    }

    int pageIndex=0,k=pageNameVector->size();
    for(pageIndex=0;pageIndex<k;pageIndex++)
    {
        if(pageNameVector->at(pageIndex).compare(pageName)==0)
            break;
    }
    if(pageIndex<k)
    {//如果该页面已经被创建，则无需创建，只需要显示该页面即可
        if(showFlag)
            changePage(pageName,pageIndex);
        return pagePointerVector->at(pageIndex);
    }

    //如果该页面还没有被创建，则创建并显示该页面
    QWidget *tmp=(QWidget*)Tool::creatClassByStringWithSingleton(pageName);
    if(tmp==NULL)
        return NULL;//如果创建不成功，则返回空

    //如果创建成功，则将该对象放入页面数组，并且加入QWidget栈中
    this->addPage(pageName,tmp);
    if(showFlag)
    {
        pageIndex=pageNameVector->size()-1;
        changePage(pageName,pageIndex);
    }
    return tmp;
}
void MainWindow::enterLastPage()
{//该函数为槽函数，被调用时，显示上次访问的页面
    if(reader->readerState() != QMediaPlayer::StoppedState)
    {//如果阅读器还在继续读，则停止读音
        reader->stop();
    }
    int num=pageBrowsedHistroy->size();
    if(num>1)
    {//当栈中的页面数量大于1时，才能进入上页，否则，不能进入上页。
        pageBrowsedHistroy->pop();
        int i=pageBrowsedHistroy->top();
        pageBrowsedHistroy->pop();
        changePage("",i);
    }
}
void MainWindow::addPage(QString pageName, QWidget *qwidget)
{
    if(pageName==NULL || pageName.isEmpty())
        return;//待插入页面名字不能为空

    pageNameVector->push_back(pageName);
    pagePointerVector->push_back(qwidget);
    stackedWidget->addWidget(qwidget);
}

void MainWindow::removePage(QString pageName, int pageIndex)
{
    if(pageName==NULL || pageName.isEmpty())
        return;//待删除页面名字不能为空

    if(pageNameVector->at(pageIndex).compare(pageName)!=0)
        return;//页面名字和下标要一致，才进行删除操作

    int i=0;
    std::vector<QString>::iterator it1=pageNameVector->begin();
    for(i=0;i<pageIndex;i++)
        it1++;
    pageNameVector->erase(it1);
    std::vector<QWidget*>::iterator it2=pagePointerVector->begin();
    for(i=0;i<pageIndex;i++)
        it2++;
    pagePointerVector->erase(it2);
    QWidget *tmp=stackedWidget->widget(pageIndex);
    stackedWidget->removeWidget(tmp);

    delete tmp;
}
