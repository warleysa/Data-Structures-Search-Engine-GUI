

#include <../Sprint5/page.h>
#include <string>

Page::Page()
{

}

void Page::pageSet(int& i, std::string& t, std::string& b, std::string& c) {
    Id = i;
    title = t;
    body = b;
    code = c;
}

Page::Page(int i, std::string t, std::string b, std::string c){
    Id = i;
    title = t;
    body = b;
    code = c;
}

