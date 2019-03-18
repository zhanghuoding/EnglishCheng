#ifndef DREAMSTUDY_H
#define DREAMSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class DreamStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit DreamStudy(QWidget *parent = 0);
    ~DreamStudy();

protected:
    void init();

signals:

public slots:

};

#endif // DREAMSTUDY_H
