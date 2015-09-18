#include "game_mode.h"
#include "ui_game_mode.h"
#include <QDebug>
game_mode::game_mode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_mode)
{
    ui->setupUi(this);
}

game_mode::~game_mode()
{
    delete ui;
}

void game_mode::on_btn_ok_clicked()
{

}

void game_mode::on_comboBox_mode_currentTextChanged(const QString &arg1)
{
    mode = arg1;
    qDebug() << mode;
}
