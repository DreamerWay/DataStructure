/*******************************************************************************
*
* FileName : Heap.h
* Comment  : Heap structure by array
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/15
*
*******************************************************************************/
#ifndef HEAP_H_
#define HEAP_H_

//using namespace std;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;
using std::cin;

const int DefaultSize=20;

template <typename T>
class Heap
{
	public:
		Heap();
		Heap(const T* Init,int n,bool IsMaxHeap);
		~Heap(){delete [] m_heap;}
		
		bool Insert(const T data);
		bool Delete(const T data);
		
		bool IsEmpty()const;
		bool IsFull()const;
		void Print()const;
		bool Clear();
	private:
		bool Adjust(const int position,const int n); //n stands for the biggest position value:m_currentsize-1
	private:
		bool Type; // MaxHeap(1) or MinHeap(0)
		int m_maxsize;
		int m_currentsize;
		T* m_heap;
};

template <typename T>
Heap<T>::Heap()
{
	Type=1; //MaxHeap default 
	m_maxsize=DefaultSize;
	m_currentsize=0;
	m_heap=new T(m_maxsize);
}

template <typename T>
Heap<T>::Heap(const T* Init,int n,bool IsMaxHeap)
{
	Type=IsMaxHeap;
	m_maxsize=n;
	m_currentsize=n;
	m_heap=new T[m_maxsize];
	for(int i=0;i<m_maxsize;i++)
		m_heap[i]=Init[i];
	for(int j=(m_maxsize-2)/2;j>=0;j--)
		Adjust(j,m_currentsize-1);
}

template <typename T>
bool Heap<T>::Adjust(const int position,const int n)
{
	if(Type)
	{
		int i=position;
		while(i<=(n-1)/2) //(n-1)/2 stands for the last node except for leaf node
		{		
			int maxchild=2*i+1;// maxchild position inited by left child
			if(maxchild+1<=n && m_heap[maxchild]<m_heap[maxchild+1])
				maxchild+=1;
			if(m_heap[i]<m_heap[maxchild])
			{
				T temp=m_heap[i];
				m_heap[i]=m_heap[maxchild];
				m_heap[maxchild]=temp;
				i=maxchild;
			}
			else
				break;
		}
		return 1;
	}
	else
	{
		int i=position;
		while(i<=(n-1)/2)
		{		
			int minchild=2*i+1;// minchild position inited by left child
			if(minchild+1<=n && m_heap[minchild]>m_heap[minchild+1])
				minchild+=1;
			if(m_heap[i]>m_heap[minchild])
			{
				T temp=m_heap[i];
				m_heap[i]=m_heap[minchild];
				m_heap[minchild]=temp;
				i=minchild;
			}
			else
				break;
		}
		return 1;
	}
}

template <typename T>
bool Heap<T>::Insert(const T data)
{
	if(IsFull())
		return 0;
	else
	{
		m_heap[m_currentsize]=data;
		int j=m_currentsize;
		m_currentsize++;
		int parent=(j-1)/2; //when parent=i,leftchild=2*i+1,rightchild=2*i+2 ; if the child is j,parent is (j-1)/2
		//Adjust(parent,m_currentsize-1);
		while(parent>=0)
		{
			Adjust(parent,m_currentsize-1);
			if(parent==0) //Attention: do not leave this after the :parent=(parent-1)/2;
				break;
			parent=(parent-1)/2;
		}
		return 1;
	}
}

template <typename T>
bool Heap<T>::Delete(const T data)
{
	if(IsEmpty())
		return 0;
	else
	{
		for(int i=0;i<m_currentsize;i++)
		{
			if(m_heap[i]==data)
			{
				
				m_heap[i]=m_heap[m_currentsize-1];
				m_currentsize--;
				Adjust(i,m_currentsize-1);
				i=i-1; //the i'th position maybe a new value ,need to check again
			}
		}
	}
}

template <typename T>
bool Heap<T>::IsEmpty()const
{
	return (m_currentsize==0);
}

template <typename T>
bool Heap<T>::IsFull()const
{
	return (m_currentsize==m_maxsize);
}

template <typename T>
void Heap<T>::Print()const
{
	cout<<"The Heap is:";
	for(int i=0;i<m_currentsize;i++)
	{
		if(i==0)
			cout<<m_heap[i];
		else
			cout<<"-->"<<m_heap[i];
	}
	cout<<endl;
}

template <typename T>
bool Heap<T>::Clear()
{
	if(!IsEmpty())
	{
		m_currentsize=0;
	}
	return 1;	
}

#endif