#include "Indexer.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

Indexer::Indexer() {

}

Indexer::Indexer(IndexInterface* i) { //overloaded constructor, connects indexer to index MAYBE CHANCE TO POINTER
    index = i;
}

void Indexer::readTagFile(string fn) {
    ifstream in(fn);
    string temp;
    string s; //whole string
    string tag;
    string sNum;
    string sDNum; //doc #
    long num;
    long dNum;
    getline(in, temp); //reads first line in (heading, garbage) and skips it

    while(!in.eof()) { //read until end of file
        getline(in, s);
        string delimiter = ",";
        sNum = s.substr(0, s.find(delimiter)); //gets nu
        s.erase(0, s.find(delimiter) + delimiter.length());
        sDNum = s.substr(0, s.find(delimiter)); //gets doc num
        s.erase(0, s.find(delimiter) + delimiter.length());
        tag = s.substr(0, s.find(delimiter)); //gets tag
        cout << sNum<< " "  << sDNum << " " << tag << endl; "\n\n";
        s.erase(0, s.find(delimiter) + delimiter.length());

        Entry* e = index -> find(tag); //FROM AVL TREE FIND ********
        if (e != nullptr) { //check if tag already in index, if it is, add new document number, returns null if notfound, if found returns pointedr to it
            e -> addDocNum(dNum);
        }

        else { //not in index, add into index
            index -> add(Entry(tag, dNum));
        }
    }

}

vector <string> Indexer::getTop50Words() {

}

vector <int> Indexer::searchIndex(string){ //vector of ints which are document numbers

}

