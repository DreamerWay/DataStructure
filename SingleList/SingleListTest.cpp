/*******************************************************************************
*
* FileName : SingleListTest.cpp
* Comment  : test the structure of SingleList
* Version  : 1.0				
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/13
*
*******************************************************************************/
#include<iostream>
#include "SingleList.h"
using namespace std;

int main()
{
	SingleList<int> list;
	SiListNode<int>* pNode=NULL;
	for(int i=0;i<10;i++)
		list.Insert(i,1);
	
	cout<<list.Length()<<endl;
	list.Print();

	list.Insert(100,0);
	list.Print();

	list.Insert(100,5);
	list.Print();

	list.Insert(100,15);
	list.Print();
	
	pNode=list.GetNode(5);
	cout<<*pNode<<endl;

	list.Remove(0);
	list.Print();

	list.Remove(5);
	list.Print();

	list.Remove(15);
	list.Print();

	pNode=list.GetNode(5);
	cout<<*pNode<<endl;

	list.Clear();
	list.Print();
	return 0;
}