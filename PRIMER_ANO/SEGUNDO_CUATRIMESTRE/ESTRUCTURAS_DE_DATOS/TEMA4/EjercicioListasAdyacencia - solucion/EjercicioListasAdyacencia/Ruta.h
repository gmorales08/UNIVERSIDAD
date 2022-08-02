#pragma once
#include "string"
using namespace std;

// Representa una ruta aérea entre aeropuertos. Las rutas son los arcos del grafo
struct Ruta {
	string *aeropuerto; // Aeropuerto destino u origen, dependiendo de si la ruta es saliente o entrante.
	int kilometros;
	string *empresa;
};
