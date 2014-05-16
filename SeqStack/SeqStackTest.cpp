/*******************************************************************************
*
* FileName : SeqStackTest.cpp
* Comment  : test the SeqStack structure
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/14
*
*******************************************************************************/
#include <iostream>
#include "SeqStack.h"

int main()
{
	SeqStack<int> stack(10);
	for(int i=0;i<15;i++)
		stack.Push(i);
	stack.Print();

	stack.Pop();
	stack.Print();

	stack.Clear();
	stack.Print();

	return 0;
}