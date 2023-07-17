#include "ArbolBinarioDeBusqueda.h"
#include "cassert"
#include "iostream"
using namespace std;

ArbolBinarioDeBusqueda::ArbolBinarioDeBusqueda() {
	n = 0;
	raiz = NULL;
	orientacionSiguienteEliminacion = 1;
}

void ArbolBinarioDeBusqueda::insertar(int nuevoElemento) {
	assert(!buscar(nuevoElemento)); // El nuevo elemento no estaba ya en el árbol

	// Creamos el nuevo nodo que contiene al elemento
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->contenido = nuevoElemento;
	nuevoNodo->padre = NULL;
	nuevoNodo->hijoIzquierdo = NULL;
	nuevoNodo->hijoDerecho = NULL;

	// Si el arbol está vacío, lo metemos en la raiz sí o sí
	if (n == 0) {
		raiz = nuevoNodo;
	}

	// En caso contrario, buscamos el hueco en donde meterlo como una hoja
	else {
		// Buscamos el hueco
		Nodo* padreDelHueco = buscarRecursivo(raiz, nuevoElemento); // Puntero al nodo que es el padre del hueco

		// Metemos el nuevo nodo como hijo izquierdo o derecho
		if (nuevoElemento < padreDelHueco->contenido) padreDelHueco->hijoIzquierdo = nuevoNodo;
		else padreDelHueco->hijoDerecho = nuevoNodo;

		// Hacemos que el nuevo nodo apunte al padre
		nuevoNodo->padre = padreDelHueco;
	}

	// Incrementamos el número de nodos
	n++;
}

bool ArbolBinarioDeBusqueda::buscar(int elementoABuscar) {
	if (n == 0) return(false);
	else {
		Nodo* nodo = buscarRecursivo(raiz, elementoABuscar);
		if (nodo->contenido == elementoABuscar) return(true);
		else return (false);
	}
}

void ArbolBinarioDeBusqueda::eliminar(int elementoAEliminar) {
	assert(buscar(elementoAEliminar)); // El elemento a eliminar tiene que estar
	Nodo* nodoParaEliminar = buscarRecursivo(raiz, elementoAEliminar);
	eliminarNodo(nodoParaEliminar);
	n--;
}

void ArbolBinarioDeBusqueda::imprimir() {
	if (raiz != NULL) imprimirRecursivo(raiz, 0, 0);
	else cout << "Arbol vacio\n";
}

ArbolBinarioDeBusqueda::~ArbolBinarioDeBusqueda() {
	if (raiz != NULL) eliminarSubarbol(raiz);
}

Nodo* ArbolBinarioDeBusqueda::buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar) {
	assert(raizSubarbol != NULL);

	// Elemento encontrado en la raíz
	if (raizSubarbol->contenido == elementoABuscar)
		return (raizSubarbol);

	// El elemento que se busca es menor que la raíz
	else if (elementoABuscar < raizSubarbol->contenido) {
		if (raizSubarbol->hijoIzquierdo == NULL) return (raizSubarbol); // El elemento no está. Devolvemos su padre
		else return (buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar)); // Seguimos buscando por la izquierda
	}

	// El elemento que se busca es mayor que la raíz
	else {
		if (raizSubarbol->hijoDerecho == NULL) return (raizSubarbol); // El elemento no está. Devolvemos su padre
		else return (buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar)); // Seguimos buscando por la derecha
	}
}

void ArbolBinarioDeBusqueda::imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion) {
	assert(raizSubarbol != NULL);
	assert(numeroTabulaciones >= 0);
	assert(orientacion == 1 || orientacion == -1 || orientacion == 0);

	// Imprimimos el nodo raiz con el nivel pasado como parametro
	for (int i = 0; i < numeroTabulaciones; i++) cout << "\t";
	cout << raizSubarbol->contenido;
	if (orientacion == -1) cout << " (izquierdo)";
	if (orientacion == 1) cout << " (derecho)";
	cout << endl;

	// Imprimimos sus hijos con una tabulacion mas
	if (raizSubarbol->hijoIzquierdo != NULL) imprimirRecursivo(raizSubarbol->hijoIzquierdo, numeroTabulaciones + 1, -1);
	if (raizSubarbol->hijoDerecho != NULL) imprimirRecursivo(raizSubarbol->hijoDerecho, numeroTabulaciones + 1, 1);
}

