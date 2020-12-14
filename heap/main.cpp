//Yoceline Aralí Mata Ledezma
//A01562116

#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main()
{
    PriorityQueue heap1, heap2, heap3, heapVacio;

    heap1.push(5);
    heap1.push(3);
    heap1.push(8);
    heap1.push(2);

    heap2.push(8);
    heap2.push(7);
    heap2.push(6);
    heap2.push(5);
    heap2.push(4);

    heap3.push(18);
    heap3.push(0);
    heap3.push(23);
    heap3.push(13);
    heap3.push(15);
    heap3.push(20);

  
    cout << "Top arbol vacio: " << heapVacio.top() << endl;
    cout << "Top arbol 1: " << heap1.top() << endl;
    cout << "Top arbol 2: " << heap2.top() << endl;
    cout << "Top arbol 3: " << heap3.top() << endl;

   
    heap1.pop();
    heap2.pop();
    heap3.pop();
    
    cout << "Despues del pop" << endl;
    cout << "Top arbol 1: " << heap1.top() << endl;
    cout << "Top arbol 2: " << heap2.top() << endl;
    cout << "Top arbol 3: " << heap3.top() << endl;

}

