#pragma once

#include "Nodo.h"
#include "string"

// Clase que representa un �rbol geneal�gico sencillo
class ArbolGenealogico
{

	Nodo *raiz; // Puntero al nodo ra�z del �rbol. NULL si el �rbol est� vac�o
	int n; // N�mero de elementos (y nodos) del �rbol. S�lo sirve para las precondiciones

	// Obtiene el n�mero de hijos directos de un nodo
	// Par�metro: nodo cuyo n�mero de hijos queremos obtener
	// Retorno: n�mero de hijos del nodo
	// Precondici�n: padre!=NULL
	// Complejidad temporal: O(hijos), siendo hijos el n�mero de hijos del nodo pasado como par�metro
	int getNumeroHijos(Nodo *padre);

	// Obtiene el puntero a un hijo concreto de un nodo
	// Par�metros:
	// - padre: nodo cuyo hijo queremos obtener
	// - posicionHijo: posici�n del hijo que queremos obtener
	// Retorno: puntero al nodo hijo
	// Precondiciones:
	// - padre!=NULL
	// - getNumeroHijos(padre)>0
	// - posicionHijo pertenece a [0, getNumeroHijos(padre)-1]
	// Complejidad temporal: O(hijos), siendo hijos el n�mero de hijos del nodo pasado como par�metro
	Nodo *getHijo(Nodo *padre, int posicionHijo);

	// Obtiene el puntero a un nodo con un determinado contenido en un sub�rbol (m�todo recursivo)
	// Par�metros: 
	// - raizSubarbol: nodo ra�z en donde empieza el sub�rbol
	// - contenido: contenido que queremos buscar en el sub�rbol
	// Retorno: puntero al primer nodo encontrado con el contenido buscado, o NULL si no se encuentra ningun nodo
	// Precondici�n: raizSubarbol != NULL
	// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol que empieza en raizSubarbol 
	Nodo *buscarNodo (Nodo *raizSubarbol, string contenido);
	
	// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con tabulaciones. Esta pensado para ser recursivo
	// Par�metros:
	// - subarbol: nodo ra�z del subarbol que queremos imprimir
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendr�n una tabulaci�n m�s
	// Precondiciones: subarbol != NULL && numeroTabulaciones>=0
	// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol que empieza en raizSubarbol
	void imprimirRecursivo (Nodo *raizSubarbol, int numeroTabulaciones);

	// Elimina recursivamente los nodos de un subarbol
	// Par�metro: el nodo ra�z del subarbol a eliminar
	// Precondici�n: subarbol != NULL
	// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol que empieza en raizSubarbol
	void eliminarSubarbol (Nodo *subarbol);

public:

	// Crea un �rbol de un solo nodo (su ra�z)
	// Par�metro: el contenido de la ra�z
	// Complejidad temporal: O(1)
	ArbolGenealogico(string nombre);

	// Inserta un nuevo nombre en el �rbol geneal�gico, como �ltimo hijo de un nodo indicado en el par�metro
	// Par�metros:
	// - nuevoNombre: nombre que queremos insertar
	// - nombrePadre: padre del nombre que queremos insertar. Ser� su �ltimo hijo
	// Precondici�n: nombrePadre existe en el �rbol, n>0
	// Complejidad temporal: O(n) 
	void insertarNombre (string nuevoNombre, string nombrePadre);

	// Imprime el �rbol en forma de esquema con tabulaciones
	// Precondicion: n>0
	// Complejidad temporal: O(n) 
	void imprimir();

	// Destructor. Destruye toda la memoria ocupada por los nodos del �rbol
	// Complejidad temporal: O(n) 
	~ArbolGenealogico();
};

