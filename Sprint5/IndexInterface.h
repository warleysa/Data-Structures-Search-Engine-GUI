#pragma once
#include "Entry.h"
#include <string>

template <class T>
class IndexInterface {
public:
    IndexInterface(){}
    virtual void add(T, string) = 0;  // = 0 makes it abstract
    virtual T* find(string) = 0;
};
