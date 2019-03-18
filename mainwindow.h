#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QPushButton>
#include<QApplication>
#include<QSize>
#include<QStackedWidget>
#include<QString>
#include<QStack>
#include<QWidget>

#include<vector>
#include<stack>

#include "customClass/quitbutton.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QWidget *creatPage(QString pageName,bool showFlag=true);//根据传入的类名创建类并默认显示页面，这些类就是运行中的各页界面
    void changePage(QString pageName="",int pageIndex=-1);//调整主界面显示下一个页面
    void addPage(QString pageName,QWidget *qwidget);//将新页面添加到stackedWidget,pageNameVector和pagePointerVector中
    void removePage(QString pageName,int pageIndex);//从stackedWidget,pageNameVector和pagePointerVector中删除页面
    void init(QApplication *qApplication);

private:
    QStackedWidget *stackedWidget;//浏览过程中的页面栈
    std::vector<QString> *pageNameVector;//存放已经被创建出来的各个页面的名字
    std::vector<QWidget*> *pagePointerVector;//存放已经被创建出来的各个页面的指针
    std::stack<int> *pageBrowsedHistroy;//主界面中的页面浏览历史栈，存放的是该页面在stackedWidget中的下标

    static QApplication *qApplication;
public slots:
    void enterLastPage();//返回操作时进入上一个页面

signals:
};

#endif // MAINWINDOW_H
