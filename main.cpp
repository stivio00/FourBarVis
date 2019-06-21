#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Four Bar Visualization");
    a.setApplicationDisplayName("FourBarVis");
    a.setApplicationVersion("0.1");
    a.setOrganizationName("UTP");
    MainWindow w;
    w.show();

    return a.exec();
}
