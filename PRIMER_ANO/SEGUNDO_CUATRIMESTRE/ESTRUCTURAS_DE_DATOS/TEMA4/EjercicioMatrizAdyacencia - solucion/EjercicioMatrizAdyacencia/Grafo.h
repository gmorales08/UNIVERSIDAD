#pragma once
#include "ListaContigua.h"
#include "string"

using namespace std;

// Grafo dirigido, no ac�clico, no multigrafo, pseudografo, no necesariamente conexo, no etiquetado
// Implementado con matriz de adyacencia
class Grafo
{
private:

	ListaContigua *matriz; // Apuntador al comienzo de un array de objetos de tipo lista. Cada uno ser� una fila de la matriz de adyacencia
	int n; // Numero de nodos
	string nombresNodos; // Lista de nombres de los nodos. Como el nombre de cada nodo es un car�cter, la lista es un string

	// Comprobamos si existe un arco entre dos nodos
	// Par�metros: 
	// - indiceNodoOrigen: el indice del nodo origen
	// - indiceNodoDestino: el indice del nodo destino
	// Retorno: true si existe el arco, false si no
	// Precondici�n: indiceNodoOrigen e indiceNodoDestino pertenece a [0, n-1]
	// Complejidad temporal: O(1)
	bool existeArco (int indiceNodoOrigen, int indiceNodoDestino);

	// Comprueba si existe un nodo en el grafo
	// Par�metro: nombre del nodo que queremos comprobar si est� en el grafo
	// Retorno: true si el nodo existe, false si no
	// Complejidad temporal: O(n) porque recorremos el vector de nombres para encontrar el nodo (b�squeda secuencial, pues los nodos est�n desordenados)
	bool existeNodo (char nombreNodo);

	// Obtiene el indice de un nodo (n�mero de columna o fila de la matriz de adyacencia en donde est�)
	// Par�metro: nombre del nodo cuyo �ndice se quiere obtener
	// Retorno: el �ndice del nodo (de 0 a n-1)
	// Precondici�n: el nodo cuyo nombre se proporciona existe dentro del grafo
	// Complejidad temporal: O(n) porque buscamos secuencialmente el nodo en la lista de nombres de nodos
	int obtenerIndice (char nombreNodo);

public:

	// Crea un grafo vac�o
	// Complejidad temporal: O(1)
	Grafo();

	// Imprime el grafo por pantalla en forma de matriz de adyacencia, imprimiendo t�tulos de las columnas y filas
	// OJO: este m�todo viola el principio de separaci�n entre interfaz y modelo
	// Complejidad temporal: O(n^2) porque imprimimos todos los posibles arcos
	void imprimir();

	// Inserta un nodo desconectado en el grafo
	// Par�metro: nombre del nuevo nodo que queremos insertar
	// Precondici�n: no existe ning�n nodo en el grafo que tenga dicho nombre
	// Complejidad temporal: O(n^2) porque por dentro usamos una matriz temporal en la cual copiamos la matriz original 
	void insertarNodo (char nombreNodo);

	// Inserta un arco en el grafo
	// Par�metros: nombres del nodo origen y del nodo destino del arco que queremos a�adir
	// Precondici�n: los dos nodos deben existir previamente en el grafo
	// Complejidad temporal: O(n) porque hay que obtener el indice del nodo a partir de su nombre
	void insertarArco (char nodoOrigen, char nodoDestino);

	// Borra un arco del nodo
	// Par�metros: nombres del nodo origen y del nodo destino del arco que queremos eliminar
	// Precondici�n: los dos nodos deben existir previamente en el grafo
	// Complejidad temporal: O(n) porque hay que obtener el indice del nodo a partir de su nombre
	void borrarArco (char nodoOrigen, char nodoDestino);

	// Borrar un nodo del grafo. Borramos autom�ticamente todos los arcos que llegan y que parten del nodo a eliminar
	// Par�metro: nombre del nodo a eliminar
	// Precondici�n: el nodo debe previamente existir
	// Complejidad temporal: O(n^2) porque por dentro usamos una matriz temporal en la cual copiamos la matriz original 
	void borrarNodo (char nombreNodo);

	// Destruye el grafo y libera la memoria de todos sus nodos
	// Complejidad temporal: O(n) porque hay que llamar al destructor de cada fila, el cual es O(1)
	~Grafo();
};

