/*******************************************************************************
*
* FileName : BinaryTreeTest
* Comment  : test the BinaryTree structure
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/19
*
*******************************************************************************/
#include<iostream>
#include "BinaryTree.h"

int main()
{
	BinaryTree<int> bintree;
	for(int i=0;i<10;i++)
		bintree.Insert(i);
	cout<<bintree.Size()<<endl;
	cout<<bintree.Depth()<<endl;
	bintree.LevelOrder();
	cout<<endl;
	bintree.PreOrder();
	cout<<endl;
	bintree.PreOrderNoRec();
	cout<<endl;
	bintree.InOrder();
	cout<<endl;
	bintree.InOrderNoRec();
	cout<<endl;
	bintree.PostOrder();
	cout<<endl;
	bintree.PostOrderNoRec();
	cout<<endl;
	
	bintree.Clear();
	cout<<"==================="<<endl;

	bintree.Insert(5);
	bintree.Insert(6);
	bintree.Insert(1);
	bintree.Insert(3);
	bintree.Insert(8);
	bintree.Insert(7);
	bintree.Insert(0);
	bintree.Insert(4);
	cout<<bintree.Size()<<endl;
	cout<<bintree.Depth()<<endl;
	bintree.LevelOrder();
	cout<<endl;
	bintree.PreOrder();
	cout<<endl;
	bintree.PreOrderNoRec();
	cout<<endl;
	bintree.InOrder();
	cout<<endl;
	bintree.InOrderNoRec();
	cout<<endl;
	bintree.PostOrder();
	cout<<endl;
	bintree.PostOrderNoRec();
	cout<<endl;
	
	return 0;
}