#ifndef WORD_H
#define WORD_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <query.h>

using namespace std;

void qSort(int, int);
void qSort();

class word {

public:
    vector<int> idList;
    vector<int> freqList;

public:
    string wordValue = " ";

    /**
     * @brief word
     */

    word() {

    }

    ~word() {

    }

    /**
     * @brief word
     * @param input
     * @param inputID
     * @param freq
     */

    word(string& input, int inputID, int freq) {
        wordValue = input;
        idList.push_back(inputID);
        freqList.push_back(freq);
    }

    /**
     * @brief updateFreq
     * @param inputID
     * Updates word frequency with +1(for word) if it is contained in the hash table
     */


    void updateFreq(int& inputID) {
        int tempValue = 1;
        for(int i = 0; i < idList.size(); i++) {
            if(idList[i] == inputID) {
                freqList[i] = freqList[i] + tempValue;
                return;
            }
        }
        idList.push_back(inputID);
        freqList.push_back(tempValue);
        return;
    }

    /**
     * @brief updateTagFreq
     * @param inputID
     * Updates word frequency with +5(for tag) if it is contained in the hash table
     */

    void updateTagFreq(int& inputID) {
        int tempValue = 5;
        for(int i = 0; i < idList.size(); i++) {
            if(idList[i] == inputID) {
                freqList[i] = freqList[i] + tempValue;
                return;
            }
        }
        idList.push_back(inputID);
        freqList.push_back(tempValue);
        return;
    }

    /**
     * @brief print
     * Prints all word values that are sorted by freuency
     */


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

    /**
     * @brief swap
     * @param a
     * @param b
     */


    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    /**
     * @brief qSort
     * @param left
     * @param right
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
    /**
     * @brief qSort
     */

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

};

#endif // WORD_H
