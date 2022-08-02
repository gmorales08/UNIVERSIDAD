#include "Pila.h"
#include "cassert" // Para "assert()"


void Pila::push(int nuevoElemento) {
	lista.insertar(0, nuevoElemento);
}

int Pila::pop() {
	assert(!isVacia()); // Precondición
	int resultado = verCima(); // Obtenemos la cima
	lista.eliminar(0); // Eliminamos la cima
	return(resultado);
}

int Pila::verCima() {
	assert(!isVacia()); // Precondición
	return(lista.getValor(0));
}

bool Pila::isVacia() {
	return (lista.getN()==0);
}

ListaEnlazada* Pila::getLista() {
	return(&lista);
}

