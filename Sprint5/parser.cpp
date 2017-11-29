#include <../Sprint5/parser.h>
#include <../Sprint5/csv.h>
#include <../Sprint5/tag.h>
#include <../Sprint5/page.h>


#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>


using std::cout;
using std::endl;

Parser::Parser(){}

Parser::Parser(char* file, char* tagFile){
    currentFile = file;
    currentTagFile = tagFile;

}

void Parser::readTagFile(){
    io::CSVReader<2> in(currentTagFile);
    in.read_header(io::ignore_extra_column, "Id", "Tag" );
    float i = 0;
    string p = " ";
    while(in.read_row(i, p)){
        Tag tempTag{i, p};
        tags.push_back(tempTag);
    }
}

int Parser::readFile() {
    std::ifstream in(currentFile);
        if (in.fail()) return (cout << "File not found" << endl) && 0;
        while(in.good())
        {
            string tempID = " ";
            int endID = 0;
            string tempTitle = " ";
            string tempBody = " ";
            string tempCode = " ";
            std::vector<std::string> row = csv_read_row(in, ',');
            for(int i = 0, leng=row.size(); i<leng; i++) {
                if (i == 1) {
                    tempID = row[i];
                    endID = std::strtod(tempID.c_str(), 0);
                    cout << "[" << endID << "]" << "\t";
                } else if (i == 5) {
                    tempTitle = row[i];
                    cout << "[" << tempTitle << "]" << "\t";
                } else if (i == 6) {
                    tempBody = row[i];
                    cout << "[" << tempBody << "]" << "\t";
                } else if (i == 7) {
                    tempCode = row[i];
                    cout << "[" << tempCode << "]" << "\t";
                }
                Page tempPage{endID, tempTitle, tempBody, tempCode};
            }
            cout << endl;
        }
        in.close();

        std::string line;
        in.open(currentFile);

        while(getline(in, line)  && in.good())
        {
            std::vector<std::string> row = csv_read_row(line, ',');
            for(int i=0, leng=row.size(); i < leng; i++)
                cout << "[" << row[i] << "]" << "\t";
            cout << endl;
        }

        in.close();
        return 0;
}

std::vector<std::string> Parser::csv_read_row(std::string &line, char delimiter)
{
    std::stringstream ss(line);
    return csv_read_row(ss, delimiter);
}

std::vector<std::string> Parser::csv_read_row(std::istream &in, char delimiter)
{
    std::stringstream ss;
    bool inquotes = false;
    std::vector<std::string> row;//relying on RVO
    while(in.good())
    {
        char c = in.get();
        if (!inquotes && c=='"') //beginquotechar
        {
            inquotes=true;
        }
        else if (inquotes && c=='"') //quotechar
        {
            if ( in.peek() == '"')//2 consecutive quotes resolve to 1
            {
                ss << (char)in.get();
            }
            else //endquotechar
            {
                inquotes=false;
            }
        }
        else if (!inquotes && c==delimiter) //end of field
        {
            row.push_back( ss.str() );
            ss.str("");
        }
        else if (!inquotes && (c=='\r' || c=='\n') )
        {
            if(in.peek()=='\n') { in.get(); }
            row.push_back( ss.str() );
            return row;
        }
        else
        {
            ss << c;
        }
    }
}

void Parser::setFile(char* p){
    currentFile = p;
}

void Parser::setTagFile(char* p){
    currentTagFile = p;
}

char& Parser::getFile(){
    return *currentFile;
}

char& Parser::getTagFile(){
    return *currentTagFile;
}

int Parser::readId(int index){
    return rows[index].Id;
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

