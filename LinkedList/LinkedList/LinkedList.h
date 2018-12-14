#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>


template <typename T>
class LinkedList
{
	template <typename R>
	struct Node
	{
		R       mData;
		Node<R> *mNext;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To initialize data object
		********************************************************************/
		Node()
		{
			mData = R();
			mNext = NULL;
		}


		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize data object
		********************************************************************/
		Node(R data)
		{
			mData = data;
			mNext = NULL;
		}
	};


private:
	Node<T> *mHead, *mTail;
	int     mCount;

public:
	LinkedList();
	~LinkedList();

	int  getCount();
	T    getData(int index);
	void setData(int index, T data);

	void clear();
	void display();
	bool insert(T data);
	bool isEmpty();
	bool isExist(T searchKey);
	bool remove(T searchKey);
	T    removeAt(int index);

	T operator[](int index);
};


template <typename T>
LinkedList<T>::LinkedList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}


template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();

	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}


template <typename T>
int LinkedList<T>::getCount()
{
	return mCount;
}


template <typename T>
T LinkedList<T>::getData(int index)
{
	if (index < 0 || index >= mCount)
		return T();

	Node<T> *traversalNode = mHead;

	for (int i = 0; i < index; i++)
		traversalNode = traversalNode->mNext;
		
	return traversalNode->mData;
}


template <typename T>
void LinkedList<T>::setData(int index, T data)
{
	if (index < 0 || index >= mCount)
		return;

	Node<T> *traversalNode = mHead;

	for (int i = 0; i < index; i++)
		traversalNode = traversalNode->mNext;

	traversalNode->mData = data;
}


template <typename T>
void LinkedList<T>::clear()
{
	if (mCount <= 0)
		return;

	Node<T> *traversalNode = mHead;
	Node<T> *toBeDeleted;

	while (traversalNode != NULL)
	{
		toBeDeleted = traversalNode;
		traversalNode = traversalNode->mNext;
		toBeDeleted->mNext = NULL;

		delete toBeDeleted;
	}


	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}


template <typename T>
void LinkedList<T>::display()
{
	if (mCount <= 0)
		return;

	Node<T> *traversalNode = mHead;

	for (int i = 0; i < mCount; i++)
		std::cout << traversalNode->mData << " ";
	std::cout << std::endl;
}

template <typename T>
bool LinkedList<T>::insert(T data)
{
	Node<T> *traversalNode = mHead, *oneBefore, *newNode;

	newNode = new Node<T>(data);
	if (newNode == NULL)
		return false;

	//Case 1 -- Empty List
	if (mHead == NULL)
	{
		newNode->mData = data;
		mHead = newNode;
		mTail = newNode;
	}

	//Case 2 -- Insert at front
	if (data > mHead->Data)
	{
		newNode->mNext = mHead;
		newNode->mData = data;
		mHead = newNode;
	}

	//Case 3 -- Insert in middle
	if (data < mHead->mData && data > mTail->mData)
	{
		for (int i = 0; i < mCount; i++)
		{
			oneBefore = traversalNode;
			traversalNode = traversalNode->mNext;
			if (data > traversalNode->mData)
			{
				newNode = traversalNode;
				newNode->mNext = traversalNode->mNext;
				newNode->mData = data;
				oneBefore->mNext = NULL;
				oneBefore->mNext = newNode;

				break;
			}
		}
	}
	
	//Case 4 -- Insert at end
	if (data < mTail->mData)
	{
		mTail->mNext = newNode;
		newNode->mNext = NULL;
		newNode->mData = data;
		mTail = newNode;
	}

	mCount++;
	return true;
}


#endif // LINKEDLIST_H
