#include "happyday.h"
#include "mainwindow.h"
#include "Singleton/singleton.h"

HappyDay::HappyDay(QWidget *parent) : MyWidget(parent)
{
    background->setPixmap(QPixmap(picRoot+QString("/words/words/HappyDay/background.jpg")));

    button1->setIcon(QPixmap(picRoot+QString("/words/words/HappyDay/icon(colours)/meadow.png")));
    button1->setIconSize(Tool::size(350,350));
    button1->setFixedSize(Tool::size(300,300));
    button1->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(150),-1,-1,-1,"#cdffff","#cdffff","#cdffff"));
    button1->setObjectName(QString("MeadowStudy"));
    button1->setVisible(true);
    button1->setGeometry(Tool::rect(165,230,300,300));

    button2->setIcon(QPixmap(picRoot+QString("/words/words/HappyDay/icon(colours)/grassland.png")));
    button2->setIconSize(Tool::size(350,350));
    button2->setFixedSize(Tool::size(290,290));
    button2->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(145),-1,-1,-1,"#cdffff","#cdffff","#cdffff"));
    button2->setObjectName(QString("GrasslandStudy"));
    button2->setVisible(true);
    button2->setGeometry(Tool::rect(270,500,290,290));

    button3->setIcon(QPixmap(picRoot+QString("/words/words/HappyDay/icon(colours)/forest.png")));
    button3->setIconSize(Tool::size(360,360));
    button3->setFixedSize(Tool::size(300,300));
    button3->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(150),-1,-1,-1,"#cdffff","#cdffff","#cdffff"));
    button3->setObjectName("ForestStudy");
    button3->setVisible(true);
    button3->setGeometry(Tool::rect(450,305,300,300));

    button4->setIcon(QPixmap(picRoot+QString("/words/words/HappyDay/icon(colours)/restaurant.png")));
    button4->setIconSize(Tool::size(350,350));
    button4->setFixedSize(Tool::size(330,330));
    button4->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(165),-1,-1,-1,"#cdffff","#cdffff","#cdffff"));
    button4->setObjectName("RestaurantStudy");
    button4->setVisible(true);
    button4->setGeometry(Tool::rect(740,225,330,330));

    button5->setIcon(QPixmap(picRoot+QString("/words/words/HappyDay/icon(colours)/park.png")));
    button5->setIconSize(Tool::size(330,330));
    button5->setFixedSize(Tool::size(260,260));
    button5->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(130),-1,-1,-1,"#cdffff","#cdffff","#cdffff"));
    button5->setObjectName("ParkStudy");
    button5->setVisible(true);
    button5->setGeometry(Tool::rect(710,480,260,260));

    button6->setIcon(QPixmap(picRoot+QString("/words/words/HappyDay/icon(colours)/sea.png")));
    button6->setIconSize(Tool::size(270,270));
    button6->setFixedSize(Tool::size(210,210));
    button6->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(105),-1,-1,-1,"#cdffff","#cdffff","#cdffff"));
    button6->setObjectName("SeaStudy");
    button6->setVisible(true);
    button6->setGeometry(Tool::rect(940,580,210,210));

    button7->setIcon(QPixmap(picRoot+QString("/words/words/HappyDay/icon(colours)/clothingShop.png")));
    button7->setIconSize(Tool::size(280,280));
    button7->setFixedSize(Tool::size(240,240));
    button7->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(120),-1,-1,-1,"#cdffff","#cdffff","#cdffff"));
    button7->setObjectName("ClothingStudy");
    button7->setVisible(true);
    button7->setGeometry(Tool::rect(1150,580,240,240));

    button8->setIcon(QPixmap(picRoot+QString("/words/words/HappyDay/icon(colours)/fruitAndVegetable.png")));
    button8->setIconSize(Tool::size(380,380));
    button8->setFixedSize(Tool::size(360,360));
    button8->setStyleSheet(Tool::styleSheetNormalAndPressed(Tool::width(180),-1,-1,-1,"#cdffff","#cdffff","#cdffff"));
    button8->setObjectName("FruitAndVegetableStudy");
    button8->setVisible(true);
    button8->setGeometry(Tool::rect(1080,250,360,360));
}
HappyDay::~HappyDay()
{

}
