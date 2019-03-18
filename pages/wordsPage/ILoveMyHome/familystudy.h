#ifndef FAMILYSTUDY_H
#define FAMILYSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class FamilyStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit FamilyStudy(QWidget *parent = 0);
    ~FamilyStudy();

protected:
    void init();

signals:

public slots:

};


#endif // FAMILYSTUDY_H
