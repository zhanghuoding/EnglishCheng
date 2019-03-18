#ifndef QUITBUTTON_H
#define QUITBUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QApplication>

class QuitButton : public QPushButton
{
    Q_OBJECT
public:
    QuitButton(QWidget *parent=0);
    ~QuitButton();
    QuitButton *initQuitButton(QApplication *a);
};

#endif // QUITBUTTON_H
