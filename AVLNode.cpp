// Code by Cevat Sonmez Yucel
#include <string>
#include <iostream>
#include "AVLNode.h"

//Constructor
AVLNode::AVLNode(int x) {
    value = x;
    left = NULL;
    right = NULL;
}

//Destructor
AVLNode::~AVLNode() {
    delete left;
    delete right;
}