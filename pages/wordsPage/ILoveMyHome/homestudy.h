#ifndef HOMESTUDY_H
#define HOMESTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class HomeStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit HomeStudy(QWidget *parent = 0);
    ~HomeStudy();

protected:
    void init();

signals:

public slots:

};

#endif // HOMESTUDY_H
