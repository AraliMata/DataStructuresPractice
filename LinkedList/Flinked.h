#pragma once
#include <iostream> 
using namespace std;

template<class T>
struct node {
	node<T>* next;
	T data;
};

template<class T>
class FLinked
{
public:
	node<T>* first;
	node<T>* last;

	FLinked<T>() {
		first = NULL;
		last = NULL;
	}

	void add(T){
		if (!first) {
			first = new node<T>;
			first->data = data;
			first->next = NULL;
			last = first;
		}
		else {
			if (last == first) {
				last = new node<T>;
				last->data = data;
				last->next = NULL;
				first->next = last;
			}
			else {
				node<T>* insdata = new node<T>;
				insdata->data = data;
				insdata->next = NULL;
				last->next = insdata;
				last = insdata;
			}
		}
	}

	T read(int);

	void updateIndex(int, T);
	void updateData(T, T);
	void delIndex(int);
	void deleteData(T);*/

	T operator[](int index) {
		return read(index);
	}

};