//--------------------------------------------------------------------
//
//  Laboratory 6                                         StackLinked.h
// 
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------
#pragma once
#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackArray : public Stack<DataType> {
  public:
    StackArray(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackArray(const StackArray& other);
    StackArray& operator=(const StackArray& other);
    ~StackArray();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:
    int maxStackSize;
    int top;
    DataType* datastackItems;
};
#include"StackArray.h"
#include <iostream>

///--------------------------------------------------------------------

template<typename DataType>
inline StackArray<DataType>::StackArray(int maxNumber)
{
	/// precondition: The stack is empty with no array spot.
  /// postcondtion: an empty stack is created with the top being set to NULL;
  /// input: The input is the maxnumber of stacks in the array stack 
  /// output: empty stack with the top being equal to 0.
  /// summary: this function takes in the maximum number of stacks can be in the stack and creates an empty stack.
	top = 0;
	maxStackSize = maxNumber;


	datastackItems = new DataType[maxStackSize];

	for (int i = 0; i < (maxStackSize - 1); i++) {


		datastackItems[i] = 0;

	}








}




///--------------------------------------------------------------------

template<typename DataType>
inline StackArray<DataType>::StackArray(const StackArray& other)
{
	/// precondition: The stack is empty with no array spot.
/// postcondtion: a copy of the other stack is made to create the new stack in the object.
/// input: The input is the other Stackarray object that will be copied into the current object arraystack.
/// output: stackarray that is a copy of the other array stack.
/// summary: this function takes in a stackarray object and copys it into the new object that is this.
	top = other.top;

	maxStackSize = other.maxStackSize;

	datastackItems = new DataType[maxStackSize];

	for (int i = 0; i < (maxStackSize - 1); i++) {


		datastackItems[i] = other.datastackItems[i];

	}









}




///--------------------------------------------------------------------
template<typename DataType>
inline StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{




	/// precondition: the other arraystack has stacks in it for the copying to be done.
	/// postcondtion: a copy of the other stack is made to create the new stack in the object.
	/// input: The input is the other Stackarray object that will be copied into the current object array stack.
	/// output: Stackarray that is a copy of the other array stack.
	/// summary: this function takes in a stack array object and copys it into the new object that is this.














	maxStackSize = other.maxStackSize;
	top = other.top;
	for (int i = 0; i <= (maxStackSize - 1); i++)
	{

		datastackItems[i] = other.datastackItems[i];
	}

	return *this;











	// TODO: insert return statement here
}




///--------------------------------------------------------------------

template<typename DataType>
inline StackArray<DataType>::~StackArray()
{
	/// precondition: the precondition is that the arraystack is created and is either empty or has stacks.
/// postcondtion: The post condtion is that the array stack is empty with no stacks in it.
/// input: No input.
/// output: Empty stack that has no stacks in it.
/// summary: This function deleted the arrray that was used for the stack.


	delete[] datastackItems;



}




///--------------------------------------------------------------------
template<typename DataType>
inline void StackArray<DataType>::push(const DataType& newDataItem) throw(logic_error)
{
	/// precondition: the precondition is that the array stack is created either empty or not full.
/// postcondtion: A stack is pushed into the array stack and the top array spot is moved up.
/// input: a new data item that would be assigned to the data item of the stack that will be pushed.
/// output: a stack with an one more stack or return an error if there is an issue with it.
/// summary: this function takes in a newdataitem and creates a new arraystack spot  that is pushed onto that stack if the stack isnot full.


	if (top == (maxStackSize - 1)) {
		throw logic_error("error the stack is full canot push");
	}
	else
	{
		top = top + 1;
		datastackItems[top] = newDataItem;
	}
}


///--------------------------------------------------------------------


template<typename DataType>
inline DataType StackArray<DataType>::pop() throw(logic_error)
{

	/// precondition: the precondition is that the array stack is created either and isnot empty
	/// postcondtion: A arraystack spot  is popped the array stack and the top array spot is moved down.
	/// input:No input.
	/// output: a stack with one less  arraystack spot  or return an error if the the array stack is full.
	/// summary: This function pops a arraystack spot  from the array stack and moves the top back one.
	if (top == -1) throw logic_error("error the stock is empty canot pop");

	else {
		top--;

		datastackItems[top + 1] = 0;



	}




}


///--------------------------------------------------------------------

template<typename DataType>
inline void StackArray<DataType>::clear()
{

	/// precondition: the precondition is that the arraystack is created and is either empty or has stacks.
	/// postcondtion: The post condtion is that the array stack is empty with no stacks in it.
	/// input: No input.
	/// output: Empty stack that has no stacks in it.
	/// summary: this function deletes the top array spot that has has and emptys all the arraystack spot .


	top = -1;

	for (int i = 0; i <= (maxStackSize - 1); i++)
	{

		datastackItems[i] = 0;
	}


}



///--------------------------------------------------------------------

template<typename DataType>
inline bool StackArray<DataType>::isEmpty() const
{

	/// precondition: the precondition is that the arraystack is created and is either empty or has stacks.
/// postcondtion: The post condtion is that the array stack is empty or has arraystack spot in it.
/// input: No input.
/// output: returns true if the array stack is empty
/// summary: This function tests if the top of the stack is empty and returns true if its empty else it will return false.
	if (top == -1) return true;
	else return false;
}


///--------------------------------------------------------------------
template<typename DataType>
inline bool StackArray<DataType>::isFull() const
{

	/// precondition: the precondition is that the arraystack is created and is either empty or has stacks.
/// postcondtion: The post condtion is that the array stack is empty or has arraystack spot s in it.
/// input: No input.
/// output: returns true if the array stack is full or not.
/// summary: This function tests if the top of the stack is at the maximum amount of arraystack spot allowed

	if (top == maxStackSize - 1) return true;
	else return false;



}




template <typename DataType>
void StackArray<DataType>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
	if (isEmpty()) {
		cout << "Empty stack." << endl;
	}
	else {
		int j;
		cout << "Top = " << top << endl;
		for (j = 0; j < maxStackSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j <= top; j++)
		{
			if (j == top)
			{
				cout << '[' << datastackItems[j] << ']' << "\t"; // Identify top
			}
			else
			{
				cout << datastackItems[j] << "\t";
			}
		}
		cout << endl;
	}
	cout << endl;
}





#endif		//#ifndef STACKARRAY_H


