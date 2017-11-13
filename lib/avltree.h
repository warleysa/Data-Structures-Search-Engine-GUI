#ifndef AVLTREE_H
#define AVLTREE_H

#include "dsexceptions.h"
#include <iostream>
using namespace std;

class AvlTree {

private:
    class AvlNode {
    public:
        int element;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode(const int & theElement,
                AvlNode *lt,
                AvlNode *rt, int h = 0)
            : element (theElement), left(lt),
              right(rt), height(h) { }

    };

    AvlNode *root;

public:
    AvlTree():root(NULL) {

    }

    AvlTree(const AvlTree & rhs):root(NULL) {
        *this = rhs;
    }

    ~AvlTree() {
        makeEmpty();
    }

    const int &findMin() const {
        if(isEmpty()) {
            cout << "ERROR: *****Underflow of AVLTree****" << endl;
        }
        return findMin(root)->element;
    }

    const int &findMax() const {
        if(isEmpty()) {
            cout << "ERROR: *****Underflow of AVLTree****" << endl;
        }
        return findMax(root)->element;
    }

};

#endif // AVLTREE_H
