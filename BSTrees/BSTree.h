#pragma once
#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <stdio.h>
#include <iostream>



template < typename DataType, class KeyType >    // DataType : tree data item
class BSTree                                     // KeyType : key field
{
public:

    /// Constructor for creating an empty tree or copy another tree
    BSTree();                         /// Default constructor creates an empty with node being equal to 0
    BSTree(const BSTree<DataType, KeyType>& other);   /// Copy constructor copies node from one tree to the other
    BSTree& operator= (const BSTree<DataType, KeyType>& other_tree);
    /// Overloaded assignment operator to check if the other tree is equal to the current object tree.

// Destructor used to delete all the nodes from the tree
    ~BSTree();
	 
    // Binary search tree manipulation operations
    void insertnode(const DataType& newDataItem); // Insert data item
    bool retrievekey(const KeyType& searchKey, DataType& searchDataItem) const;
    // Retrieve data item
    bool removenode(const KeyType& deleteKey);            // Remove data item
    void writetreeKeys() const;                      // Output keys
    void cleartree();                                // Clear tree

    // Binary search tree status operations
    bool istreeEmpty() const;                        // Tree is empty
    // !! isFull() has been retired. Not very useful in a linked structure.

    // Output the tree structure -- used in testing/debugging
    void showtreeStructure() const;

    // In-lab operations
    int gettreeHeight() const;                       // Height of tree
    int gettreeCount() const;              // Number of nodes in tree
    void writeLessThan(const KeyType& searchKey) const; // Output keys < searchKey

protected:

    class BSTreeNode                  // Inner class: facilitator for the BSTree class
    {
    public:

        // Constructor
        BSTreeNode(const DataType& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr);

        // Data members
        DataType dataItem;         // Binary search tree data item
        BSTreeNode* left,    // Pointer to the left child
            * right;   // Pointer to the right child
    };

    // Recursive helpers for the public member functions -- insert
    // prototypes of these functions here.
    void insertnodeHelper(BSTreeNode*& p, const DataType& newDataItem);
    bool retrievekeyHelper(BSTreeNode* p, const KeyType& searchKey, DataType& searchDataItem) const;
    bool removenodeHelper(BSTreeNode*& p, const KeyType& deleteKey);
    // cutRightmose used in one implementation of remove.
    void cutRightmost(BSTreeNode*& r, BSTreeNode*& delPtr);
    void writeKeysHelper(BSTreeNode* p) const;
    void cleartreeHelper(BSTreeNode* p);
    void showlevelHelper(BSTreeNode* p, int level) const;
    int getHeightHelper(BSTreeNode* p) const;
    int gettreeCountHelper(BSTreeNode* p) const;
    void writeLTHelper(BSTreeNode* p, const KeyType& searchKey) const;
    void copyTree(const BSTree<DataType, KeyType>& otherTree);
    void copyTreeHelper(BSTreeNode*& p, const BSTreeNode* otherPtr);

    // Data member
    BSTreeNode* root;   // Pointer to the root node
};

#endif   // define BSTREE_H