#pragma once
#include "Entry.h"
#include <vector>
#include <string>
#include "IndexInterface.h"

const long TABLESIZE = 900000;

class HashTable: public IndexInterface { //inherets IndexInterface stuff
private:
    vector <Entry> table [TABLESIZE]; //vectors allow chaining, positions 0 - 199999 where things can be hashed to, if collision, bumped down chain

    long HashValue(string); //takes tag, runs it through formula to turn into number so it can be placed in table
public:
    HashTable();
    void add(Entry);
    Entry* find(string);
};
