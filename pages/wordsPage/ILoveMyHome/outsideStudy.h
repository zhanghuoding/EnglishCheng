#ifndef OUTSIDESTUDY_H
#define OUTSIDESTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class OutsideStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit OutsideStudy(QWidget *parent = 0);
    ~OutsideStudy();

protected:
    void init();

signals:

public slots:

};

#endif // OUTSIDESTUDY_H
