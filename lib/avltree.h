#ifndef AVLTREE_H
#define AVLTREE_H

#include "dsexceptions.h"
#include <iostream>
using namespace std;

/*
 * ADD contains(int, avlnode)
 * ADD findMin(avlnode)
 * ADD findMax(avlnode)
 * ADD makeEmpty(avlnode)
 * ADD insert(int, avlnode)
 */

template <class T>

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

    bool contains(const int &x) const {
        return contains(x, root);
    }

    void makeEmpty() {
        makeEmpty(root);
    }

    void insert(const int &x, T& input) {
        insert(x, root);
    }

    T& returnNodeAt(int input) {
        return returnNodeAt(x, root);
    }

private:
    T& returnNodeAt(int input, node *leaf) {
        if(input < leaf->element) {
            if(leaf->left != NULL)
                return returnNodeAt(key, leaf->left);
        } else if(input >= leaf->element) {
            if(leaf->right != NULL)
                return returnNodeAt(input, leaf->right);
        } else if(input == leaf->element) {
            return leaf->data;
        }
    }

    int height(AvlNode *t) const {
        return t == NULL ? -1 : t->height;
    }

    int max(int lhs, int rhs) const {
        return lhs > rhs ? lhs : rhs;
    }

    void rotateWithLeftChild(AvlNode *& i1) {

    }

    void rotateWithLeftChild(AvlNode *& i2) {

    }

    void doubleWithLeftChild(AvlNode *& i3) {

    }

    void doubleWithRightChild(AvlNode *& i4) {

    }

};

#endif // AVLTREE_H
