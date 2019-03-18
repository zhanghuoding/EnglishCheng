#ifndef GRASSLANDSTUDY_H
#define GRASSLANDSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class GrasslandStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit GrasslandStudy(QWidget *parent = 0);
    ~GrasslandStudy();

protected:
    void init();

signals:

public slots:

};

#endif // GRASSLANDSTUDY_H
