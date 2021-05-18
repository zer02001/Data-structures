//--------------------------------------------------------------------
//
//  Laboratory 6                                          StackArray.h
// 
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------


#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType> {

  public:

    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackLinked(const StackLinked& other);
    StackLinked& operator=(const StackLinked& other);
    ~StackLinked();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:

    class StackNode {
      public:
	StackNode(const DataType& nodeData, StackNode* nextPtr);

	DataType dataItem;
	StackNode* next;
    };

    StackNode* top;
};

	//#ifndef STACKARRAY_H


template<typename DataType>
inline StackLinked<DataType>::StackLinked(int maxNumber)
{
	/// precondition: The stack is empty with no linked node.
	/// postcondtion: an empty stack is created with the top being set to NULL;
	/// input: The input is the maxnumber of stacks in the linked stack 
	/// output: empty stack with the top being equal to NULL.
	/// summary: this function takes in the maximum number of stacks can be in the stack and creates an empty stack.


	top = NULL;


}



///--------------------------------------------------------------------

template<typename DataType>
inline StackLinked<DataType>::StackLinked(const StackLinked& other)
{




	/// precondition: The stack is empty with no linked node.
	/// postcondtion: a copy of the other stack is made to create the new stack in the object.
	/// input: The input is the other stacklinked object that will be copied into the current object linked stack.
	/// output: stacklinked that is a copy of the other linked stack.
	/// summary: this function takes in a stack linked object and copys it into the new object that is this.



	StackNode other_top = other.top;




	top = 0;


	while (other_top != NULL) {


		top = new StackNode(other_top->dataItem, top);
		other_top = other_top->next;




	}
	return this;


}



///--------------------------------------------------------------------

template<typename DataType>
inline StackLinked <DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{



	/// precondition: the other linkedstack has stacks in it for the copying to be done.
	/// postcondtion: a copy of the other stack is made to create the new stack in the object.
	/// input: The input is the other stacklinked object that will be copied into the current object linked stack.
	/// output: stacklinked that is a copy of the other linked stack.
	/// summary: this function takes in a stack linked object and copys it into the new object that is this.


	StackNode other_top = other.top;

	if (this != &other) return *this;

	clear();


	top = NULL;


	while (other_top != NULL) {


		top = new StackNode(other_top->dataItem, top);
		other_top = other_top->next;




	}
	return this;




}




///--------------------------------------------------------------------

template<typename DataType>
inline StackLinked<DataType>::~StackLinked()
{// postcondtion: The post condtion is that the linked stack is empty with no stacks in it.
/// input: No input.
/// output: Empty stack that has no stacks in it.
/// summary: This function calls the clear funtion that is used to clear the linked stack.


	clear();
}





///--------------------------------------------------------------------

template<typename DataType>
inline void StackLinked<DataType>::push(const DataType& newDataItem) throw(logic_error)

/// precondition: the precondition is that the linked stack is created either empty or not full.
/// postcondtion: A stack is pushed into the linked stack and the top pointer is moved up.
/// input: a new data item that would be assigned to the data item of the stack that will be pushed.
/// output: a stack with an one more stack or return an error if there is an issue with it.
/// summary: this function takes in a newdataitem and creates a new stacknode that is pushed onto that stack if the stack isnot full.



{
	if (isFull() != false) {

		throw logic_error("push() while stack full");
	}
	else {

		StackNode* newstacknode = new StackNode(newDataItem, top);

		newstacknode->next = top;
		top = newstacknode;


	}



}




///--------------------------------------------------------------------


template<typename DataType>
inline DataType StackLinked<DataType>::pop() throw(logic_error)
{

	/// precondition: the precondition is that the linked stack is created either and isnot empty
	/// postcondtion: A stacknode is popped the linked stack and the top pointer is moved down.
	/// input:No input.
	/// output: a stack with one less  stacknode or return an error if the the linked stack is full.
	/// summary: This function pops a stacknode from the linked stack and moves the top pointer to the previous stacknode.

	if (isEmpty() == true)
		throw logic_error("the stack is empty nothing to pop from it");

	else {


		StackNode* tempptr = top->next;

		StackNode* temptop = top;

		top = tempptr;

		delete temptop;




	}







}




///--------------------------------------------------------------------

template<typename DataType>
inline void StackLinked<DataType>::clear()
{

	/// precondition: the precondition is that the linkedstack is created and is either empty or has stacks.
	/// postcondtion: The post condtion is that the linked stack is empty with no stacks in it.
	/// input: No input.
	/// output: Empty stack that has no stacks in it.
	/// summary: this function deletes the top pointer that has has and emptys all the stacknodes.


	StackNode* temp;
	StackNode* nexttemp;
	while (top != NULL) {

		temp = top;
		nexttemp = top->next;
		top = nexttemp;

		delete temp;



	}






}






///--------------------------------------------------------------------

template<typename DataType>
inline bool StackLinked<DataType>::isEmpty() const
{

	/// precondition: the precondition is that the linkedstack is created and is either empty or has stacks.
/// postcondtion: The post condtion is that the linked stack is empty or has stacknodes in it.
/// input: No input.
/// output: returns true if the linked stack is empty
/// summary: This function tests if the top of the stack is empty and returns true if its empty else it will return false.



	if (top == NULL) return true;
	else return false;




}




///--------------------------------------------------------------------

template<typename DataType>
inline bool StackLinked<DataType>::isFull() const
{

	/// precondition: the precondition is that the linkedstack is created and is either empty or has stacks.
/// postcondtion: The post condtion is that the linked stack is empty or has stacknodes in it.
/// input: No input.
/// output: returns true if the linked stack is full or not.
/// summary: This function tests if the top of the stack is at the maximum amount of stacknodes allowed
	return false;
}



///--------------------------------------------------------------------

template<typename DataType>
inline StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr)
{
	/// precondition: the precondition is that the linkedstack is created and is either empty or has stacks.
	/// postcondtion: The post condtion is that the linked stack has an extra stacknode in it
	/// input: the node data that will take the data item that will be assigned to the nodedata and the next pointer for it.
	/// output: a new stacknode that is added to the stack.
	/// summary: This function will create a new stacknode with the data item that is needed for it.
	dataItem = nodeData;
	next = nextPtr;



}



///--------------------------------------------------------------------
template <typename DataType>
void StackLinked <DataType>::showStructure() const

/// precondition: the precondition is that the tree either has nodes or it is empty.
/// postcondtion: The post condtion is that the linked stack is empty or has stacknodes in it.
/// input: No input.
/// output: output the nodes in the stack and a pointer to the top of the stack.
/// summary: This function takes in the stack and outputs the data item in the stacknodes of the stack.

{
	if (top == NULL)
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		cout << "Top\t";
		for (StackNode* temp = top; temp != 0; temp = temp->next) {
			if (temp == top) {
				cout << " '[" << temp->dataItem << "]\t ";
			}
			else {
				cout << temp->dataItem << "\t";
			}
		}
		cout << "Bottom" << endl;
	}

}



/// precondition: the precondition is that the linkedstack is created and is either empty or has stacks.
