#include "query.h"

query::query()
{

}

std::vector<qWord> query::getSearch(){
    return search;
}

void query::processSearch(std::string s){
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
       } else if (!n){
           qWord q{temp, a, o, n};
           search.push_back(q);
       }
   }
}

