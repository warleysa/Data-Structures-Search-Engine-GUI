#pragma once
#include <vector>
#include <array>
#include <string>
#include <iostream>


const long TABLESIZE = 500000;

template<class T>
class HashTable { //inherets IndexInterface stuff
private:
    std::array<std::vector<T>, TABLESIZE> table; //vectors allow chaining, positions 0 - 199999 where things can be hashed to, if collision, bumped down chain
    int HashValue(std::string); //takes tag, runs it through formula to turn into number so it can be placed in table
    int totalAdded;
public:
    HashTable();
    int totalEntries();
    void add(T&, std::string);
    T* find(std::string);
    void clear();
};

template<class T>
void HashTable<T>::clear() {
    table.empty();
}

template<class T>
HashTable<T>::HashTable() {
    std::fill(table.begin(), table.end(), std::vector<T>());
    totalAdded = 0;
}

template<class T>
int HashTable<T>::totalEntries() {
    return totalAdded;
}

template<class T>
int HashTable<T>::HashValue(std::string s) { //takes tag, runs it through formula to turn into number so it can be placed in table
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

void HashTable<T>::add(T& e, std::string tag) {
    int l = HashValue(tag); //converts tag to position num according to formula
    //std::cout << "TABLE ELEMENT ACCESSED: " << l << std::endl;
    //std::cout << "vector ADD: " << table[l]. << std::endl;
    table[l].push_back(e); //adds it into the table
    totalAdded = totalAdded+1;
}

template<class T>

T* HashTable<T>::find(std::string s) {
    //std::cout << "entering nullptr1" << std::endl;

    int l = HashValue(s); //if tag in table, in position l. problem is that sometimes more than 1 tag at same spot (collision) which I handle with chaining
    //std::cout << "TABLE ELEMENT ACCESSED: " << l << std::endl;
    for (int i{}; i < table[l].size(); i++) {
        if (table[l][i].wordValue == s) {
            //std::cout << "FOUND WORD: " << s << std::endl;
           // std::cout << "TABLE WORD ACCESSED: " << table[l][i].wordValue << std::endl;
            return &table[l][i];
        }
    }
    //std::cout << "RETURNING NULLPTR: " << std::endl;
    return nullptr;
}
