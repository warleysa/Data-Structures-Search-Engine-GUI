#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//entry = pg number and words on that page
//vector class made of these

class Entry {
private:
    string tag; //<><><><> TAG IS WORD
    vector <long> docnum; //<><><><>
    vector <int> wordLocation;
public:
    Entry& operator = (const Entry& other);
    Entry(const Entry& other);  // copy constructor
    Entry();
    Entry(string x, long y, int z);
    string getTag();
    void addDocNum(long x, int y);
    int getWordLocation(int x);
    void output(ostream& oput);
    long getDocNum(int x); //
    int getSize();

};
