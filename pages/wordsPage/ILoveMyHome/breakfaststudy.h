#ifndef BREAKFASTSTUDY_H
#define BREAKFASTSTUDY_H


#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class BreakfastStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit BreakfastStudy(QWidget *parent = 0);
    ~BreakfastStudy();

protected:
    void init();

signals:

public slots:

};

#endif // BREAKFASTSTUDY_H
