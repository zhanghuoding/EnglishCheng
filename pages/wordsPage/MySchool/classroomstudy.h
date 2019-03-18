#ifndef CLASSROOMSTUDY_H
#define CLASSROOMSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class ClassroomStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit ClassroomStudy(QWidget *parent = 0);
    ~ClassroomStudy();

protected:
    void init();

signals:

public slots:

};

#endif // CLASSROOMSTUDY_H
