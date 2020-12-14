#include "FLinked.h"

//O(1)
/*template<class T>
FLinked<T>::FLinked() {
	first = NULL;
	last = NULL;
}*/

//O(1)
template<class T>
void FLinked<T>::add(T data)
{
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

//Worst case O(n)
template<class T>
T FLinked<T>::read(int index)
{
	if (index == 0) {
		return this->first->data;
	}
	else {
		node<T>* curr = this->first;
		for (int i = 0; i < index; ++i) {
			curr = curr->next;
		}
		return curr->data;
	}
}

//Worst case O(n)
template<class T>
void FLinked<T>::updateIndex(int index, T dat)
{
	if (index == 0) {
		this->first->data = dat;
	}
	else {
		node<T>* curr = this->first;
		for (int i = 0; i < index; ++i) {
			curr = curr->next;
		}
		curr->data = dat;
	}
}

//Worst case O(n)
template<class T>
void FLinked<T>::updateData(T dat, T newDat)
{
	node<T>* curr = this->first;
	bool find = false;
	while (!find) {
		if (curr->data == dat) {
			curr->data = newDat;
			find = true;
		}
		curr = curr->next;
	}
}

//Worst case O(n)
template<class T>
void FLinked<T>::delIndex(int index)
{
	if (index == 0) {
		node<T>* first1 = this->first;
		node<T>* next1 = this->first->next;
		this->first = next1;
		delete first1;
	}
	else {
		node<T>* curr = this->first;
		for (int i = 0; i < index; ++i) {
			curr = this->next;
			if (i == index - 1)
			{
				node<T>* del = curr->next;
				if (del == this->last) {
					curr->next == NULL;
					delete del;
				}
				else {
					curr->next = del->next;
					delete del;
				}
			}
		}
	}

}

//Worst case O(n^2)
template<class T>
void FLinked<T>::deleteData(T dat)
{
	node<T>* curr = this->first;
	bool find = false;
	int count = 0;
	while (!find) //Worst case O(n^2) , //Best O(1)
	{
		if (curr->data = dat && count != 0) {
			for (int i = 0; i < count - 1; ++i) {
				curr = this->next;
				node<T>* del = curr->next;
				curr->next = del->next;
				delete del;
				find = true;
			}
		}
		else if (curr->data = dat && count != 0) {//O(1)
			node<T>* next1 = curr->next;
			this->first = next1;
			delete curr;
			find = true;
		}

		curr = this->next;
		count++;
	}

}