#include "cassert"
#include "ordenacionSeleccion.h"

int buscarMinimo(int *vector, int n, int inicio, int fin) {
	// Precondiciones
	assert(inicio >= 0);
	assert(inicio <= fin);
	assert(fin<n);
	assert(vector != NULL);

	// Inicializamos el mínimo con el primer elemento
	int minimo = vector[inicio];
	int indiceMinimo = inicio;

	// Cada vez que encontremos un numero menor que el minimo que tenemos, actualizamos el mínimo que tenemos con ese número
	for (int i = inicio + 1; i <= fin; i++) {
		if (vector[i] < minimo) {
			minimo = vector[i];
			indiceMinimo = i;
		}
	}

	// Devolvemos la posición del mínimo
	return (indiceMinimo);
}

void ordenarPorSeleccion(int *vector, int n) {
	assert(vector != NULL);
	for (int i = 0; i<n; i++) {
		// Buscamos el minimo en lo que queda de vector hasta el final
		int posicionMinimo = buscarMinimo(vector, n, i, n - 1);

		// Ponemos el mínimo en la posición adecuada del vector, y lo que había allí lo ponemos en donde encontramos el mínimo
		int temp = vector[i];
		vector[i] = vector[posicionMinimo];
		vector[posicionMinimo] = temp;
	}
}