#include <../Sprint5/page.h>
#include <string>

Page::Page()
{

}

/**
 * @brief Page::pageSet
 * @param i
 * @param t
 * @param b
 * @param c
 * Sets all values for pages
 */

void Page::pageSet(int& i, std::string& t, std::string& b, std::string& c) {
    Id = i;
    title = t;
    body = b;
    code = c;
}

/**
 * @brief Page::Page
 * @param i
 * @param t
 * @param b
 * @param c
 * Constructor for Page with values
 */

Page::Page(int i, std::string t, std::string b, std::string c){
    Id = i;
    title = t;
    body = b;
    code = c;
}

