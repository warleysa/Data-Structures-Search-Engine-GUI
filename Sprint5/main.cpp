#include <iostream>
#include <thread>
#include <../Sprint5/parser.cpp>


#include "../SearchEngineGUI/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Parser p{"/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/data/Q15.csv", "/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/data/T15.csv"};
    //p.readFile();
    //p.readTagFile();

    return a.exec();
}
