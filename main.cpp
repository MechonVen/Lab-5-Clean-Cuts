#include <iostream>
#include "BST.h"

int main() {
    //Create an object of the BST class
    BinarySearchTree tree;

    int n; //Variable for number of tree values
    std::cout << "Enter the number of values you want to enter into a BST:" << std::endl;
    std::cin >> n;
    int array[n]; //Create an array of specified size to hold the elements that are to enter the BST
    std::cout << "Enter the elements of the tree:" << std::endl;

    //Loop to take user input for BST elements/keys
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    //Insert input values into the tree
    for (int i = 0; i < n; i++) {
        tree.InsertKey(array[i]);
    }

    //Print in, pre, and post-order traversals of the input BST
    tree.BSTPrintInOrder();
    tree.BSTPrintPreOrder();
    tree.BSTPrintPostOrder();

    return 0;
}
