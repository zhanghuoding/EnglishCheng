#ifndef CLOTHINGSTUDY_H
#define CLOTHINGSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class ClothingStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit ClothingStudy(QWidget *parent = 0);
    ~ClothingStudy();

protected:
    void init();

signals:

public slots:

};
#endif // CLOTHINGSTUDY_H
