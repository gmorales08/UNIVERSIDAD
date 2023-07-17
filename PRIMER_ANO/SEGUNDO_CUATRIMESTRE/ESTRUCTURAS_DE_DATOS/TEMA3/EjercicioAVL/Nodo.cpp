#include "Nodo.h"
#include "cassert"

Nodo::Nodo(int nuevoElemento) {
	contenido = nuevoElemento;
	padre = NULL;
	hijoIzquierdo = NULL;
	hijoDerecho = NULL;
	altura = 0;
}


void Nodo::setContenido(int nuevoContenido) {
	contenido = nuevoContenido;
}

void Nodo::setHijoIzquierdo (Nodo *nuevoHijoIzquierdo) {
	// Apuntamos al nuevo hijo izquierdo
	hijoIzquierdo = nuevoHijoIzquierdo;

	// Hacemos que nuestro nuevo hijo nos apunte
	if (hijoIzquierdo!=NULL) hijoIzquierdo->padre = this;
}

void Nodo::setHijoDerecho (Nodo *nuevoHijoDerecho) {
	// Apuntamos al nuevo hijo derecho
	hijoDerecho = nuevoHijoDerecho;

	// Hacemos que nuestro nuevo hijo nos apunte
	if (hijoDerecho!=NULL) hijoDerecho->padre = this;
}

void Nodo::setPadre(Nodo *nuevoPadre) { 
	// Eliminamos la referencia hacia mí que hay en mi padre
	if (padre != NULL) {
		if (padre->hijoIzquierdo == this) padre->hijoIzquierdo = NULL;
		if (padre->hijoDerecho == this) padre->hijoDerecho = NULL;
	}
	padre = nuevoPadre; 
}


int Nodo::getContenido() {return(contenido);}
Nodo* Nodo::getPadre() {return(padre);}
Nodo* Nodo::getHijoIzquierdo() {return (hijoIzquierdo);}
Nodo* Nodo::getHijoDerecho() {return (hijoDerecho);}
int Nodo::getAltura() { return(altura); }

int Nodo::getAlturaSubarbolIzquierdo() {
	int alturaHijoIzquierdo; // Altura del hijo izquierdo
	if (hijoIzquierdo == NULL) alturaHijoIzquierdo = -1;
	else alturaHijoIzquierdo = hijoIzquierdo->getAltura();
	return(alturaHijoIzquierdo);
}

int Nodo::getAlturaSubarbolDerecho() {
	int alturaHijoDerecho; // Altura del hijo derecho
	if (hijoDerecho == NULL) alturaHijoDerecho = -1;
	else alturaHijoDerecho = hijoDerecho->getAltura();
	return(alturaHijoDerecho);
}


void Nodo::actualizarAltura() {

	// Calculamos las alturas de los hijos
	int alturaHijoIzquierdo = getAlturaSubarbolIzquierdo();
	int alturaHijoDerecho = getAlturaSubarbolDerecho();
	
	// Calculamos la altura del nodo
	if (alturaHijoIzquierdo >= alturaHijoDerecho) altura = alturaHijoIzquierdo + 1;
	else altura = alturaHijoDerecho + 1;
}

int Nodo::getFactorEquilibrio() {

	// Calculamos las alturas de los hijos
	int alturaHijoIzquierdo = getAlturaSubarbolIzquierdo();
	int alturaHijoDerecho = getAlturaSubarbolDerecho();

	// Devolvemos el factor de equilibrio
	return (alturaHijoDerecho - alturaHijoIzquierdo);	
}


Nodo::~Nodo() {
	// Precondición: los dos hijos ya han sido eliminados previamente
	assert(hijoIzquierdo == NULL && hijoDerecho == NULL);

	// Eliminamos la referencia hacia mí que hay en mi padre
	setPadre(NULL);
}