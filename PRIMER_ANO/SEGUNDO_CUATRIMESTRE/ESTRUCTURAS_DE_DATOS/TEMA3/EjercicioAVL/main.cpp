#include "iostream"
#include "AVL.h"

using namespace std;

void main () {	

	// Probamos la rotación simple a la izquierda
	cout << "Probamos la rotacion simple a la izquierda" << endl;
	AVL arbolPruebaRotacionSimpleIzquierda; // Arbol AVL para probar la rotación
	int insercionesPruebaRotacionSimpleIzquierda[] = { 1, 2, 3, 4, 5, 6 }; // Inserciones que haremos
	for (int i=0; i<6; i++) {
		cout << "Insercion de " << insercionesPruebaRotacionSimpleIzquierda[i] << ":\n";
		arbolPruebaRotacionSimpleIzquierda.insertar(insercionesPruebaRotacionSimpleIzquierda[i]);
		arbolPruebaRotacionSimpleIzquierda.imprimir();
	}

	// Probamos la rotación simple a la derecha
	cout << "\nProbamos la rotacion simple a la derecha" << endl;
	AVL arbolPruebaRotacionSimpleDerecha; // Arbol AVL para probar la rotación
	int insercionesPruebaRotacionSimpleDerecha[] = {6, 5, 4, 3, 2, 1 }; // Inserciones que haremos
	for (int i = 0; i<6; i++) {
		cout << "Insercion de " << insercionesPruebaRotacionSimpleDerecha[i] << ":\n";
		arbolPruebaRotacionSimpleDerecha.insertar(insercionesPruebaRotacionSimpleDerecha[i]);
		arbolPruebaRotacionSimpleDerecha.imprimir();
	}

	// Probamos la rotación compuesta derecha-izquierda 
	cout << "\nProbamos la rotacion compuesta derecha-izquierda" << endl;
	AVL arbolPruebaRotacionCompuestaDerechaIzquierda; // Arbol AVL para probar la rotación
	int insercionesPruebaRotacionCompuestaDerechaIzquierda[] = {2, 5, 3, 9, 8, 1, 10, 4, 6, 7}; // Inserciones que haremos
	for (int i = 0; i<10; i++) {
		cout << "Insercion de " << insercionesPruebaRotacionCompuestaDerechaIzquierda[i] << ":\n";
		arbolPruebaRotacionCompuestaDerechaIzquierda.insertar(insercionesPruebaRotacionCompuestaDerechaIzquierda[i]);
		arbolPruebaRotacionCompuestaDerechaIzquierda.imprimir();
	}

	// Probamos la rotación compuesta izquierda-derecha
	cout << "\nProbamos la rotacion compuesta izquierda-derecha" << endl;
	AVL arbolPruebaRotacionCompuestaIzquierdaDerecha; // Arbol AVL para probar la rotación
	int insercionesPruebaRotacionCompuestaIzquierdaDerecha[] = {9, 6, 8, 2, 3, 10, 5, 7, 1, 4}; // Inserciones que haremos
	for (int i = 0; i<10; i++) {
		cout << "Insercion de " << insercionesPruebaRotacionCompuestaIzquierdaDerecha[i] << ":\n";
		arbolPruebaRotacionCompuestaIzquierdaDerecha.insertar(insercionesPruebaRotacionCompuestaIzquierdaDerecha[i]);
		arbolPruebaRotacionCompuestaIzquierdaDerecha.imprimir();
	}
}
