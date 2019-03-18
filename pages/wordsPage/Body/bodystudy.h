#ifndef BODYSTUDY_H
#define BODYSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class BodyStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit BodyStudy(QWidget *parent = 0);
    ~BodyStudy();

protected:
    void init();

signals:

public slots:

};

#endif // BODYSTUDY_H
