#include "Results.h"

Results::Results() { }

Results::Results(long l, double d) {
    docNum = l;
    score = d;
}

long Results::getDocNum() {
    return docNum;
}

double Results::getScore() {
    return score;
}

void Results::setScore(double d) {
    score = d;
}

bool Results::operator > (const Results& s) const {
    return score > s.score;
}
