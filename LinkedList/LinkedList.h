#pragma once
#include <iostream>
using namespace std;

template<class T>
struct node {
	node<T>* next;
	T data;
};

template<class T>
class LinkedList{
public:
	node<T>* first;
	node<T>* last;

	FLinked<T>() {
		first = NULL;
		last = NULL;
	}

	void add(T dataR) {

		if (!first) {
			first = new node<T>;
			first->data = dataR;
			first->next = NULL;
			last = first;
		}
		else {
			if (last == first) {
				last = new node<T>;
				last->data = dataR;
				last->next = NULL;
				first->next = last;
			}
			else {
				node<T>* insdata = new node<T>;
				insdata->data = dataR;
				insdata->next = NULL;
				last->next = insdata;
				last = insdata;
			}
		}

	}

	T read(int index) {

		int i = 0;

		if (this->first == NULL) {
			cout << "The list is empty" << endl;
			return -1;
		}
		else if (index < 0) {
			std::cout << "Position " << index << " doesn't exist, first element will be returned" << endl;
			return this->first->data;
		}
		else if (index == 0) {
			return this->first->data;
		}
		else {
			node<T>* curr = this->first;
			while(i < index && curr != last) {
				curr = curr->next;
				i++;
			}
			if (i != index) {
				std::cout << "It doesn't exist the element " << index << ". Data of last element will be returned " << endl;
			}
			return curr->data;
		}

	}

	void updateIndex(int index, T newData){

		int i = 0;

		if (this->first == NULL) 
			cout << "The list is empty, it is not possible to update" << endl;
		else if (index < 0)
			std::cout << "Position " << index << " invalid, it wasn't possible to update" << endl;
		else if (index == 0) 
			this->first->data = newData;
		else {
			node<T>* current = this->first;
			while (i < index && current != last) {
				current = current->next;
				i++;
			}

			if (i != index) 
				std::cout << "Position " << index << " invalid, it wasn't possible to update" << endl;
			else
				current->data = newData;
		}

	}

	void updateData(T dataR, T newData){

		node<T>* current = this->first;
		node<T>* currentTemp = this->first;
		bool find = false;

		if (this->first == NULL) {
			cout << "La lista se encuentra vacia, no es posible actualizar" << endl;
			find = true;
		}
		else if (this->last->data == dataR) {
			this->last->data = newData;
			find = true;
		}
		else {
			while (!find && currentTemp != this->last) {
				if (current->data == dataR) {
					current->data = newData;
					find = true;
				}

				currentTemp = current;
				current = current->next;
			}

			if (!find)
				std::cout << "Dato " << dataR << " no encontrado, no fue posible actualizar" << endl;
		}
	}

	void deleteIndex(int index){
		
		int i = 0;

		if (this->first == NULL)
			cout << "La lista se encuentra vacia, no es posible eliminar ning�n elemento" << endl;
		else if (index < 0) 
			std::cout << "Posicion " << index << " no valida, no hay elemento para eliminar" << endl;
		else if (index == 0) {
			node<T>* firstTemp = this->first;
			node<T>* nextTemp = firstTemp->next;
			if (nextTemp == NULL) {
				this->first = NULL;
				this->last = NULL;
			}
			else {
				this->first = nextTemp;
			}
			delete firstTemp;
		}
		else {
			node<T>* current = this->first;
			while (i < index && current != last) {
				if (i == index - 1){
					node<T>* delete1 = current->next;
					if (delete1 == this->last) {
						current->next = NULL;
						this->last = current;
						delete delete1;
					}
					else {
						current->next = delete1->next;
						delete delete1;
					}
				}
				current = current->next;
				i++;
			}

			if (i != index)
				std::cout << "Posicion " << index << " no valida, no hay elemento para eliminar " << endl;
		}

	}

	void deleteData(T dataR) {

		node<T>* firstTemp = this->first;
		bool find = false;
		int count = 0;

		if (this->first == NULL)
			cout << "La lista se encuentra vacia, no es posible eliminar ning�n elemento" << endl;
		else if (firstTemp->data == dataR) {
			node<T>* nextTemp = firstTemp->next;
			if (nextTemp == NULL) {
				this->first = NULL;
				this->last = NULL;
			}
			else {
				this->first = nextTemp;
			}
			delete firstTemp;
		}
		else {
			node<T>* current = firstTemp;
			node<T>* currentTemp = this->first;;
			while (!find && currentTemp != this->last)
			{
				if (current->data == dataR) {
					deleteIndex(count);
					find = true;
				}

				currentTemp = current;
				current = current->next;
				count++;
			}

			if (!find) {
				std::cout << "Dato " << dataR << " inexistente en la lista, no se puede eliminar ningun eliminar ningun elemento. " << endl;
			}
		}
	}

	T operator[](int index) {
		return read(index);
	}

};
