#include "ArbolGenealogico.h"
#include "cassert"
#include "iostream"

using namespace std;

int ArbolGenealogico::getNumeroHijos(Nodo * padre) {
	assert(padre != NULL);

	Nodo *hijoActual = padre->hijoIzquierdo; // Hijo actual en el que estamos (inicialmente es el primero)
	int numeroHijosDirectos; // Resultado de la funci�n

	// Si no tiene ni siquiera un primer hijo, no tiene ning�n hijo
	if (hijoActual == NULL) numeroHijosDirectos = 0;

	// Si tiene hijos, vamos iterando por ellos (de hermano a hermano) para contar cu�ntos hay
	else {
		numeroHijosDirectos = 1; // Al menos tiene uno (el primer hijo)		
		// Vamos desplaz�ndonos al hermano derecho hasta que ya no podamos m�s
		while (hijoActual->hermanoDerecho != NULL) {
			hijoActual = hijoActual->hermanoDerecho;
			numeroHijosDirectos++;
		}
	}
	return(numeroHijosDirectos);
}

Nodo * ArbolGenealogico::getHijo(Nodo * padre, int posicionHijo) {
	assert(padre != NULL);
	int numeroHijos = getNumeroHijos(padre); // Numero de hijos del padre
	assert(numeroHijos > 0);
	assert(posicionHijo >= 0 && posicionHijo<numeroHijos);

	// Llegamos hasta el hijo adecuado, iterando a lo largo de los hermanos
	Nodo *resultado = padre->hijoIzquierdo; // Puntero al nodo hijo al que queremos acceder. Inicializado con el primero
	for (int i = 0; i < posicionHijo; i++) resultado = resultado->hermanoDerecho; // Llegamos hasta el hijo adecuado

	// Devolvemos el puntero al nodo hijo
	return(resultado);
}

Nodo* ArbolGenealogico::buscarNodo (Nodo *raizSubarbol, string contenido) {
	assert(raizSubarbol != NULL);

	// Primero buscamos en la propia raiz. Si encontramos el contenido ah�, hemos terminado
	if (raizSubarbol->contenido == contenido) return (raizSubarbol);

	// Si no, buscamos en sus subarboles hijos. 
	// Retornamos directamente si lo encontramos en alguno de sus subarboles hijos
	else {
		int numeroSubarboles = getNumeroHijos(raizSubarbol); // N�mero de hijos de la raizSubarbol
		for (int i=0; i<numeroSubarboles; i++) {

			// Buscamos recursivamente en uno de los sub�rboles que cuelgan de la ra�z
			Nodo *resultado = buscarNodo(getHijo(raizSubarbol, i), contenido);
			
			// Si lo hemos encontrado en el sub�rbol, terminamos
			if (resultado != NULL) return (resultado);
		}
	}

	// Si hemos llegado hasta aqu�, no lo hemos encontrado en el sub�rbol actual
	return (NULL);
}

void ArbolGenealogico::imprimirRecursivo(Nodo *raizSubarbol, int numeroTabulaciones) {
	assert (raizSubarbol != NULL);
	assert(numeroTabulaciones >= 0);

	// Imprimimos el nodo raiz con el nivel pasado como parametro
	for (int i=0; i<numeroTabulaciones; i++) cout << "\t";
	cout << raizSubarbol->contenido << endl;

	// Imprimimos cada uno de sus sub�rboles con una tabulacion mas
	int numeroSubarboles = getNumeroHijos(raizSubarbol); // N�mero de hijos de la raizSubarbol
	for (int i = 0; i < numeroSubarboles; i++) imprimirRecursivo(getHijo(raizSubarbol, i), numeroTabulaciones + 1);
}

void ArbolGenealogico::eliminarSubarbol (Nodo *raizSubarbol) {
	assert(raizSubarbol != NULL);

	// Primero eliminamos los hijos, si hay. Lo hacemos desde el �ltimo hasta el primero
	int numeroSubarboles = getNumeroHijos(raizSubarbol); // N�mero de hijos de la raizSubarbol
	for (int i = numeroSubarboles-1; i >=0; i--) {

		// Obtenemos el hijo que queremos borrar
		Nodo *hijoActual = getHijo(raizSubarbol, i);

		// Si el hijoActual es primog�nito (e hijo �nico), hacemos que su padre ya no apunte a �l
		// Si no, hacemos que su hermano izquierdo ya no apunte a �l.
		if (i == 0) hijoActual->padre->hijoIzquierdo=NULL;
		else getHijo(raizSubarbol, i - 1)->hermanoDerecho = NULL;

		// Finalmente, borramos al hijoActual
		eliminarSubarbol(hijoActual);		
	}
		
	// Finalmente eliminamos la raiz
	delete raizSubarbol;
}

ArbolGenealogico::ArbolGenealogico(string nombre) {
	raiz = new Nodo;
	raiz->contenido = nombre;
	raiz->padre = NULL;
	raiz->hermanoDerecho = NULL;
	raiz->hijoIzquierdo = NULL;
	n=1;
}

void ArbolGenealogico::insertarNombre (string nuevoNombre, string nombrePadre) {
	Nodo *padre = buscarNodo(raiz, nombrePadre); // Buscamos el futuro padre del nodo que vamos a insertar

	assert(padre != NULL); // El padre debe existir en el arbol
	assert (n>0); // El arbol no puede estar vacio

	// Creamos el nuevo nodo que contendr� lo que queremos insertar en el �rbol
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->contenido = nuevoNombre;
	nuevoNodo->padre=padre;
	nuevoNodo->hijoIzquierdo = NULL;
	nuevoNodo->hermanoDerecho = NULL; // Lo insertamos como �ltimo hijo de su padre

	// Hacemos que el nodo reci�n insertado sea el �ltimo hijo de su padre	
	int numeroHijos = getNumeroHijos(padre); // Numero de hijos que tiene el padre, antes de insertar el nuevo nodo
	if (numeroHijos == 0) padre->hijoIzquierdo = nuevoNodo; // Si el padre no tiene hijos, somos su primer hijo
	else {
		Nodo *ultimoHijo = getHijo(padre, numeroHijos-1); // Ultimo hijo del padre, antes de insertar el nuevo nodo
		ultimoHijo->hermanoDerecho = nuevoNodo; // Hacemos que el �ltimo hijo nos apunte, para que ahora lo seamos nosotros
	}

	n++;
}

void ArbolGenealogico::imprimir() {
	assert(n>0);
	imprimirRecursivo (raiz, 0);
} 

ArbolGenealogico::~ArbolGenealogico() {
	assert(n>0);
	assert(raiz!=NULL);
	eliminarSubarbol(raiz);
}

