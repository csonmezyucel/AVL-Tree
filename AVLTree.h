// Code by Cevat Sonmez Yucel
#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(int value);
    void remove(int value);
    void printTree();
    bool exists(int value);

private:
    bool exists(AVLNode* root, int value);
    AVLNode* insert(AVLNode* root, int value);
    AVLNode* remove(AVLNode* root, int value);
    void balance();
    int height(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* root);
    AVLNode* rotateRight(AVLNode* root);
    AVLNode* root;
    AVLNode* lowestUnbalanced;
};

#endif