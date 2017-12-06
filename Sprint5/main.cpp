#include <iostream>
#include <thread>
#include <../Sprint5/parser.cpp>
#include <Indexer.h>
#include <result.h>


#include "../SearchEngineGUI/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*
    result* test = new result();
    vector<int> i1 = {1, 2, 3, 4, 78};
    vector<int> f1 = {3, 4, 1, 999, 24};
    test->idListResult = i1;
    test->freqListResult = f1;
    vector<int> i2 = {1, 3, 2, 5};
    vector<int> f2 = {1, 2, 3, 100};
    test->mergeOr(i2, f2);
    test->print();
    std::cout << "END OF PROGRAM" << endl;
    */

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //return 0;
    return a.exec();

};
