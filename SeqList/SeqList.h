/*******************************************************************************
*
* FileName : SeqList.h
* Comment  : sequence list
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/06
*
*******************************************************************************/

#ifndef SEQLIST_H_
#define SEQLIST_H_

//using namespace std;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;
using std::cin;

const int DefaultSize=100;
template <typename T>
class SeqList
{
	public:
		SeqList(int size=DefaultSize):m_maxsize(size),m_currentsize(-1)
		{
			if(size>0)
				m_elements=new T[size];
			else
				m_elements=NULL;
		}
		~SeqList()
		{
			delete [] m_elements;
		}

		int Length()const //get the SeqList's length
		{
			return m_currentsize+1;
		}

		int isEmpty()const //the SeqList is empty or not
		{
			return m_currentsize==-1;
		}

		int isFull()const //the SeqList is full or not
		{
			return m_currentsize==(m_maxsize-1);
		}
		
		void Print()const; //print the all elements by position
		T& GetElement(int i)const; //get the element by position
		int FindElement(T x)const; //find the position of element x
		int InsertElement(T x,int i); //insert an element before the position of i
		int RemoveElement(T x); //remove all of the element x from the SeqList

	private:
		T *m_elements;
		const int m_maxsize;
		int m_currentsize;
};

template <typename T> 
void SeqList<T>::Print()const
{
	if(m_currentsize>=0)
	{
		for(int i=0;i<=m_currentsize;i++)
			cout<<"element"<<i<<":"<<m_elements[i]<<endl;
	}
}

template <typename T>
T& SeqList<T>::GetElement(int i)const
{
	if(i<=m_currentsize)
		return m_elements[i];
	else
	{
		cout<<"Can't find the position:"<<i<<endl;
		exit (1);
	}
}

template <typename T>
int SeqList<T>::FindElement(T x)const
{
	for(int i=0;i<=m_currentsize;i++)
		if(x==m_elements[i])
			return i;

	cout<<"Can't find the element:"<<x<<endl;
	return -1;
}

template <typename T>
int SeqList<T>::InsertElement(T x,int i)
{
	if(i<0 || i>m_currentsize+1)
	{
		cout<<"the position is illegal"<<endl;
		return 0;
	}
	else if (isFull())
	{
		cout<<"The List is full,There is no space to insert an element"<<endl;
		return 0;
	}
	else
	{
		for(int j=m_currentsize+1;j>i;j--)
			m_elements[j]=m_elements[j-1];
		m_elements[i]=x;
		m_currentsize++;
		return 1;
	}
}

template <typename T>
int SeqList<T>::RemoveElement(T x)
{
	int position=-1,signal=0;
	while((position=FindElement(x))>=0)
	{
		signal=0;
		for(int j=position;j<m_currentsize;j++)
			m_elements[j]=m_elements[j+1];
		m_currentsize--;
		signal=1;
	}
	if(signal)
		return 1;
	else
		return 0;
}

#endif
