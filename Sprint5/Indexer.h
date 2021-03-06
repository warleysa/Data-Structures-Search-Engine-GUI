#pragma once
#include <string>
#include <vector>
#include "IndexInterface.h"
#include "HashTable.h"
#include "word.h"
using namespace std;


class Indexer
{
private:
    bool qEntered;
    int totalQuestions = 0;
    int totalWords = 0;
public:
    HashTable<word>* index;
    void getStopWords();
    int getTotalWords();
    Indexer();
    ~Indexer();
    Indexer(HashTable<word>* i);
    void readNewTag(int& inputID, string& inputWord);
    word searchIndex(string); //vector of ints which are document numbers
    void readNewWord(int& inputID, string& inputWord);

};

