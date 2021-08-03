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
        std::cout << "Exists: e <integer>\n";
        std::cout << "Print: p\n";
        std::cout << "Stop: s\n";
        std::cout << "------------\n";
        std::string command;
        int value;
        std::cin >> command;
        if (command == "s") {
            std::cout << "------------\n";
            break;
        }
        if (command == "p") {
            myTree.printTree();
            continue;
        }
        std::cin >> value;
        if (command == "i") {
            myTree.insert(value);
        }
        if (command == "r") {
            myTree.remove(value);
        }
        if (command == "e") {
            std::cout << "------------\n";
            if (myTree.exists(value)) {
                std::cout << "'" << value << "'" << " exists in the tree\n";
            }
            else {
                std::cout << "'" << value << "'" << " does not exist in the tree\n";
            }
            std::cout << "------------\n";
        }
    }  
    return 0;      
}