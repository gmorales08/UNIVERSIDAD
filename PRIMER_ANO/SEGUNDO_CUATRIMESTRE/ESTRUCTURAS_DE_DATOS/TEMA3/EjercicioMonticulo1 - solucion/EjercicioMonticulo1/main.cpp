#include "iostream"
#include "Monticulo.h"

using namespace std;

void main () {

	// Creamos el monticulo vacio
	Monticulo monticulo;

	// Creamos la lista de inserciones
	int inserciones[] = {3, 4, 6, 7, 5, 2};

	// Vamos insertando e imprimiendo
	for (int i=0; i<6; i++) {
		cout << "Insercion de " << inserciones[i] << ":\n";
		monticulo.insertar(inserciones[i]);
		monticulo.imprimir();
	}
		
}

