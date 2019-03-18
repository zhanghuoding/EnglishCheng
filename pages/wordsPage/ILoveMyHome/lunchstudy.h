#ifndef LUNCHSTUDY_H
#define LUNCHSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class LunchStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit LunchStudy(QWidget *parent = 0);
    ~LunchStudy();

protected:
    void init();

signals:

public slots:

};

#endif // LUNCHSTUDY_H
