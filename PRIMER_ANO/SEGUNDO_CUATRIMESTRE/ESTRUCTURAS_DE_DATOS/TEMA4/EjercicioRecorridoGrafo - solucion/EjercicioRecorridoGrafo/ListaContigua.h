#pragma once

// Numero de posiciones en que se incrementa/decrementa la capacidad de la ListaContigua cada vez que es necesario
// Precondición: INCREMENTO >= 1
#define INCREMENTO 2

// Clase que representa a una lista contigua en memoria y cuya capacidad se redimensiona automáticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
class ListaContigua
{
	// Puntero que apuntará a la zona de memoria en donde empieza la ListaContigua
	int* vector;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondición: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondiciones: capacidad >= n
	int capacidad;

	// Nos dice si la ListaContigua está llena o no.
	// Retorno: verdadero si está llena, falso si no está llena
	// Complejidad temporal: O(1)
	bool isLlena();

public:

	// Constructor. Crea una ListaContigua de tamaño 0
	// Complejidad temporal: O(1)
	ListaContigua();

	// Devuelve un elemento de la ListaContigua
	// Parámetro: la posición del elemento
	// Retorno: el elemento encontrado en esa posición
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal: O(1)
	int getValor(int posicion);

	// Modifica un elemento de la ListaContigua
	// Parámetros:
	// - posicion: la posición del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal: O(1)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tamaño actual de la ListaContigua
	// Retorno: número actual de elementos de la ListaContigua
	// Complejidad temporal: O(1)
	int getN();

	// Devuelve la capacidad actual de la ListaContigua
	// Retorno: número máximo que actualmente podría contener la ListaContigua
	// Complejidad temporal: O(1)
	int getCapacidad();

	// Inserta un nuevo elemento en la última posición de la ListaContigua, 
	// ampliando previamente la capacidad si es necesario
	// Parámetros:
	// - nuevoValor: el nuevo elemento que queremos poner
	// Complejidad temporal: O(n)
	void insertarAlFinal(int nuevoValor);

	// Elimina el elemento de la última posición de la ListaContigua,
	// disminuyendo posteriormente la capacidad si es necesario
	// Complejidad temporal: O(1)
	void eliminarAlFinal();

	// Inserta un nuevo elemento en una posición de la lista, dejando primero un hueco para meterlo ahí
	// Los elementos que había desde la posición hasta el final de la ListaContigua se desplazarán una posición a la derecha
	// Parámetros:
	// - posición: la posición en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones:
	// - posicion en [0, n]
	// Complejidad temporal: O(n)
	void insertar(int posicion, int nuevoValor);

	// Elimina un elemento en una posición dada.
	// Los elementos que había desde posicion+1 hasta el final de la ListaContigua se desplazarán una posición a la izquierda
	// Parámetros:
	// - posicion: la posición del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el último
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal: O(n)
	void eliminar(int posicion);

	// Concatena una lista al final de la lista actual. 
	// Cada uno de los elementos de la lista a concatenar se copian, en orden, al final de la lista actual
	// Parámetro: puntero a la lista cuyos elementos queremos concatenar al final de nuestra lista
	// Precondición: listaAConcatenar!=NULL
	// Complejidad temporal: O(n+m), siendo m = listaAConcatenar.getN()
	void concatenar(ListaContigua* listaAConcatenar);

	// Busca la posición de un elemento en la ListaContigua
	// Parámetro: el elemento a buscar
	// Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	int buscar(int elementoABuscar);

	// Destructor. Libera memoria
	// Complejidad temporal: O(1)
	~ListaContigua();
};








