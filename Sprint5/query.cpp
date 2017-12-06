#include "query.h"
#include <porter2_stemmer.h>

/**
 * @brief query::query
 */

query::query()
{

}

/**
 * @brief query::getSearch
 * @return
 * Returns vector of qwords that is set with query settings
 */

std::vector<qWord> query::getSearch(){
    return search;
}

/**
 * @brief query::processSearch
 * @param s
 * Processes user query and loads the values/settings into vector of qWords
 */

void query::processSearch(std::string& s){
   for(int i = 0; i < s.length(); i++){
       s[i] = tolower(s[i]);
   }
   std::istringstream input(s);
   std::string temp;
   bool a = false;
   bool o = false;
   bool n = false;
   while(input >> temp){
       if(temp == "and"){
           a = true;
           o = false;
           n = false;
       }else if(temp == "or"){
           a = false;
           o = true;
           n = false;
       }else if(temp == "not"){
           a = false;
           o = false;
           n = true;
       } else {
           qWord q{temp, a, o, n};
           search.push_back(q);
       }
   }
}

