#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
	
private:

	struct Node
	{
		T Data;
		Node* Next;
		Node* Prev;
	};

	Node* Head;

	void PrintNodeDetails(Node* Current)
	{
		if (!Current)
		{
			cout << "NULL <--> NULL\n";
			return;
		}
		if (Current->Prev != nullptr)
			cout << Current->Prev->Data;
		else
			cout << "NULL";

		cout << " <--> " << Current->Data << " <--> ";

		if (Current->Next != nullptr)
			cout << Current->Next->Data << endl;
		else
			cout << "NULL\n";
	}

	Node* Find(Node* Start, T Value)
	{
		while (Start != nullptr)
		{
			if (Start->Data == Value)
				return Start;
			Start = Start->Next;
		}
		return nullptr;
	}

	Node* GetNode(int Index)
	{
		if (Index > size - 1 || Index < 0) return nullptr;

		int Counter = 0;
		Node* Temp = Head;

		while (Temp)
		{
			if (Counter == Index) return Temp;
			Temp = Temp->Next;
			Counter++;
		}

		return nullptr;
	}

	void InsertAfter(Node* Current, T Value)
	{
		Node* NewNode = new Node();
		size++;
		NewNode->Data = Value;
		NewNode->Prev = Current;
		NewNode->Next = Current->Next;

		if (NewNode->Next != nullptr) NewNode->Next->Prev = NewNode;

		Current->Next = NewNode;
	}

protected:
	int size = 0;
	
public:

	clsDblLinkedList()
	{
		Head = nullptr;
	}

	void InsertAtBeginning(T Value)
	{
		Node* NewNode = new Node();
		size++;
		NewNode->Data = Value;
		NewNode->Prev = nullptr;
		NewNode->Next = Head;

		if (Head != nullptr)
		{
			Head->Prev = NewNode;
		}
		Head = NewNode;
	}

	/*void InsertAfter(T ValuePrev, T Value)
	{
		if (Head == nullptr) return;
		
		Node* NodeFound = Find(Head, ValuePrev);

		if (!NodeFound) return;

		Node* NewNode = new Node();
		size++;
		NewNode->Data = Value;
		NewNode->Prev = NodeFound;
		NewNode->Next = NodeFound->Next;

		if (NewNode->Next != nullptr) NewNode->Next->Prev = NewNode;

		NodeFound->Next = NewNode;
	}*/

	bool InsertAfter(int Index, T Value)
	{
		Node* ItemNode = GetNode(Index);
		if (!ItemNode) return false;

		InsertAfter(ItemNode, Value);
		return true;

	}

	void InsertAtEnd(T Value)
	{
		Node* NewNode = new Node();
		NewNode->Data = Value;
		NewNode->Next = nullptr;
		size++;
		if (Head == nullptr)
		{
			Head = NewNode;
			NewNode->Prev = nullptr;
		}
		else
		{
			Node* LastNode = Head;

			while (LastNode->Next != nullptr)
			{
				LastNode = LastNode->Next;
			}
			NewNode->Prev = LastNode;
			LastNode->Next = NewNode;
		}
	}

	void DeleteNode(T ValueOfNode)
	{
		Node* FoundNode = Find(Head, ValueOfNode);

		if (!Head || !FoundNode) return;

		if (Head == FoundNode) Head = FoundNode->Next;
		if (FoundNode->Next) FoundNode->Next->Prev = FoundNode->Prev;
		if (FoundNode->Prev) FoundNode->Prev->Next = FoundNode->Next;

		size--;
		delete FoundNode;
	}

	void DeleteFirstNode()
	{
		if (!Head) return;
		
		Node* NodeFirst = Head;
		Head = Head->Next;
		if (Head) Head->Prev = nullptr;
		size--;
		delete NodeFirst;
	}

	void DeleteLastNode()
	{
		if (!Head) return;

		Node* LastNode = Head;

		if (!LastNode->Next)
		{
			Head = nullptr;
			delete LastNode;
			size--;
			return;
		}

		while (LastNode->Next != nullptr)
			LastNode = LastNode->Next;
		LastNode->Prev->Next = nullptr;
		size--;
		delete LastNode;
	}

	void PrintListDetails()
	{
		Node* Temp = Head;
		cout << "\n";
		while (Temp != nullptr)
		{
			PrintNodeDetails(Temp);
			Temp = Temp->Next;
		}
		cout << "\n";
	}

	void PrintList()
	{
		cout << "\n";
		Node* Temp = Head;
		while (Temp != nullptr)
		{
			cout << Temp->Data << " ";
			Temp = Temp->Next;
		}
		cout << "\n";
	}

	void PrintListWithConnectNode()
	{
		cout << "\nNULL <--> ";
		Node* Temp = Head;
		while (Temp != nullptr)
		{
			cout << Temp->Data << " <--> ";
			Temp = Temp->Next;
		}
		cout << "NULL\n";
	}

	int Size()
	{
		return size;
	}

	bool IsEmpty()
	{
		return !size;
	}

	void Clear()
	{
		/*while (Head != NULL)
		{
			Node* Temp = Head;
			Head = Head->Next;
			delete Temp;
			size--;
		}*/
		while (size > 0)
			DeleteFirstNode();
	}

	void Reverse()
	{
		Node* Current = Head;
		Node* Temp = nullptr;

		while (Current)
		{
			Temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = Temp;
			Current = Current->Prev;
		}

		if (Temp) Head = Temp->Prev;
	}

	T GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);

		return (ItemNode ? ItemNode->Data : T{});

		//If the index is valid → return the actual data.
		//If the index is invalid(out of range) → return T{} → which gives the default - initialized value of type T.
		//Examples :
		//If T is :
		//Data Type	T{} returns	Explanation
		//int	0	default value for integers
		//float	0.0f	default for floating - point numbers
		//bool	false	default for booleans
		//char	'\0'	null character
		//std::string	""	empty string
		//MyClass	MyClass()	default - constructed object
		//SomeType * nullptr	default for pointers
	}

	bool UpdateItem(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index);
		if (!ItemNode) return false;

		ItemNode->Data = NewValue;
		return true;
	}

	~clsDblLinkedList()
	{
		while (Head != nullptr)
		{
			Node* Temp = Head;
			Head = Head->Next;
			delete Temp;
		}
	}
};

