/*******************************************************************************
*
* FileName : BinaryTree.h
* Comment  : BinaryTree structure
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/19
*
*******************************************************************************/
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <stack>
#include <queue>
#include "BinTreeNode.h"


template <typename T>
class BinaryTree
{
	public:
		BinaryTree():m_root(NULL){}
		~BinaryTree();

		int Depth()const;
		int Size()const;
		bool Clear();
		bool Insert(const T data); //insert the data by its value in the left or right 
		void Print()const;
		BinTreeNode<T>* Find(const T data)const;

		void PreOrder()const;
		void InOrder()const;
		void PostOrder()const;

		void PreOrderNoRec()const;
		void InOrderNoRec()const;	
		void PostOrderNoRec()const;

		void LevelOrder()const;

	private:
		int Size(BinTreeNode<T>* root)const;
		int Depth(BinTreeNode<T>* root)const;
		void Clear(BinTreeNode<T>* root);
		void PreOrder(BinTreeNode<T>* root)const;
		void InOrder(BinTreeNode<T>* root)const;
		void PostOrder(BinTreeNode<T>* root)const;
		
	private:
		BinTreeNode<T>* m_root;
};

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	Clear();
}

template <typename T>
bool BinaryTree<T>::Clear()
{
	Clear(m_root);
	m_root=NULL;
	return 1;
}

template <typename T>
void BinaryTree<T>::Clear(BinTreeNode<T>* root)
{
	if(root->m_left != NULL)
		Clear(root->m_left);
	if(root->m_right != NULL)
		Clear(root->m_right);
	delete root;
}

template <typename T>
int BinaryTree<T>::Size()const
{
	return Size(m_root);
}

template <typename T>
int BinaryTree<T>::Size(BinTreeNode<T>* root)const
{
	if(root == NULL)
		return 0;
	int size_left=0;
	int size_right=0;
	size_left=Size(root->m_left);
	size_right=Size(root->m_right);
	return size_left+size_right+1;
}

template <typename T>
int BinaryTree<T>::Depth()const
{
	return Depth(m_root);
}

template <typename T>
int BinaryTree<T>::Depth(BinTreeNode<T>* root)const
{
	if(root == NULL)
		return 0;
	int depth_left=0;
	int depth_right=0;
	depth_left=Depth(root->m_left);
	depth_right=Depth(root->m_right);
	return (depth_left>depth_right ? depth_left:depth_right)+1;
}

template <typename T>
bool BinaryTree<T>::Insert(const T data)
{
	BinTreeNode<T>* p=m_root;
	BinTreeNode<T>* pInsert=new BinTreeNode<T>(data);
	if(p==NULL)
	{
		m_root=pInsert;
		return 1;
	}
	while(1)
	{
		if(pInsert->m_data > p->m_data)
		{
			if(p->m_right==NULL)
			{
				p->m_right=pInsert;
				return 1;
			}
			else
				p=p->m_right;
		}
		else if(pInsert->m_data < p->m_data)
		{
			if(p->m_left==NULL)
			{
				p->m_left=pInsert;
				return 1;
			}
			else
				p=p->m_left;
		}
		else
		{
			cout<<"The Insert data already exits!"<<endl;
			return 0;
		}
	}
}

template <typename T>
void BinaryTree<T>::PreOrder(BinTreeNode<T>* root)const
{
	if(root!=NULL)
	{
		cout<<"-->"<<root->m_data;
		if(root->m_left)
			PreOrder(root->m_left);
		if(root->m_right)
			PreOrder(root->m_right);
	}	
}

template <typename T>
void BinaryTree<T>::InOrder(BinTreeNode<T>* root)const
{
	if(root!=NULL)
	{
		if(root->m_left)
			InOrder(root->m_left);
		cout<<"-->"<<root->m_data;
		if(root->m_right)
			InOrder(root->m_right);
	}
}

template <typename T>
void BinaryTree<T>::PostOrder(BinTreeNode<T>* root)const
{
	if(root!=NULL)
	{
		if(root->m_left)
			PostOrder(root->m_left);
		if(root->m_right)
			PostOrder(root->m_right);
		cout<<"-->"<<root->m_data;
	}
}

template <typename T>
void BinaryTree<T>::PreOrder()const
{
	PreOrder(m_root);
}

template <typename T>
void BinaryTree<T>::InOrder()const
{
	InOrder(m_root);
}

template <typename T>
void BinaryTree<T>::PostOrder()const
{
	PostOrder(m_root);
}

template <typename T>
void BinaryTree<T>::PreOrderNoRec()const
{
	stack<BinTreeNode<T>*> s;
	BinTreeNode<T>* pNode=m_root;
	while((pNode !=NULL) || (!s.empty()))
	{
		if(pNode !=NULL)
		{
			cout<<"-->"<<*pNode;
			s.push(pNode);
			pNode=pNode->m_left;
		}
		else
		{
			pNode=s.top();
			s.pop();
			pNode=pNode->m_right;
		}
	}
}

template <typename T>
void BinaryTree<T>::InOrderNoRec()const
{
	stack<BinTreeNode<T>*> s;
	BinTreeNode<T>* pNode=m_root;
	while((pNode != NULL) || (!s.empty()))
	{
		while(pNode != NULL)
		{
			s.push(pNode);
			pNode=pNode->m_left;
		}
		if(!s.empty())
		{
			pNode=s.top();
			s.pop();
			cout<<"-->"<<*pNode;
			pNode=pNode->m_right;
		}
	}
}

template <typename T>	
void BinaryTree<T>::PostOrderNoRec()const
{

	stack<BinTreeNode<T>*> s1,s2;  
    BinTreeNode<T>* curr=NULL;
	BinTreeNode<T>* pNode=NULL;
    s1.push(m_root);
    while(!s1.empty())
    {
        curr=s1.top();
		s1.pop();
        s2.push(curr);
        if(curr->m_left)
            s1.push(curr->m_left);
        if(curr->m_right)
            s1.push(curr->m_right);
    }
    while(!s2.empty())
    {
        pNode=s2.top();
		s2.pop();
		cout<<"-->"<<*pNode;
    }
}

template <typename T>
void BinaryTree<T>::LevelOrder()const
{
	queue<BinTreeNode<T>*> q;
	BinTreeNode<T>* pNode=NULL;
	q.push(m_root);
	while(!q.empty())
	{
		pNode=q.front();
		q.pop();
		cout<<"-->"<<*pNode;
		
		if(pNode->m_left != NULL)
			q.push(pNode->m_left);
		if(pNode->m_right != NULL)
			q.push(pNode->m_right);
	}
}

#endif 