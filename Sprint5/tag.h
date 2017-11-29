#ifndef TAG_H
#define TAG_H
#include <string>

class Tag
{
public:
    float tagId = -1;
    std::string phrase = " ";
    Tag(float, std::string);
    Tag();
    void setTagId(float);
    void setTag(std::string);
};

#endif // TAG_H
