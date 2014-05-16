/*******************************************************************************
*
* FileName : DuLinkList.h
* Comment  : DuLinkList strcture with head
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/13
*
*******************************************************************************/
#ifndef DULINKLIST_H_
#define DULINKLIST_H_

#include "DuListNode.h"

using namespace std;

template <typename T>
class DuLinkList
{
	public:
		DuLinkList();
		~DuLinkList();

		int Length()const; //return the length of the DuLinkList with the next&&pre direction simultaneously
		DuListNode<T>* GetData(int n)const; //return the n'th DuLinkList node
		void Print()const;

		bool Insert(T data,int n=1);
		bool Remove(int n=1);
		bool Clear(); //clear up the list's all nodes,the head node left only
	private:
		DuListNode<T>* head;
};

template <typename T>
DuLinkList<T>::DuLinkList()
{
	head = new DuListNode<T>;
	head->m_next=head;
	head->m_pre=head;
}

template <typename T>
DuLinkList<T>::~DuLinkList()
{
	DuListNode<T>* pointer=head;
	DuListNode<T>* pCurrent=NULL;
	while(pointer->m_next != head)
	{
		pCurrent=pointer->m_next;
		pointer->m_next=pCurrent->m_next;
		delete pCurrent;
	}
	delete head;
}

template <typename T>
int DuLinkList<T>::Length()const
{
	int count=0;
	DuListNode<T>* pNext=head->m_next;
	DuListNode<T>* pPre=head->m_pre;
	while(pNext !=head && pPre !=head )
	{
		if(pNext==pPre)
		{
			count++;
			break;
		}

		if(pPre->m_next==pNext)
			break;

		count+=2;
		pNext=pNext->m_next;
		pPre=pPre->m_pre;
	}

	return count;
}

template <typename T>
DuListNode<T>* DuLinkList<T>::GetData(int n)const
{
	if(n<1 || n>Length())
		return NULL;
	else
	{
		DuListNode<T>* pointer=head;
		int count =0;
		while(count<n)
		{
			pointer = pointer->m_next;
			count++;
		}
		return pointer;
	}
}

template <typename T>
void DuLinkList<T>::Print()const
{
	DuListNode<T>* pointer=head->m_next;
	cout<<"The list's elements:head";
	while(pointer != head)
	{
		cout<<"<==>"<<*pointer;
		pointer=pointer->m_next;
	}
	cout<<endl;
}

template <typename T>
bool DuLinkList<T>::Insert(T data,int n)
{
	if(n<1 || n-1>Length())
		return 0;
	else
	{
		DuListNode<T>* pInsert = new DuListNode<T>(data);
		DuListNode<T>* pointer = head;
		int count=1;
		while(count<n)
		{
			pointer=pointer->m_next;
			count++;
		}
		pInsert->m_next=pointer->m_next;
		pInsert->m_pre=pointer;
		pointer->m_next->m_pre=pInsert;
		pointer->m_next=pInsert;
		
		return 1;
	}	
}

template <typename T>
bool DuLinkList<T>::Remove(int n)
{
	if(n<1 || n>Length())
		return 0;
	else
	{
		DuListNode<T>* pointer = head;
		int count=1;
		while(count<n)
		{
			pointer=pointer->m_next;
			count++;
		}
		pointer->m_next->m_next->m_pre=pointer;
		pointer->m_next=pointer->m_next->m_next;

		return 1;
	}
}

template <typename T>
bool DuLinkList<T>::Clear()
{
	DuListNode<T>* pointer = head->m_next;
	DuListNode<T>* pRemove = NULL;
	while(pointer != head)
	{
		pRemove=pointer;
		pointer=pointer->m_next;
		pointer->m_pre=pRemove->m_pre;
		pRemove->m_pre->m_next=pointer;
		delete pRemove;
	}
	return 1;
}

#endif