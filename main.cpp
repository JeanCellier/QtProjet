#include "mainwindow.h"
#include "idwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    IdWindow id;
    id.show();


    return a.exec();
}
