#include "ListaEnlazada.h"
#include "cassert"
using namespace std;

Nodo * ListaEnlazada::getNodo (int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion <= n-1);

	Nodo *resultado = NULL; // Aquí guardaremos el puntero al nodo resultado 
	
	// Recorremos la lista hasta la posición correcta
	resultado = punteroPrimerNodo; // Hacemos que el resultado apunte al primer nodo
	for (int i=0; i<posicion; i++) 
		resultado = resultado->siguienteNodo;

	return (resultado);
}

ListaEnlazada::ListaEnlazada() {
	punteroPrimerNodo = NULL;
	n=0;
}

int ListaEnlazada::getValor(int posicion) {
	assert(n > 0);
	assert (posicion >= 0 && posicion <= n-1); 
	// Obtenemos el nodo que contiene el elemento
	Nodo *nodoQueContieneResultado = getNodo (posicion);
	return (nodoQueContieneResultado->elemento);
}

void ListaEnlazada::setValor(int posicion, int nuevoValor) {
	assert(n > 0);
	assert (posicion >= 0 && posicion <= n-1); 
	getNodo(posicion)->elemento = nuevoValor;
}

int ListaEnlazada::getN() {
	return (n);
}

void ListaEnlazada::insertar (int posicion, int nuevoValor) {
	assert (posicion >= 0 && posicion <= n); 

	// Creamos el nuevo nodo con el nuevo valor
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->elemento = nuevoValor;

	// Si la lista estaba vacia...
	if (n==0) {
		punteroPrimerNodo = nuevoNodo;
		nuevoNodo->siguienteNodo = NULL;
	}

	// Si la lista no está vacía, distinguimos tres casos
	else {
		
		// Si estamos insertando al principio, el siguiente del insertado
		// es el que antes era el primero (apuntado por "lista")
		if (posicion == 0) {
			nuevoNodo->siguienteNodo = punteroPrimerNodo;
			punteroPrimerNodo = nuevoNodo;
		}

		// Si estamos añadiendo al final de la lista
		else if (posicion == n) {
			nuevoNodo->siguienteNodo = NULL;
			getNodo(n - 1)->siguienteNodo = nuevoNodo;
		}

		// En cualquier otro caso, hay un nodo
		// anterior y otro posterior
		else {
			// Obtenemos los nodos anterior y siguiente al que queremos insertar
			Nodo *anterior = getNodo(posicion - 1); // Nodo que estará antes del que queremos insertar
			Nodo *siguiente = anterior->siguienteNodo; // Nodo que estará después del que queremos insertar

			// Hacemos que cada uno apunte al lugar adecuado
			anterior->siguienteNodo = nuevoNodo;
			nuevoNodo->siguienteNodo = siguiente;
		}

	} // Fin else

	// Incrementamos el numero de elementos
	n++;
}


void ListaEnlazada::eliminar (int posicion) {
	assert(n > 0);
	assert (posicion >= 0 && posicion <= n-1); 

	Nodo *nodoAEliminar = NULL; // Puntero al nodo que queremos eliminar

	// Si el nodo que queremos eliminar es el primero
	if (posicion == 0) {
		nodoAEliminar = punteroPrimerNodo;
		Nodo *nodoSiguiente = nodoAEliminar->siguienteNodo; // Obtenemos el siguiente, o NULL si no lo hay
		punteroPrimerNodo = nodoSiguiente; // Apuntamos al que antes era el segundo nodo, o NULL si solo había un nodo en la lista
	}

	// Si el nodo que queremos eliminar no es el primero
	// Nota que en este caso n>=2 pues si fuera n==1 ya se hubiera ejecutado el anterior caso
	// Nota también que este caso incluye el hecho de que el nodo a eliminar pueda ser el último
	else {
		Nodo *nodoAnterior = getNodo(posicion-1); // Nodo anterior al que queremos eliminar
		nodoAEliminar = nodoAnterior->siguienteNodo; // Nodo que queremos eliminar
		Nodo *nodoSiguiente = nodoAEliminar->siguienteNodo; // Nodo siguiente al que queremos eliminar
		nodoAnterior->siguienteNodo = nodoSiguiente; // Hacemos que el anterior apunte al siguiente
	}

	// Liberamos la memoria del nodo
	delete(nodoAEliminar);

	// Actualizamos n
	n--;
}



ListaEnlazada::~ListaEnlazada() {
	// Eliminamos el primer elemento de la lista. Esta operación la repetimos n veces
	// Eliminar el primer elemento de la lista es O(1)
	while (n>0) eliminar(0);
}



