#pragma once
#include "Ruta.h"

// Estructura que representa un nodo de una lista enlazada doble
struct Nodo
{
	Ruta elemento; // El elemento que guarda el nodo
	Nodo *anteriorNodo; // Puntero al nodo anterior de la lista enlazada
	Nodo *siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
};

