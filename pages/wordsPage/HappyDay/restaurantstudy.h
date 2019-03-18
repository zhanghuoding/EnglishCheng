#ifndef RESTAURANTSTUDY_H
#define RESTAURANTSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class RestaurantStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit RestaurantStudy(QWidget *parent = 0);
    ~RestaurantStudy();

protected:
    void init();

signals:

public slots:
    virtual void runPage(MyLabel *label=NULL, bool isEnter=false);
    virtual void startRepeat();//从第一个单词进行重复
    virtual void startLastWord(MyLabel *label=NULL,bool isEnter=false);//返回上一个单词
    virtual void startNextWord(MyLabel *label=NULL,bool isEnter=false);//进入下一个单词
    virtual void lastWord(MyLabel *label=NULL,bool isEnter=false);//返回上一个单词
    virtual void nextWord(MyLabel *label=NULL,bool isEnter=false);//进入下一个单词
};

#endif // RESTAURANTSTUDY_H
