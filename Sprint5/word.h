#ifndef WORD_H
#define WORD_H

#include <vector>
<<<<<<< HEAD
#include <iostream>
#include <algorithm>

using namespace std;

void qSort(int, int);
void qSort();

class word {
private:

public:
    vector<int> idList;
    vector<int> freqList;
    string wordValue;
    word() {
        wordValue = " ";
=======

using namespace std;

class word {
private:
    vector<int> idList;
    vector<int> freqList;

public:
    string wordValue = " ";
    word() {

>>>>>>> 5b38a75... Fixed hash table for templating and making the array/vector
    }

    word(string input, int inputID) {
        wordValue = input;
        idList.push_back(inputID);
        int tempValue = 1;
        freqList.push_back(tempValue);
    }


    void updateFreq(int inputID) {
        for(int i =0; i < idList.size(); i++) {
            if(idList[i] == inputID) {
                freqList[i] = freqList[i] + 1;
                return;
            }
        }
        idList.push_back(inputID);
        int tempValue = 1;
        freqList.push_back(tempValue);
        return;
    }
<<<<<<< HEAD

    void print() {
        cout << "ID LIST::::" << endl;
        for(int i = 0; i < idList.size(); i++) {
            cout << " : " << idList[i] << endl;
        }
        cout << "FREQ LIST::::" << endl;
        for(int i = 0; i < freqList.size(); i++) {
            cout << " : " << freqList[i] << endl;
        }
    }


    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

/*
 * Sorting functions for relevancy rankings
 * Uses Sprint 3 algorithm for sorting vectors (In DSVector)
 */

    void qSort(int left, int right){
           int i = left;
           int j = right;
           int temp;
           int temp2;
           int pivot = freqList[(left+right) / 2];
           while(i <= j){
               while(freqList[i] < pivot){
                   i++;
               }
               while(freqList[j] > pivot){
                   j--;
               }
               if(i <= j){
                   temp = freqList[i];
                   temp2 = idList[i];
                   freqList[i] = freqList[j];
                   idList[i] = idList[j];
                   freqList[j] = temp;
                   idList[j] = temp2;
                   i++;
                   j--;
               }
           }

           if(left < j){
               qSort(left, j);
           }
           if(i < right){
               qSort(i, right);
           }
       }

    void qSort(){


        if(freqList.size() <= 1) {
            return;
        }
        int i = 0;
        int j = freqList.size()-1;
        qSort(i, j);



        std::reverse(freqList.begin(), freqList.end());
        std::reverse(idList.begin(), idList.end());
    }
=======
>>>>>>> 5b38a75... Fixed hash table for templating and making the array/vector
};

#endif // WORD_H
