#ifndef ENTRY_H
#define ENTRY_H

#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//entry = pg number and words on that page
//vector class made of these

class Entry {
private:
    string tag; //<><><><>
    vector<long> docnum; //<><><><>
public:
    Entry& operator = (const Entry& other);
    Entry(const Entry& other);  // copy constructor
    Entry();
    Entry(string x, long y);
    string getTag();
    void addDocNum(long x);
    void output(ostream& oput);
};

#endif
