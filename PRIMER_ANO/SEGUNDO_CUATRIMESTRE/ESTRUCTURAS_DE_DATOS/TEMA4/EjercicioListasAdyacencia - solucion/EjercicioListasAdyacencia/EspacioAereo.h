#pragma once

#include "ListaContigua.h"
#include "Aeropuerto.h"
#include "string"

using namespace std;

// Clase que representa a un grafo cuyos nodos son aeropuertos y los arcos son las rutas a�reas
// entre ellos. El grafo es dirigido, no ac�clico, no multigrafo, no pseudografo, no necesariamente 
// conexo, etiquetado con los kil�metros de cada ruta a�rea y la compa��a que opera dicha ruta
class EspacioAereo {

	ListaContigua nodos; // Lista de nodos del grafo
	int n; // Numero actual de nodos del grafo

private:

	// Averigua si un aeropuerto existe en el grafo o no
	// Par�metro: nombre del aeropuerto
	// Retorno: true si existe, false si no
	// Complejidad temporal: O(n), porque es b�squeda secuencial en lista contigua
	bool existeAeropuerto(string nombre);

	// Obtiene la lista de rutas que parten desde un origen
	// Par�metro: nombre del aeropuerto de origen
	// Retorno: puntero a una lista con las rutas que parten desde el origen
	// Precondici�n: el aeropuerto de origen existe en el grafo
	// Complejidad temporal: O(n), pues hay que encontrar el nodo origen
	ListaEnlazada* getDestinos(string origen);

	// Obtiene la lista de rutas que llegan a un destino
	// Par�metro: nombre del aeropuerto de destino
	// Retorno: puntero a una lista con las rutas que llegan al estino
	// Precondici�n: el aeropuerto de destino existe en el grafo
	// Complejidad temporal: O(n), pues hay que encontrar el nodo destino
	ListaEnlazada* getOrigenes(string destino);

	// Averigua si hay una ruta entre dos aeropuertos
	// Par�metros: nombre del aeropuerto origen y del aeropuerto destino
	// Retorno: true si hay ruta desde el origen hasta el destino, false si no
	// Complejidad temporal: O(arcos), pues hay que buscar el aeropuerto origen y,
	// dentro de su lista enlazada, el aeropuerto destino. Ambas b�squedas son secuenciales
	bool existeRuta(string origen, string destino);

public:

	// Construye un grafo vac�o
	// Complejidad temporal: O(1)
	EspacioAereo();

	// Imprime por consola el espacio aereo entero
	// OJO: este m�todo viola el principio de separaci�n entre interfaz y modelo
	// Complejidad temporal: O(arcos), siendo arcos el numero de arcos del grafo
	void imprimir();

	// Inserta un nuevo aeropuerto, sin rutas entrantes ni salientes
	// Par�metro: nombre del nuevo aeropuerto
	// Precondici�n: el nombre del nuevo aeropuerto no debe existir previamente en el grafo
	// Complejidad temporal: O(1)
	void insertarAeropuerto(string nombre);

	// Inserta una nueva ruta en el espacio a�reo
	// Par�metros:
	// - origen: nombre del aeropuerto origen
	// - destino: nombre del aeropuerto destino
	// - distancia: numero de kil�metros de la ruta
	// - empresa: nombre de la compa��a a�rea que opera la l�nea
	// Precondiciones: 
	// - Origen y destino existen en el grafo
	// - No existe a�n en el grafo una ruta entre origen y destino
	// - distancia > 0
	// Complejidad temporal: O(n), pues hay que buscar secuencialmente el aeropuerto de origen
	void insertarRuta(string origen, string destino, int distancia, string empresa);

	// Elimina una ruta
	// Par�metros: nombres de los aeropuertos origen y destino
	// Precondiciones: ambos aeropuertos y la ruta existen en el grafo
	// Complejidad temporal: O(arcos), siendo arcos el n�mero actual de arcos del grafo,
	// ya que en el peor caso habr�a que buscar la ruta en todos los arcos del grafo
	void eliminarRuta(string origen, string destino);

	// Elimina un aeropuerto de la red. Elimina tambi�n todas las rutas que parten y llegan a �l
	// Par�metro: nombre del aeropuerto a eliminar
	// Precondici�n: el aeropuerto tiene que existir en el grafo
	// Complejidad temporal: O(arcos), siendo arcos el numero actual de arcos del grafo, ya que hay, 
	// en el peor caso, que eliminar todos los arcos
	void eliminarAeropuerto(string nombre);

};

