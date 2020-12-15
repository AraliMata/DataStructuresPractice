#include "HashTable.h"

HashTable::HashTable(int n) {
    size = n;
    table = new list<HashNode>[size];
}

//O(1)
int HashTable::getHashValue(unsigned long long int key) {
    return key % size;
}

//O(1)
void HashTable::insert(HashNode ip) {

    table[getHashValue(ip.key)].push_back(ip);
}

//O(n)
void HashTable::printElements() {

    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] = ";
        for (HashNode const& j : table[i])
            cout << "IP: " << j.ip << " Numero de accesos: " << j.no_accesos << " -> ";

        cout << endl;
    }

}

//O(1) Mejor caso
void HashTable::find(unsigned long long int key){
    int hashValue = getHashValue(key);

    for (HashNode const& i : table[hashValue]) {
        if (i.key == key) {
            cout << "IP: " << i.ip << endl;
            cout << "Numero de accesos: " << i.no_accesos << endl;
            break;
        }
    }
   
}

