#pragma once // Esta directiva evita que se incluya por error este archivo m�s de una vez en el main

// Numero de posiciones en que se incrementa/decrementa la capacidad de la ListaContigua cada vez que es necesario
// Precondici�n: INCREMENTO >= 1
#define INCREMENTO 2

// Clase que representa a una lista contigua en memoria y cuya capacidad se redimensiona autom�ticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
class ListaContigua
{
	// Puntero que apuntar� a la zona de memoria en donde empieza la ListaContigua
	int *vector;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondici�n: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondiciones: capacidad >= n
	int capacidad;

	// Nos dice si la ListaContigua est� llena o no.
	// Retorno: verdadero si est� llena, falso si no est� llena
	// Complejidad temporal: O(1)
	bool isLlena();

	// Ampl�a o disminuye la capacidad en un valor
	// Par�metro: cantidad a aumentar (si es positivo) o disminuir
	//            (si es negativo) la capacidad actual de la lista
	// Complejidad temporal: O(n)
	void ampliarCapacidad(int incremento);

public:

	// Constructor. Crea una ListaContigua de tama�o 0
	// Complejidad temporal: O(1)
	ListaContigua();

	// Devuelve un elemento de la ListaContigua
	// Par�metro: la posici�n del elemento
	// Retorno: el elemento encontrado en esa posici�n
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal: O(1)
	int getValor(int posicion);

	// Modifica un elemento de la ListaContigua
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal: O(1)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tama�o actual de la ListaContigua
	// Retorno: n�mero actual de elementos de la ListaContigua
	// Complejidad temporal: O(1)
	int getN(); 

	// Devuelve la capacidad actual de la ListaContigua
	// Retorno: n�mero m�ximo que actualmente podr�a contener la ListaContigua
	// Complejidad temporal: O(1)
	int getCapacidad(); 

	// Inserta un nuevo elemento en la �ltima posici�n de la ListaContigua, 
	// ampliando previamente la capacidad si es necesario
	// Par�metros:
	// - nuevoValor: el nuevo elemento que queremos poner
	// Complejidad temporal: O(n)
	void insertarAlFinal (int nuevoValor);

	// Elimina el elemento de la �ltima posici�n de la ListaContigua,
	// disminuyendo posteriormente la capacidad si es necesario
	// Complejidad temporal: O(1)
	void eliminarAlFinal();

	// Destructor. Libera memoria
	// Complejidad temporal: O(1)
	~ListaContigua();
};








