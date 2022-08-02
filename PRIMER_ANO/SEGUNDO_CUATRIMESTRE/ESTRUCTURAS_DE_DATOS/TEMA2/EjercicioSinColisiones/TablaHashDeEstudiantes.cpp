#include "TablaHashDeEstudiantes.h"
#include "cassert"
#include "iostream"

using namespace std;


int TablaHashDeEstudiantes::obtenerPosicion (int clave) {
	return (clave%capacidad);
}

TablaHashDeEstudiantes::TablaHashDeEstudiantes(int capacidad) {

	// Inicializamos los atributos
	nombres = new string[capacidad];
	ocupada = (bool*) malloc (capacidad*sizeof(bool));
	claves = (int*) malloc (capacidad*sizeof(int));
	this->capacidad = capacidad;

	// Ponemos todos los flags a falso
	for (int i=0; i<capacidad; i++) ocupada[i]=false;
}

bool TablaHashDeEstudiantes::existeEstudiante (int clave) {
	int posicion = obtenerPosicion(clave);
	if (ocupada[posicion] && claves[posicion]==clave) return (true);
	else return (false);
}

string TablaHashDeEstudiantes::getEstudiante (int clave) {
	assert(existeEstudiante(clave)); // Precondición: el estudiante debe existir
	int posicion = obtenerPosicion(clave);
	return (nombres[posicion]);
}

void TablaHashDeEstudiantes::introducirEstudiante (int clave, string estudiante) {
	int posicion = obtenerPosicion(clave);
	assert(!ocupada[posicion]); // Precondición: en donde queremos meter el estudiante no hay nada aún
	nombres[posicion]=estudiante;
	ocupada[posicion]=true;
	claves[posicion]=clave;
}

void TablaHashDeEstudiantes::eliminarEstudiante (int clave) {
	assert(existeEstudiante(clave));
	int posicion = obtenerPosicion(clave);
	ocupada[posicion]=false;
}

void TablaHashDeEstudiantes::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupada[i] << " | Clave: " << claves[i] << " | Contenido: " << nombres[i] << endl;
}

TablaHashDeEstudiantes::~TablaHashDeEstudiantes() {
	delete[] nombres;
	free (ocupada);
	free (claves);
}
