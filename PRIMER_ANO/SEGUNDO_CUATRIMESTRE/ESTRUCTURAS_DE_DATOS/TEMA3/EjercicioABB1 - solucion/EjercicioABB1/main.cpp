#include "iostream"
#include "ArbolBinarioDeBusqueda.h"

using namespace std;

void main () {

	ArbolBinarioDeBusqueda arbol;

	// Creamos la lista de inserciones
	int inserciones[] = {5, 1, 6, 3, 7, 2, 4};
	const int n = 7;

	// Vamos insertando e imprimiendo
	for (int i=0; i<n; i++) {
		cout << "Insercion de " << inserciones[i] << ":\n";
		arbol.insertar(inserciones[i]);
		arbol.imprimir();
	}

	// Ahora vamos a buscar todos los que hemos insertado, en orden directo
	cout << "Buscamos todos en orden directo:\n";
	for (int i = 0; i < n; i++) {
		cout << "Buscamos " << inserciones[i] << ": ";
		if (arbol.buscar(inserciones[i])) cout << "ENCONTRADO";
		else cout << "NO ENCONTRADO";
		cout << endl;
	}

	// Ahora vamos a buscar todos los que hemos insertado, en orden inverso
	cout << "Buscamos todos en orden inverso:\n";
	for (int i = n-1; i >= 0; i--) {
		cout << "Buscamos " << inserciones[i] << ": ";
		if (arbol.buscar(inserciones[i])) cout << "ENCONTRADO";
		else cout << "NO ENCONTRADO";
		cout << endl;
	}

}
