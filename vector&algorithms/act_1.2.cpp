#include <iostream>
#include <vector>
#include "Ordena.h"
#include "Busca.h"

using namespace std;
int main()
{
    vector<int> vec = { 3,5,9,2,1 };
    vector<int> vec1 = {106, 7, 6, 5, 98, 19, 8, 98, 1};
    vector<int> vec2 = {240, 78, 6, 1, 67};
   
    Ordena::ordenaIntercambio(vec);
    Ordena::ordenaBurbuja(vec1);
    Ordena::ordenaMerge(vec2, 0, vec2.size() - 1);


    Ordena::imprimirVector(vec);
    Ordena::imprimirVector(vec1);
    Ordena::imprimirVector(vec2);


    cout << "El número 9 se encuentra en el lugar " << Busca::busqSecuencial(vec, 9) + 1<< endl;
    cout << "El número 8 se encuentra en el lugar " << Busca::busqBinaria(vec1, 8) + 1 << endl;
}
