#ifndef BST_H
#define BST_H

//Class for the nodes used in the BST implementation
class BSTNode {
public:
    int key;
    BSTNode* left; //Pointer to left child node
    BSTNode* right; //Pointer to right child node

    //Default class constructor declaration to initialize variables
    BSTNode(int nodeKey, BSTNode* leftChild = nullptr, BSTNode* rightChild = nullptr);
};

class BinarySearchTree {
private:
    BSTNode* root; //Declare root node to be used as start/root of BST

    //Recursive function that goes through a subtree and deletes all nodes under it
    void DeleteTree(BSTNode* subtreeRoot);

    //Recursive functions that travel through the BST according to the traversal type
    void BSTInOrder(BSTNode* node);
    void BSTPreOrder(BSTNode* node);
    void BSTPostOrder(BSTNode* node);

public:
    //Functions that print the results of the other traversal functions
    void BSTPrintInOrder();
    void BSTPrintPreOrder();
    void BSTPrintPostOrder();

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
#endif //BST_H
