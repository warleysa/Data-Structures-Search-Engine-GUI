#include "Indexer.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Entry.h"
#include "porter2_stemmer.h"

#include <algorithm>
using namespace std;

Indexer::Indexer() {}

Indexer::Indexer(IndexInterface<Entry>* i) { //overloaded constructor, connects indexer to index MAYBE CHANCE TO POINTER
    index = i;
}

vector <string> dropWords;

vector <Results> Indexer::findWord(string word) {
    cout << "got to find" << endl;
    Porter2Stemmer::stem(word); //stem search word
    Entry* e = index -> find(word); //finds word
    vector <Results> results;
    int loc;
    for (int i{}; i < e->getSize(); i++) {
        loc = -1; //reset size (haven't found it in results)
        for (int z{}; z < results.size(); z++) {
            if (e->getDocNum(i) == results[z].getDocNum()) {
                loc = z; //set to particular decision because found
                break;
            }
        }
        if (loc == -1) {
            results.push_back(Results(e->getDocNum(i), 1)); //1 because first instance
        }
        else {
            results[loc].setScore(results[loc].getScore() + 1); //incrememnting how many times seen
        }
        //look at doc num in position i
        //if there, increment score by one (found another instance)
        //if not in vector, add as new entry
    }
    sort(results.begin(), results.end(), greater<Results>()); //sort array in descending order TERM FREQUENCY METRIC
    return results;
    //score words on how many times in document
    //more
}

vector <Results> Indexer::findWords(string word, string word2) {
    //if result in e1 and e2 agree in document number and differ in wordLoc by 1
    cout << "got to find" << endl;
    Porter2Stemmer::stem(word); //stem search word
    Entry* e = index -> find(word); //finds word
    Entry* e2 = index -> find(word2);
    bool paired;
    vector <Results> results;
    int loc;
    for (int i{}; i < e->getSize(); i++) {
        paired = false; //haven't found pairing (to strat)
        for (int z{}; z < e2->getSize(); z++) {
            if (e->getDocNum(i) == e2->getDocNum(z) && e->getWordLocation(i) + 1 == e2-> getWordLocation(z))
                    paired = true;
        }
        if (paired) {
            loc = -1; //reset size (haven't found it in results)
            for (int z{}; z < results.size(); z++) {
                if (e->getDocNum(i) == results[z].getDocNum()) {
                    loc = z; //set to particular decision because found
                    break;
                }
            }
            if (loc == -1) {
                results.push_back(Results(e->getDocNum(i), 1)); //1 because first instance
            }
            else {
                results[loc].setScore(results[loc].getScore() + 1); //incrememnting how many times seen
            }
        }
        //look at doc num in position i
        //if there, increment score by one (found another instance)
        //if not in vector, add as new entry
    }
    sort(results.begin(), results.end(), greater<Results>()); //sort array in descending order TERM FREQUENCY METRIC
    return results;
    //score words on how many times in document
    //more
}

void Indexer::readQueryFile(string fn) {
    ifstream iin("stopwords.txt");
    while (!iin.eof()) { //while not end of file
        string w;
        iin >> w;               //reads all words into vector
        dropWords.push_back(w);
    }
    ifstream in(fn);
    string temp;
    string s; //whole string
    string title;
    string body;
    string sDNum; //doc #
    int l;
    long dNum;
    getline(in, temp); //reads first line in (heading, garbage) and skips it

    vector <string> wordList;
    vector <int> wordLoc;
    while(!in.eof()) { //read until end of file
        getline(in, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower); //changes all to lower case
        totalQuestions++;
        l = 0; //resets word location to 0 at beginning of each document
        //UP UNTIL LINE 56 BREAKING UP CSV INFO *********************************
        string delimiter = ",";
        temp = s.substr(0, s.find(delimiter)); //gets nu
        s.erase(0, s.find(delimiter) + delimiter.length());
        sDNum = s.substr(0, s.find(delimiter)); //gets doc num
        s.erase(0, s.find(delimiter) + delimiter.length());
        temp = s.substr(0, s.find(delimiter)); //gets rid of columns not needed
        s.erase(0, s.find(delimiter) + delimiter.length());
        temp = s.substr(0, s.find(delimiter)); //gets rid of columns not needed
        s.erase(0, s.find(delimiter) + delimiter.length());
        temp = s.substr(0, s.find(delimiter)); //gets rid of columns not needed
        s.erase(0, s.find(delimiter) + delimiter.length());
        //tag = s.substr(0, s.find(delimiter)); //gets tag
        title = s.substr(0, s.find(delimiter));
        s.erase(0, s.find(delimiter) + delimiter.length());
        body = s.substr(0, s.find(delimiter));
        s.erase(0, s.find(delimiter) + delimiter.length());

        dNum = atol(sDNum.c_str()); //string to long

        while(title.length() > 0) { //pulls off word using spaces until last word TITLE PROCESSOR
            string word;
            l++;
            int i = title.find(" ");
            if (i > 0) {
                word = title.substr(0, i);
                title.erase(0, i + 1);
            }
            else {
                word = title;//.substr(0, title.length() - 1);
                title = "";
            }
            wordList.push_back(word); //pushes word into list of "raw" words
            wordLoc.push_back(l);
        }
        while(body.length() > 0) { //pulls off word using spaces until last word BODY PROCESSOR
            string word;
            l++;
            int i = body.find(" ");
            if (i > 0) {
                word = body.substr(0, i);
                body.erase(0, i + 1);
            }
            else {
                word = body;//.substr(0, title.length() - 1);
                body = "";
            }
            wordList.push_back(word); //pushes word into list of "raw" words
            wordLoc.push_back(l);

        }
        cleanWordList(wordList, wordLoc);
        dNum = atol(sDNum.c_str()); //string to long
        for(int p{}; p < wordList.size(); p++) {
            parseWords(wordList[p], dNum, wordLoc[p]);
            cout << wordList[p] << endl; //words being put into hash table
        }
    }
}

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

void Indexer::parseWords(string t, long d, int z) {
    Entry* e = index -> find(t); //FROM AVL TREE FIND ********
    if (e != nullptr) { //check if tag already in index, if it is, add new document number, returns null if notfound, if found returns pointedr to it
        e -> addDocNum(d, z);
    }
    else { //not in index, add into index
        totalWords++;
        index -> add(Entry(t, d, z), t);
    }
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
        transform(s.begin(), s.end(), s.begin(), ::tolower); //changes all to lower case
        //UP UNTIL LINE 141 BREAKING UP CSV INFO *********************************
        string delimiter = ",";
        sNum = s.substr(0, s.find(delimiter)); //gets nu
        s.erase(0, s.find(delimiter) + delimiter.length());
        sDNum = s.substr(0, s.find(delimiter)); //gets doc num
        s.erase(0, s.find(delimiter) + delimiter.length());
        //tag = s.substr(0, s.find(delimiter)); //gets tag
        tag = s.substr(0, s.length() - 1); //gets tag
        //s.erase(0, s.find(delimiter) + delimiter.length());
        dNum = atol(sDNum.c_str()); //string to long
        parseWords(tag, dNum, -1);
    }
}

vector <string> Indexer::getTop50Words() {

}

int Indexer::getTotalQuestions() {
    return totalQuestions;
}

int Indexer::getTotalWords() {
    return totalWords;
}

vector <long> Indexer::searchIndex(string t){ //vector of ints which are document numbers, string is tag
    Entry* e = index -> find(t); //FROM AVL TREE FIND ********
    vector <long> docNums;
    for (int i{}; i < e->getSize(); i++) {
        docNums.push_back(e->getDocNum(i));
    }
    return docNums;
}

