#pragma once
#include "string"

using namespace std;

// Nodo de un árbol
struct Nodo {
	string contenido; // Contenido del nodo (el elemento)
	Nodo *padre; // Puntero al nodo padre. NULL si no hay
	Nodo *hijoIzquierdo; // Puntero al primer hijo. NULL si no hay
	Nodo *hermanoDerecho; // Puntero al hermano derecho. NULL si no hay
};



