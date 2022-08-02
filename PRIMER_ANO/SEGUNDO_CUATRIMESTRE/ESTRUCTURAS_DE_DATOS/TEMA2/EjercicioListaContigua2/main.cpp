#include "iostream"
#include "ListaContigua.h"
#include "impresionListasContiguas.h"

using namespace std;


void main() {

	// Creamos una ListaContigua que nos servirá para las pruebas
	ListaContigua lista;

	cout << "Nueva ListaContigua creada:\n";
	imprimirListaContigua(&lista);

	cout << "Rellenando ListaContigua:\n";
	for (int i = 0; i <= 10; i++) {
		lista.insertarAlFinal(i); // Introducimos el nuevo elemento
		imprimirListaContigua(&lista);
	}

	cout << "Insertar al principio de 100 a 104\n";
	for (int i = 100; i <= 104; i++) {
		lista.insertar(0, i);
		imprimirListaContigua(&lista);
	}

	cout << "Insertamos 200 en la posicion 3:\n";
	lista.insertar(3, 200);
	imprimirListaContigua(&lista);

	cout << "Eliminar los 5 ultimos:\n";
	for (int i = 0; i < 5; i++) {
		lista.eliminarAlFinal();
		imprimirListaContigua(&lista);
	}

	cout << "Eliminar los 5 primeros:\n";
	for (int i = 0; i < 5; i++) {
		lista.eliminar(0);
		imprimirListaContigua(&lista);
	}

	// Buscar elementos
	cout << "Elemento 100 encontrado en posicion " << lista.buscar(100) << endl;
	cout << "Elemento 2 encontrado en posicion " << lista.buscar(2) << endl;
	cout << "Elemento 5 encontrado en posicion " << lista.buscar(5) << endl;
	cout << "Elemento 20 encontrado en posicion " << lista.buscar(20) << endl;

	// Creamos una segunda lista, la inicializamos con 500 a 504 y la imprimimos
	cout << "Nueva lista2:\n";
	ListaContigua lista2;
	for (int i = 500; i <= 505; i++) lista2.insertarAlFinal(i);
	imprimirListaContigua(&lista2);

	// Concatenamos la lista2 con la primera lista, e imprimimos esta ultima
	cout << "Concatenamos la nueva lista a la vieja:\n";
	lista.concatenar(&lista2);
	imprimirListaContigua(&lista);	
}


