#ifndef MINHEAP_H_
#define MINHEAP_H_
#include <vector>

template <class T>
class MinHeap {
private:
	vector<T> *heap;
	int heapsize, elements;
	void MoveDown(int i);
	void ShiftUp(int i);
	void heapify();

public:
	MinHeap(Vector<T> vec);
	MinHeap(Vector<T> *vec);
	MinHeap(T ary[], int N);
	MinHeap(int N);
	void insert(T c);
	T removeMin();
	T getMin();
};

template <class T> 
MinHeap::MinHeap(vector<T> vec) {
	heap = new vector<T>(vec.size());
	heapsize = vec.size();
	elements = vec->size();
	for (int i = 0; i < heapsize; i++)
		heap->at(i) = vec[i];
	heapify();
}

template <class T> 
MinHeap::MinHeap(vector<T> *vec) {
	heap = new vector<T>(vec->size());
	heapsize = vec->size();
	elements = vec->size();
	for (int i = 0; i < heapsize; i++)
		heap->at(i) = vec->at(i);
	heapify();
}

template <class T> 
MinHeap::MinHeap(T[] ary, int N) {
	heap = new vector<T>(N);
	heapsize = N;
	elements = N;
	for (int i = 0; i < heapsize; i++)
		heap->at(i) = ary[i];
	heapify();
}

template <class T> MinHeap::MinHeap(int N) {
	heap = new vector<T>(N);
	heapsize = N;
	elements = N;
}

template <class T>
void MinHeap::Heapify() {
	for (int i = elements - 1; i >= 0; --i)
		shiftDown(i);
}

template <class T>
void MinHeap::shiftDown(int i) {
	int lc = (2 * i) + 1;
	int rc = (2 * i) + 2;

	if (lc >= elements) // at end lc is a leaf
		return;

	int minidx = i;

	if (heap->at(minidx) > heap->at(lc))
		minidx = lc;

	if ((rc < elements) && (heap->at(minidx) > heap->at(rc))
		minidx = rc;

	if (minidx != i) {
		T tmp = heap->at(minidx);
		heap->at(minidx) = heap->at(lc);
		heap->at(lc) = tmp;
		shiftdown(minidx);
	}
}

template <class T>
void MinHeap::shiftUp(int i) {

	if (i == 0)
		return;

	int parent = (i - 1) / 2;

    if (heap->at(i) < heap->parent(i))
	{
		T tmp = heap->at(parent);
		heap->at(parent) = heap->at(i);
		heap->at(i) = heap->at(tmp);
		shiftUp(parent);
	}
}

template <class T>
void MinHeap::insert(T c) {
	if (elements < heapsize)
	{
		heap[elements] = c;
		shiftUp(elements);
		elements++;
	}
	else if (c < heap[elements - 1]){
		heap[elements - 1] = c;
		shiftup(elements);
	}
	return;
}

T MinHeap::getMin() {
	return heap->at(0);
}

void MinHeap::removeMin() {
	if (elements == 0)
		return;

	heap->at(0) = heap->at(heapsize - 1);
	elements--;
	heap->shiftDown(0);
}


#endif MINHEAP_H_