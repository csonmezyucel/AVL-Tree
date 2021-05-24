// Code by Cevat Sonmez Yucel
#ifndef AVLNODE_H
#define AVLNODE_H

class AVLNode {
public:
    AVLNode(int x);
    ~AVLNode();
    int value;
    AVLNode* left;
    AVLNode* right;
};

#endif