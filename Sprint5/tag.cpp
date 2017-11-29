
#include <../Sprint5/tag.h>

Tag::Tag()
{

}

Tag::Tag(float i, std::string p){
    tagId = i;
    phrase = p;
}

void Tag::setTag(std::string p){
    phrase = p;
}

void Tag::setTagId(float i){
    tagId = i;
}
