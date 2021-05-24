// Code by Cevat Sonmez Yucel
#include "AVLNode.h"
#include "AVLTree.h"
#include <string>
#include <iostream>

int main() {
    AVLTree myTree;
    // Interface for using the AVL Tree
    while(true) {
        std::cout << "Insert: i <integer>\n";
        std::cout << "Remove: r <integer> \n";
        std::cout << "Print: p\n";
        std::cout << "Stop: s\n";
        std::cout << "------------\n";
        std::string command;
        int x;
        std::cin >> command;
        if (command == "s") {break;}
        if (command == "p") {
            myTree.printTree();
            continue;
        }
        std::cin >> x;
        if (command == "i") {
            myTree.insert(x);
        }
        if (command == "r") {
            myTree.remove(x);
        }
    }        
}