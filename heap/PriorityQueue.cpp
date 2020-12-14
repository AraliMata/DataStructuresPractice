#include "PriorityQueue.h"

int PriorityQueue::getLeftChildIndex(int parentIndex)
{
	return 2 * parentIndex + 1;
}

int PriorityQueue::getRightChildIndex(int parentIndex)
{
	return 2 * parentIndex + 2;
}

int PriorityQueue::getParentIndex(int childIndex)
{
	return (childIndex - 1) / 2;
}

void PriorityQueue::orderUp() {

	int i = size() - 1;
	int parentIndex = getParentIndex(i);
	while (parentIndex >= 0 && heap[parentIndex] > heap[i]) {

		swap(parentIndex, i);
		i = parentIndex;
		parentIndex = getParentIndex(i);
	}
}

void PriorityQueue::orderDown() {
	int i = 0;
	int lefChildIndex = getLeftChildIndex(i);
	int rightChildIndex = getRightChildIndex(i);

	while (lefChildIndex < size()) {
		int smallerChildIndex = lefChildIndex;

		if (rightChildIndex < size() && heap[rightChildIndex] < heap[rightChildIndex])
			smallerChildIndex = rightChildIndex;


		if (heap[i] < heap[smallerChildIndex]) {
			break;
		}
		else {
			swap(i, smallerChildIndex);
			i = smallerChildIndex;
			lefChildIndex = getLeftChildIndex(i);
			rightChildIndex = getRightChildIndex(i);
		}
	}

}

int PriorityQueue::size()
{
	return heap.size();
}

void PriorityQueue::push(int data){
	heap.push_back(data);
	orderUp();
}

int PriorityQueue::pop()
{
	if (!isEmpty()) {
		int root = heap[0];
		swap(0, heap.size() - 1);
		heap.pop_back();
		orderDown();
		return root;
	}
	else {
		cout << "No hay elementos en el arbol" << endl;
	}
}

int PriorityQueue::top()
{
	if (!isEmpty())
		return heap[0];
	else
		cout << "No hay elementos en el arbol" << endl;

	return -1;
}

bool PriorityQueue::isEmpty()
{
	return size()  == 0;
}

void PriorityQueue::swap(int val1, int val2)
{
	int temp = heap[val1];
	heap[val1] = heap[val2];
	heap[val2] = temp;
}

