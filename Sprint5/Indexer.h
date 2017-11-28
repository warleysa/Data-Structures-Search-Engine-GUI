#pragma once
#include <string>
#include <vector>
#include "IndexInterface.h"
using namespace std;


class Indexer
{
private:
    IndexInterface* index;

public:
    Indexer(IndexInterface*);
    Indexer();
    void readTagFile(string);
    //getQuestionsIndexed();
   // getWordsIndexed();
    vector <string> getTop50Words();
    vector <int> searchIndex(string); //vector of ints which are document numbers
};

