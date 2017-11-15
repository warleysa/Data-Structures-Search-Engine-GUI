#ifndef AVLTREE_H
#define AVLTREE_H

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
        T *data;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode(const int & theElement,
                AvlNode *lt,
                AvlNode *rt, int h = 0)
            : element (theElement), left(lt),
              right(rt), height(h){ }

    };

    AvlNode *root;

public:
    AvlTree():root(nullptr) {

    }

    AvlTree(const AvlTree & rhs):root(nullptr) {
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
        insert(x, input, root);
    }

    bool isEmpty( ) const {
        return root == nullptr;
    }

    T& returnNodeAt(int input) {
        return returnNodeAt(input, root);
    }

private:
    T& returnNodeAt(int input, AvlTree *leaf) {
        if(input < leaf->element) {
            if(leaf->left != nullptr)
                return returnNodeAt(input, leaf->left);
        } else if(input >= leaf->element) {
            if(leaf->right != nullptr)
                return returnNodeAt(input, leaf->right);
        } else if(input == leaf->element) {
            return leaf->data;
        }
    }

    void insert(const int & x, T& input, AvlNode *& t) {
        if( t == nullptr )
            t = new AvlNode(x, nullptr, nullptr, input);
        else if( x < t->element )
        {
            insert( x, t->left );
            if( height( t->left ) - height( t->right ) == 2 )
                if( x < t->left->element )
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
        }
        else if( t->element < x )
        {
            insert( x, t->right );
            if( height( t->right ) - height( t->left ) == 2 )
                if( t->right->element < x )
                    rotateWithRightChild(t);
                else
                    doubleWithRightChild(t);
        }
        else;  // Duplicate; do nothing

        t->height = max( height(t->left), height( t->right ) ) + 1;
    }

    int height(AvlNode *t) const {
        return t == nullptr ? -1 : t->height;
    }

    int max(int lhs, int rhs) const {
        return lhs > rhs ? lhs : rhs;
    }

    void rotateWithLeftChild(AvlNode *& i1) {

    }

    void rotateWithRightChild(AvlNode *& i2) {

    }

    void doubleWithLeftChild(AvlNode *& i3) {

    }

    void doubleWithRightChild(AvlNode *& i4) {

    }

    void makeEmpty(AvlNode*& t) {
        if(t != nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    bool contains(const int &x, AvlTree *t) const {
        while(t != nullptr)
            if(x < t->element) {
                t = t->left;
            } else if(t->element < x) {
                t = t->right;
            } else {
                return true;
            }
        return false;
    }
};

#endif // AVLTREE_H
