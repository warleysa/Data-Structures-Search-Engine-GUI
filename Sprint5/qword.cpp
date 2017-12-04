#include "qword.h"

qWord::qWord()
{
    word = " ";
}

qWord::qWord(std::string word, bool a, bool o, bool n){
    this->word = word;
    this->a = a;
    this->o = o;
    this->n = n;
}

void qWord::setWord(std::string word){
    this->word = word;
}

std::string qWord::getWord(){
    return word;
}

void qWord::setAnd(bool a){
    this->a = a;
}

bool qWord::getAnd(){
    return a;
}

void qWord::setOr(bool o){
    this->o = o;
}

bool qWord::getOr(){
    return o;
}

void qWord::setNot(bool n){
    this->n = n;
}

bool qWord::getNot(){
    return n;
}
