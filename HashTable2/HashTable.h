#pragma once
#include <iostream>
#include <list>
#include "HashNode.h"

using namespace std;
class HashTable{

private:
	list<HashNode>* table;
	int size;

public:
	HashTable(int);

	int getHashValue(unsigned long long int);
	void insert(HashNode);
	void printElements();
	void find(unsigned long long int);
};

