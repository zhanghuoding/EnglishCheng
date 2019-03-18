#ifndef FRUITANDVEGETABLESTUDY_H
#define FRUITANDVEGETABLESTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class FruitAndVegetableStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit FruitAndVegetableStudy(QWidget *parent = 0);
    ~FruitAndVegetableStudy();

protected:
    void init();

signals:

public slots:
    virtual void runPage(MyLabel *label=NULL, bool isEnter=false);

};

#endif // FRUITANDVEGETABLESTUDY_H
