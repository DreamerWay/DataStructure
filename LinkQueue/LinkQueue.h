/*******************************************************************************
*
* FileName : LinkQueue.h
* Comment  : LinkQueue structure with head node "front(head)->first->......->rear"
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/14
*
*******************************************************************************/
#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

#include "QueueNode.h"

template <typename T>
class LinkQueue
{
	public:
		LinkQueue();
		~LinkQueue();

		bool En_queue(const T data); // put one node into the queue
		QueueNode<T>* De_queue(); //delete one node from the queue

		bool Clear();
		void Print()const;
		int Size()const;
	private:
		QueueNode<T>* m_front;
		QueueNode<T>* m_rear;
};

template <typename T>
LinkQueue<T>::LinkQueue()
{
	QueueNode<T>* head = new QueueNode<T>();
	m_front=m_rear=head;
}

template <typename T>
LinkQueue<T>::~LinkQueue()
{
	Clear();
	delete m_front;
}

template <typename T>
bool LinkQueue<T>::En_queue(T data)
{
	QueueNode<T>* pNode = new QueueNode<T>(data);
	m_rear->m_next=pNode;
	m_rear=pNode;
	return 1;
}

template <typename T>
QueueNode<T>* LinkQueue<T>::De_queue()
{
	if(m_front != m_rear)
	{
		QueueNode<T>* pNode=m_front->m_next;
		m_front->m_next=pNode->m_next;
		return pNode;
	}
}

template <typename T>
bool LinkQueue<T>::Clear()
{
	QueueNode<T>* pDelete=NULL;
	while(m_front->m_next != m_rear)
	{
		pDelete=m_front->m_next;
		m_front->m_next=pDelete->m_next;
		delete pDelete;
	}
	pDelete=m_rear;
	m_rear=m_front;
	delete pDelete;
	
	return 1;
}

template <typename T>
void LinkQueue<T>::Print()const
{
	QueueNode<T>* pNode=m_front->m_next;
	cout<<"The Queue is:front";
	while(pNode != NULL)
	{
		cout<<"-->"<<*pNode;
		pNode=pNode->m_next;
	}
	cout<<endl;
}

template <typename T>
int LinkQueue<T>::Size()const
{
	QueueNode<T>* pNode=m_front;
	int count=0;
	while(pNode->m_next != NULL)
	{
		count++;
		pNode=pNode->m_next;
	}
	return count;
}

#endif