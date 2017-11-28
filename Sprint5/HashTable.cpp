#include "HashTable.h"
#include "IndexInterface.h"
#include "Entry.h"
#include <vector>
#include <string>

HashTable::HashTable() {}

long HashTable::HashValue(string s) { //takes tag, runs it through formula to turn into number so it can be placed in table
    //DJB2 hash function
    unsigned long H = 5381; //unsigned saves memory
    int c;
    for (int i{}; i < s.length(); i++) {
        c = s[i]; //char into int automatically converts to ASCII
        H = ((H << 5) + H) + tolower(c); //<< bit shift 5 to left (multiply num by 32 but in binary shifts) adds an H then next character
        //creates num from string
    }
    cout << H % TABLESIZE << endl;
    return H % TABLESIZE;
}

void HashTable::add(Entry e) {
    long l = HashValue(e.getTag()); //converts tag to position num according to formula
    table[l].push_back(e); //adds it into the table
}

Entry* HashTable::find(string s) {
    Entry* e = nullptr;
    long l = HashValue(s); //if tag in table, in position l. problem is that sometimes more than 1 tag at same spot (collision) which I handle with chaining
    for (int i{}; i < table[l].size(); i++) {
        if (table[l][i].getTag() == s) {
            return &table[l][i];
        }
    }
    return nullptr; //never found the entry
}
