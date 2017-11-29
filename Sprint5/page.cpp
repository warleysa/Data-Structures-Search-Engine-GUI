

#include <../Sprint5/page.h>
#include <string>

Page::Page()
{

}

Page::Page(float i, std::string t, std::string b, std::string c){
    Id = i;
    title = t;
    body = b;
    code = c;
}

