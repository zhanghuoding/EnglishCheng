#ifndef INTERESTSTUDY_H
#define INTERESTSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class InterestStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit InterestStudy(QWidget *parent = 0);
    ~InterestStudy();

protected:
    void init();

signals:

public slots:

};

#endif // INTERESTSTUDY_H
