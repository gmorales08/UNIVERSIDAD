#pragma once
#include "Nodo.h"

// �rbol binario de b�squeda. No se permiten duplicados
class ArbolBinarioDeBusqueda
{
	Nodo *raiz; // Raiz del �rbol, o NULL si el arbol est� vac�o
	int n; // Numero de nodos del arbol
	
public:

	// Construye un �rbol binario de b�squeda vac�o
	// Complejidad temporal: O(1)
	ArbolBinarioDeBusqueda();

	// Inserta un elemento (siempre se insertar� como hoja)
	// Par�metro: nuevo elemento a insertar. Lo coloca en su sitio adecuado
	// Precondici�n: nuevoElemento no exist�a previamente en el �rbol
	// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
	void insertar (int nuevoElemento);

	// Busca un elemento en el arbol binario de busqueda
	// Par�metro: elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: true si se encuentra en el �rbol, false si no
	// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
	bool buscar(int elementoABuscar);
	
	// Imprime el �rbol en forma de esquema tabulado, indicando si cada nodo es hijo izquiero o derecho de su padre
	// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol, tanto con la mejor topolog�a como con la peor
	void imprimir();

	// Destruye el �rbol, liberando la memoria de todos los nodos
	// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol, tanto con la mejor topolog�a como con la peor
	~ArbolBinarioDeBusqueda();

private:

	// Busca recursivamente un elemento en el arbol binario de busqueda
	// Par�metros:
	// - raizSubarbol indica el subarbol en donde buscar
	// - elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: puntero al nodo que contiene el elementoABuscar si lo encuentra, o, 
	//          si no lo encuentra, puntero al nodo padre de donde se podr�a insertar
	// Precondici�n: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
	Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar);

	// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con una tabulaci�n. Esta pensado para ser recursivo
	// Par�metros:
	// - subarbol: nodo ra�z del subarbol que queremos imprimir
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendr�n una tabulaci�n m�s
	// - orientacion indica si subarbol (primer parametro) es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
	// Precondiciones: 
	// - subarbol != NULL
	// - numeroTabulaciones>=0
	// - orientacion == 1 || orientacion == -1 || orientacion == 0
	// Complejidad temporal: O(n), tanto con la mejor topolog�a (T(n)=1+2T(n/2)) como con la peor (T(n)=1+T(n-1))
	void imprimirRecursivo (Nodo *subarbol, int numeroTabulaciones, int orientacion);

	// Elimina recursivamente los nodos de un subarbol
	// Par�metro: el nodo ra�z del subarbol a eliminar
	// Precondici�n: subarbol != NULL
	// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol, tanto con la mejor topolog�a como con la peor
	void eliminarSubarbol (Nodo *raizSubarbol);

};

