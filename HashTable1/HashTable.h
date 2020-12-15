#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <iostream>

using namespace std;
class HashTable
{
private:
	list<int> *table;
	int size;
	
public:
	HashTable(int);

	int getHashValue(int);
	void insert(int);
	void printElements();

};

