#include <iostream>
#include <thread>
#include <../Sprint5/parser.cpp>
#include <Indexer.h>


#include "../SearchEngineGUI/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*
    Indexer* test = new Indexer();
    test->readNewWord(12564, "hello");
    test->readNewWord(4, "sgdjh");
    test->readNewWord(4, "sdhjg");
    test->readNewWord(7, "sdhjg");
    test->readNewWord(8, "sajdtjy");
    test->readNewWord(9, "sadjyf");
    test->readNewWord(3, "sjyfd");
    test->readNewWord(5, "sadjyfg");
    test->readNewWord(1252323, "hello");
    test->readNewWord(2352, "hello");
    test->readNewWord(2354, "hello");
    std::cout << "END OF PROGRAM" << endl;
    */
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //return 0;
    return a.exec();
};
