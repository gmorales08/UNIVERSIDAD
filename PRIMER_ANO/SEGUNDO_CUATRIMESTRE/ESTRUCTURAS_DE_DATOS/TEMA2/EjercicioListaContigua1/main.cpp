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
	for (int i = 0; i <= 11; i++) {
		lista.insertarAlFinal(i); // Introducimos el nuevo elemento
		imprimirListaContigua(&lista);
	}
	cout << "Elemento0=" << lista.getValor(0) << "|Elemento11=" << lista.getValor(11) << endl;

	cout << "Cambio elemento 4 por 50. Nueva ListaContigua:\n";
	lista.setValor(4, 50);
	imprimirListaContigua(&lista);

	// Borramos los ultimos cuatro elementos
	for (int i = 0; i < 4; i++) {
		cout << "Borramos el ultimo elemento. Nueva ListaContigua:\n";
		lista.eliminarAlFinal();
		imprimirListaContigua(&lista);
	}

	// Insertamos 100, 101, 102 y 103 al final
	for (int i = 100; i <= 103; i++) {
		cout << "Insertamos " << i << " al final. Nueva ListaContigua:\n";
		lista.insertarAlFinal(i);
		imprimirListaContigua(&lista);
	}
}


