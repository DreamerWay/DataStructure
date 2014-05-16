/*******************************************************************************
*
* FileName : HeapTest.cpp	
* Comment  : test the heap structure
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/15
*
*******************************************************************************/
#include <iostream>
#include "Heap.h"

int main()
{
	int array[10]={1,6,5,7,9,0,2,4,8,3};
	Heap<int> heap(array,10,1);
	heap.Print();

	heap.Insert(6);
	heap.Print();

	heap.Delete(6);
	heap.Print();

	heap.Insert(15);
	heap.Print();

	heap.Delete(3);
	heap.Print();

	heap.Delete(9);
	heap.Print();

	heap.Insert(10);
	heap.Print();

	heap.Insert(6);
	heap.Print();
	return 0;
}