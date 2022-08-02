#include "ordenacion.h"
#include "Monticulo.h"

void ordenarPorMonticulo(ListaContigua *lista) {
	Monticulo monticulo; // Monticulo auxiliar que servirá para ordenar
	int n = lista->getN(); // Numero de elementos

	// Creamos el monticulo
	for (int i = 0; i < n; i++) {
		int elemento = lista->getValor(i);
		monticulo.insertar(elemento);
	}

	// Vamos sacando del monticulo y poniéndolo en la lista, en orden
	for (int i = 0; i<n; i++) {
		int elemento = monticulo.getRaiz();
		monticulo.borrar();
		lista->setValor(i, elemento);
	}
}