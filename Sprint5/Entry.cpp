#include "Entry.h"
#include <string>
#include <vector>
#include "math.h"

using namespace std; //same word on tons of pages (elephant)

Entry::Entry()
{
    tag = "";
    //vector already empty
}

Entry& Entry::operator =(const Entry& other) {
    if (this != &other) { //only when not the same
        docnum.clear();
        tag = other.tag;
        for (int i{}; i < (int)other.docnum.size(); i++)
            /** warley - added casting to signed int for (int)other.docnum.size() */
            addDocNum(other.docnum[i]);
    }
    /** warley - needs return value */
}

Entry::Entry(const Entry& other) {
    docnum.clear();
    tag = other.tag;
    for (int i{}; i < (int)other.docnum.size();i++)
        /** warley - added casting to signed int for (int)other.docnum.size() */
        addDocNum(other.docnum[i]);
}

Entry::Entry(string x, long y){
    tag = x;
    docnum.push_back(y);
}

void Entry::output(ostream& oput) {
    oput << tag << " : ";
    int line = tag.size() + 3; //add 3 for space : space -- current number characters used so far
    for (int i{}; i < (int)docnum.size(); i++) { //oput because outputting to file
        /** warley - added casting to signed int for (int)other.docnum.size() */
        line = line + (long)log10(docnum[i]) + 2; //if a one digit num, log10 = 0, if 10 to 99 = 1.something, so add 2 for comma and 2nd num
        if (line >= 50) {
            oput << endl;
            oput << "    ";
            line = 4;
        }
        oput << docnum[i];
        if (i < (int)docnum.size() - 1) //print comma if not on last word
            /** warley - added casting to signed int for (int)other.docnum.size() */
            oput << ",";
    }
    oput << endl;
}

string Entry::getTag() {return tag;}

void Entry::addDocNum(long x) {
    docnum.push_back(x); //inserts as new largest pg num
}
