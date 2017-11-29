#include <../Sprint5/parser.h>
#include <QCoreApplication>
#include <../lib/avltree.hpp>

int main(int argc, char *argv[])
{
    Parser p{"/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/data/Q15.csv", "/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/data/T15.csv"};
    p.readFile();
    p.readTagFile();

    return 0;
}
