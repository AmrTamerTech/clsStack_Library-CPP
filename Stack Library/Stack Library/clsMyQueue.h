#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue 
{
protected:
	clsDblLinkedList <T> myList;

public:
	void Push(T Value)
	{
		myList.InsertAtEnd(Value);
	}

	void Pop()
	{
		myList.DeleteFirstNode();
	}

	int Size()
	{
		return myList.Size();
	}

	T Front()
	{
		return myList.GetItem(0);
	}

	T Back()
	{
		return myList.GetItem(Size() - 1);
	}

	bool IsEmpty()
	{
		return myList.IsEmpty();
	}

	T GetItem(int Index)
	{
		return myList.GetItem(Index);
	}

	void Reverse()
	{
		myList.Reverse();
	}

	void UpdateItem(int Index, T NewValue)
	{
		myList.UpdateItem(Index, NewValue);
	}

	void InsertAfter(int Index, T Value)
	{
		myList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		myList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		myList.InsertAtEnd(Value);
	}

	void Clear()
	{
		myList.Clear();
	}

	void Print()
	{
		myList.PrintList();
	}
};

