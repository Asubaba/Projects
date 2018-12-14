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
	if (mCount == 0)
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
	if (mCount == 0)
		return;

	Node<T> *traversalNode = mHead;

	if (mHead == NULL)
	{
		std::cout << "Empty list\n";
		return;
	}

	while (traversalNode != NULL)
	{
		std::cout << traversalNode->mData << " ";
		traversalNode = traversalNode->mNext;
	}
		
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
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		//Case 2 -- Insert at front
		if (data < mHead->mData)
		{
			newNode->mNext = mHead;
			mHead = newNode;
		}
		else if (data >= mTail->mData) //Case 3 -- Insert at end
		{
			mTail->mNext = newNode;
			mTail = newNode;
		}
		else //Case 4 -- Insert in middle
		{
			oneBefore = traversalNode;
			traversalNode = traversalNode->mNext;

			while (traversalNode->mData < data)
			{
				oneBefore = traversalNode;
				traversalNode = traversalNode->mNext;
			}

			if(traversalNode->mData != data)
			{
				newNode->mNext = traversalNode;
				oneBefore->mNext = newNode;
			}
			else
			{
				delete newNode;
				return false;
			}
		}
	}

	mCount++;
	return true;
}


template <typename T>
bool LinkedList<T>::isEmpty()
{
	return mCount == 0;
}


template <typename T>
bool LinkedList<T>::isExist(T searchKey)
{
	if (mCount == 0)
		return;

	Node<T> *traversalNode = mHead;
	bool found = false;

	for (int i = 0; i < mCount; i++)
	{
		if (traversalNode->mData == searchKey)
			found = true;

		traversalNode = traversalNode->mNext;
	}
	return found;
}


template <typename T>
bool LinkedList<T>::remove(T searchKey)
{
	if (mCount == 0)
		return;

	Node<T> *traversalNode = mHead;

	for (int i = 0; i < mCount; i++)
	{
		if (traversalNode->mData == searchKey)
		{
			delete traversalNode;
			return true;
		}

		traversalNode = traversalNode->mNext;
	}
	return false;
}
#endif // LINKEDLIST_H
