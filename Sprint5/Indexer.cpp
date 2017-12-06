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

Indexer::Indexer() {
    index = new HashTable<word>();
    qEntered = false;
    getStopWords();
}

Indexer::~Indexer() {
    index->clear();
    delete index;
}


void Indexer::getStopWords() {
    ifstream no("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/stop.txt");
    string temp;
    while(no >> temp){
        dropWords.push_back(temp);
    }
    no.close();
}

Indexer::Indexer(HashTable<word>* i) { //overloaded constructor, connects indexer to index MAYBE CHANCE TO POINTER
    index = i;
}



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


/*
void Indexer::cleanWordList(vector <string> &wl, vector <int> &wLoc){
    for(int x{}; x < dropWords.size(); x++) {
        for(int i{wl.size() - 1}; i >= 0; i--) { //goes from end to begining
            if (dropWords[x] == wl[i]) { //NEED A TOLOWER HERE
                wl.erase(wl.begin() + i); //deletes word
                wLoc.erase(wLoc.begin() + i); //deletes word location of deleted word
            }
        }
    }
    for(int i{}; i < wl.size(); i++) {
        Porter2Stemmer::stem(wl[i]); //calls stem function from inside porter2stemmer and stems words
    }
}
*/


int Indexer::getTotalWords() {
    return index->totalEntries();
}

word Indexer::searchIndex(string t){ //vector of ints which are document numbers, string is tag
    if(index->find(t) == nullptr) {
        word temp;
        return temp;
    }
    return *(index->find(t));
}

