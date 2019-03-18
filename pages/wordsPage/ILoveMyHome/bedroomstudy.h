#ifndef BEDROOMSTUDY_H
#define BEDROOMSTUDY_H

#include "customClass/mystudypage.h"
#include "via.h"
#include "customClass/tool.h"

class BedroomStudy : public MyStudyPage
{
    Q_OBJECT
public:
    explicit BedroomStudy(QWidget *parent = 0);
    ~BedroomStudy();

protected:
    void init();

signals:

public slots:

};


#endif // BEDROOMSTUDY_H
