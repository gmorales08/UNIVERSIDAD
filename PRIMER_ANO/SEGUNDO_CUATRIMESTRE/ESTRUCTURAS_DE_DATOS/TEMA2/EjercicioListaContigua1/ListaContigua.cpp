#include "ListaContigua.h"
#include "cassert"
#include "cstdlib"
using namespace std;

bool ListaContigua::isLlena() {
	return (n == capacidad);
}

ListaContigua::ListaContigua() {
	vector = NULL; // No hay que reservar memoria ya que la ListaContigua se crea vacía en un principio
	n=0;
	capacidad=0;
}

int ListaContigua::getValor(int posicion) {
	assert(posicion >= 0 && posicion <= n-1);
	return (vector[posicion]);
}

void ListaContigua::setValor(int posicion, int nuevoValor) {
	assert(posicion >= 0 && posicion <= n-1);
	vector[posicion] = nuevoValor;
}

int ListaContigua::getN() {
	return (n);
}

int ListaContigua::getCapacidad() {
	return (capacidad);
}

void ListaContigua::insertarAlFinal (int nuevoValor) {

	// Si la ListaContigua está ya llena, antes de insertar ampliamos su capacidad en INCREMENTO
	if (isLlena()) ampliarCapacidad(INCREMENTO);
	
	// Metemos el nuevo elemento. 
	vector[n] = nuevoValor;
	n++;
	
}

void ListaContigua::eliminarAlFinal () {
	// Eliminar es simplemente disminuir el numero actual de elementos
	n--;

	// Si la capacidad sobrante es demasiada (2*INCREMENTO), la reducimos en INCREMENTO unidades
	if (capacidad - n == 2 * INCREMENTO) ampliarCapacidad(-INCREMENTO);
}

void ListaContigua::ampliarCapacidad(int incremento) {
	vector = (int*)realloc(vector, sizeof(int)*(capacidad + incremento));
	capacidad += incremento;
}

ListaContigua::~ListaContigua() {
	free(vector);
}


