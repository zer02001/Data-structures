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

	/// creates a node and assigns the data item that was passed in as well as where the pointers left and right.



{




	dataItem = nodeDataItem;
	left = leftPtr;
	right = rightPtr;


}

///--------------------------------------------------------------------

template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>::BSTree()

// creates and empty binary and assigns the root to 0.



{


	root = 0;


}

///--------------------------------------------------------------------

template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>::BSTree(const BSTree& source)

/// creates and empty tree and then assigns the source tree to the root of this object by calling the copytree function 



{

	root = 0;
	copyTree(source);
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= (const BSTree& other_tree)

///sets the other tree to the current tree in the object

{
	/// Avoid accidentally trying to set object to itself.
	/// clears the current tree in the object and then sends the other tree to the 
	/// If the other tree is equal to the object tree then you can return this
	if (this.root != &other_tree.root)
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

///--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::copyTree(const BSTree<DataType, KeyType>& sourceTree)

/// Sets a tree to be equivalent to the tree source and pass it in the copyhelpertree.

{
	copyTreeHelper(root, sourceTree.root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::copyTreeHelper(BSTreeNode*& pointer, const BSTreeNode* otherpointer)

/// Recursive helper function that helps set a tree to be equivalent to another tree by creating enough nodes for the tree that is copied too.

{
	if (root != 0) {
		root = new BSTreeNode(otherpointer->DataItem, 0, 0);


		copyTreeHelper(pointer->left, otherpointer->left);



		copyTreeHelper(pointer->right, otherpointer->right);
	}
}

//--------------------------------------------------------------------
template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>:: ~BSTree()

/// Frees the memory used by the tree by calling the cleartree function to delete memory.

{
	cleartree();
}

///--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::insertnode(const DataType& newDataItem)

/// inserts node into the tree by usint the insert helper to figure where the dataitem will go in the tree.
{
	insertnodeHelper(root, newDataItem);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::insertnodeHelper(BSTreeNode*& pointer,
	const DataType& newDataItem)

	/// inserthelper takes in the data item and compare to check if the tree is empty to insert it in the root pointer.
	/// If the tree is not empty the dataitem key will be compared to the left and right nodes of the tree to figure out where it will be placed.
{
	if (pointer == 0)
		pointer = new BSTreeNode(newDataItem, 0, 0);




	else if (newDataItem.getKey() < pointer->dataItem.getKey()) /// compare the key with the root key.

		insertnodeHelper(pointer->left, newDataItem); /// switch to the left side of tree

	else if (newDataItem.getKey() > pointer->dataItem.getKey()) /// switch to searching the right side of the tree
		insertnodeHelper(pointer->right, newDataItem);
	else
		pointer->dataItem = newDataItem;
}

///--------------------------------------------------------------------

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::retrievekey(const KeyType& searchKey, DataType& searchDataItem) const

/// searches the tree for the searchdataitem and return true or false.
/// It will return true if it is found and will copy the data from the the tree to the searchDataItem


{
	return retrievekeyHelper(root, searchKey, searchDataItem);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::retrievekeyHelper(BSTreeNode* pointer,
	const KeyType& search_Key,
	DataType& searchDataItem) const

	/// helper that will search the tree to check if there is a tree node with the same dataitem.

{
	bool answer;

	if (pointer == 0)
	{

		answer = false; /// if the tree is empty then false will be returned
	}
	else if (search_Key < pointer->dataItem.getKey())
	{

		answer = retrievekeyHelper(pointer->left, search_Key, searchDataItem); /// search the left because the Key is smaller.
	}
	else if (search_Key > pointer->dataItem.getKey())
	{

		answer = retrievekeyHelper(pointer->right, search_Key, searchDataItem);  /// search the right side because the key is larger
	}
	else
	{

		searchDataItem = pointer->dataItem;
		answer = true;
	}

	return answer;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::removenode(const KeyType& delete_Key)



{
	/// deleted a node from the tree using the delete key that is passed in the function


	return removenodeHelper(root, delete_Key);
}

/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::removenodeHelper(BSTreeNode*& pointer, const KeyType& delete_Key)

/// traverses through the tree to check if the nodekey matches any of the nodes in the tree.
/// If the key is more than the node key then it will traverse to the right recursively.
/// If the key is less than the key of the node then it will traverse to the left until it finds the node
/// or it will make return false and not do the deleting.
{
	BSTreeNode* deleteP;
	bool answer;

	if (pointer == 0)
		answer = false;



	else if (delete_Key < pointer->dataItem.getKey())
		answer = removenodeHelper(pointer->left, delete_Key);
	else if (delete_Key > pointer->dataItem.getKey())
		answer = removenodeHelper(pointer->right, delete_Key);


	else
	{
		if (pointer->left == 0 || pointer->right == 0) {
			deleteP = pointer;
			if (pointer->left == 0)
			{
				pointer = pointer->right;
				delete deleteP;
			}
			else if (pointer->right == 0)
			{
				pointer = pointer->left;
				delete deleteP;
			}
		}

		else  if (pointer->left != 0 || pointer->right != 0)

		{

			BSTreeNode* t = pointer->left;
			while (t->right) {
				t = t->right;
			}

			pointer->dataItem = t->dataItem;

			removenodeHelper(pointer->left, t->dataItem.getKey());

		}
		answer = true;
	}

	return answer;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::cutRightmost(BSTreeNode*& r,
	BSTreeNode*& delpointer)

{
	if (r->right != 0)
		cutRightmost(r->right, delpointer);   /// moves to the right most of the tree by moving to the right of the tree until the right pointer of a node is 0.
	else if (r->right == 0)
	{
		delpointer->dataItem = r->dataItem; /// used to deleted the node and set the root node to the left node.
		r = r->left;
	}
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::writetreeKeys() const

// Outputs the keys from the smallest to the largest from the left to the right

{
	writeKeysHelper(root);

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::writeKeysHelper(BSTreeNode* pointer) const
/// outputs the keys of the tree from  recursively going from the left to the right side of the tree.

{
	if (pointer == 0)return;
	else
	{
		writeKeysHelper(pointer->left);
		cout << pointer->dataItem.getKey() << "---";
		writeKeysHelper(pointer->right);
	}
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::cleartree()

/// clears the tree from all the nodes and sets the root node to 0

{
	cleartreeHelper(root);
	root = 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::cleartreeHelper(BSTreeNode* pointer)

/// deletes all the nodes from the tree by freeing the me

{
	if (pointer != 0)
	{
		/// deleting the nodes of the tree from the left to the right to not cause any memory issues.
		cleartreeHelper(pointer->left);
		cleartreeHelper(pointer->right);


		delete pointer;
	}
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::istreeEmpty() const

/// returns true if the tree is empty and false if its not empty.

{
	if (root == 0) return true;
	else return false;
}


///--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::showtreeStructure() const

/// outputs the nodes of the tree and take into account which node will be on the left and right side of the tree.

{
	if (root == 0)
		cout << "The tree is empty insert nodes!!!!" << endl;
	else
	{
		cout << "\n\n";
		showlevelHelper(root, 1);
		cout << "\n\n";
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::showlevelHelper(BSTreeNode* p,
	int level) const

	/// recursive helper to print the nodes in the tree which will be go through the right side to print and add spaces to  the tree.
	/// each level of the tree will have 6 space different between each one of them.

{
	int j;   // Loop counter

	if (p != 0)
	{
		showlevelHelper(p->right, level + 1);
		for (j = 0; j < level; j++)
			cout << "      ";
		cout << " " << p->dataItem.getnodeKey();
		cout << endl << endl;
		showlevelHelper(p->left, level + 1);
	}
}

//--------------------------------------------------------------------
//                         Programming Exercise 2
//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::gettreeHeight() const

// used to return the hieght of the tree using the getheighthelper

{

	return  getHeightHelper(root);

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::getHeightHelper(BSTreeNode* pointer) const

/// recursive helper runs thro the tree from the left and right side
// If the rightside is longer than the right then the height of the tree will be used from the right.

{
	int lengthleft,        /// length to find the left side of the tree
		lengthright;        /// Length to find the right side of the tree


	if (pointer == 0)
		return 0;
	else
	{
		lengthleft = getHeightHelper(pointer->left) + 1;




		lengthright = getHeightHelper(pointer->right) + 1;



		if (lengthleft >= lengthright)
			return lengthleft;
		else return lengthright;
	}


}

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::gettreeCount() const

// return the amount of nodes that exist in the tree using the recursive helper.

{
	return gettreeCountHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::gettreeCountHelper(BSTreeNode* p) const

/// recursive helper goes thro the left and right nodes and that return the count in integers and adds one to it to find the count for them.

{
	if (p == 0) {
		return 0;
	}
	int count = gettreeCountHelper(p->left) + gettreeCountHelper(p->right) + 1;
	return count;
}



