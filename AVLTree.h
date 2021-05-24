// Code by Cevat Sonmez Yucel
#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(int x);
    void remove(int x);
    void printTree();

private:
    AVLNode* insert(AVLNode* root, int x);
    AVLNode* remove(AVLNode* root, int x);
    void balance();
    int height(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* root);
    AVLNode* rotateRight(AVLNode* root);
    AVLNode* root;
    AVLNode* lowestUnbalanced;
};

#endif