#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
using namespace std;

/**
 * Most of this implementation was provided in Mark Fontenot's class
 * Some functions are referred to from Mark Weiss's website
 * It can be found at http://users.cs.fiu.edu/~weiss/
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

    void printTree(AvlNode *t1) const {
        if(t1 != nullptr)
        {
            printTree(t1->left);
            cout << t1->element << endl;
            printTree(t1->right);
        }
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
        if(t == nullptr) {
            t = new AvlNode(x, nullptr, nullptr, input);
        } else if(x < t->element) {
            insert(x, t->left);
            if(height(t->left) - height(t->right) == 2) {
                if(x < t->left->element) {
                    rotateWithLeftChild(t);
                } else {
                    doubleWithLeftChild(t);
                }
            }

        } else if(t->element < x) {

            insert(x, t->right);
            if(height( t->right ) - height(t->left) == 2) {
                if(t->right->element < x) {
                    rotateWithRightChild(t);
                }else {
                    doubleWithRightChild(t);
                }
            }
        } else {

        }

        t->height = max(height(t->left), height(t->right)) + 1;
    }

    int height(AvlNode *temp) const {
        return temp == nullptr ? -1 : temp->height;
    }

    int max(int lhs, int rhs) const {
        return lhs > rhs ? lhs : rhs;
    }

    void rotateWithLeftChild(AvlNode *& k2) const {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    /**
            * Rotate binary tree node with right child.
            * For AVL trees, this is a single rotation for case 4.
            * Update heights, then set new root.
            */

    void rotateWithRightChild(AvlNode *& k1) const {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        k1 = k2;
    }

    /**
            * Double rotate binary tree node: first left child.
            * with its right child; then node k3 with new left child.
            * For AVL trees, this is a double rotation for case 2.
            * Update heights, then set new root.
            */

    void doubleWithLeftChild(AvlNode *& k3) const {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    /**
            * Double rotate binary tree node: first right child.
            * with its left child; then node k1 with new right child.
            * For AVL trees, this is a double rotation for case 3.
            * Update heights, then set new root.
            */
    void doubleWithRightChild(AvlNode *& k1) const {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
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

    AvlNode* findMax(AvlNode *t) const {
        if(t != nullptr) {
            while(t->right != nullptr) {
                t = t->right;
            }
            return t;
        }
    }
};

#endif // AVLTREE_HPP
