/*******************************************************************************
*
* FileName : SeqListTest.cpp
* Comment  : Test the SeqList datastructure in SeqList.h
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/06
*
*******************************************************************************/
#include <iostream>
#include "SeqList.h"


int main()
{
	SeqList<int> List(10);
	int array[10]={1,2,3,4,5,6};
	for (int i=0;i<10;i++)
	{
		List.InsertElement(array[i],0);
	}
	cout<<"the List's length:"<<List.Length()<<endl;
	List.Print();
	if(List.isFull())
		cout<<"the List is full"<<endl;

	List.InsertElement(3,2);
	List.RemoveElement(0);
	List.Print();

	cout<<List.GetElement(10)<<endl;
	cout<<"the List's length:"<<List.Length()<<endl;

	return 0;
}