#ifndef WORDOBJECT_H
#define WORDOBJECT_H

#include <string>
#include <vector>

class wordObject {

public:
    std::vector<int> idList;
    std::string word;
    int intWord;

    wordObject() {
        intWord = -1;
    }

    wordObject(int id, std::string input) {

    }
};

#endif // WORDOBJECT_H
