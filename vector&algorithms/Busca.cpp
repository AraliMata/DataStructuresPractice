#include "Busca.h"

int Busca::busqSecuencial(vector<int> vec, int buscado)
{
    int i = 0;
    int encontrado = -1;
    while (i < vec.size()  && encontrado == -1) {

        if (vec[i] == buscado) {
            encontrado = i ;
        }else{ 
            i++;
        }
               
    }
    return encontrado;
}

int Busca::busqBinaria(vector<int> vec, int n)
{
    int encontrado = -1;
    int primero = 0;
    int ultimo = vec.size() - 1;
    int medio = (primero + ultimo) / 2;
    while (primero <= ultimo && encontrado == -1)
    {
        if (vec[medio] < n)
        {
            primero = medio + 1;
        }
        else if (vec[medio] == n)
        {
            encontrado  = medio;
        }
        else {
            ultimo = medio - 1;
        }

        medio = (primero + ultimo) / 2;
    }

    return encontrado;
}
