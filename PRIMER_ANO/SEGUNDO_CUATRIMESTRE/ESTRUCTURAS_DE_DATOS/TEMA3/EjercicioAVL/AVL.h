#pragma once
#include "Nodo.h"

// Árbol binario de búsqueda del tipo AVL. No se permiten duplicados
class AVL
{
	Nodo *raiz; // Raiz del árbol, o NULL si el arbol está vacío
	int n; // Numero de nodos del arbol

public:

	// Construye un árbol binario de búsqueda vacío
	// Complejidad temporal: O(1)
	AVL();

	// Inserta un elemento, asegurandose de que el árbol siga siendo AVL al terminar
	// Parámetro: nuevo elemento a insertar. 
	// Complejidad temporal: O(lgn)
	void insertar(int nuevoElemento);

	// Busca un elemento en el arbol 
	// Parámetro: elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: true si se encuentra en el árbol, false si no
	// Complejidad temporal: O(lgn) 
	bool buscar(int elementoABuscar);

	// Imprime el árbol en forma de esquema tabulado
	// Complejidad temporal: O(n)
	void imprimir();

	// Destruye el árbol, liberando la memoria de todos los nodos
	// Complejidad temporal: O(n)
	~AVL();

private:

	// Inserta un elemento (siempre se insertará como hoja), como si fuera un arbol binario de busqueda normal
	// Parámetro: nuevo elemento a insertar. Lo coloca en su sitio adecuado
	// Retorno: puntero al nodo insertado
	// Complejidad temporal: O(lgn)
	Nodo* insertarHoja(int nuevoElemento);
	
	// Reequilibra el arbol AVL despues de insertar una hoja, empezando por dicha hoja y ascendiendo hasta la raiz
	// Parámetro: hoja desde la que empezamos a subir
	// Precondicion: hoja != NULL
	// Complejidad temporal: O(logn)
	void reequilibrar(Nodo *hoja);

	// Imprime un subarbol por pantalla en forma de esquema, sangrando cada nodo con una 
	// tabulación más que su padre. Esta pensado para ser recursivo
	// Parámetros:
	// - subarbol: nodo raíz del subarbol que queremos imprimir
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
	// - orientacion indica si subarbol (primer parametro) es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
	// Precondicion: subarbol != NULL
	// Complejidad temporal: O(n), siendo n el número de nodos del subarbol
	void imprimirRecursivo(Nodo *subarbol, int numeroTabulaciones, int orientacion);

	// Elimina recursivamente los nodos de un subarbol
	// Parámetro: el nodo raíz del subarbol a eliminar
	// Precondición: subarbol != NULL
	// Complejidad temporal: O(n), siendo n el número de nodos del subarbol
	void eliminarSubarbol(Nodo *subarbol);

	// Busca recursivamente un elemento en el arbol binario de busqueda
	// Parámetros:
	// - raizSubarbol indica el subarbol en donde buscar
	// - elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: puntero al nodo que contiene el elementoABuscar si lo encuentra, o, 
	//          si no lo encuentra, puntero al nodo padre de donde se podría insertar
	// Precondición: raizSubarbol != NULL
	// Complejidad temporal: O(lgn), siendo n el numero de nodos del subárbol
	Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar);

	// Implementa, en un subarbol, una rotación simple a la izquierda
	// Parametro: raíz del nodo raíz del subarbol en donde se hará la rotación
	// Retorno: puntero a la nueva raiz del subarbol
	// Precondiciones:
	// - El nodo raíz existe y tiene un factor de equilibrio de 2
	// - Su hijo derecho existe y tiene un factor de equilibrio de 1
	// Complejidad temporal: O(1)
	Nodo* rotarSimpleIzquierda(Nodo *raizSubarbol);

	// Implementa, en un subarbol, una rotación simple a la derecha
	// Parametro: raíz del nodo raíz del subarbol en donde se hará la rotación
	// Retorno: puntero a la nueva raiz del subarbol
	// Precondiciones:
	// - El nodo raíz existe y tiene un factor de equilibrio de -2
	// - Su hijo izquierdo existe y tiene un factor de equilibrio de -1
	// Complejidad temporal: O(1)
	Nodo* rotarSimpleDerecha(Nodo *raizSubarbol);

	// Implementa, en un subarbol, una rotación compuesta derecha-izquierda
	// Parametro: raíz del nodo raíz del subarbol en donde se hará la rotación
	// Retorno: puntero a la nueva raiz del subarbol
	// Precondiciones:
	// - El nodo raíz existe y tiene un factor de equilibrio de 2
	// - Su hijo derecho existe y tiene un factor de equilibrio de -1
	// Complejidad temporal: O(1)
	Nodo* rotarCompuestaDerechaIzquierda(Nodo *raizSubarbol);

	// Implementa, en un subarbol, una rotación compuesta izquierda-derecha
	// Parametro: raíz del nodo raíz del subarbol en donde se hará la rotación
	// Retorno: puntero a la nueva raiz del subarbol
	// Precondiciones:
	// - El nodo raíz existe y tiene un factor de equilibrio de -2
	// - Su hijo izquierdo existe y tiene un factor de equilibrio de 1
	// Complejidad temporal: O(1)
	Nodo* rotarCompuestaIzquierdaDerecha(Nodo *raizSubarbol);

	// Hace que el padre de antiguoHijo apunte en su lugar a nuevoHijo
	// Parámetros:
	// - antiguoHijo: nodo cuyo padre dejará de apuntarle
	// - nuevoHijo: queremos que el padre de antiguoHijo pase a apuntar a nuevoHijo
	// Precondición: antiguoHijo != NULL
	// Complejidad temporal: O(1)
	void cambiarHijo(Nodo *antiguoHijo, Nodo *nuevoHijo);

};



