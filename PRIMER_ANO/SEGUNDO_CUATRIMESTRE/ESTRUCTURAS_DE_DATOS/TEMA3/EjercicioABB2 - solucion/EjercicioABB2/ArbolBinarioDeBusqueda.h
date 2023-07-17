#pragma once
#include "Nodo.h"

// Árbol binario de búsqueda. Se permiten duplicados, y éstos van hacia la izquierda
class ArbolBinarioDeBusqueda
{
	Nodo *raiz; // Raiz del árbol, o NULL si el arbol está vacío
	int n; // Numero de nodos del arbol
	int orientacionSiguienteEliminacion; // Orientacion (-1 si es izquierdo, 1 si es derecho) que tendrá que tener la siguiente eliminación a realizar

public:

	// Construye un árbol binario de búsqueda vacío
	// Complejidad temporal: O(1)
	ArbolBinarioDeBusqueda();

	// Inserta un elemento (siempre se insertará como hoja)
	// Parámetro: nuevo elemento a insertar. Lo coloca en su sitio adecuado
	// Precondición: nuevoElemento no existía previamente en el árbol
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	void insertar (int nuevoElemento);

	// Busca un elemento en el arbol binario de busqueda
	// Parámetro: elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: true si se encuentra en el árbol, false si no
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	bool buscar(int elementoABuscar);
	
	// Elimina el primer nodo que se encuentre con un elemento dado
	// Parámetro: elemento a eliminar
	// Precondiciones: elementoAEliminar existe en el árbol
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	void eliminar (int elementoAEliminar);

	// Imprime el árbol en forma de esquema tabulado, indicando si cada nodo es hijo izquiero o derecho de su padre
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
	void imprimir();

	// Destruye el árbol, liberando la memoria de todos los nodos
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
	~ArbolBinarioDeBusqueda();

private:

	// Busca recursivamente un elemento en el arbol binario de busqueda
	// Parámetros:
	// - raizSubarbol indica el subarbol en donde buscar
	// - elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: puntero al nodo que contiene el elementoABuscar si lo encuentra, o, 
	//          si no lo encuentra, puntero al nodo padre de donde se podría insertar
	// Precondición: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar);
	
	// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con una tabulación. Esta pensado para ser recursivo
	// Parámetros:
	// - subarbol: nodo raíz del subarbol que queremos imprimir
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
	// - orientacion indica si subarbol (primer parametro) es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
	// Precondiciones: 
	// - subarbol != NULL
	// - numeroTabulaciones>=0
	// - orientacion == 1 || orientacion == -1 || orientacion == 0
	// Complejidad temporal: O(n), tanto con la mejor topología (T(n)=1+2T(n/2)) como con la peor (T(n)=1+T(n-1))
	void imprimirRecursivo(Nodo* subarbol, int numeroTabulaciones, int orientacion);

	// Elimina recursivamente los nodos de un subarbol
	// Parámetro: el nodo raíz del subarbol a eliminar
	// Precondición: subarbol != NULL
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
	void eliminarSubarbol(Nodo* raizSubarbol);

	// Elimina el nodo pasado como parametro. Lo sustituye por un descendiente suyo (recursivamente)
	// Parámetros:
	// - nodoParaEliminar: puntero al nodo que queremos eliminar
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	// (n es el número de nodos del subarbol que empieza en nodoParaEliminar)
	void eliminarNodo(Nodo* nodoParaEliminar);
	
	// Buscar el maximo de un subarbol (ir por la rama derecha hasta no poder más)
	// Parámetro: raiz del subarbol en donde buscar
	// Retorno: puntero al nodo que contiene el máximo
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	Nodo *buscarMaximo (Nodo *raizSubarbol);

	// Buscar el minimo de un subarbol (ir por la rama izquierda hasta no poder más)
	// Parámetro: raiz del subarbol en donde buscar
	// Retorno: puntero al nodo que contiene el minimo
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	Nodo *buscarMinimo (Nodo *raizSubarbol);

};

