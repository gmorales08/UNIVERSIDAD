#include "AVL.h"
#include "cassert"
#include "iostream"
using namespace std;

AVL::AVL() {
	n = 0;
	raiz = NULL;
}

bool AVL::buscar(int elementoABuscar) {
	if (n == 0) return(false);
	else {
		Nodo* nodo = buscarRecursivo(raiz, elementoABuscar);
		if (nodo->getContenido() == elementoABuscar) return(true);
		else return (false);
	}
}

void AVL::insertar(int nuevoElemento) {
	assert(!buscar(nuevoElemento));

	// Insertamos el nuevo elemento como una hoja
	Nodo *hojaInsertada = insertarHoja(nuevoElemento);

	// Reequilibramos el árbol
	reequilibrar(hojaInsertada);

} // Fin método insertar


Nodo* AVL::insertarHoja(int nuevoElemento) {
	assert(!buscar(nuevoElemento));

	// Creamos el nuevo nodo que contiene al elemento
	Nodo *nuevoNodo = new Nodo(nuevoElemento);

	// Si el arbol está vacío, lo metemos en la raiz sí o sí
	if (n == 0) {
		raiz = nuevoNodo;
	}

	// En caso contrario, buscamos el hueco
	else {
		// Buscamos el hueco
		Nodo *padreDelHueco = buscarRecursivo(raiz, nuevoElemento); // Puntero al nodo que es el padre del hueco

		// Metemos el nuevo nodo como hijo izquierdo o derecho
		if (nuevoElemento <= padreDelHueco->getContenido()) padreDelHueco->setHijoIzquierdo(nuevoNodo);
		else padreDelHueco->setHijoDerecho(nuevoNodo);
	}

	// Incrementamos el número de nodos
	n++;

	// Devolvemos un puntero al nodo metido
	return(nuevoNodo);
}


void AVL::reequilibrar(Nodo *hoja) {
	assert(hoja != NULL);
	
	// Desde el padre de la hoja, vamos ascendiendo hasta llegar a la raíz.
	// No necesitamos comprobar la hoja, ya que al ser una hoja su altura es 0 y su factor
	// de equilibrio siempre es 0.
	// Por cada nodo que examinamos, actualizamos su altura, averiguamos su factor de equilibrio,
	// y finalmente rotamos en caso de que dicho factor de equilibrio sea 2 ó -2
	Nodo *nodoActual = hoja->getPadre(); // Calculamos el padre de la hoja inicial
	while (nodoActual != NULL) {

		// Primero calculamos la altura del árbol
		nodoActual->actualizarAltura();

		// Averiguamos su factor de equilibrio
		int factorEquilibrio = nodoActual->getFactorEquilibrio();

		// Si el factor de equilibrio es 2, tenemos dos casos
		if (factorEquilibrio == 2){
			int factorEquilibrioDerecho = nodoActual->getHijoDerecho()->getFactorEquilibrio();
			if (factorEquilibrioDerecho == 1) nodoActual = rotarSimpleIzquierda(nodoActual);
			if (factorEquilibrioDerecho == -1) nodoActual = rotarCompuestaDerechaIzquierda(nodoActual);
		}

		// Si el factor de equilibrio es -2, tenemos otros dos casos
		if (factorEquilibrio == -2){
			int factorEquilibrioIzquierdo = nodoActual->getHijoIzquierdo()->getFactorEquilibrio();
			if (factorEquilibrioIzquierdo == -1) nodoActual = rotarSimpleDerecha(nodoActual);
			if (factorEquilibrioIzquierdo == 1) nodoActual = rotarCompuestaIzquierdaDerecha(nodoActual);
		}

		// En la siguiente iteracion, haremos lo mismo con el padre del nodo actual
		nodoActual = nodoActual->getPadre();

	} // Fin while
} // Fin método reequilibrar


void AVL::imprimir() {
	if (raiz != NULL) imprimirRecursivo(raiz, 0, 0);
	else cout << "Arbol vacio\n";
}

AVL::~AVL() {
	if (raiz != NULL) eliminarSubarbol(raiz);
}

