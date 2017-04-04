#include "mainwindow.h"
#include "idwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        MainWindow w;

        IdWindow id;

        if(id.exec()==QDialog::Accepted)
        {
            w.show();
            return a.exec();
        }

        return 0;

}
