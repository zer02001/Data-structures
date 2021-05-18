#include "HashTable.h"



template<typename DataType, typename KeyType>
inline HashTable<DataType, KeyType>::HashTable(int initTableSize)
{


	///precondition: The precondition that the object is created with an input for how big the table size would be.
	///postcondtion: The hastable is created with the use of the table size and using the BST tree to create the array for the nodes.\
	/// input: The input to this function is the size of the table that is needed to be used.
	/// output: The output is a hash table that is created using the binary tree for the nodes that are placed in the same index.


	/// summary: This function takes in the size of the table from the user and creates a new hashtable by allocating new memory using the bst tree to make the array of trees.
	
	tableSize = initTableSize;

	hashtable = new BSTree<DataType, KeyType>[tableSize];






}

template<typename DataType, typename KeyType>
inline HashTable<DataType, KeyType>::HashTable(const HashTable& other)
{
	///precondition: The precondition that the object is created with an input of the other hastable to be copied to the current object.
	///postcondtion: The hastable is created and copied the nodes from other hastable using the other referrence.
	/// input: The input to this function is the other hashtable function that gets copied to the new object created
	/// output: The output is a hash table that is created with the same index values as the other hashtable.

	/// summary: This function takes in the other hastable object and copies the values from it to the new object that has been created 



	tableSize = other.tableSize;


	
	
	
	hashtable = new BSTree<DataType, KeyType>[other.tableSize];

	for (int i = 0; i < other.tableSize; i++)
		hashtable[i] = other.hastable[i];

}

template<typename DataType, typename KeyType>
inline HashTable<DataType , KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable& other)
{

	///precondition: The precondition that the object is created with an input of the other hastable to be copied to the current object.
	///postcondtion: The hastable is created and copied the nodes from other hastable using the other referrence.
	/// input: The input to this function is the other hashtable function that gets copied to the current object that is used for the hashtable
	/// output: The output is a hash table that is created with the same index values as the other hashtable.

	/// summary: This function takes in the other hastable object and copies the values from it to an already existing hashtable .



	if (this != &other)
		return *this;


	else {
		

		for (int i = 0; i < tableSize; i++) {


			hashtable[i].cleartree();


		}

		tableSize = other.tableSize;

		hashtable = new BSTree<DataType, KeyType>[other.tableSize];

		for (int i = 0; i < other.tableSize; i++)
			hashtable[i] = other.hastable[i];
	
	
	}

	return *this;




	 
	
}

template<typename DataType, typename KeyType>
inline HashTable<DataType, KeyType>::~HashTable()
{
	///precondition: The precondition that the object is created and the object gets out of scope for the deconstructer to be called.
	///postcondtion: The post condition is that all the indexs in the hastable get cleared and the hashtable is deleted from memory.
	/// input:  NO input.
	/// output: The output is that the hashtable cleared and the deleted.

	/// summary: This function clears the hashtable from all the indexs and then deletes the hashtable from all the indexes.
	

	for (int i = 0; i < tableSize; i++) {


		hashtable[i].cleartree();


	}



	delete hashtable;
}

template<typename DataType, typename KeyType>
inline void HashTable<DataType, KeyType>::insert(const DataType& newDataItem)
{

	///precondition: The precondition that the object is created and the hashtable is created 
	///postcondtion: The post condition is that a node is added to the hashtable using this function.
	/// input:  The new data item that is inserted into the hashtable using the hashing function.
	/// output: hashtable with an one extra data item that is inserted into the table.

	/// summary: This function inserts a new data item to the hashtable and places it using the hash function.



	unsigned int hashkey = newDataItem.hash(newDataItem.getKey());

	int poistion = hashkey %= tableSize;

	hashtable[poistion].insertnode(newDataItem);






}

template<typename DataType, typename KeyType>
inline bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey)
{

	///precondition: The precondition that the object is created and the hashtable is created 
	///postcondtion: The post condition is that a node is removes from  the hashtable using this function.
	/// input:  The delete key  that is deleted from the hashtable using the hashing function.
	/// output: hashtable with one deleted index from the hash function.

	/// summary: This function deletes a node from hastable if the node is found in the one of positions.

	DataType temp;
	unsigned int hashkey =  temp.hash(deleteKey);

	 int poistion = hashkey %= tableSize;

	return hashtable[poistion].removenode(deleteKey);
}

template<typename DataType, typename KeyType>
inline bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const
{
	///precondition: The precondition that the object is created and the hashtable is created 
	///postcondtion: The post condition is that the return item is returned to the user if the search key is found.
	/// input:  the input is the search key to find the data item in the hashtable and the return item that will be returned at the end of the function
	/// output: return data if it was found in the hashtable or the function will return false instead.

	/// summary: This function takes in the search key to look for in the hashtable use the hash function to check if the search key exists in the hashtable.




	unsigned int hashkey = returnItem.hash(searchKey);
	 int position = hashkey % tableSize;

	return hashtable[position].retrievekey(searchKey, returnItem);
}

template<typename DataType, typename KeyType>
inline void HashTable<DataType, KeyType>::clear()
{
	///precondition: The precondition that the object is created and the hashfunction has some data items added to it.
	///postcondtion: The post condition is that all the indexs in the hastable get cleared.
	/// input:  NO input.
	/// output: The output is that the hashtable cleared from all the indexes.

	/// summary: This function clears the hashtable from all the nodes in it.



	for (int i = 0; i < tableSize; i++) {
	
	
		hashtable[i].cleartree();
	
	
	}



}

template<typename DataType, typename KeyType>
inline bool HashTable<DataType, KeyType>::isEmpty() const
{

	///precondition: The precondition that the object is created.
	///postcondtion: The post condition is that the hashtable isnot effected by this function.
	/// input:  NO input.
	/// output: The output is that the hashtable cleared from all the indexes.

	/// summary: This function returns true if the function is empty by checking the hashtable at each position

	for (int i = 0; i < tableSize; i++) {


		 if (hashtable[i].istreeEmpty() == false);
		 return false;


	}


	return true;

}


template<typename DataType, typename KeyType>
double HashTable<DataType, KeyType>::standardDeviation() const
{
	return -1.0;
}

template<typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source)
{

///precondition: The precondition that the object is created and an  input of the other hastable to be copied to the current object.
///postcondtion: The hastable is created and copied the nodes from other hastable using the other referrence.
/// input: The input to this function is the other hashtable function that gets copied to the current object that is used for the hashtable
/// output: The output is a hash table that has its indexes copied from the other source tree.

/// summary: This function takes in the other hastable object and copies the values from it to an already existing hashtable .


	delete hashtable;
	
	hashtable = new BSTree<DataType, KeyType>[source.tableSize];

	for (int i = 0; i < source.tableSize; i++)
		hashtable[i] = source.hastable[i];

}


template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const {
	for (int i = 0; i < tableSize; ++i) {
		cout << endl;
		cout << i << ": ";
		hashtable[i].showtreekeys();
		cout << endl;
	}
}