void AVL::imprimirRecursivo(Nodo *raiz, int numeroTabulaciones, int orientacion) {
	assert(raiz != NULL);

	// Imprimimos el nodo raiz con el nivel pasado como parametro
	for (int i = 0; i<numeroTabulaciones; i++) cout << "\t";
	cout << raiz->getContenido();
	if (orientacion == -1) cout << " (izquierdo)";
	if (orientacion == 1) cout << " (derecho)";
	cout << endl;

	// Imprimimos sus hijos con una tabulacion mas
	if (raiz->getHijoIzquierdo() != NULL) imprimirRecursivo(raiz->getHijoIzquierdo(), numeroTabulaciones + 1, -1);
	if (raiz->getHijoDerecho() != NULL) imprimirRecursivo(raiz->getHijoDerecho(), numeroTabulaciones + 1, 1);
}

void AVL::eliminarSubarbol(Nodo *subarbol) {
	assert(subarbol != NULL);

	// Primero eliminamos los hijos, si hay
	if (subarbol->getHijoIzquierdo() != NULL) eliminarSubarbol(subarbol->getHijoIzquierdo());
	if (subarbol->getHijoDerecho() != NULL) eliminarSubarbol(subarbol->getHijoDerecho());

	// Finalmente eliminamos la raiz
	delete subarbol;
}

Nodo* AVL::buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar) {
	assert(raizSubarbol != NULL);

	// Elemento encontrado en la raíz
	if (raizSubarbol->getContenido() == elementoABuscar)
		return (raizSubarbol);

	// El elemento que se busca es menor que la raíz
	else if (elementoABuscar < raizSubarbol->getContenido()) {
		if (raizSubarbol->getHijoIzquierdo() == NULL) return (raizSubarbol); // El elemento no está. Devolvemos su padre
		else return (buscarRecursivo(raizSubarbol->getHijoIzquierdo(), elementoABuscar)); // Seguimos buscando por la izquierda
	}

	// El elemento que se busca es mayor que la raíz
	else {
		if (raizSubarbol->getHijoDerecho() == NULL) return (raizSubarbol); // El elemento no está. Devolvemos su padre
		else return (buscarRecursivo(raizSubarbol->getHijoDerecho(), elementoABuscar)); // Seguimos buscando por la derecha
	}
}


