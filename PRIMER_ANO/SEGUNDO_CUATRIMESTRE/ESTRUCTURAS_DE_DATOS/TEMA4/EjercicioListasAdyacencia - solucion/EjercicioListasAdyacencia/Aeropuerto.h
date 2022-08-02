#pragma once
#include "ListaEnlazada.h"
#include "string"

using namespace std;

// Representa a un aeropuerto. Los aeropuertos son los nodos del grafo
struct Aeropuerto {
	string* nombre; // Nombre del aeropuerto. Es su clave
	ListaEnlazada *rutasSalientes; // Lista de rutas salientes del aeropuerto
	ListaEnlazada *rutasEntrantes; // Lista de rutas entrantes al aeropuerto
};