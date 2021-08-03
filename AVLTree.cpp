// Code by Cevat Sonmez Yucel
#include "AVLTree.h"
#include "AVLNode.h"
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>


// Constructor
AVLTree::AVLTree() {
    root = NULL;
    lowestUnbalanced = NULL;
}

// Destructor
AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert function that makes use of its helper function
void AVLTree::insert(int value) {
    // Root is made equal to what the helper function returns
    root = insert(root, value);

    // Calls the balance function if there is an imbalance in the tree
    // Imbalance is defined as difference between right and left height of a node being greater than 1
    if (lowestUnbalanced) {
        balance();
    }

    // As the tree is now balanced, there is no lowestUnbalanced node
    lowestUnbalanced = NULL;
}

// Helper function for insert
AVLNode* AVLTree::insert(AVLNode* root, int value) {
    // If the root is null, a new instance of the AVLNode class is created and returned
    if (!root) {
        AVLNode* root = new AVLNode(value);
        return root;
    }
    // Less than case
    else if (root -> value > value) {
        root -> left = insert(root -> left, value);
    }
    // Greater than case
    else if (root -> value < value) {
        root -> right = insert(root -> right, value);
    }
    // Checking if a node is unbalanced
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    if (abs(leftHeight - rightHeight) >= 2 && !lowestUnbalanced) {
        lowestUnbalanced = root;
    }
    return root;
}

// remove function that makes use of its helper function
void AVLTree::remove(int value) {
    if (root) {
        root = remove(root, value);
    }
    if (lowestUnbalanced) {
        balance();
    }
    lowestUnbalanced = NULL;
}

// Helper function for remove
AVLNode* AVLTree::remove(AVLNode* root, int value) {
    if (root -> value == value) {
        AVLNode* temp1 = root -> right;
        root = root -> left;
        if (root) {root -> right = temp1;}
        else {root = temp1;}
        return root;
    }

    // Less than case
    if (root -> value > value && root -> left) {
        root -> left = remove(root -> left, value);
    }

    //Greater than case
    if (root -> value < value && root -> right) {
        root -> right = remove(root -> right, value);
    }

    // Checking if a node is unbalanced
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    if (abs(leftHeight - rightHeight) >= 2 && !lowestUnbalanced) {
        lowestUnbalanced = root;
    }
    return root;
}

// Prints the level order traversal of tree
void AVLTree::printTree() {
    std::queue<AVLNode*> nodes;
    std::queue<int> levels;
    if (root) {
        nodes.push(root);
        levels.push(0);
    }
    int prevLevel = 0;
    std::cout << "Level 0: ";
    while (nodes.size()) {
        AVLNode* curNode = nodes.front();
        int curLevel = levels.front();
        if (curNode -> left) {
            nodes.push(curNode -> left);
            levels.push(curLevel + 1);
        }
        if (curNode -> right) {
            nodes.push(curNode -> right);
            levels.push(curLevel + 1);
        }
        int toPrint = nodes.front() -> value;
        int levelAt = levels.front();
        if (levelAt != prevLevel) {
            std::cout << "\nLevel " << levelAt << ": ";
            prevLevel = levelAt;
        }
        std::cout << toPrint << " ";
        nodes.pop();
        levels.pop();
    }
    std::cout << "\n";
}

// exists function that makes use of its helper funtion
bool AVLTree::exists(int value) {
    return exists(root, value);
}

// Helper function for exists
// Checks if given value exists in the tree
bool AVLTree::exists(AVLNode* root, int value) {
    if (!root) {
        return false;
    }
    if (root -> value == value) {
        return true;
    }
    else if (root -> value > value) {
        return exists(root -> left, value);
    }
    else if (root -> value < value) {
        return exists(root -> right, value);
    }
    return false;
}

// Recursive function to return the height of each node
int AVLTree::height(AVLNode* node) {
    if (!node) {
        return -1;
    }
    if (!node -> left && !node -> right) {
        return 0;
    }
    else {
        return std::max(height(node -> left), height(node -> right)) + 1;
    }
}

// balance function that is called if the tree is unbalanced after insert or remove
void AVLTree::balance() {
    int balanceFactor = height(lowestUnbalanced -> right) - height(lowestUnbalanced -> left);
    if (balanceFactor < 0) {
        int leftBalanceFactor = height(lowestUnbalanced -> left -> right) - height(lowestUnbalanced -> left -> left);
        if (leftBalanceFactor <= 0) {
            //left left Case (Single, right rotation)
            root = rotateRight(root);
        }
        else if (leftBalanceFactor > 0) {
            //left right Case (Double, left right rotation)
            AVLNode* temp1 = lowestUnbalanced;
            lowestUnbalanced = lowestUnbalanced -> left;
            root = rotateLeft(root);
            lowestUnbalanced = temp1;
            root = rotateRight(root);
        }
    }
    if (balanceFactor > 0) {
        int rightBalanceFactor = height(lowestUnbalanced -> right -> right) - height(lowestUnbalanced -> right -> left);
        if (rightBalanceFactor < 0) {
            //right left Case (Double, right left rotation)
            AVLNode* temp2 = lowestUnbalanced;
            lowestUnbalanced = lowestUnbalanced -> right;
            root = rotateRight(root);
            lowestUnbalanced = temp2;
            root = rotateLeft(root);
        }
        else if (rightBalanceFactor >= 0) {
            //right right Case (Single, left rotation)
            root = rotateLeft(root);
        }
    }
}

// Recursive function to rotate given node left
AVLNode* AVLTree::rotateLeft(AVLNode* root) {
    if (root == lowestUnbalanced) {
        AVLNode* temp1 = root;
        AVLNode* temp2 = root -> right -> left;
        AVLNode* temp3 = root -> right;
        temp1 -> right = temp2;
        temp3 -> left = temp1;
        return temp3;
    }
    if (root -> value > lowestUnbalanced -> value) {
        root -> left = rotateLeft(root -> left);
    }
    else if (root -> value < lowestUnbalanced -> value) {
        root -> right = rotateLeft(root -> right);
    }
    return root;
}

// Recursive function to rotate given node right
AVLNode* AVLTree::rotateRight(AVLNode* root) {
    if (root == lowestUnbalanced) {
        AVLNode* temp1 = root;
        AVLNode* temp2 = root -> left -> right;
        AVLNode* temp3 = root -> left;
        temp1 -> left = temp2;
        temp3 -> right = temp1;
        return temp3;
    }
    if (root -> value > lowestUnbalanced -> value) {
        root -> left = rotateRight(root -> left);
    }
    else if (root -> value < lowestUnbalanced -> value) {
        root -> right = rotateRight(root -> right);
    }
    return root;
}