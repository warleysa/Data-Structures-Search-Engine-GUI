#ifndef RESULT_H
#define RESULT_H
#include <vector>
#include <qword.h>
#include <algorithm>
#include <parser.h>
#include <iostream>

using namespace std;

class result  {
public:
    vector<int> idListResult;
    vector<int> freqListResult;
    result() {

    }


    result(vector<qWord>& temp1, Parser*& p) {

        for(int i = 0; i < temp1.size(); i++) {
            if (temp1[i].getAnd() == true) {
                word res = p->vStrings->searchIndex(temp1[i].getWord());
                mergeAnd(res.idList, res.freqList);
            } else if(temp1[i].getNot() == true) {
                word res = p->vStrings->searchIndex(temp1[i].getWord());
                mergeNot(res.idList, res.freqList);
            } else if(temp1[i].getOr() == true) {
                word res = p->vStrings->searchIndex(temp1[i].getWord());
                mergeOr(res.idList, res.freqList);
            } else {
                word result1 = p->vStrings->searchIndex(temp1[0].getWord());
                idListResult = result1.idList;
                freqListResult = result1.freqList;
                qSort();
            }
        }
    }

    void mergeAnd(vector<int>& idMerge, vector<int>& freqMerge) {

        vector<int> tempId;
        vector<int> tempFreq;

        for(int i = 0; i < idListResult.size(); i++){
            for(int j = 0; j < idMerge.size(); j++){
                if(idListResult[i] == idMerge[j]){
                    tempId.push_back(idListResult[i]);
                    tempFreq.push_back(freqListResult[i] + freqMerge[j]);
                }
            }
        }
        idListResult = tempId;
        freqListResult = tempFreq;
        qSort();
    }

    void mergeOr(vector<int>& idMerge, vector<int>& freqMerge) {

        vector<int> tempId;
        vector<int> tempFreq;
        bool add = true;

        idListResult.insert(idListResult.end(), idMerge.begin(), idMerge.end());
        freqListResult.insert(freqListResult.end(), freqMerge.begin(), freqMerge.end());
        tempId = idListResult;
        tempFreq = freqListResult;

        for (int i = 0; i < idListResult.size(); i++) {
            for(int j = 0; j < tempId.size(); j++){
                if ((idListResult[i] == tempId[j]) && (j != i)) {
                    freqListResult[i] = -1;
                }
            }
        }
        qSort();
        for(int i = 0; i < freqListResult.size(); i++){
            if(freqListResult[i] == -1){
                idListResult.erase(idListResult.begin()+i, idListResult.end());
                freqListResult.erase(freqListResult.begin()+ i, freqListResult.end());
            }
        }
    }
    void mergeNot(vector<int>& idMerge, vector<int>& freqMerge) {

        vector<int> tempId;
        vector<int> tempFreq;
        bool add = true;
        cout << "ENTERING NOT" << endl;

        for(int i = 0; i < idListResult.size(); i++){
            add = true;
            for(int j = 0; j < idMerge.size(); j++){
                if(idListResult[i] == idMerge[j]){
                    add = false;
                }
                if((j == idMerge.size()-1) && (add == true)){
                    tempId.push_back(idListResult[i]);
                    tempFreq.push_back(freqListResult[i]);
                    add = false;
                }
            }
        }
        idListResult = tempId;
        freqListResult = tempFreq;
        qSort();
    }



    void print() {
        cout << "ID LIST::::" << endl;
        for(int i = 0; i < idListResult.size(); i++) {
            cout << " : " << idListResult[i] << endl;
        }
        cout << "FREQ LIST::::" << endl;
        for(int i = 0; i < freqListResult.size(); i++) {
            cout << " : " << freqListResult[i] << endl;
        }
    }
    void qSort(int left, int right){
           int i = left;
           int j = right;
           int temp;
           int temp2;
           int pivot = freqListResult[(left+right) / 2];
           while(i <= j){
               while(freqListResult[i] < pivot){
                   i++;
               }
               while(freqListResult[j] > pivot){
                   j--;
               }
               if(i <= j){
                   temp = freqListResult[i];
                   temp2 = idListResult[i];
                   freqListResult[i] = freqListResult[j];
                   idListResult[i] = idListResult[j];
                   freqListResult[j] = temp;
                   idListResult[j] = temp2;
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


        if(freqListResult.size() <= 1) {
            return;
        }
        int i = 0;
        int j = freqListResult.size()-1;
        qSort(i, j);

        std::reverse(freqListResult.begin(), freqListResult.end());
        std::reverse(idListResult.begin(), idListResult.end());
    }
};

#endif // RESULT_H
