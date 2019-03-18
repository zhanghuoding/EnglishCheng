#ifndef DINNERSTUDY_H
#define DINNERSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class DinnerStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit DinnerStudy(QWidget *parent = 0);
    ~DinnerStudy();

protected:
    void init();

signals:

public slots:

};
#endif // DINNERSTUDY_H
