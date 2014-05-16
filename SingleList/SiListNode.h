/*******************************************************************************
*
* FileName : SiListNode.h
* Comment  : SingleList node's strcture
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/06
*
*******************************************************************************/
#ifndef SILISTNODE_H_
#define SILISTNODE_H_

//using namespace std;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;
using std::cin;

template<typename T> 
class SingleList;

template <typename T>
class SiListNode
{
	public:
		friend typename SingleList<T>; //SingleList class need to access the ListNode's private data
		SiListNode():m_next(NULL){}
		SiListNode(const T data,SiListNode<T> *next=NULL):m_data(data),m_next(next){}
		~SiListNode(){m_next=NULL;}
		
		T GetData()const; //get the m_data of the current ListNode object
		friend ostream& operator<<(ostream &out,SiListNode<T> &node); //"<<" operator overloading to print the m_data
	private:
		T m_data;
		SiListNode<T> *m_next;
};

template <typename T>
T SiListNode<T>::GetData()const
{
	return m_data;
}

template <typename T>
ostream& operator<< (ostream &out,SiListNode<T> &node)
{
	out<<node.m_data;
	return out;
}

#endif
