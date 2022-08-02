#pragma once
#include "ListaContigua.h"

// Lista que siempre se mantiene ordenada de menor a mayor
class ListaContiguaOrdenada
{

private:

	ListaContigua* lista; // Lista contigua con que implementaremos la lista ordenada

	// Busca, mediante la búsqueda binaria recursiva, un elemento en una sublista de la lista actual. 
	// Si no existe, devuelve la posición en que debería ser insertado para mantener la lista ordenada
	// Parámetros:
	// - valorABuscar: el elemento que se quiere buscar entre lista[posicionInicioSublista] y 
	//   lista[posicionInicioSublista+(n-1)] (ambos inclusive)
	// - posicionInicioSublista: posicion de inicio de la sublista en donde buscar, dentro de la lista actual
	// - nSublista: número de elementos de la sublista que empieza en posicionInicioSublista
	// Retorno: si lo encuentra, devuelve su posición en la lista actual. Si no lo encuentra, devuelve la 
	// posicion en que debería ser insertado para mantener ordenada a la lista
	// Precondiciones (posicionFinSublista = posicionInicioSublista+nSublista-1):
	// - nSublista >= 1
	// - posicionInicioSublista pertenece a [0,n-1]
	// - posicionFinSublista pertenece a [0,n-1]
	// - posicionInicioSublista <= posicionFinSublista
	// Complejidad temporal: O(logn), siendo n el tamaño de la sublista  
	int buscarPosicion(int valorABuscar, int posicionInicioSublista, int nSublista);

public:

	// Constructor. Crea una lista contigua ordenada vacía
	ListaContiguaOrdenada();

	// Inserta un elemento en la posicion adecuada para que la lista siga ordenada
	// Parámetro: el nuevo elemento a insertar
	// Complejidad temporal: O(n) -O(logn) para buscar la posicion adecuada y O(n) para insertar el elemento ahí-
	void insertar(int nuevoValor);

	// Busca la posición de un elemento en la ListaContigua
	// Parámetro: el elemento a buscar
	// Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(logn), pues llama a buscarPosicion()
	int buscar(int elementoABuscar);

	// Elimina un elemento de la lista sin necesidad de dar su posición. Lo busca primero
	// con búsqueda binaria
	// Parámetro: elemento a eliminar
	// Precondición: elementoAEliminar existe
	// Complejidad temporal: O(n)
	void eliminar(int elementoAEliminar);

	// Obtiene la lista interna con que se implementa la lista ordenada
	// Retorno: puntero a la lista interna
	ListaContigua* getLista();

	// Destructor. Libera memoria
	// Complejidad temporal: O(1)
	~ListaContiguaOrdenada();

};

