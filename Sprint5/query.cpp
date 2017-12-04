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
   std::cout << s;
   std::istringstream input(s);
   std::string temp;
   std::string temp0;
   bool a = false;
   bool o = false;
   bool n = false;
   bool two = false;
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
       }else if(temp[0] == '['){
           temp0 = temp.substr(1, temp.length()-1 );
           two = true;
           std::cout << temp0 << std::endl;
       }else if(!two){
           qWord q{temp, a, o, n};
           search.push_back(q);
           std::cout << temp << std::endl;
       }else{
           temp = temp.substr(0, temp.length()-1);
           temp0 += " ";
           temp0 += temp;
           std::cout << temp0 << std::endl;
           qWord q{temp0, a, o, n};
           search.push_back(q);
           two = false;
       }
   }
   std::cout << search.at(3).getWord() << std::endl;
}
