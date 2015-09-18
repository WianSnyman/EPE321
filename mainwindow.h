#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_host_clicked();
    void newConnection();
    void on_btn_clear_clicked();

    void on_btn_join_clicked();

    void on_txt_ip_port2_selectionChanged();

    void on_btn_move_clicked();

    void on_btn_attack_clicked();

    void on_btn_destroy_clicked();

    void on_btn_place_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *server;
    QTcpSocket *socket[3];
    QTcpSocket *client;
    int clients;
    QString ip_port;
    int turns;
};

#endif // MAINWINDOW_H
