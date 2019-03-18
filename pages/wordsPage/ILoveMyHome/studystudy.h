#ifndef STUDYSTUDY_H
#define STUDYSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class StudyStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit StudyStudy(QWidget *parent = 0);
    ~StudyStudy();

protected:
    void init();

signals:

public slots:

};


#endif // STUDYSTUDY_H
