#ifndef PARKSTUDY_H
#define PARKSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class ParkStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit ParkStudy(QWidget *parent = 0);
    ~ParkStudy();

protected:
    void init();

signals:

public slots:

};

#endif // PARKSTUDY_H
