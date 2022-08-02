#include "iostream"
#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"
using namespace std;


void main () {

	// Creamos una lista que nos servirá para las pruebas
	ListaEnlazada lista;
	cout << "Nueva ListaEnlazada creada:\n";
	imprimirListaEnlazada(&lista);

	// Prueba de insercion en lista vacia
	cout << "Inserto 10 con la lista vacia:\n";
	lista.insertar(0, 10);
	imprimirListaEnlazada(&lista);

	// Prueba de insercion al final
	cout << "Inserto 20 y 21 al final:\n";
	for (int i = 20; i <= 21; i++) {
		int n = lista.getN(); // Obtenemos el numero de elementos de la lista
		lista.insertar(n, i); // Insertamos al final
		imprimirListaEnlazada(&lista);
	}

	// Prueba de insercion al principio
	cout << "Inserto 30 al principio:\n";
	lista.insertar(0, 30);
	imprimirListaEnlazada(&lista);

	// Prueba de insercion en medio
	cout << "Inserto 40 en la posicion 2:\n";
	lista.insertar(2, 40);
	imprimirListaEnlazada(&lista);

	// Prueba de eliminacion al principio
	cout << "Elimino el primer elemento:\n";
	lista.eliminar(0);
	imprimirListaEnlazada(&lista);

	// Prueba de eliminación del final
	cout << "Elimino el ultimo elemento:\n";
	int n = lista.getN(); // Numero actual de elementos de la lista
	lista.eliminar(n - 1);
	imprimirListaEnlazada(&lista);

	// Prueba de eliminación del medio
	cout << "Elimino el elemento del medio:\n";
	lista.eliminar(1);
	imprimirListaEnlazada(&lista);

	// Prueba de eliminacion hasta dejar la lista vacia
	cout << "Elimino el 20 y el 10 para dejar la lista vacia:\n";
	lista.eliminar(1); imprimirListaEnlazada(&lista);
	lista.eliminar(0); imprimirListaEnlazada(&lista);

	// Vuelvo a repetir las inserciones del principio,
	// para comprobar que realmente las eliminaciones lo han hecho bien
	// y no han dejado inconsistente a la lista
	cout << "Vuelvo a repetir las inserciones del principio:\n";

	// Prueba de insercion en lista vacia
	cout << "Inserto 10 con la lista vacia:\n";
	lista.insertar(0, 10);
	imprimirListaEnlazada(&lista);

	// Prueba de insercion al final
	cout << "Inserto 20 y 21 al final:\n";
	for (int i = 20; i <= 21; i++) {
		int n = lista.getN(); // Obtenemos el numero de elementos de la lista
		lista.insertar(n, i); // Insertamos al final
		imprimirListaEnlazada(&lista);
	}

	// Prueba de insercion al principio
	cout << "Inserto 30 al principio:\n";
	lista.insertar(0, 30);
	imprimirListaEnlazada(&lista);

	// Prueba de insercion en medio
	cout << "Inserto 40 en la posicion 2:\n";
	lista.insertar(2, 40);
	imprimirListaEnlazada(&lista);

	// Insertamos otros dos para hacer mejores pruebas luego
	cout << "Insertamos 50 y 60 al final:\n";
	lista.insertar(5, 50);
	lista.insertar(6, 60);
	imprimirListaEnlazada(&lista);

	// Ver elementos
	cout << "Elemento 0 es " << lista.getValor(0) << endl;
	cout << "Elemento 4 es " << lista.getValor(4) << endl;
	cout << "Elemento 2 es " << lista.getValor(2) << endl;
	cout << "Elemento 6 es " << lista.getValor(6) << endl;

	// Modificar elementos
	cout << "Cambio elementos 0, 4, 2 y 6 por sus inversos. El resultado es:\n";
	lista.setValor(0, -30);
	lista.setValor(4, -21);
	lista.setValor(2, -40);
	lista.setValor(6, -60);
	imprimirListaEnlazada(&lista);
}


