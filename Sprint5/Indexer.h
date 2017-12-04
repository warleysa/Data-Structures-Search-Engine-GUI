#pragma once
#include <string>
#include <vector>
#include "IndexInterface.h"
#include "Entry.h"
#include "Results.h"
using namespace std;


class Indexer
{
private:
    IndexInterface<Entry>* index;
    int totalQuestions = 0;
    int totalWords = 0;
public:
    int getTotalQuestions();
    int getTotalWords();
    Indexer(IndexInterface<Entry>*);
    Indexer();
    void readTagFile(string);
    void cleanWordList(vector <string> &, vector <int> &);
    vector <string> getTop50Words();
    vector <long> searchIndex(string); //vector of ints which are document numbers
    void parseWords(string, long, int);
    void readQueryFile(string);
    vector <Results> findWord(string);
    vector <Results> findWords(string, string); //call this with 2 words situation
};

