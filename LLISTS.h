#ifndef LLISTS_H_
#define LLISTS_H_

#include "Node.h"

template <class T>
class ListNode : public Node<T> {
public:
	ListNode *next;

	ListNode() { next = NULL };
	ListNode(T c) { contents = c; next = NULL; }
};

template <class T>
class LListS {
private:
	ListNode<T> *head;
	ListNode<T> *tail;
	int size;
public:
	LListS();
	~LListS();
	bool add_front(T c);
	bool add_back(T c);
	bool insert_before(T c, T n);
	bool insert_after(T c, T n);
	T remove_front();
	T remove_back();
	T peak_front();
	T peak_tail();
	int getSize();
};

template <class T>
LListS<T>::LListS()
{
	head = tail = NULL;
	size = 0;
}

template <class T>
LListS<T>::~LListS()
{
	size = 0;
	ListNode<T> *tmpNode;
	tail = NULL;
	while (head != NULL)
	{
		tmpNode = head;
		head = head->next;
		delete(tmpNode);
	}
}

template <class T>
bool LListS<T>::add_front(T c) {
	//if (c == NULL)
	//	return false;
	ListNode<T> *tmpNode = new ListNode<T>(c);
	tmpNode->next = head;
	head = tmpNode;
	if (size == 0)
		tail = head;
	size++;
	return true;
}

template <class T>
bool LListS<T>::add_back(T c) {
	if (c == NULL)
		return false;	
	ListNode<T> *tmpNode = new ListNode<T>(c);
	if (tail == NULL) {
		tail = tmpNode;
		head = tail;
	}
	else {
		tail->next = tmpNode;
		tail = tmpNode;		
	}
	size++;
	return true;
}

template <class T>
bool LListS<T>::insert_before(T c, T n) {
	if (c == NULL)
		return false;
	ListNode<T> *trav = head;
	ListNode<T> *prev = head;
	while (trav != NULL) {
		if (n != trav->contents) {
			prev = trav;
			trav = trav->next;
		}
		else {
			if (trav == head) {
				return add_front(c);
			}
			else {
				ListNode<T> *tmpPtr = new ListNode<T>(c);
				tmpPtr->next = trav;
				prev->next = tmpPtr;
				size++;
				return true;
			}
		}

	}
	return false;
}
template <class T>
bool LListS<T>::insert_after(T c, T n) {
	if (c == NULL)
		return false;
	ListNode<T> *trav = head;
	while (trav != NULL) {
		if (n != trav->contents)
			trav = trav->next;
		else {
			if (trav == tail) {
				return add_back(c);
			}
			else {
				ListNode<T> *tmpPtr = new ListNode<T>(c);
				tmpPtr->next = trav->next;
				trav->next = tmpPtr;
				size++;
				return true;
			}
		}

	}
	return false;
}

template <class T>
T LListS<T>::remove_front() {
	T retval;
	ListNode<T> *tmpNode;
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
T LListS<T>::remove_back() {
	T retval;
	ListNode<T> *tmpNode;
	ListNode<T> *prev = head;	
	if (tail == NULL || prev == NULL)
		return NULL;
	else{
		while (prev->next != tail)
			prev = prev->next;
		retval = tail->contents;
		tmpNode = tail;
		tail = prev;
		tail->next = NULL;
		delete(tmpNode);
		size--;
		return retval;
	}
}
template <class T>
T LListS<T>::peak_front()
{
	if (head == NULL)
		return NULL;
	else
		return head->contents;
}

template <class T>
T LListS<T>::peak_tail()
{
	if (tail == NULL)
		return NULL;
	else
		return tail->contents;
}
template <class T>
int LListS<T>::getSize()
{
	return size;
}
#endif