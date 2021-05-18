#include "Heap.h"
//--------------------------------------------------------------------
//
//  Laboratory 11                                         show11.cpp
//
//  Array implementation of the showStructure operation for the
//  Heap ADT
//
//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>:: showStructure () const

// Outputs the priorities of the data items in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
    int j;   // Loop counter

    cout << endl;
    if ( size == 0 )
       cout << "Empty heap" << endl;
    else
    {
       cout << "size = " << size << endl;       // Output array form
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ )
           cout << treenodes[j].getPriority() << "\t";
       cout << endl << endl;
       showSubtree(0,0);                        // Output tree form
    }
}

template<typename DataType, typename KeyType, typename Comparator>
void Heap<DataType, KeyType, Comparator>::writeLevels() const
{
    int level = 1;
    int nodes = 0;
    for (int i = 0; i < size; i++)
    {
        if (nodes == level)
        {
            cout << endl << endl;
            nodes = 0;
            level *= 2;
        }
        cout << treenodes[i].getPriority() << "   ";
        nodes += 1;
    }
    cout << endl;
    cout << endl;






}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>:: showSubtree ( int index, int level ) const

// Helper function for the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in treenodes[index]. Argument
// level is the level of this treenodes within the tree.

{
     int j;   // Loop counter

     if ( index < size )
     {
        showSubtree(2*index+2,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )        // Tab over to level
            cout << "\t";
        cout << " " << treenodes[index].getPriority();   // Output treenodes's priority
        if ( 2*index+2 < size )                // Output "connector"
           cout << "<";
        else if ( 2*index+1 < size )
           cout << "\\";
        cout << endl;
        showSubtree(2*index+1,level+1);        // Output left subtree
    }
}

