#include <iostream>
#include <thread>
#include <./docobject.h>
#include <./wordobject.h>
#include <./userinterface.h>
#include <../lib/avltree.hpp>


using namespace std;

int main() {
    userInterface* ui = new userInterface();
    ui->menu();
    return 0;
}
