#pragma once

class Results
{
private:
    long docNum;
    double score;
public:
    Results();
    Results(long, double);
    long getDocNum();
    double getScore();
    void setScore(double);
    bool operator > (const Results& s) const;
};
