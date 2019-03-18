#include "letterfightchoicepage.h"
#include "via.h"

LetterFightChoicePage::LetterFightChoicePage(QWidget *parent) : MyWidget(parent)
{
    background->setPixmap(QPixmap(picRoot+QString("/letter/fightChoice/background.jpg")));
}

