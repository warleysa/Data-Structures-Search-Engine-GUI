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
<<<<<<< HEAD
    bool qEntered;
=======
    HashTable<word>* index;
    int totalQuestions = 0;
>>>>>>> 5b38a75... Fixed hash table for templating and making the array/vector
    int totalWords = 0;
public:
    HashTable<word>* index;
    int getTotalWords();
    Indexer();
    Indexer(HashTable<word>* i);
    void readTagFile(int inputID, string inputWord);
<<<<<<< HEAD
    vector <string> getTop50Words();
    word searchIndex(string); //vector of ints which are document numbers
    void readNewWord(int& inputID, string& inputWord);
=======
    void cleanWordList(vector <string> &, vector <int> &);
    vector <string> getTop50Words();
    vector <long> searchIndex(string); //vector of ints which are document numbers
    void readNewWord(int inputID, string inputWord);
    /*
    vector <Results> findWord(string);
    vector <Results> findWords(string, string); //call this with 2 words situation
    */
>>>>>>> 5b38a75... Fixed hash table for templating and making the array/vector
};

