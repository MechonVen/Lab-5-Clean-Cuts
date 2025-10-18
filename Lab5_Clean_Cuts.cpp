#include <iostream>
#include "Lab5_Clean_Cuts.h"

BSTNode::BSTNode(int nodeKey, BSTNode* leftChild, BSTNode* rightChild) {
    key = nodeKey;
    left = leftChild;
    right = rightChild;
}

//Functions for in, pre, and post-order traversal
void BinarySearchTree::BSTPrintInOrder(BSTNode* node) {
    std::cout << "Traversal Type: In-Order" << std::endl;
    if (node) {
        BSTPrintInOrder(node->left);
        std::cout << "Value: " << node->key << std::endl;
        BSTPrintInOrder(node->right);
    }
}
void BinarySearchTree::BSTPrintPreOrder(BSTNode* node) {
    std::cout << "Traversal Type: Pre-Order" << std::endl;
    if (node) {
        std::cout << "Value: " << node->key << std::endl;
        BSTPrintPreOrder(node->left);
        BSTPrintPreOrder(node->right);
    }
}
void BinarySearchTree::BSTPrintPostOrder(BSTNode* node) {
    std::cout << "Traversal Type: Post-Order" << std::endl;
    if (node) {
        BSTPrintInOrder(node->left);
        BSTPrintInOrder(node->right);
        std::cout << "Value: " << node->key << std::endl;
    }
}

//BST class function implementations
void BinarySearchTree::DeleteTree(BSTNode* subtreeRoot) {
    if (subtreeRoot) {
        DeleteTree(subtreeRoot->left);
        DeleteTree(subtreeRoot->right);
        delete subtreeRoot;
    }
}

BSTNode* BinarySearchTree::Search(int searchKey) {
    BSTNode* currentNode = root;
    while (currentNode) {
        if (searchKey == currentNode->key) {
            return currentNode;
        }
        else if (searchKey < currentNode->key) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }
    return nullptr;
}

//Insert node according to proper BST order
void BinarySearchTree::InsertNode(BSTNode* newNode) {
    if (root == nullptr) {
        root = newNode;
    }
    else {
        BSTNode* currentNode = root;
        while (currentNode) {
            if (newNode->key < currentNode->key) {
                if (currentNode->left == nullptr) {
                    currentNode->left = newNode;
                    currentNode = nullptr;
                }
                else {
                    currentNode = currentNode->left;
                }
            }
            else {
                if (currentNode->right == nullptr) {
                    currentNode->right = newNode;
                    currentNode = nullptr;
                }
                else {
                    currentNode = currentNode->right;
                }
            }
        }
    }
}

bool BinarySearchTree::Contains(int key) {
    return Search(key) != nullptr;
}

//Function to insert a new key into the BST
bool BinarySearchTree::InsertKey(int key) {
    if (Contains(key)) { //Ignore/disallow duplicate keys
        return false;
    }
    InsertNode(new BSTNode(key));
    return true;
}

//Constructor and Destructor for BST class
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}
BinarySearchTree::~BinarySearchTree() {
    DeleteTree(root);
}
