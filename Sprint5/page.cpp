

#include <../Sprint5/page.h>
#include <string>

Page::Page()
{

}

Page::Page(int& i, std::string& t, std::string& b, std::string& c){
    Id = i;
    title = t;
    body = b;
    code = c;
}

