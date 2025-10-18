#include <iostream>
#include "Lab5_Clean_Cuts.h"

int main() {
    BinarySearchTree tree; //Create an object of the BST class

    int n; //Variable for number of tree values
    int num; //Variable for tree values
    std::cout << "Enter the number of values you want to enter into a BST:" << std::endl;
    std::cin >> n;
    int array[n];
    std::cout << "Enter the elements of the tree:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    //Insert input values into the tree
    for (int i = 0; i < n; i++) {
        tree.InsertKey(array[i]);
    }
    /* This idea does not work, ask Peter lol (probably need to use visitor functions instead)
    tree.BSTPrintInOrder();
    tree.BSTPrintPreOrder();
    tree.BSTPrintPostOrder();
    */
    return 0;
}
