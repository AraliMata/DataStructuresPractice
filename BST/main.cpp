//Yoceline Aralí Mata Ledezma 

#include<iostream>
#include "BST.h"
using namespace std;

int main() {
    BST t;
    string opcion;
    string continuar = "C";
    int opcionVista;
    int dato;

    //Árbol 1
    t.insert(6);
    t.insert(2);
    t.insert(3);
    t.insert(5);
    t.insert(1);

  
    while (continuar == "C") {
        cout << "MENU" << endl;
        cout << "Elija una opcion " << endl;
        cout << "1. Mostrar elementos del arbol" << endl;
        cout << "2. Mostrar altura del arbol" << endl;
        cout << "3. Mostrar antecesores de un dato" << endl;
        cout << "4. Mostrar nivel en el que se encuentra un dato" << endl;

        cin >> opcion;

        if (opcion == "1") {
            cout << "Elija la forma en la que desea que los datos sean mostrados " << endl;
            cout << "1. preorder " << endl;
            cout << "2. inorder " << endl;
            cout << "3. postorder " << endl;
            cout << "4. level by level " << endl;

            cin >> opcionVista;

            t.visit(opcionVista);
        }
        else if (opcion == "2") {
            t.height();
        }
        else if (opcion == "3") {
            cout << "Introduzca el dato del cual quiere saber sus antecesores " << endl;
            cin >> dato;

            t.ancestors(dato);
        }
        else if (opcion == "4") {
            cout << "Introduzca el dato del cual quiere saber su nivel " << endl;
            cin >> dato;

            t.whatLevelAmI(dato);
        }

        cout << endl;
        cout << "Para continuar presione 'C' " << endl;
        cout << "Para salir presione cualquier tecla " << endl;

        cin >> continuar;
    }
    
   
    return 0;
}
