/*******************************************************************************
*
* FileName : DuLinkListTest.cpp
* Comment  : test the DuLinkList structure
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/14
*
*******************************************************************************/
#include <iostream>
#include "DuLinkList.h"

int main()
{
	DuLinkList<double> list;
	for(double i=1;i<10;i++)
		list.Insert(i);
	list.Print();
	cout<<list.Length();

	list.Insert(100,10);
	list.Print();

	list.Insert(5.3,3);
	list.Print();

	list.Remove(3);
	list.Print();

	list.Remove(15);
	list.Print();

	DuListNode<double>* pData=list.GetData(6);
	if(pData)
		cout<<*pData<<endl;

	list.Clear();
	list.Print();
	
	DuListNode<double>* pData1=list.GetData(6);
	if(pData1)
		cout<<*pData1<<endl;
	return 0;
}