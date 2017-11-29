#ifndef PAGE_H
#define PAGE_H
#include <string>

class Page
{
public:
    float Id = -1;
    float ownerId = -1;
    float score = -1;
    std::string title;
    std::string body;
    std::string code;
    Page(float, std::string, std::string, std::string);
    Page();
};

#endif // PAGE_H
