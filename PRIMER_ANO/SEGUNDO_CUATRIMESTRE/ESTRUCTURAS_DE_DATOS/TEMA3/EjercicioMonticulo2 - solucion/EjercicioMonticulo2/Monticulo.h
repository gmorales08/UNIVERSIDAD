#pragma once
#include "ListaContigua.h"

// Clase que representa un monticulo (arbol binario completo en el cual la clave de cada nodo es menor que la de sus descendientes)
class Monticulo
{
private:

	ListaContigua vector; // Lista contigua en memoria que representar� al monticulo

public:

	// Imprime el �rbol en forma de esquema con tabulaciones
	// Complejidad temporal: O(n)
	void imprimir();

	// Inserta un nuevo elemento en el monticulo
	// Par�metro: nuevoElemento a insertar
	// Postcondici�n: el �rbol sigue siendo un mont�culo despues de insertar el nuevo elemento
	// Complejidad temporal: O(logn)
	void insertar(int nuevoElemento);

	// Borra la raiz
	// Precondici�n: el monticulo no esta vacio
	// Complejidad temporal: O(logn)
	void borrar();

	// Obtiene una copia de la raiz del monticulo
	// Precondicion: el monticulo no esta vacio
	// Complejidad temporal: O(1)
	int getRaiz();

private:

	// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con una tabulaci�n m�s que su padre. 
	// Esta pensado para ser recursivo
	// Par�metros:
	// - raiz: numero del nodo ra�z del subarbol que queremos imprimir (empezando la numeraci�n por 1). 
	//   Si ese numero de nodo no existe (que sea mayor que el numero de nodos), no se imprime nada
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendr�n una tabulaci�n m�s
	// Precondiciones: 
	// - raiz >= 1
	// - numeroTabulaciones >= 0
	// Complejidad temporal: O(n)
	void imprimirRecursivo (int raiz, int numeroTabulaciones);

	// Comprueba si el �rbol que empieza en el nodo dado como argumento es un monticulo
	// Par�metro: numero del elemento que es la raiz del subarbol que queremos comprobar
	// Retorno: true si el sub�rbol es un mont�culo, false si no lo es
	// Precondici�n: raizSubarbol est� en [1,n]
	// Complejidad temporal: O(n)
	bool isMonticulo (int raizSubarbol);

	// Convierte en un mont�culo algo que ya es un monticulo excepto la raiz
	// Precondiciones:
	// - el subarbol izquierdo y el subarbol derecho son mont�culos
	// - el arbol tiene al menos dos elementos
	// Complejidad temporal: O(logn)
	void reestructurar();
};

