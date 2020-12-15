//Yoceline Aralí Mata Ledezma 
//Matricula: A01562116
//01/12/2020

#include <iostream>
#include <list>
#include "HashTable.h"

using namespace std;
int main(){

    HashTable hashTable(5);
    HashTable hashTable2(11);
    HashTable hashTable3(5);

    int arr[] = { 2, 4, 6, 8, 10 };
    int arr2[] = {1,2,16,24,5,21,73,4,8,15,13,12,18};
    int arr3[] = { 7, 8, 9, 16, 43, 90, 55 };

    for (int i = 0; i < 5; i++)
        hashTable.insert(arr[i]);

    for (int i = 0; i < 13; i++)
        hashTable2.insert(arr2[i]);

    for (int i = 0; i < 7; i++)
        hashTable3.insert(arr3[i]);

   cout << "Hash table 1" << endl;
   hashTable.printElements();
   cout << endl << "Hash table 2" << endl;
   hashTable2.printElements();
   cout << endl << "Hash table 1" << endl;
   hashTable3.printElements();
}
