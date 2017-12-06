
#include <../Sprint5/tag.h>

/**
 * @brief Tag::Tag
 */

Tag::Tag()
{

}

/**
 * @brief Tag::Tag
 * @param i
 * @param p
 */

Tag::Tag(float i, std::string p){
    tagId = i;
    phrase = p;
}

/**
 * @brief Tag::setTag
 * @param p
 */

void Tag::setTag(std::string p){
    phrase = p;
}

/**
 * @brief Tag::setTagId
 * @param i
 */

void Tag::setTagId(float i){
    tagId = i;
}
