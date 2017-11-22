#pragma once
#include "Entry.h"
#include <string>

class IndexInterface {
public:
    IndexInterface(){}
    virtual void add(Entry) = 0;  // = 0 makes it abstract
    virtual Entry* find(string) = 0;
};
