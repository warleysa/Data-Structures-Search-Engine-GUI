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
        idList.push_back(id);
        word = input;
    }

    void addID(int input) {
        idList.push_back(input);
    }

    int getID(int position) {
        return idList.at(position);
    }
};

#endif // WORDOBJECT_H
