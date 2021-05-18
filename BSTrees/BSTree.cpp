////  Laboratory 9                                            BSTree.cpp
//#ifndef BSTREE_CPP
#define BSTREE_CPP
#include <new>
#include <iostream>
#include "BSTree.h"
using namespace std;
//--------------------------------------------------------------------
template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode(const DataType& nodeDataItem,
    BSTreeNode* leftPtr,
    BSTreeNode* rightPtr)

    // Creates a binary search tree node containing data item elem, left
    // child pointer leftPtr, and right child pointer rightPtr.

    : dataItem(nodeDataItem),
    left(leftPtr),
    right(rightPtr)

{}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>::BSTree()

// Creates an empty tree.

    : root(0)

{}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>::BSTree(const BSTree& source)

// Creates an empty tree.

    : root(0)

{
    copyTree(source);
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= (const BSTree& other_tree)

// Sets a tree to be equivalent to the tree "source".

{
    // Avoid accidentally trying to set object to itself.
    // Calling clear() on an object, then copying the deleted data doesn't work.
    // Although this may seems like overkill and an unlikely scenario, it can happen,
    if (this != &other_tree)
    {
        cleartree();
        copyTree(other_tree);
        return *this;
    }
    else
    {
        return *this;
    }
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::copyTree(const BSTree<DataType, KeyType>& sourceTree)

// Sets a tree to be equivalent to the tree "source".

{
    copyTreeHelper(root, sourceTree.root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::copyTreeHelper(BSTreeNode*& p, const BSTreeNode* sourcePtr)

// Recursive helper function that helps set a tree to be equivalent to another tree.

{
    if (p != 0) {
        p = new BSTreeNode(sourcePtr->DataItem, 0, 0);
        copyTreeHelper(p->left, sourcePtr->left);
        copyTreeHelper(p->right, sourcePtr->right);
    }
}

//--------------------------------------------------------------------
template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>:: ~BSTree()

// Frees the memory used by a tree.

{
    cleartree();
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::insertnode(const DataType& newDataItem)


{
    insertnodeHelper(root, newDataItem);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::insertnodeHelper(BSTreeNode*& p,
    const DataType& newDataItem)

    // Recursive helper function for insert. Inserts newDataItem in
    // the subtree pointed to by p.

{
    if (p == 0) // Insert
        p = new BSTreeNode(newDataItem, 0, 0);
    else if (newDataItem.getKey() < p->dataItem.getKey())
        insertnodeHelper(p->left, newDataItem);                  // Search left
    else if (newDataItem.getKey() > p->dataItem.getKey())
        insertnodeHelper(p->right, newDataItem);                 // Search right
    else
        p->dataItem = newDataItem;                           // Update
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::retrievekey(const KeyType& searchKey, DataType& searchDataItem) const

// Searches a tree for the data item with key searchKey. If the data item
// is found, then copies the data item to searchDataItem and returns true.
// Otherwise, returns false with searchDataItem undefined.

{
    return retrievekeyHelper(root, searchKey, searchDataItem);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::retrievekeyHelper(BSTreeNode* p,
    const KeyType& searchKey,
    DataType& searchDataItem) const

    // Recursive helper function for retrieve. Searches the subtree
    // pointed to by p.

{
    bool result;   // Result returned

    if (p == 0)
    {
        // Fell off the tree while searching. Item is not in tree.
        result = false;
    }
    else if (searchKey < p->dataItem.getKey())
    {
        // Key is smaller than current node. Search to left.
        result = retrievekeyHelper(p->left, searchKey, searchDataItem);
    }
    else if (searchKey > p->dataItem.getKey())
    {
        // Key is larger than current node. Search to right.
        result = retrievekeyHelper(p->right, searchKey, searchDataItem);
    }
    else
    {
        // Found the desired item
        searchDataItem = p->dataItem;
        result = true;
    }

    return result;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::removenode(const KeyType& deleteKey)

// Removes the data item with key deleteKey from a tree. If the
// data item is found, then deletes it from the tree and returns true.
// Otherwise, returns false.

{
    return removenodeHelper(root, deleteKey);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::removenodeHelper(BSTreeNode*& p, const KeyType& deleteKey)


{
    BSTreeNode* delPtr; // Pointer to node to delete
    int result;                 // Result returned

    if (p == 0)
        result = false;                           // Search failed
    else if (deleteKey < p->dataItem.getKey())
        result = removenodeHelper(p->left, deleteKey);    // Search left
    else if (deleteKey > p->dataItem.getKey())
        result = removenodeHelper(p->right, deleteKey);   // Search right
    else
    {                                            // Found
        delPtr = p;
        if (p->left == 0)
        {
            p = p->right;                    // No left child
            delete delPtr;
        }
        else if (p->right == 0)
        {
            p = p->left;                     // No right child
            delete delPtr;
        }
        else
            // Node has both children: removing is more complex.
        {

            // ** Start implemtation option #1
            // Find node with largest key smaller than p's key.
            BSTreeNode* temp = p->left;
            while (temp->right) {
                temp = temp->right;
            }
            // Copy node data to p
            p->dataItem = temp->dataItem;
            // And remove the node whose data was copied to p.
            removenodeHelper(p->left, temp->dataItem.getKey());

        }
        result = true;
    }

    return result;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::cutRightmost(BSTreeNode*& r,
    BSTreeNode*& delPtr)

{
    if (r->right != 0)
        cutRightmost(r->right, delPtr);   // Continue down to the right
    else
    {
        delPtr->dataItem = r->dataItem;
        delPtr = r;
        r = r->left;
    }
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::writetreeKeys() const

// Outputs the keys in a tree in ascending order.

{
    writeKeysHelper(root);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::writeKeysHelper(BSTreeNode* p) const

// Recursive helper for writeKeys.
// Outputs the keys in the subtree pointed to by p.

{
    if (p != 0)
    {
        writeKeysHelper(p->left);
        cout << p->dataItem.getKey() << " ";
        writeKeysHelper(p->right);
    }
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::cleartree()

// Removes all the nodes from a tree.

{
    cleartreeHelper(root);
    root = 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::cleartreeHelper(BSTreeNode* p)

// Recursive helper for clear. Clears the subtree pointed to by p.

{
    if (p != 0)
    {
        // Use post-order traversal. Otherwise get into trouble by
        // referencing p->left and/or p->right after p had been deallocated.
        cleartreeHelper(p->left);
        cleartreeHelper(p->right);
        delete p;
    }
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::istreeEmpty() const

// Returns true if a tree is empty. Otherwise returns false.

{
    return root == 0;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::showtreeStructure() const

// Outputs the keys in a binary search tree. The tree is output
// rotated counterclockwise 90 degrees from its conventional
// orientation using a "reverse" inorder traversal. This operation is
// intended for testing and debugging purposes only.

{
    if (root == 0)
        cout << "Empty tree" << endl;
    else
    {
        cout << endl;
        showlevelHelper(root, 1);
        cout << endl;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::showlevelHelper(BSTreeNode* p,
    int level) const

    // Recursive helper for showStructure.
    // Outputs the subtree whose root node is pointed to by p.
    // Parameter level is the level of this node within the tree.

{
    int j;   // Loop counter

    if (p != 0)
    {
        showlevelHelper(p->right, level + 1);         // Output right subtree
        for (j = 0; j < level; j++)    // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem.getKey();   // Output key
        if ((p->left != 0) &&           // Output "connector"
            (p->right != 0))
            cout << "<";
        else if (p->right != 0)
            cout << "/";
        else if (p->left != 0)
            cout << "\\";
        cout << endl;
        showlevelHelper(p->left, level + 1);          // Output left subtree
    }
}

//--------------------------------------------------------------------
//                         Programming Exercise 2
//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::gettreeHeight() const

// Returns the height of a tree.

{
    return getHeightHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::getHeightHelper(BSTreeNode* p) const

// Recursive helper for height. Returns the height of
// the subtree pointed to by p -- that is, the length of the longest
// path from the node pointed to by p to any leaf node.

{
    int l,        // Length of the longest path thru the left child
        r,        // Length of the longest path thru the right child
        result;   // Result returned

    if (p == 0)
        result = 0;                    // Leaf node
    else
    {
        l = getHeightHelper(p->left) + 1;    // Get height of left subtree
        r = getHeightHelper(p->right) + 1;   // Get height of right subtree
        if (l >= r)                  // Return larger
            result = l;
        else
            result = r;
    }

    return result;
}

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::gettreeCount() const

// Returns the number of nodes in the tree

{
    return gettreeCountHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::gettreeCountHelper(BSTreeNode* p) const

// Recursive partner of the getCount() function. Returns the count of
// the subtree pointed to by p -- that is, the number of nodes in the
// left child + number of nodes in the right child + 1

{
    if (p == 0) {
        return 0;
    }

    return gettreeCountHelper(p->left) + gettreeCountHelper(p->right) + 1;
}


template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::writeLessThan(const KeyType& searchKey) const

// Outputs the keys in a tree that are less than searchKey.

{
    writeLTHelper(root, searchKey);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::writeLTHelper(BSTreeNode* p,
    const KeyType& searchKey) const

    // Recursive helper function for writeLessThan. Outputs the keys
    // in the subtree pointed to by p that are less than searchKey.

{
    if (p != 0)
    {
        writeLTHelper(p->left, searchKey);
        if (searchKey > p->dataItem.getKey())
        {
            cout << p->dataItem.getKey() << endl;
            writeLTHelper(p->right, searchKey);
        }
    }
}


