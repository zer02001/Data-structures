#ifndef HEAP_CPP
#define HEAP_CPP


#include "Heap.h"
/// precondition:
/// postcondtion: 
/// 
/// <typeparam name="DataType"></typeparam>
template<typename DataType, typename KeyType, typename Comparator>
inline Heap<DataType, KeyType, Comparator>::Heap(int maxNumber)
{


	maxSize = maxNumber;
	size = 0;
	treenodes = new DataType[maxSize];




}

template<typename DataType, typename KeyType, typename Comparator>
inline Heap<DataType, KeyType, Comparator>::Heap(const Heap& other)
{
    if (this == other) return *this;
    else {
        maxSize = other.maxNumber;
        size = other.size;
        treenodes = new DataType[maxSize];
    }
    
}

template<typename DataType, typename KeyType, typename Comparator>
inline  Heap <DataType, KeyType, Comparator>& Heap<DataType, KeyType, Comparator>::operator=(const Heap& other)
{
	if (this == &other) return *this;

	if (size != 0 ) {

        for (int i = 0; i < maxSize; i++) {

            treenodes[i] = 0;



        }

        size = 0;
	}

	maxSize = other.maxNumber;
	size = other.size;
	treenodes = new DataType[maxSize];

	for (int i = 0; i < size; i++) {
	
        treenodes[i] = other.treenodes[i];
	
	
	
	
	}



	
}

template<typename DataType, typename KeyType, typename Comparator>
inline Heap<DataType, KeyType, Comparator>::~Heap()
{

   
    size = 0;

	delete [] treenodes;





}

template<typename DataType, typename KeyType, typename Comparator>
inline void Heap<DataType, KeyType, Comparator>::insert(const DataType& newDataItem) throw(logic_error)
{
    if ( size == maxSize) throw logic_error("error found the heap is full");

	else {
	
        Comparator comparing;
		int position = size;
		treenodes[size] = newDataItem;
		

		while (comparing(treenodes[position].getPriority(), treenodes[(position - 1) / 2].getPriority())) {
		
		
			DataType temp = treenodes[position];
            DataType temp2 = treenodes[(position - 1) / 2];

            treenodes[position] = temp2;
			treenodes[(position - 1) / 2] = temp;
			position = (position - 1) / 2;
		
		
		
		
		
		
		
		
		}
		size++;
	
	
	
	
	
	
	}


	



}

template<typename DataType, typename KeyType, typename Comparator>
inline DataType Heap<DataType, KeyType, Comparator>::remove() throw(logic_error)
{
    if (size == 0)
    {
        throw logic_error("The list is empty please add nodes first!!!!");
    }
    
        size--;

        DataType returnData = treenodes[0];
        treenodes[0] = treenodes[size];


        int position = 0;
        while (position < size)
        {
            Comparator comparing;
            if ((position * 2) + 2 <= size)
            {

                if (comparing(treenodes[position].getPriority(),
                    treenodes[(position * 2) + 1].getPriority()))
                {

                    if (comparing(treenodes[position].getPriority(),
                        treenodes[(position * 2) + 2].getPriority())) {
                        return returnData;
                    }

                    else if (comparing(treenodes[(position * 2) + 2].getPriority(),
                        treenodes[(position * 2) + 1].getPriority()))
                    {
                        DataType temp1 = treenodes[position];
                        DataType temp2 = treenodes[(position * 2) + 2];


                        treenodes[position] = temp2;
                        treenodes[(position * 2) + 2] = temp1;
                        position = (position * 2) + 2;
                    }

                    else
                    {
                        DataType temp1 = treenodes[position];
                        DataType temp2 = treenodes[position + 1];


                        treenodes[position] = temp2;
                        treenodes[(position * 2) + 1] = temp1;
                        position = (position * 2) + 1;
                    }
                }
            }

            else if ((position * 2) + 1 <= size)
            {

                if (comparing(treenodes[(position * 2) + 1].getPriority(),
                    treenodes[position].getPriority()))
                {
                    DataType temp = treenodes[position];
                    DataType temp2 = treenodes[(position * 2) + 1];


                    treenodes[position] = temp2;
                    treenodes[(position * 2) + 1] = temp;
                    position = (position * 2) + 1;
                }
                else if (!(comparing(treenodes[(position * 2) + 1].getPriority(),
                    treenodes[position].getPriority())))
                {
                    return returnData;
                }
            }
            else
            {
                return returnData;
            }
        }

        return returnData;

    
}

template<typename DataType, typename KeyType, typename Comparator>
inline void Heap<DataType, KeyType, Comparator>::clear()
{


    size = 0;
}

template<typename DataType, typename KeyType, typename Comparator>
inline bool Heap<DataType, KeyType, Comparator>::isEmpty() const
{
    if (size == 0) return true;
    else return false;
}

template<typename DataType, typename KeyType, typename Comparator>
inline bool Heap<DataType, KeyType, Comparator>::isFull() const
{
    if (size == maxSize) return true;

    else return false;
}

#endif