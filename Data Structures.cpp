// Data Structures.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include "Stack.h"
#include "LLISTS.h"
#include "MinHeap.h"

using namespace std;
int main(int argc, char *argv[])
{
/*	Stack<int> *s = new Stack<int>();
	for (int i = 0; i < 100; i++)
		s->push(i);


	cout << s->getSize() << endl;

	while (s->getSize() != 0)
		cout << s->pop() << endl;
	
	int z = cin.get();*/

/*	LListS<int> *LLS = new LListS<int>();
	cout << LLS->getSize() << endl;
	LLS->add_front(3);
	LLS->add_front(2);
	LLS->add_front(0);
	LLS->add_back(5);
	LLS->insert_before(1, 2);
	LLS->insert_after(4, 3);
	cout << LLS->peak_front() << " " << LLS->peak_tail() << " " << LLS->getSize() << endl;
	cout << LLS->remove_front() << " " << LLS->remove_back() << endl;
	cout << LLS->peak_front() << " " << LLS->peak_tail() << " " << LLS->getSize() << endl;
	cout << LLS->getSize() << endl;
	int z = cin.get();*/

	int A[100];
	for (int i = 0; i < 100; i++)
	{
		A[i] = rand();
	}

	MinHeap<int> *H = new MinHeap<int>(A, 100);




	return 0;
}

