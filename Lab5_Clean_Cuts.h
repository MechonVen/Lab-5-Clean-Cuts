//
// Created by bebon on 10/16/2025.
//

#ifndef LAB5_CLEAN_CUTS_H
#define LAB5_CLEAN_CUTS_H

class BSTNode {
public:
    int key;
    BSTNode* left; //Pointer to left child node
    BSTNode* right; //Pointer to right child node

    BSTNode(int nodeKey, BSTNode* leftChild = nullptr, BSTNode* rightChild = nullptr);
};

class BinarySearchTree {
private:
    BSTNode* root;

    void DeleteTree(BSTNode* subtreeRoot);

public:
    void BSTPrintInOrder(BSTNode* node);
    void BSTPrintPreOrder(BSTNode* node);
    void BSTPrintPostOrder(BSTNode* node);
    //Function declaration for searching for a key
    BSTNode* Search(int searchKey);

    //Functions responsible for inserting new nodes and checking for duplicates
    void InsertNode(BSTNode* newNode);
    bool Contains(int key);
    bool InsertKey(int key);

    //Constructor and Destructor declarations
    BinarySearchTree();
    ~BinarySearchTree();
};


//This needs to be below every class and class function for the implementation
//file to recognize
#endif //LAB5_CLEAN_CUTS_H
