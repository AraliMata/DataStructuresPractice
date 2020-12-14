#include "Ordena.h"

void Ordena::ordenaIntercambio(vector<int>& vec)
{
	int i, j, aux;
	for (i = 0; i <= vec.size(); i++)
		for (j = i + 1; j < vec.size(); j++)
			if (vec[i] > vec[j])
			{
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
}

void Ordena::ordenaBurbuja(vector<int>& vec)
{
	bool interruptor = true;
	int tmp = 0;
	for (int pasada = 0; pasada < vec.size() - 1 && interruptor; pasada++) {
		interruptor = false;
		for (int j = 0; j < vec.size() - 1 - pasada; j++) {
			if (vec[j + 1] < vec[j]) {
				tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;
				interruptor = true;
			}
		}
	}
}

void Ordena::ordenaMerge(vector<int>& vec, int iz, int der)
{
	if (iz < der) {
		int m = iz + (der - iz) / 2;

		ordenaMerge(vec, iz, m);
		ordenaMerge(vec, m + 1, der);

		merge(vec, iz, m, der);
	}
}

void Ordena::merge(vector<int>& vec, int inicio, int med, int fin)
{
	int inicio2 = med + 1;

	if (vec[med] <= vec[inicio2]) {
		return;
	}

	while (inicio <= med && inicio2 <= fin) {

		if (vec[inicio] <= vec[inicio2]) {
			inicio++;
		}
		else {
			int valor = vec[inicio2];
			int indice = inicio2;

			while (indice != inicio) {
				vec[indice] = vec[indice - 1];
				indice--;
			}
			vec[inicio] = valor;

			inicio++;
			med++;
			inicio2++;
		}
	}
}

void Ordena::imprimirVector(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ",";
	}
	cout << endl;
}
