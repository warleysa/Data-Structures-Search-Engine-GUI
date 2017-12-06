#ifndef QUERY_H
#define QUERY_H
#include <string>
#include <vector>
#include <locale>
#include <iostream>
#include <sstream>
#include "qword.h"


class query
{
private:


public:
    query();
    std::vector<qWord> search;
    std::vector<qWord> getSearch();
    void processSearch(std::string&);
};

#endif // QUERY_H
