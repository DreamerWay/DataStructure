/*******************************************************************************
*
* FileName : DuListNode.h
* Comment  : DuLinkList node structure
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/13
*
*******************************************************************************/
#ifndef DULISTNODE_H_
#define DULISTNODE_H_

//using namespace std;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;
using std::cin;

template<typename T> 
class DuLinkList;

template <typename T>
class DuListNode
{
	public:
		friend typename DuLinkList<T>; //DuLinkList class need to access the SiListNode's private data
		DuListNode();
		DuListNode(const T data,DuListNode<T>* next=NULL,DuListNode<T>* pre=NULL);
		~DuListNode();
		T GetData()const; //get the m_data of the current SiListNode object
		friend ostream& operator<<(ostream &out,DuListNode<T> &node); //"<<" operator overloading to print the m_data
	private:
		T m_data;
		DuListNode<T>* m_next;
		DuListNode<T>* m_pre;
};

template <typename T>
DuListNode<T>::DuListNode()
{
	m_pre=m_next=NULL;
}

template <typename T>
DuListNode<T>::DuListNode(const T data,DuListNode<T>* next,DuListNode<T>* pre)
{
	m_data=data;
	m_next=next;
	m_pre=pre;
}

template <typename T>
DuListNode<T>::~DuListNode()
{
	m_pre=m_next=NULL;
}

template <typename T>
T DuListNode<T>::GetData()const
{
	return m_data;
}

template <typename T>
ostream& operator<<(ostream &out,DuListNode<T> &node)
{
	out<<node.m_data;
	return out;
}

#endif