Nodo* AVL::rotarSimpleIzquierda(Nodo *raizSubarbol) {
	
	// Precondición: la raiz existe y tiene un factor de equilibrio de 2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->getFactorEquilibrio() == 2);

	// Precondición: el hijo derecho existe y tiene un factor de equilibrio de 1
	Nodo *hijoDerecho = raizSubarbol->getHijoDerecho(); // Hijo derecho de la raiz 
	assert(hijoDerecho != NULL);
	assert(hijoDerecho->getFactorEquilibrio() == 1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "A", "B" y "C"
	// No necesitamos guardar ni "A" ni "C" porque no cambian de sitio
	Nodo *x = raizSubarbol;
	Nodo *y = hijoDerecho;
	Nodo *B = y->getHijoIzquierdo();

	// Hacemos que el padre de "x" pase a apuntar a "y" en vez de a "x"
	cambiarHijo(x, y);

	// Hacemos que "B" sea hijo derecho de "x"
	x->setHijoDerecho(B);

	// Hacemos que "x" sea hijo izquierdo de "y"
	y->setHijoIzquierdo(x);
	
	// Recalculamos las alturas de "x" e "y", en este orden
	x->actualizarAltura();
	y->actualizarAltura();

	// Devolvemos la nueva raiz del subarbol
	return(y);
}


Nodo* AVL::rotarSimpleDerecha(Nodo *raizSubarbol) {

	// Precondición: la raiz existe y tiene un factor de equilibrio de -2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->getFactorEquilibrio() == -2);

	// Precondición: el hijo izquierdo existe y tiene un factor de equilibrio de -1
	Nodo *hijoIzquierdo = raizSubarbol->getHijoIzquierdo(); // Hijo izquierdo de la raiz 
	assert(hijoIzquierdo != NULL);
	assert(hijoIzquierdo->getFactorEquilibrio() == -1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "A", "B" y "C"
	// No necesitamos guardar ni "A" ni "C" porque no cambian de sitio
	Nodo *x = hijoIzquierdo;
	Nodo *y = raizSubarbol;
	Nodo *B = x->getHijoDerecho();

	// Hacemos que el padre de "y" pase a apuntar a "x" en vez de a "y"
	cambiarHijo(y, x);

	// Hacemos que "B" sea hijo derecho de "y"
	y->setHijoIzquierdo(B);

	// Hacemos que "y" sea hijo derecho de "x"
	x->setHijoDerecho(y);

	// Recalculamos las alturas de "y" y "x", en este orden	
	y->actualizarAltura();
	x->actualizarAltura();

	// Devolvemos la nueva raiz del subarbol
	return(x);
}


Nodo* AVL::rotarCompuestaDerechaIzquierda(Nodo *raizSubarbol) {

	// Precondición: la raiz existe y tiene un factor de equilibrio de 2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->getFactorEquilibrio() == 2);

	// Precondición: el hijo derecho existe y tiene un factor de equilibrio de -1
	Nodo *hijoDerecho = raizSubarbol->getHijoDerecho(); // Hijo derecho de la raiz 
	assert(hijoDerecho != NULL);
	assert(hijoDerecho->getFactorEquilibrio() == -1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "z", "A", "B", "C" y "D"
	// No necesitamos guardar ni "A" ni "D" porque no cambian de sitio
	Nodo *x = raizSubarbol;
	Nodo *z = hijoDerecho;
	Nodo *y = z->getHijoIzquierdo();
	Nodo *B = y->getHijoIzquierdo();
	Nodo *C = y->getHijoDerecho();

	// Hacemos que el padre de "x" pase a apuntar a "y" en vez de a "x"
	cambiarHijo(x, y);

	// Hacemos que "B" sea hijo derecho de "x"
	x->setHijoDerecho(B);

	// Hacemos que "C" sea hijo izquierdo de "z"
	z->setHijoIzquierdo(C);

	// Hacemos que "x" y "z" sean hijos de "y"
	y->setHijoIzquierdo(x);
	y->setHijoDerecho(z);

	// Recalculamos las alturas de "x", "z" e "y", en este orden	
	x->actualizarAltura();
	z->actualizarAltura();
	y->actualizarAltura();

	// Devolvemos la nueva raiz del subarbol
	return(y);
}


Nodo* AVL::rotarCompuestaIzquierdaDerecha(Nodo *raizSubarbol) {

	// Precondición: la raiz existe y tiene un factor de equilibrio de -2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->getFactorEquilibrio() == -2);

	// Precondición: el hijo izquierdo existe y tiene un factor de equilibrio de 1
	Nodo *hijoIzquierdo = raizSubarbol->getHijoIzquierdo(); // Hijo izquierdo de la raiz 
	assert(hijoIzquierdo != NULL);
	assert(hijoIzquierdo->getFactorEquilibrio() == 1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "z", "A", "B", "C" y "D"
	// No necesitamos guardar ni "A" ni "D" porque no cambian de sitio
	Nodo *z = raizSubarbol;
	Nodo *x = hijoIzquierdo;
	Nodo *y = x->getHijoDerecho();
	Nodo *B = y->getHijoIzquierdo();
	Nodo *C = y->getHijoDerecho();

	// Hacemos que el padre de "z" pase a apuntar a "y" en vez de a "z"
	cambiarHijo(z, y);

	// Hacemos que "B" sea hijo derecho de "x"
	x->setHijoDerecho(B);

	// Hacemos que "C" sea hijo derecho de "z"
	z->setHijoIzquierdo(C);

	// Hacemos que "x" y "z" sean hijos de "y"
	y->setHijoIzquierdo(x);
	y->setHijoDerecho(z);

	// Recalculamos las alturas de "x", "z" e "y", en este orden	
	x->actualizarAltura();
	z->actualizarAltura();
	y->actualizarAltura();

	// Devolvemos la nueva raiz del subarbol
	return(y);
}


void AVL::cambiarHijo(Nodo *antiguoHijo, Nodo *nuevoHijo) {
	assert(antiguoHijo != NULL);
	
	// Averiguamos el padre
	Nodo *padre = antiguoHijo->getPadre();
	
	// Si el antiguo hijo no tiene padre, es que el antiguo hijo es la raíz del árbol AVL completo
	// En ese caso, cambiamos el atributo del AVL que apunta a la raíz para que apunte al nuevoHijo
	if (padre == NULL) {
		raiz = nuevoHijo;
		nuevoHijo->setPadre(NULL);
	}

	// En caso de que el antiguoHijo tenga padre, hacemos que el padre apunte al nuevoHijo
	else {
		if (padre->getHijoIzquierdo() == antiguoHijo) padre->setHijoIzquierdo(nuevoHijo);
		if (padre->getHijoDerecho() == antiguoHijo) padre->setHijoDerecho(nuevoHijo);
	}

	// Hacemos que el antiguoHijo no apunte a nadie, ya que ahora no tiene padre
	antiguoHijo->setPadre(NULL);
}