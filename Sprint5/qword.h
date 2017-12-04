#ifndef QWORD_H
#define QWORD_H
#include <string>


class qWord
{
private:
       std::string word;
       bool a = false; //and
       bool o = false; //or
       bool n = false; //not


public:
    qWord();
    qWord(std::string, bool, bool, bool);
    void setWord(std::string);
    std::string getWord();
    void setAnd(bool);
    bool getAnd();
    void setOr(bool);
    bool getOr();
    void setNot(bool);
    bool getNot();
};

#endif // QWORD_H
