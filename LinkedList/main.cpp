//Yoceline Aral� Mata Ledezma

#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;
int main()
{
    LinkedList<int> list;
    list.add(1);
    list.add(3);
    list.add(19);
    list.add(20);
    list.add(20);
   
    list.deleteIndex(0);
    list.deleteData(20);
    list.updateIndex(0, 14);
    list.updateData(2, 30);

    std::cout << "Element " << 0 << ": " << list.read(0) << endl;
    std::cout << "Element " << 1 << ": " << list.read(1) << endl;
    std::cout << "Element " << 2 << ": " << list.read(2) << endl;
    std::cout << "Element " << 3 << ": " << list.read(3) << endl;
    
    return 0;

}

