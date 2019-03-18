#ifndef LIVINGROOMSTUDY_H
#define LIVINGROOMSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class LivingRoomStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit LivingRoomStudy(QWidget *parent = 0);
    ~LivingRoomStudy();

protected:
    void init();

signals:

public slots:
};
#endif // LIVINGROOMSTUDY_H
