#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include "HashNode.h"
#include "HashTable.h"

class Info{
private:
	HashTable *ips;
	unsigned long long int convertIp(string);
public:
	Info(int);
	void readData(string);
	void printData();
	void findIp(string);
	
};

