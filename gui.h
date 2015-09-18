#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QDebug>
#include <QInputDialog>
#include <QComboBox>
#include "game_mode.h"
namespace Ui {
class GUI;
}

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = 0);
    ~GUI();

private slots:
    void reinit();
private:
    Ui::GUI *ui;
    int boardStat[6][5];
    QString selected_mode;
    game_mode options;
};

#endif // GUI_H
