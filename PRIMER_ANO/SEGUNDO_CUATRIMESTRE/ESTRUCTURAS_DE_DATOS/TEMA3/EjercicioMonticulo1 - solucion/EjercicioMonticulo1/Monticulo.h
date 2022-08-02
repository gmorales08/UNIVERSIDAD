#pragma once
#include "ListaContigua.h"

// Clase que representa un monticulo (arbol binario completo en el cual la clave de cada nodo es menor que la de sus descendientes)
class Monticulo
{
private:

	ListaContigua vector; // Lista contigua en memoria que representará al monticulo

public:

	// Imprime el árbol en forma de esquema con tabulaciones
	// Complejidad temporal: O(n)
	void imprimir();

	// Inserta un nuevo elemento en el monticulo
	// Parámetro: nuevoElemento a insertar
	// Postcondicion: el árbol con el nuevoElemento ya insertado sigue siendo un montículo
	// Complejidad temporal: O(logn)
	void insertar(int nuevoElemento);

private:

	// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con una tabulación más que su padre. 
	// Esta pensado para ser recursivo
	// Parámetros:
	// - raiz: numero del nodo raíz del subarbol que queremos imprimir (empezando la numeración por 1). 
	//   Si ese numero de nodo no existe (que sea mayor que el numero de nodos), no se imprime nada
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
	// Precondiciones: 
	// - raiz >= 1
	// - numeroTabulaciones >= 0
	// Complejidad temporal: O(n)
	void imprimirRecursivo (int raiz, int numeroTabulaciones);

	// Comprueba recursivamente si el árbol que empieza en el nodo dado como argumento es un monticulo
	// Parámetro: numero del elemento que es la raiz del subarbol que queremos comprobar
	// Retorno: true si el subárbol es un montículo, false si no lo es
	// Precondición: raizSubarbol está en [1,n]
	// Complejidad temporal: O(n)
	bool isMonticulo (int raizSubarbol);

};

