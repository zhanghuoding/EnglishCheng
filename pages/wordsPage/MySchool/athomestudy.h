#ifndef ATHOMESTUDY_H
#define ATHOMESTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class AtHomeStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit AtHomeStudy(QWidget *parent = 0);
    ~AtHomeStudy();

protected:
    void init();

signals:

public slots:

};

#endif // ATHOMESTUDY_H
