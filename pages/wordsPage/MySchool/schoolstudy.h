#ifndef SCHOOLSTUDY_H
#define SCHOOLSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class SchoolStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit SchoolStudy(QWidget *parent = 0);
    ~SchoolStudy();

protected:
    void init();

signals:

public slots:

};

#endif // SCHOOLSTUDY_H
