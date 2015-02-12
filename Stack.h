#ifndef STACK_H_
#define STACK_H_

#include "Node.h"

	template <class T>
	class StackNode : public Node<T> {
	public:
		StackNode *next;

		StackNode() { next = NULL };
		StackNode(T c) { contents = c; next = NULL; }
	};

	template <class T>
	class Stack {
	private:
		StackNode<T> *head;
		int size;
	public:
		Stack();
		~Stack();
		void push(T c);
		T pop();
		int getSize();
	};

	template <class T>
	Stack<T>::Stack()
	{
		head = NULL;
		size = 0;
	}

	template <class T>
	Stack<T>::~Stack()
	{
		size = 0;
		StackNode<T> *tmpNode;
		while (head != NULL)
		{
			tmpNode = head;
			head = head->next;
			delete(tmpNode)
		}
	}

	template <class T>
	void Stack<T>::push(T c) {
		StackNode<T> *tmpNode = new StackNode<T>(c);
		tmpNode->next = head;
		head = tmpNode;
		size++;
	}

	template <class T>
	T Stack<T>::pop() {
		T retval;
		StackNode<T> *tmpNode;
		if (head == NULL)
			return NULL;
		else{
			retval = head->contents;
			tmpNode = head;
			head = head->next;
			delete(tmpNode);
			size--;
			return retval;
		}
	}

	template <class T>
	int Stack<T>::getSize()
	{
		return size;
	}
#endif