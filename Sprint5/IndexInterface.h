#pragma once
#include <string>

template <class T>
class IndexInterface {
public:
    IndexInterface(){}
    virtual void add(T, std::string) = 0;  // = 0 makes it abstract
    virtual T* find(std::string) = 0;
};
