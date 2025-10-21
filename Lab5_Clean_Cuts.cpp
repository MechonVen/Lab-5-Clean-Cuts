#include <iostream>
#include "Lab5_Clean_Cuts.h"

BSTNode::BSTNode(int nodeKey, BSTNode* leftChild, BSTNode* rightChild) { //Basic constructor
    key = nodeKey;
    left = leftChild;
    right = rightChild;
}

//Functions for in, pre, and post-order traversal
void BinarySearchTree::BSTInOrder(BSTNode* node) {
    if (node) {
        BSTInOrder(node->left); //First print/travel to left node subtree
        std::cout << "Value: " << node->key << std::endl; //Print key of current subtree root node
        BSTInOrder(node->right); //Last, print/travel to right node subtree
        //Function will recursively go through each node under the node specificed in the argument, and
        //print the keys in the order: left->root->right
    }
}
void BinarySearchTree::BSTPreOrder(BSTNode* node) {
    if (node) {
        std::cout << "Value: " << node->key << std::endl; //First print key of current subtree root node
        BSTPreOrder(node->left); //Then print/travel to left node subtree
        BSTPreOrder(node->right); //Last, print/travel to right node subtree
        //Function will recursively go through each node under the node specificed in the argument, and
        //print the keys in the order: root->left->right
    }
}
void BinarySearchTree::BSTPostOrder(BSTNode* node) {
    if (node) {
        BSTPostOrder(node->left); //First print/travel to left node subtree
        BSTPostOrder(node->right); //Then print/travel to right node subtree
        std::cout << "Value: " << node->key << std::endl; //Last, print key of current subtree root node
        //Function will recursively go through each node under the node specificed in the argument, and
        //print the keys in the order: root->left->right
    }
}

//Functions for printing in, pre, and post-order traversal types from the root
void BinarySearchTree::BSTPrintInOrder() {
    std::cout << "Traversal Type: In-Order" << std::endl;
    BSTInOrder(root); //Call in-order traversal function from root to print the whole tree
}
void BinarySearchTree::BSTPrintPreOrder() {
    std::cout << "Traversal Type: Pre-Order" << std::endl;
    BSTPreOrder(root); //Call pre-order traversal function from root to print the whole tree
}
void BinarySearchTree::BSTPrintPostOrder() {
    std::cout << "Traversal Type: Post-Order" << std::endl;
    BSTPostOrder(root); //Call post-order traversal function from root to print the whole tree
}

//BST class function implementations
//Recursive function that goes through a subtree's nodes and deletes all of them
void BinarySearchTree::DeleteTree(BSTNode* subtreeRoot) {
    if (subtreeRoot) { //If null, break (goes back to previous recursive function call)
        DeleteTree(subtreeRoot->left);
        DeleteTree(subtreeRoot->right);
        delete subtreeRoot;
    }
}

//Function to search for a given node starting from the tree's root
BSTNode* BinarySearchTree::Search(int searchKey) {
    BSTNode* currentNode = root;
    while (currentNode) { //Loop breaks when currentnode becomes null; search key was not found
        if (searchKey == currentNode->key) {
            return currentNode; //Return currentnode if searchkey was found at currentnode
        }
        else if (searchKey < currentNode->key) {
            currentNode = currentNode->left; //Move to left child if searchkey is less than the currentkey
        }
        else {
            currentNode = currentNode->right; //Move to right child if searchkey is greater than currentkey
        }
    }
    return nullptr;
}

//Insert node according to proper BST order
void BinarySearchTree::InsertNode(BSTNode* newNode) {
    if (root == nullptr) {
        root = newNode; //Set newnode as the tree's root if the BST is empty
    }
    else { //If the BST is not empty (has at least 1 existing node)
        BSTNode* currentNode = root; //Set currentnode to the root to start from the BST's root
        while (currentNode) {
            if (newNode->key < currentNode->key) { //If the newnode's key is less than the currentnode...
                if (currentNode->left == nullptr) { //Set the newnode to the left child of the current node if it's empty
                    currentNode->left = newNode;
                    currentNode = nullptr; //Set currentnode to null to break the loop (since the newnode has been placed)
                }
                else {
                    currentNode = currentNode->left; //Otherwise, if the left child is occupied, move to the left
                }
            }
            else { //If the newnode's key is greater than the currentnode...
                if (currentNode->right == nullptr) { //Set the newnode to the right child of the current node if it's empty
                    currentNode->right = newNode;
                    currentNode = nullptr; //Set currentnode to null to break the loop (since the newnode has been placed)
                }
                else {
                    currentNode = currentNode->right; //Otherwise, if the right child is occupied, move to the right
                }
            }
        }
    }
}

//Function to see if a key already exists in the BST
bool BinarySearchTree::Contains(int key) {
    return Search(key) != nullptr; //Returns true if the argument key already exists in the tree
}

//Function to insert a new key into the BST
bool BinarySearchTree::InsertKey(int key) {
    if (Contains(key)) { //Ignore/disallow duplicate keys
        return false;
    }
    InsertNode(new BSTNode(key)); //If there are no duplicates, call to insert the new key
    return true;
}

//Constructor and Destructor for BST class
BinarySearchTree::BinarySearchTree() {
    root = nullptr; //Set root to null for an empty BST
}
BinarySearchTree::~BinarySearchTree() {
    DeleteTree(root); //Delete the entire tree (call delete function starting from tree root)
}
