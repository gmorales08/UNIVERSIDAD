#pragma once // Esta directiva evita que se incluya por error este archivo más de una vez en el main

// Numero de posiciones en que se incrementa/decrementa la capacidad de la ListaContigua cada vez que es necesario
// Precondición: INCREMENTO >= 1
#define INCREMENTO 2

// Clase que representa a una lista contigua en memoria y cuya capacidad se redimensiona automáticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
class ListaContigua
{
	// Puntero que apuntará a la zona de memoria en donde empieza la ListaContigua
	int *vector;

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

	// Amplía o disminuye la capacidad en un valor
	// Parámetro: cantidad a aumentar (si es positivo) o disminuir
	//            (si es negativo) la capacidad actual de la lista
	// Complejidad temporal: O(n)
	void ampliarCapacidad(int incremento);

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
	void insertarAlFinal (int nuevoValor);

	// Elimina el elemento de la última posición de la ListaContigua,
	// disminuyendo posteriormente la capacidad si es necesario
	// Complejidad temporal: O(1)
	void eliminarAlFinal();

	// Destructor. Libera memoria
	// Complejidad temporal: O(1)
	~ListaContigua();
};








