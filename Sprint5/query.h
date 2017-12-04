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
    std::vector<qWord> search;


public:
    query();
    std::vector<qWord> getSearch();
    void processSearch(std::string);
};

#endif // QUERY_H
