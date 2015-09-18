#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txt_ip_port2->setText("Format: xxx.xxx.xxx.xxx::port");
    client = new QTcpSocket();
    turns = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_host_clicked()
{
    //prevent from join button being clicked
    ui->btn_join->setEnabled(false);
    //

    server = new QTcpServer(this);

    connect(server,SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any,9999))
    {
        ui->txt_net_log->append("Server could not start");
    }
    else
    {
        ui->txt_net_log->append("Server started");
        QHostAddress add;
        QTcpSocket sock;
        sock.connectToHost("www.google.co.za", 80); // google DNS, or something else reliable
        if (sock.waitForConnected())
        {
            add = sock.localAddress();
        }
        QString ip = add.toString();
        ui->txt_ip_port->setText(ip.append("::9999"));
    }
    clients = 0;
}

void MainWindow::newConnection()
{
    if(server->hasPendingConnections()&& clients < 4)
    {
        if(clients < 3)
        {
            socket[clients] = server->nextPendingConnection();
            socket[clients]->write("hello client \r\n");
            socket[clients]->flush();
            //wait for write
            //socket[clients]->waitForBytesWritten(3000);
        }
        else
        {
            socket[clients] = server->nextPendingConnection();
            socket[clients]->write("Server full! \r\n");
            socket[clients]->flush();
            socket[clients]->close();
            clients --;
        }
        clients ++;
    }
}

void MainWindow::on_btn_clear_clicked()
{
    ui->txt_net_log->clear();
}

void MainWindow::on_btn_join_clicked()
{
    //prevent from host button being clicked
    ui->btn_host->setEnabled(false);
    //

    ip_port = ui->txt_ip_port2->text();
    ui->txt_net_log->append(ip_port);
    QStringList ip = ip_port.split("::");
    QString port = ip.at(1);
    int port_num = port.toInt();
    client->connectToHost(ip.at(0),port_num);
    if(client->waitForConnected(5000))
    {
        qDebug() << "Connected";

        //send
        client->write("Hello server\r\n\r\n\r\n");
        client->waitForBytesWritten(5000);

        //get
        client->waitForReadyRead(3000); //wait for data or response
        ui->txt_net_log->append(client->readAll());
        //disconnect
        client->close();
    }
    else
    {
        qDebug() << "Not Connected";
    }

}

void MainWindow::on_txt_ip_port2_selectionChanged()
{
    ui->txt_ip_port2->clear();
}


void MainWindow::on_btn_move_clicked()
{
    //send move message
}

void MainWindow::on_btn_attack_clicked()
{
    //send attack message
}

void MainWindow::on_btn_destroy_clicked()
{
    //send destroy message
}

void MainWindow::on_btn_place_clicked()
{
    //send placement message
}