void ArbolBinarioDeBusqueda::eliminarSubarbol(Nodo* raizSubarbol) {
	assert(raizSubarbol != NULL);

	// Primero eliminamos los hijos, si hay
	if (raizSubarbol->hijoIzquierdo != NULL) eliminarSubarbol(raizSubarbol->hijoIzquierdo);
	if (raizSubarbol->hijoDerecho != NULL) eliminarSubarbol(raizSubarbol->hijoDerecho);

	// Eliminamos la referencia desde el padre. Hay que averiguar si  
	// el nodo era su hijo derecho o izquierdo
	Nodo* padre = raizSubarbol->padre; // Guardamos primero quien es el padre
	if (padre != NULL) {
		if (padre->hijoIzquierdo == raizSubarbol) padre->hijoIzquierdo = NULL;
		if (padre->hijoDerecho == raizSubarbol) padre->hijoDerecho = NULL;
	}

	// Eliminamos la raiz	
	delete raizSubarbol;
}

void ArbolBinarioDeBusqueda::eliminarNodo(Nodo* nodoParaEliminar) {
	assert(nodoParaEliminar != NULL);

	Nodo* nodoDesdeDondeCopiar = NULL; // Nodo cuyo contenido se copiará en nodoParaEliminar, si éste último tiene hijos

	// Tenemos cuatro casos excluyentes: 
	// 1. Que no se tenga ningún hijo
	// 2. Que se tengan dos
	// 3. Que se tenga sólo el derecho
	// 4. O que se tenga sólo el izquierdo

	// Primer caso: no tenemos ningún hijo (somos un nodo hoja). Lo eliminamos sin más
	if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho == NULL) {

		// Eliminamos primero la referencia desde el padre. Hay que averiguar si  
		// el nodo era su hijo derecho o izquierdo
		Nodo* padre = nodoParaEliminar->padre; // Guardamos primero quien es el padre
		if (padre != NULL) {
			if (padre->hijoIzquierdo == nodoParaEliminar) padre->hijoIzquierdo = NULL;
			if (padre->hijoDerecho == nodoParaEliminar) padre->hijoDerecho = NULL;
		}

		// Finalmente liberamos la memoria del nodo
		delete nodoParaEliminar;
	}

	else {

		// Segundo caso. Tenemos dos hijos. Cogemos el maximo de la izquierda o el minimo de la derecha segun lo que hicimos la ultima vez
		if (nodoParaEliminar->hijoIzquierdo != NULL && nodoParaEliminar->hijoDerecho != NULL) {

			if (orientacionSiguienteEliminacion == 1) {
				nodoDesdeDondeCopiar = buscarMinimo(nodoParaEliminar->hijoDerecho);
				orientacionSiguienteEliminacion = -1;
			}
			else {
				nodoDesdeDondeCopiar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
				orientacionSiguienteEliminacion = 1;
			}
		}

		// Tercer caso. Tenemos sólo el hijo derecho
		else if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho != NULL) {
			nodoDesdeDondeCopiar = buscarMinimo(nodoParaEliminar->hijoDerecho);
			orientacionSiguienteEliminacion = -1;
		}

		// Cuarto caso. Tenemos sólo el hijo izquierdo
		else { // nodoParaEliminar->getHijoIzquierdo() != NULL && nodoParaEliminar->getHijoDerecho() == NULL
			nodoDesdeDondeCopiar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
			orientacionSiguienteEliminacion = 1;
		}

		// Ahora que ya tenemos claro el nodoDesdeDondeCopiar, lo copiamos en el hueco dejado por nodoParaEliminar
		nodoParaEliminar->contenido = nodoDesdeDondeCopiar->contenido;

		// Borramos recursivamente el nodoDesdeDondeCopiar, pues ya lo hemos copiado en el hueco que hemos dejado.
		eliminarNodo(nodoDesdeDondeCopiar);

	} // Fin del caso 2, 3 y 4

} // Fin procedimiento eliminar()

Nodo* ArbolBinarioDeBusqueda::buscarMaximo(Nodo* raizSubarbol) {
	// Vamos por la rama derecha hasta que no podamos más
	assert(raizSubarbol != NULL);
	if (raizSubarbol->hijoDerecho == NULL) return (raizSubarbol);
	else return (buscarMaximo(raizSubarbol->hijoDerecho));
}

Nodo* ArbolBinarioDeBusqueda::buscarMinimo(Nodo* raizSubarbol) {
	// Vamos por la rama izquierda hasta que no podamos más
	assert(raizSubarbol != NULL);
	if (raizSubarbol->hijoIzquierdo == NULL) return (raizSubarbol);
	else return (buscarMinimo(raizSubarbol->hijoIzquierdo));
}