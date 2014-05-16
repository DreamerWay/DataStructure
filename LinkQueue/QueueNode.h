/*******************************************************************************
*
* FileName : QueueNode.h
* Comment  : LinkQueue node structure
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/14
*
*******************************************************************************/
#ifndef QUEUENODE_H_
#define QUEUENODE_H_

//using namespace std;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;
using std::cin;

template <typename T>
class LinkQueue;

template <typename T>
class QueueNode
{
	public:
		friend class LinkQueue<T>;

		QueueNode():m_next(NULL){}
		QueueNode(const T data,QueueNode<T>* next=NULL):m_data(data),m_next(next){}
		~QueueNode(){m_next=NULL;}

		friend ostream& operator<<(ostream &out,QueueNode<T> &node);
	private:
		T m_data;
		QueueNode<T>* m_next;
};

template <typename T>
ostream& operator<<(ostream &out,QueueNode<T> &node)
{
	out<<node.m_data;
	return out;
}

#endif