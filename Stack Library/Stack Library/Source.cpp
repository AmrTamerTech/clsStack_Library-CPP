#include <iostream>
#include "clsMyStack.h"

using namespace std;

int main()
{
	clsMyStack <int> MyStack;

	MyStack.Push(10);
	MyStack.Push(20);
	MyStack.Push(30);
	MyStack.Push(40);
	MyStack.Push(50);

	cout << "\nStack: ";
	MyStack.Print();

	cout << "\nStack Size: " << MyStack.Size();
	cout << "\nStack Top: " << MyStack.Top();
	cout << "\nStack Bottom: " << MyStack.Bottom();

	MyStack.Pop();
	cout << "\n\nStack after Pop(): ";
	MyStack.Print();

	//Extension #1
	cout << "\nItem(2): " << MyStack.GetItem(2) << endl;

	//Extension #2
	MyStack.Reverse();
	cout << "\nStack after Reverse(): ";
	MyStack.Print();

	//Extension #3
	MyStack.UpdateItem(2, 600);
	cout << "\nStack after updating Item(2) to 600: ";
	MyStack.Print();

	//Extension #4
	MyStack.InsertAfter(2, 800);
	cout << "\nStack after Inserting 800 after Item(2): ";
	MyStack.Print();

	//Extension #5
	MyStack.InsertAtFront(1000);
	cout << "\nStack after Inserting 1000 at Top: ";
	MyStack.Print();

	//Extension #6
	MyStack.InsertAtBack(2000);
	cout << "\nStack after Inserting 2000 at Bottom: ";
	MyStack.Print();

	//Extension #7
	MyStack.Clear();
	cout << "\nStack after Clear(): ";
	MyStack.Print();

	system("pause > 0");
	return 0;
}