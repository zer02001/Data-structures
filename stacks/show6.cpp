/// show6.cpp

///--------------------------------------------------------------------
#include "StackArray.h"
#include "StackLinked.h"
template <typename DataType>
void StackArray<DataType>::showStructure() const 

/// Array implementation. Outputs the data items in a stack. If the
/// stack is empty, outputs "Empty stack". This operation is intended
/// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxStackSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << datastackItems[j] << ']'<< "\t"; // Identify top
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

///--------------------------------------------------------------------

