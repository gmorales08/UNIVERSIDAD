#include "iostream"
#include "Monticulo.h"
#include "cstdlib"
#include "ctime"
#include "impresionListasContiguas.h"
#include "ordenacion.h"

using namespace std;

void main () {

	// Creamos el monticulo vacio
	Monticulo monticulo;

	// Creamos la lista de inserciones
	int inserciones[] = {2, 3, 4, 7, 5, 6};

	// Vamos insertando e imprimiendo
	for (int i=0; i<6; i++) {
		cout << "Insercion de " << inserciones[i] << ":\n";
		monticulo.insertar(inserciones[i]);
		monticulo.imprimir();
	}

	// Imprimimos y borramos la raiz
	cout << "Sacamos raiz: " << monticulo.getRaiz() << endl;
	monticulo.borrar();
	monticulo.imprimir();

	// Imprimimos y borramos la raiz
	cout << "Sacamos raiz: " << monticulo.getRaiz() << endl;
	monticulo.borrar();
	monticulo.imprimir();

	// Creamos una lista con 20 elementos, cada uno aleatoriamente del 50 al 100
	srand((unsigned int)time(NULL));
	ListaContigua lista;
	for (int i=0; i<19; i++) {
		int numero = rand()%51 + 50;
		lista.insertar(lista.getN(), numero); // Insertamos al final para que sea mas eficiente (no hay que correr los numeros posteriores porque no hay)
	}
	cout << "Lista a ordenar: ";
	imprimirListaContigua(&lista);

	// Ordenamos la lista y la imprimimos
	ordenarPorMonticulo(&lista);
	cout << "Lista ordenada: ";
	imprimirListaContigua(&lista);
	
}

