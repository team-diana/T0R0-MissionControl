#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
//#include "KeyPress.h"

#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    //QDesktopWidget *desktop = app.desktop();

    MainWindow window;
    //window.showMaximized();
    //window.showNormal();
    window.showFullScreen();
    //window.setFixedSize(500,500);

    qDebug() << "\nStart successful\n";


    return app.exec();
}
