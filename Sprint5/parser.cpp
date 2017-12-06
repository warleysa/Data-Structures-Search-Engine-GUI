#include <../Sprint5/parser.h>
#include <../Sprint5/csv.h>
#include <../Sprint5/tag.h>
#include <../Sprint5/page.h>


#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <istream>
#include <thread>

using std::cout;
using std::endl;
using std::vector;

Parser::Parser(){
    rows.resize(1270000);
    Page* filler = new Page();
    std::fill(rows.begin(), rows.end(), *filler);
}

void Parser::readTagFile(char* file){
    io::CSVReader<2> in(file);
    in.read_header(io::ignore_extra_column, "Id", "Tag" );
    int i = 0;
    string p = " ";
    while(in.read_row(i, p)){
        Tag tempTag{i, p};
        vStrings->readNewTag(i, p);
    }
}

int Parser::readFile(char* file) {
    std::ifstream in(file);
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
                    idLocations.push_back(endID);
                    //cout << "[" << endID << "]" << "\t";
                } else if (i == 5) {
                    tempTitle = row[i];
                    //cout << "[" << tempTitle << "]" << "\t";
                } else if (i == 6) {
                    tempBody = row[i];
                    //cout << "[" << tempBody << "]" << "\t";
                    parseBodyWords(tempBody, endID);
                } else if (i == 7) {
                    tempCode = row[i];
                    //cout << "[" << tempCode << "]" << "\t";
                }
            }
            rows.at(docLoadPos).pageSet(endID, tempTitle, tempBody, tempCode);
            docLoadPos++;
        }
        in.close();
        cout << "END OF FILE : " << file << endl;
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

int Parser::readId(int index){
    return rows[index].Id;
}

int Parser::readScore(int index){
    return rows[index].score;
}

string Parser::readTitle(int index){
    cout << rows[index].title << endl;
    return rows[index].title;
}

string Parser::readBody(int index){
    return rows[index].body;
}

string Parser::readCode(int index){
    return rows[index].code;
}


int Parser::TotalQuestions() {
    return idLocations.size();
}


int Parser::findFile(int ID) {
    int pos = 0;

    for(int i = 0; i <= idLocations.size(); i++) {
        if(ID == idLocations[i]) {
            pos = i;
            break;
        }
    }
    return pos;
}

void Parser::parseBodyWords(std::string &input, int &idNumber) {
    std::istringstream iss(input);
    while (iss) {
        string word;
        iss >> word;
        word.erase(std::remove(word.begin(), word.end(), '.'), word.end());
        word.erase(std::remove(word.begin(), word.end(), ':'), word.end());
        word.erase(std::remove(word.begin(), word.end(), ';'), word.end());
        word.erase(std::remove(word.begin(), word.end(), ','), word.end());
        word.erase(std::remove(word.begin(), word.end(), '?'), word.end());
        word.erase(std::remove(word.begin(), word.end(), '/'), word.end());
        word.erase(std::remove(word.begin(), word.end(), '\\'), word.end());
        word.erase(std::remove(word.begin(), word.end(), ')'), word.end());
        word.erase(std::remove(word.begin(), word.end(), '('), word.end());
        word.erase(std::remove(word.begin(), word.end(), '!'), word.end());
        word.erase(std::remove(word.begin(), word.end(), '='), word.end());
        word.erase(std::remove(word.begin(), word.end(), '"'), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        vStrings->readNewWord(idNumber, word);
    }
}

void Parser::clear() {
    vStrings->index->clear();
}


