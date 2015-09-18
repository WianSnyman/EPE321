#ifndef GAME_MODE_H
#define GAME_MODE_H

#include <QWidget>

namespace Ui {
class game_mode;
}

class game_mode : public QWidget
{
    Q_OBJECT

public:
    explicit game_mode(QWidget *parent = 0);
    ~game_mode();
    QString mode;

private slots:
    void on_btn_ok_clicked();

    void on_comboBox_mode_currentTextChanged(const QString &arg1);

private:
    Ui::game_mode *ui;    

};

#endif // GAME_MODE_H
