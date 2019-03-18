#ifndef KITCHENSTUDY_H
#define KITCHENSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class KitchenStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit KitchenStudy(QWidget *parent = 0);
    ~KitchenStudy();

protected:
    void init();

signals:

public slots:

};

#endif // KITCHENSTUDY_H
