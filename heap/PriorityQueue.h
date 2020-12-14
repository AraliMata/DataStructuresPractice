#pragma once
#include <vector>
#include <iostream>

using namespace std;

class PriorityQueue
{
private:
	vector<int> heap;

	int getLeftChildIndex(int);
	int getRightChildIndex(int);
	int getParentIndex(int);
	void orderUp();
	void orderDown();

public:
	void push(int);
	int pop();
	int top();
	bool isEmpty();
	int size();
	void swap(int, int);
	
};

