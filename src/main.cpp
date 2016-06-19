#include "mainwindow.h"
#include <QApplication>

int const MainWindow::EXIT_REBOOT=-1;

int main(int argc, char *argv[])
{
    int Exitcode=0;
    do{
    QApplication a(argc, argv);
    MainWindow w;
    w.tmp=0;
    w.show();
    Exitcode = a.exec();
    }while( Exitcode == MainWindow::EXIT_REBOOT);
    return Exitcode;
}
