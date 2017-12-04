#pragma once
#include "Entry.h"
#include <vector>
#include <string>
#include "IndexInterface.h"


const long TABLESIZE = 200000;
template<class T>
class HashTable: public IndexInterface<T> { //inherets IndexInterface stuff
private:
    vector <T> table [TABLESIZE]; //vectors allow chaining, positions 0 - 199999 where things can be hashed to, if collision, bumped down chain
    long HashValue(string); //takes tag, runs it through formula to turn into number so it can be placed in table
public:
    HashTable();
    void add(T, string);
    T* find(string);
};

template<class T>
HashTable<T>::HashTable() {}

template<class T>
long HashTable<T>::HashValue(string s) { //takes tag, runs it through formula to turn into number so it can be placed in table
    //DJB2 hash function
    unsigned long H = 5381; //unsigned saves memory
    int c;
    for (int i{}; i < s.length(); i++) {
        c = s[i]; //char into int automatically converts to ASCII
        H = ((H << 5) + H) + tolower(c); //<< bit shift 5 to left (multiply num by 32 but in binary shifts) adds an H then next character
        //creates num from string
    }
   //cout << H % TABLESIZE << endl;
    return H % TABLESIZE;
}

template<class T>
void HashTable<T>::add(T e, string tag) {
    long l = HashValue(tag); //converts tag to position num according to formula
    table[l].push_back(e); //adds it into the table
}

template<class T>
T* HashTable<T>::find(string s) {
    T* e = nullptr;
    long l = HashValue(s); //if tag in table, in position l. problem is that sometimes more than 1 tag at same spot (collision) which I handle with chaining
    for (int i{}; i < table[l].size(); i++) {
        if (table[l][i].getTag() == s) {
            return &table[l][i];
        }
    }
    return nullptr; //never found the entry
}
