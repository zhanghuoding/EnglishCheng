#ifndef FORESTSTUDY_H
#define FORESTSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class ForestStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit ForestStudy(QWidget *parent = 0);
    ~ForestStudy();

protected:
    void init();

signals:

public slots:

};

#endif // FORESTSTUDY_H
