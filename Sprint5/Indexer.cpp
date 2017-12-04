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

Indexer::Indexer() {
    index = new HashTable<word>();
<<<<<<< HEAD
    qEntered = false;
=======
}

Indexer::Indexer(HashTable<word>* i) { //overloaded constructor, connects indexer to index MAYBE CHANCE TO POINTER
    index = i;
}

vector <string> dropWords;
/*

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
>>>>>>> 5b38a75... Fixed hash table for templating and making the array/vector
}

Indexer::Indexer(HashTable<word>* i) { //overloaded constructor, connects indexer to index MAYBE CHANCE TO POINTER
    index = i;
    qEntered = false;
}
*/

<<<<<<< HEAD

void Indexer::readNewWord(int& inputID, string& inputWord) {

    if(index->find(inputWord) == nullptr) {
        //cout << "READING WORD" << endl;
        word* temp = new word(inputWord, inputID);
        index->add(*temp, inputWord);
        qEntered = true;
    } else {
        //cout << "finding word" << endl;
        index->find(inputWord)->updateFreq(inputID);
    }

}

=======
void Indexer::readNewWord(int inputID, string inputWord) {
    /*
    ifstream iin("stopwords.txt");
    while (!iin.eof()) { //while not end of file
        string w;
        iin >> w;               //reads all words into vector
        dropWords.push_back(w);
    }
    iin.close();
    */

    if(totalQuestions == 0) {
        word* temp = new word(inputWord, inputID);
        index->add(*temp, inputWord);
        totalQuestions = 1;
    } else {
        //index->find(inputWord)->updateFreq(inputID);
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

>>>>>>> 5b38a75... Fixed hash table for templating and making the array/vector
void Indexer::readTagFile(int inputID, string inputWord) {
    /*
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
    */
}

vector <string> Indexer::getTop50Words() {

}

int Indexer::getTotalWords() {
    return index->totalEntries();
}

<<<<<<< HEAD
word Indexer::searchIndex(string t){ //vector of ints which are document numbers, string is tag
    return *(index->find(t));
=======
vector <long> Indexer::searchIndex(string t){ //vector of ints which are document numbers, string is tag
    /*
    Entry* e = index -> find(t); //FROM AVL TREE FIND ********
    vector <long> docNums;
    for (int i{}; i < e->getSize(); i++) {
        docNums.push_back(e->getDocNum(i));
    }
    return docNums;
    */
>>>>>>> 5b38a75... Fixed hash table for templating and making the array/vector
}

