#ifndef BUSSTUDY_H
#define BUSSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class BusStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit BusStudy(QWidget *parent = 0);
    ~BusStudy();

protected:
    void init();

signals:

public slots:

};

#endif // BUSSTUDY_H
