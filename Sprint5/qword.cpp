#include "qword.h"

/**
 * @brief qWord::qWord
 */

qWord::qWord()
{
    word = " ";
}

/**
 * @brief qWord::qWord
 * @param word
 * @param a
 * @param o
 * @param n
 * Contructor that sets qWord values that are set
 */

qWord::qWord(std::string word, bool a, bool o, bool n){
    this->word = word;
    this->a = a;
    this->o = o;
    this->n = n;
}

/**
 * @brief qWord::setWord
 * @param word
 */

void qWord::setWord(std::string word){
    this->word = word;
}

/**
 * @brief qWord::getWord
 * @return
 */

std::string qWord::getWord(){
    return word;
}

/**
 * @brief qWord::setAnd
 * @param a
 */

void qWord::setAnd(bool a){
    this->a = a;
}

/**
 * @brief qWord::getAnd
 * @return
 */

bool qWord::getAnd(){
    return a;
}

/**
 * @brief qWord::setOr
 * @param o
 */

void qWord::setOr(bool o){
    this->o = o;
}

/**
 * @brief qWord::getOr
 * @return
 */

bool qWord::getOr(){
    return o;
}

/**
 * @brief qWord::setNot
 * @param n
 */

void qWord::setNot(bool n){
    this->n = n;
}

/**
 * @brief qWord::getNot
 * @return
 */

bool qWord::getNot(){
    return n;
}
