#include "Indexer.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "porter2_stemmer.h"
#include <HashTable.h>
#include "word.h"

#include <algorithm>
using namespace std;
vector <string> dropWords;

/**
 * @brief Indexer::Indexer
 * Constructor for indexer
 */

Indexer::Indexer() {
    index = new HashTable<word>();
    qEntered = false;
    getStopWords();
}

/**
 * @brief Indexer::~Indexer
 */

Indexer::~Indexer() {
    index->clear();
    delete index;
}

/**
 * @brief Indexer::getStopWords
 * Reads in the stop words
 */

void Indexer::getStopWords() {
    ifstream no("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/stop.txt");
    string temp;
    while(no >> temp){
        dropWords.push_back(temp);
    }
    no.close();
}

/**
 * @brief Indexer::Indexer
 * @param i
 * Constructor for overloaded hashtable
 */

Indexer::Indexer(HashTable<word>* i) { //overloaded constructor, connects indexer to index MAYBE CHANCE TO POINTER
    index = i;
}

/**
 * @brief Indexer::readNewWord
 * @param inputID
 * @param inputWord
 * Removes stop words
 * Stems the word
 * Adds the word to index Hashtable
 */


void Indexer::readNewWord(int& inputID, string& inputWord) {
    if(binary_search(dropWords.begin(), dropWords.end(), inputWord) == true) {
        return;
    }

    Porter2Stemmer::stem(inputWord);

    if(index->find(inputWord) == nullptr) {
        //cout << "READING WORD" << endl;
        word temp(inputWord, inputID, 1);
        index->add(temp, inputWord);
        qEntered = true;
    } else {
        //cout << "finding word" << endl;
        index->find(inputWord)->updateFreq(inputID);
    }
    return;
}

/**
 * @brief Indexer::readNewTag
 * @param inputID
 * @param inputTag
 * Adds tag files to index hashtable
 */


void Indexer::readNewTag(int& inputID, string& inputTag) {

    if(index->find(inputTag) == nullptr) {
        //cout << "READING TAG" << endl;
        word* temp = new word(inputTag, inputID, 5);
        index->add(*temp, inputTag);
        qEntered = true;
    } else {
        //cout << "finding TAG" << endl;
        index->find(inputTag)->updateTagFreq(inputID);
    }
    return;
}

int Indexer::getTotalWords() {
    return index->totalEntries();
}

/**
 * @brief Indexer::searchIndex
 * @param t
 * @return
 * Returns the word object for the string searched from the hash table
 */

word Indexer::searchIndex(string t){ //vector of ints which are document numbers, string is tag
    if(index->find(t) == nullptr) {
        word temp;
        return temp;
    }
    return *(index->find(t));
}

