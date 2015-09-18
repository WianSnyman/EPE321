#include "gui.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUI w;
    w.show();
   // w.setFixedSize(1064,1158);

    return a.exec();
}
