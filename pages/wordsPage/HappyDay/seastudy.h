#ifndef SEASTUDY_H
#define SEASTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class SeaStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit SeaStudy(QWidget *parent = 0);
    ~SeaStudy();

protected:
    void init();

signals:

public slots:

};
#endif // SEASTUDY_H
