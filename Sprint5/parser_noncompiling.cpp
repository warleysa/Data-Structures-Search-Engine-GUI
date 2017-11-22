#include "parser_noncompiling.h"

Parser::Parser(){}

Parser::Parser(char* file, char* tagFile){
    currentFile = file;
    currentTagFile = tagFile;
}

Parser::row::row(){}

Parser::row::row(int i, int o, int s, string t, string b, string c){
    Id = i;
    ownerId = o;
    score = s;
    title = t;
    body = b;
    code = c;
}

Parser::tag::tag(){}

Parser::tag::tag(int i, string p){
    tagId = i;
    phrase = p;
}

void Parser::readTagFile(){
    io::CSVReader<2> in(currentTagFile);
    in.read_header(io::ignore_extra_column, "Id", "Tag");
    int i = 0;
    string p = " ";
    while(in.read_row(i,p)){
        tempTag = new tag(i,p);
        tags.push_back(tempTag);
    }
}

void Parser::readFile(){
    io::CSVReader<6> in(currentFile);
    in.read_header(io::ignore_extra_column, "Id", "OwnerUserId", "Score", "Title", "Body", "Code");
    int i, o, s = 0;
    string t, b, c = " ";
    while(in.read_row(i,o,s,t,b,c)){
        tempRow = new row(i,o,s,t,b,c);
        rows.push_back(tempRow);
        rowCount++;
    }
}

void Parser::setFile(char* p){
    currentFile = p;
}

void Parser::setTagFile(char* p){
    currentTagFile = p;
}

char& Parser::getFile(){
    return currentFile;
}

char& Parser::getTagFile(){
    return currentTagFile;
}

int Parser::readId(int index){
    return rows[index].Id;
}

int Parser::readOwnerId(int index){
    return rows[index].ownerId;
}

int Parser::readScore(int index){
    return rows[index].score;
}

int Parser::readTagId(int index){
    return tags[index].tagId;
}

string Parser::readTitle(int index){
    return rows[index].title;
}

string Parser::readBody(int index){
    return rows[index].body;
}

string Parser::readCode(int index){
    return rows[index].code;
}

string Parser::readTag(int index){
    return tags[index].phrase;
}

