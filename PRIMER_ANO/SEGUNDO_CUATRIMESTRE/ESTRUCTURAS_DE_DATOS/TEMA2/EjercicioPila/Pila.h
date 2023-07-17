#pragma once
#include "ListaEnlazada.h"

// Clase que implementa una pila de elementos. La pila se implementa internamente mediante
// una lista enlazada doble y circular.
// La cima de la pila será el primer elemento de la lista
class Pila
{
private:

	// Lista enlazada interna para implementar la pila
	ListaEnlazada lista;

public:

	// Mete un nuevo elemento en la cima de la pila
	// Parámetro: nuevo elemento que copiaremos en la cima
	// Complejidad temporal: O(1)
	void push(int nuevoElemento);

	// Obtiene el elemento que está en la cima y lo borra de ahí
	// Retorno: una copia del elemento que está en la cima
	// Precondición: la pila no está vacía
	// Complejidad temporal: O(1)
	int pop();

	// Obtiene el elemento que está en la cima sin borrarlo de ahí
	// Retorno: una copia del elemento que está en la cima
	// Precondición: la pila no está vacía
	// Complejidad temporal: O(1)
	int verCima();

	// Comprueba si la pila está vacía
	// Retorno: verdadero si está vacía, falso si no lo está
	// Complejidad temporal: O(1)
	bool isVacia();

	// Devuelve la lista interna que implementa a la pila
	// Retorno: un puntero a la lista interna de la pila
	// Complejidad temporal: O(1)
	ListaEnlazada *getLista();

};

