#include "dreamstudy.h"
#include "customClass/keyboard.h"
#include "Singleton/singleton.h"

#include <QDebug>

DreamStudy::DreamStudy(QWidget *parent) : MyStudyPage(parent)
{
    wordsNum=pageWordsNum("DreamStudy");

    if(nextPageName)
    {//设置下个页面的名字，在直接进入下个关卡时需要使用
        delete nextPageName;
        nextPageName=new QString("InterestStudy");
    }

    picPath=picRoot+QString("/words/words/MySchool/scene/dream/");

    background->setPixmap(QPixmap(picPath+QString("background.jpg")));

    girlLabel->setVisible(false);

    labels->at(0)->setFixedSize(Tool::size(100,180));
    labels->at(0)->setGeometry(Tool::rect(0,400,100,180));

    labels->at(1)->setFixedSize(Tool::size(400,300));
    labels->at(1)->setGeometry(Tool::rect(250,150,400,300));

    labels->at(2)->setFixedSize(Tool::size(200,180));
    labels->at(2)->setGeometry(Tool::rect(510,400,200,180));

    labels->at(3)->setFixedSize(Tool::size(220,180));
    labels->at(3)->setGeometry(Tool::rect(590,590,220,180));

    labels->at(4)->setFixedSize(Tool::size(200,240));
    labels->at(4)->setGeometry(Tool::rect(95,270,200,240));

    labels->at(5)->setFixedSize(Tool::size(400,300));
    labels->at(5)->setGeometry(Tool::rect(1020,540,400,300));

    labels->at(6)->setFixedSize(Tool::size(200,300));
    labels->at(6)->setGeometry(Tool::rect(820,340,200,300));

    labels->at(7)->setFixedSize(Tool::size(250,280));
    labels->at(7)->setGeometry(Tool::rect(180,560,250,280));

    labels->at(8)->setFixedSize(Tool::size(450,300));
    labels->at(8)->setGeometry(Tool::rect(1000,300,450,300));

    labels->at(9)->setFixedSize(Tool::size(200,250));
    labels->at(9)->setGeometry(Tool::rect(1100,340,200,250));

    sentenceLabel->setText("dream");

    wordsCard->setPixmap(QPixmap(picRoot+QString("/words/public/wordsCard.gif")));
    wordsCard->setSize(400,205,263,137);
    wordsCard->setGeometry(Tool::rect(700,50,400,205));

    init();
}
DreamStudy::~DreamStudy()
{

}
void DreamStudy::init()
{
    wordsPhrase=new chpotr[wordsNum]{
        {"","","home","家"},
        {"artist","艺术家","an artist","一位艺术家","artist.gif","artistBorder.gif","","","artistPra.png"},
        {"astronaut","宇航员","an astronaut","一位宇航员","astronaut.gif","astronautBorder.gif","","","astronautPra.png"},
        {"driver","司机","taxi driver","出租车司机","driver.gif","driverBorder.gif","","","driverPra.png"},
        {"pilot","飞行员","","","pilot.gif","pilotBorder.gif","","","pilotPra.png"},
        {"policeman","警察","","","policeman.gif","policemanBorder.gif","","","policemanPra.png"},
        {"singer","歌手","a singer","一名歌手","singer.gif","singerBorder.gif","","","singerPra.png"},
        {"vet","兽医","a vet","一名兽医","vet.gif","vetBorder.gif","","","vetPra.png"},
        {"clerk","职员","bank clerk","银行办事人员","clerk.gif","clerkBorder.gif","","","clerkPra.png"},
        {"farmer","农民","","","farmer.gif","farmerBorder.gif","","","farmerPra.png"},
        {"worker","工人","a worker","一名农场工人","worker.gif","workerBorder.gif","","","workerPra.png"}
    };
}

