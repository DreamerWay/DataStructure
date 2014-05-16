/*******************************************************************************
*
* FileName : SingleList.h
* Comment  : SingleList structure with head node
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/06
*
*******************************************************************************/

#ifndef SINGLELIST_H_
#define SINGLELIST_H_

#include<string>
#include "SiListNode.h"

template <typename T>
class SingleList
{
	public:
		SingleList();
		~SingleList();
		
		int Length()const; //get the length of the list
		SiListNode<T>* GetNode(int n)const; //get the n'th node of the list,return the poiner of the node
		void Print()const; //print all of the list's elements

		bool Insert(T data,int n=1); //insert a node in the n'th node position,the list's node position begin with 0
		bool Remove(int n=1); //remove the n'th node from the list
		bool Clear(); //clear up the list's all nodes,the head node left only
	private:
		SiListNode<T> *head;
};

template <typename T>
SingleList<T>::SingleList()
{
	head=new SiListNode<T>();
	head->m_next=NULL;
}

template <typename T>
SingleList<T>::~SingleList()
{
	SiListNode<T> * pointer=head->m_next;
	while(pointer!=NULL)
	{
		SiListNode<T> * pCurrentNode=pointer;
		pointer=pointer->m_next;
		delete pCurrentNode;
	}
	delete head;
}

template <typename T>
int SingleList<T>::Length()const
{
	SiListNode<T> * pointer=head->m_next;
	int count=0;
	while(pointer != NULL)
	{
		count++;
		pointer=pointer->m_next;
	}
	return count;
}

template <typename T>
SiListNode<T>* SingleList<T>::GetNode(int n)const
{
	if(n<1 || n>Length())
		return NULL;
	else
	{
		SiListNode<T> * pointer = head;
		int count=0;
		while(count<n)
		{
			pointer=pointer->m_next;
			count++;
		}
		return pointer;
	}
}

template <typename T>
void SingleList<T>::Print()const
{
	SiListNode<T>* pointer = head->m_next;
	cout<<"The list's elements:";
	cout<<"head";
	while(pointer != NULL)
	{
		cout<<"-->"<<*pointer;
		pointer = pointer->m_next;
	}
	cout<<endl;
}

template <typename T>
bool SingleList<T>::Insert(T data,int n)
{
	if(n<1 || n-1>Length())
		return 0;
	else
	{
		SiListNode<T>* pInsert=new SiListNode<T>(data);
		SiListNode<T>* pointer = head;
		int count=1;
		while(count<n)
		{
			count++;
			pointer=pointer->m_next;
		}
		pInsert->m_next=pointer->m_next;
		pointer->m_next=pInsert;

		return 1;
	}
}

template <typename T>
bool SingleList<T>::Remove(int n)
{
	if(n<1 || n>Length())
		return 0;
	else
	{
		SiListNode<T>* pointer = head;
		SiListNode<T>* pRemove = NULL;
		int count=1;
		while(count<n)
		{
			count++;
			pointer=pointer->m_next;
		}
		pRemove=pointer->m_next;
		pointer->m_next=pRemove->m_next;
		delete pRemove;
		return 1;
	}
}

template <typename T>
bool SingleList<T>::Clear()
{
	if(Length()<1)
		return 1;
	else
	{
		SiListNode<T>* pointer = head;
		SiListNode<T>* pClear = NULL;
		while(pointer->m_next != NULL)
		{
			pClear=pointer->m_next;
			pointer->m_next=pClear->m_next;
			delete pClear;
		}
		return 1;
	}
}

#endif