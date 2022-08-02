#pragma once
#include "Nodo.h"

// Clase que representa a una lista enlazada simple. No tiene restricci�n de tama�o
// Se trata de una lista enlazada de nodos, en donde cada nodo tiene un elemento (un int), y un puntero al siguiente nodo
class ListaEnlazada
{
	// Puntero que apuntar� al primer nodo de la lista, o ser� NULL si la lista est� vac�a
	Nodo *punteroPrimerNodo;

	// Numero actual de elementos que tiene la lista
	// Precondici�n: n>=0
	int n;

	// Obtiene un nodo de la lista
	// Par�metro: la posici�n del nodo
	// Retorno: un puntero al nodo que est� en dicha posici�n
	// Precondiciones: 
	// - la posici�n debe estar en el intervalo [0, n-1]
	// - La lista no esta vacia (n>0)
	// Complejidad temporal: O(n)
	Nodo * getNodo (int posicion);

public:

	// Constructor. Crea una lista de tama�o 0
	// Complejidad temporal: O(1)
	ListaEnlazada();

	// Devuelve un elemento de la lista en determinada posici�n
	// Par�metro: la posici�n del elemento
	// Retorno: una copia del elemento encontrado en esa posici�n
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	int getValor(int posicion);

	// Modifica un elemento de la lista
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tama�o actual de la lista
	// Complejidad temporal: O(1)
	int getN(); 

	// Inserta un nuevo elemento en una posici�n de la lista
	// Par�metros:
	// - posici�n: la posici�n en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones: posicion en [0, n]
	// Complejidad temporal: O(n)
	void insertar (int posicion, int nuevoValor);

	// Elimina un elemento en una posici�n dada.
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el �ltimo
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	void eliminar (int posicion);

	// Destructor. Libera memoria
	// Complejidad temporal: O(n)
	~ListaEnlazada();
};







