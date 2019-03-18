#include "letterchoicepage.h"
#include "via.h"

LetterChoicePage::LetterChoicePage(QWidget *parent) : MyWidget(parent)
{
    background->setPixmap(QPixmap(picRoot+QString("/letter/letterChoice/background.jpg")));
}

