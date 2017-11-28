#include <iostream>
#include <thread>
#include <../Sprint5/userinterface_nonGUI.h>
#include <../lib/avltree.hpp>


#include "../SearchEngineGUI/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
