#include "HashTable.h"

HashTable::HashTable(int n) {
    size = n;
    table = new list<int>[size];
}

//O(n) 
int HashTable::getHashValue(int key) {
    int x = 1;
    int keyHash = key % size;
    int index = keyHash;
     
    while (!table[index].empty()) {
        index = (keyHash + x * x) % size;
        if (index == keyHash)
            break;
        x++;
    }

    return index;
}

//O(1)
void HashTable::insert(int key){

    table[getHashValue(key)].push_back(key);
}

//O(n)
void HashTable::printElements(){
 
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] = ";
        for (int j : table[i])
            cout << j << " -> ";

        cout << endl;
    }
    
}


