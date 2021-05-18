//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 2                  heapsort.cs
//
//  (Shell) heapSort() function
//
//--------------------------------------------------------------------

template < typename DataType >
void moveDown ( DataType treenodes [], int root, int size )



	{
		int max_value = root; 
		int left = 2 * root + 1; 
		int right = 2 * root + 2; 

	
		if (left < size && treenodes[left] > treenodes[max_value])
			max_value = left;

	
		if (right < size && treenodes[right] > treenodes[max_value])
			max_value = right;

	
		if (max_value != root)

		{
			std::swap(treenodes[root], treenodes[max_value]);

		
			moveDown(treenodes, max_value, size);
		}

	}



//--------------------------------------------------------------------

template < typename DataType >
void heapSort ( DataType treenodes [], int size )

// Heap sort routine. Sorts the data items in the array in ascending
// order based on priority.

{
    DataType temp;   // Temporary storage
    int j;     // Loop counter

    // Build successively larger heaps within the array until the
    // entire array is a heap.

    for ( j = (size-1)/2 ; j >= 0 ; j-- )
        moveDown(treenodes,j,size);

    // Swap the root data item from each successively smaller heap with
    // the last unsorted data item in the array. Restore the heap after
    // each exchange.

    for ( j = size-1 ; j > 0 ; j-- )
    {
        temp = treenodes[j];
        treenodes[j] = treenodes[0];
        treenodes[0] = temp;
        moveDown(treenodes,0,j);
    }
}

