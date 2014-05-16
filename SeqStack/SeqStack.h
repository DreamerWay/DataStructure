/*******************************************************************************
*
* FileName : SeqStack.h
* Comment  : Sequence Stack structure
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/14
*
*******************************************************************************/
#ifndef SEQSTACK_H_
#define SEQSTACK_H_

//using namespace std;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;
using std::cin;

template <typename T>
class SeqStack
{
	public:
		SeqStack(int sz):m_size(sz),m_top(-1){m_pStack=new T[m_size];}
		~SeqStack(){delete [] m_pStack;}

		bool IsEmpty()const; 
		bool IsFull()const;
		void Print()const;

		bool Push(T data);
		T Pop();
		bool Clear();

	private:
		int m_top;
		int m_size;
		T* m_pStack;
};

template <typename T>
bool SeqStack<T>::IsEmpty()const
{
	return (m_top==-1);
}

template <typename T>
bool SeqStack<T>::IsFull()const
{
	return (m_top==m_size-1);
}

template <typename T>
void SeqStack<T>::Print()const
{
	cout<<"The Stack is:Buttom";
	for(int i=0;i<=m_top;i++)
		cout<<"-->"<<m_pStack[i];
	cout<<endl;
}

template <typename T>
bool SeqStack<T>::Push(T data)
{
	if(IsFull())
	{
		return 0;
	}
	else
	{
		m_top+=1;
		m_pStack[m_top]=data;
		return 1;
	}
}

template <typename T>
T SeqStack<T>::Pop()
{
	if(IsEmpty())
	{
		exit (1);
	}

	T popData=m_pStack[m_top];
	m_top-=1;
	return popData;
}

template <typename T>
bool SeqStack<T>::Clear()
{
	m_top=-1;
	return 1;
}

#endif