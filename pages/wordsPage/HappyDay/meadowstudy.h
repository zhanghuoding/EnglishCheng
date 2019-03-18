#ifndef MEADOWSTUDY_H
#define MEADOWSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class MeadowStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit MeadowStudy(QWidget *parent = 0);
    ~MeadowStudy();

protected:
    void init();

signals:

public slots:

};

#endif // MEADOWSTUDY_H
