/*******************************************************************************
*
* FileName : BinTreeNode.h
* Comment  : Binary Tree Node structure
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/19
*
*******************************************************************************/
#ifndef BINTREENODE_H_ 
#define BINTREENODE_H_

//using namespace std;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;
using std::cin;
using std::stack;
using std::queue;

template <typename T>
class BinaryTree;

template <typename T>
class BinTreeNode
{
	public:
		friend class BinaryTree<T>;
		BinTreeNode(){m_left=m_right=NULL;}
		BinTreeNode(const T data,BinTreeNode<T>* left=NULL,BinTreeNode<T>* right=NULL);
		~BinTreeNode(){m_left=m_right=NULL;}
		friend ostream& operator<<(ostream &out,const BinTreeNode<T> &node);
	private:
		T m_data;
		BinTreeNode<T>* m_left;
		BinTreeNode<T>* m_right;
};

template <typename T>
BinTreeNode<T>::BinTreeNode(const T data,BinTreeNode<T>* left,BinTreeNode<T>* right)
{
	m_data=data;
	m_left=left;
	m_right=right;
}

template <typename T>
ostream& operator<<(ostream &out,const BinTreeNode<T> &node)
{
	out<<node.m_data;
	return out;
}

#endif