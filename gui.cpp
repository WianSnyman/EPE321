#include "gui.h"
#include "ui_gui.h"
#include "game_mode.h"
GUI::GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
    //
    //options.show();
    //options.setFocus();
    //selected_mode = options.mode;
    //qDebug() << selected_mode;
    //
    reinit();
}

GUI::~GUI()
{
    delete ui;
}

void GUI::reinit()
{
    ui->action_move->setIcon(QIcon("move.png"));
    ui->action_attack->setIcon(QIcon("attack.png"));
    ui->action_destroy->setIcon(QIcon("destroy.png"));

    QList<QPushButton *> all_btns = this->findChildren<QPushButton *>();
    qDebug() << all_btns.size();
    for (int i = 0; i < all_btns.size(); ++i)
    {
        if(all_btns.at(i)->objectName().operator ==("action_attack")
                ||
           all_btns.at(i)->objectName().operator ==("action_move")
                ||
           all_btns.at(i)->objectName().operator ==("action_destroy")
                ||
           all_btns.at(i)->objectName().operator ==("action_end_turn")
                ||
           all_btns.at(i)->objectName().operator ==("action_end_place")
                ||
           all_btns.at(i)->objectName().operator ==("btn_host")
                ||
           all_btns.at(i)->objectName().operator ==("btn_join"))
        {

        }else
        {
            all_btns.at(i)->setStyleSheet("border:2px solid #000000;background-color: rgb(153,204,255);");
            //ui->buttonGroup->addButton(all_btns.at(i),i);
        }
    }
}
