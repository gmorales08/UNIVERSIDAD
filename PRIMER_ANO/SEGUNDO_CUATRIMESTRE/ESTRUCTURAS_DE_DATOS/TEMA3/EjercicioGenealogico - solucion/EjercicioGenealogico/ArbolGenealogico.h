#pragma once

#include "Nodo.h"
#include "string"

// Clase que representa un árbol genealógico sencillo
class ArbolGenealogico
{

	Nodo *raiz; // Puntero al nodo raíz del árbol. NULL si el árbol está vacío
	int n; // Número de elementos (y nodos) del árbol. Sólo sirve para las precondiciones

	// Obtiene el número de hijos directos de un nodo
	// Parámetro: nodo cuyo número de hijos queremos obtener
	// Retorno: número de hijos del nodo
	// Precondición: padre!=NULL
	// Complejidad temporal: O(hijos), siendo hijos el número de hijos del nodo pasado como parámetro
	int getNumeroHijos(Nodo *padre);

	// Obtiene el puntero a un hijo concreto de un nodo
	// Parámetros:
	// - padre: nodo cuyo hijo queremos obtener
	// - posicionHijo: posición del hijo que queremos obtener
	// Retorno: puntero al nodo hijo
	// Precondiciones:
	// - padre!=NULL
	// - getNumeroHijos(padre)>0
	// - posicionHijo pertenece a [0, getNumeroHijos(padre)-1]
	// Complejidad temporal: O(hijos), siendo hijos el número de hijos del nodo pasado como parámetro
	Nodo *getHijo(Nodo *padre, int posicionHijo);

	// Obtiene el puntero a un nodo con un determinado contenido en un subárbol (método recursivo)
	// Parámetros: 
	// - raizSubarbol: nodo raíz en donde empieza el subárbol
	// - contenido: contenido que queremos buscar en el subárbol
	// Retorno: puntero al primer nodo encontrado con el contenido buscado, o NULL si no se encuentra ningun nodo
	// Precondición: raizSubarbol != NULL
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol que empieza en raizSubarbol 
	Nodo *buscarNodo (Nodo *raizSubarbol, string contenido);
	
	// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con tabulaciones. Esta pensado para ser recursivo
	// Parámetros:
	// - subarbol: nodo raíz del subarbol que queremos imprimir
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
	// Precondiciones: subarbol != NULL && numeroTabulaciones>=0
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol que empieza en raizSubarbol
	void imprimirRecursivo (Nodo *raizSubarbol, int numeroTabulaciones);

	// Elimina recursivamente los nodos de un subarbol
	// Parámetro: el nodo raíz del subarbol a eliminar
	// Precondición: subarbol != NULL
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol que empieza en raizSubarbol
	void eliminarSubarbol (Nodo *subarbol);

public:

	// Crea un árbol de un solo nodo (su raíz)
	// Parámetro: el contenido de la raíz
	// Complejidad temporal: O(1)
	ArbolGenealogico(string nombre);

	// Inserta un nuevo nombre en el árbol genealógico, como último hijo de un nodo indicado en el parámetro
	// Parámetros:
	// - nuevoNombre: nombre que queremos insertar
	// - nombrePadre: padre del nombre que queremos insertar. Será su último hijo
	// Precondición: nombrePadre existe en el árbol, n>0
	// Complejidad temporal: O(n) 
	void insertarNombre (string nuevoNombre, string nombrePadre);

	// Imprime el árbol en forma de esquema con tabulaciones
	// Precondicion: n>0
	// Complejidad temporal: O(n) 
	void imprimir();

	// Destructor. Destruye toda la memoria ocupada por los nodos del árbol
	// Complejidad temporal: O(n) 
	~ArbolGenealogico();
};

