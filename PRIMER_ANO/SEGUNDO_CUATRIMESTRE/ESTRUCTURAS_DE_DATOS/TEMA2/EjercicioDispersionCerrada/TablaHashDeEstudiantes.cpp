#include "TablaHashDeEstudiantes.h"
#include "cassert"
#include "iostream"

using namespace std;


int TablaHashDeEstudiantes::obtenerPosicion (int clave) {
	return (clave%capacidad);
}

int TablaHashDeEstudiantes::buscarEstudiante (int clave) {

	int posicion = obtenerPosicion(clave); // Posicion en donde vamos buscando. Empezamos por donde idealmente debería estar
	bool encontrado = false; // Flag que nos indica si lo hemos encontrado
	int casillasPorVer = capacidad; // El bucle para si hemos dado la vuelta a toda la tabla, por lo tanto esta variable nos indica cuánto nos falta para ello
	
	// Vamos mirando la tabla en orden secuencial hasta que: o lo encontremos, o demos la vuelta a toda la tabla,
	// o hasta encontrar una casilla vacia y no borrada. O, dicho de forma inversa (usando el álgebra de bool), 
	// buscamos mientras no lo encontremos, y no hayamos dado la vuelta a toda la tabla, 
	// y mientras la casilla no esté vacía o borrada
	while (!encontrado && casillasPorVer > 0 && (!vacias[posicion] || borradas[posicion])) {
		if (!vacias[posicion] && claves[posicion]==clave) encontrado=true;
		else {
			posicion = (posicion+1)%capacidad; // Incrementamos posicion (la siguiente a la ultima es la primera)
			casillasPorVer--;
		}
	} 

	if (encontrado) return (posicion);
	else return (-1);
}


int TablaHashDeEstudiantes::buscarHueco (int clave) {
	assert(!isLlena());

	int posicion = obtenerPosicion(clave); // Posicion ideal en donde tendríamos el hueco en el primer caso

	// Vamos buscando secuencialmente en la tabla, a partir de la posición ideal, hasta encontrar un hueco,
	// es decir, una casilla vacia (nos da igual si esta borrada o no)
	while (!vacias[posicion]) posicion = (posicion+1)%capacidad; // Incrementamos posicion (la siguiente a la ultima es la primera)
	
	return (posicion);
}


TablaHashDeEstudiantes::TablaHashDeEstudiantes(int capacidad) {

	// Reservamos memoria para la tabla
	nombres = new string[capacidad];
	vacias = (bool*) malloc (capacidad*sizeof(bool));
	borradas = (bool*) malloc (capacidad*sizeof(bool));
	claves = (int*) malloc (capacidad*sizeof(int));

	// Inicializamos los atributos
	this->capacidad = capacidad;
	n=0;

	// Ponemos todos los flags a falso
	for (int i=0; i<capacidad; i++) {
		vacias[i]=true;
		borradas[i]=false;
	}
}

bool TablaHashDeEstudiantes::existeEstudiante (int clave) {
	int posicionReal = buscarEstudiante(clave);
	if (posicionReal == -1) return (false);
	else return (true);
}

string TablaHashDeEstudiantes::getEstudiante (int clave) {
	assert(existeEstudiante(clave)); // Precondición: el estudiante debe existir
	int posicionReal = buscarEstudiante(clave);
	return (nombres[posicionReal]);
}

void TablaHashDeEstudiantes::introducirEstudiante (int clave, string estudiante) {
	assert(!isLlena());
	assert(!existeEstudiante(clave));
	int posicionReal = buscarHueco(clave);
	nombres[posicionReal]=estudiante;
	vacias[posicionReal]=false;
	claves[posicionReal]=clave;
	n++;
}

void TablaHashDeEstudiantes::eliminarEstudiante (int clave) {
	assert(existeEstudiante(clave));
	int posicionReal = buscarEstudiante(clave);
	vacias[posicionReal]=true;
	borradas[posicionReal]=true;
	n--;
}

void TablaHashDeEstudiantes::imprimir() {
	for (int i=0; i<capacidad; i++) 
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Clave: " << claves[i] << " | Contenido: " << nombres[i] << endl;
}

bool TablaHashDeEstudiantes::isLlena() {
	return (n==capacidad);
}

TablaHashDeEstudiantes::~TablaHashDeEstudiantes() {
	delete[] nombres;
	free (vacias);
	free (borradas);
	free (claves);
}
