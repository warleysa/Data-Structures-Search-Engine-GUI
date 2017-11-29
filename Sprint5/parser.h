#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <../Sprint5/csv.h>
#include <../lib/avltree.hpp>
#include <../Sprint5/page.h>
#include <../Sprint5/tag.h>




using std::string;

class Parser{
private:
    char* currentFile;
    char* currentTagFile;
    int rowCount = -1; //-1 means on header row
    int colCount = -1; //-1 means on row title column
    const int idCol = 2; //column numbers
    const int ownerIdCol = 3; //""
    const int scoreCol = 5; //""
    const int titleCol = 6; //""
    const int bodyCol = 7; //""
    const int codeCol = 8; //""
    std::vector<Page> rows; //can be replaced with AVL or Hash
    std::vector<Tag> tags;

    std::vector<std::string> csv_read_row(std::istream &in, char delimiter);
    std::vector<std::string> csv_read_row(std::string &in, char delimiter);

public:

    Parser(); //default (does nothing)
    Parser(char*, char*); //overloaded constructor with two file names
    void setFile(char*); //sets question file
    void setTagFile(char*); //sets tag file
    char& getFile(); //returns current question file name
    char& getTagFile(); //returns current tag file name
    int readFile(); //reads question file and stores to vector or AVL or Hash depending on what's used
    void readTagFile(); //reads tags file and stores to vector or AVL or Hash depending on what's used
    int readId(int); //getters for every row and tag
    int readScore(int); //""
    int readTagId(int); //""
    string readTitle(int); //""
    string readBody(int); //""
    string readCode(int); //""
    string readTag(int);  //""
};

#endif // PARSER_H
