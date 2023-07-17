#include "Grafo.h"
#include "cstdlib"
#include "cassert"
#include "string"
#include "iostream"

using namespace std;

bool Grafo::existeArco (int indiceNodoOrigen, int indiceNodoDestino) {
	assert(indiceNodoOrigen >= 0 && indiceNodoOrigen <= n-1);
	assert(indiceNodoDestino >= 0 && indiceNodoDestino <= n-1);
	if (matriz[indiceNodoOrigen].getValor(indiceNodoDestino) > 0) return true;
	else return false;
}

bool Grafo::existeNodo (char nombreNodo) {
	// Si find() no encuentra el caracter, devuelve string::npos, que suele ser -1.
	// Si lo encuentra, devuelve su posición en el string (empezando por 0)
	if (string::npos == nombresNodos.find(nombreNodo)) return false;
	else return true;
}

int Grafo::obtenerIndice (char nombreNodo) {
	assert (existeNodo(nombreNodo));
	// Si find() no encuentra el caracter, devuelve string::npos, que suele ser -1.
	// Si lo encuentra, devuelve su posición en el string (empezando por 0)
	int posicion = nombresNodos.find(nombreNodo);
	return (posicion);
}

Grafo::Grafo() {
	matriz = NULL;
	n=0;
}

void Grafo::imprimir() {

	// Si el grafo está vacio, imprimimos mensaje informativo
	if (n==0) cout << "La matriz esta vacia\n";

	// En caso contrario, imprimimos la matriz de adyacencia bien alineada
	else {

		// Imprimimos la primera línea de la matriz, con los nombres de los nodos
		cout << "  "; // Imprimimos espacio de la esquina superior izquierda de la matriz	
		for (int i=0; i<n; i++) cout << nombresNodos[i] << " "; // Imprimimos el nombre de los nodos en las columnas
		cout << endl;

		// Imprimimos las filas
		for (int i=0; i<n; i++) {
			cout << nombresNodos[i] << " "; // Imprimimos el nombre del nodo de la fila
			for (int j=0; j<n; j++) cout << existeArco (i,j) << " ";
			cout << endl;
		}
		cout << endl;
	}
}

void Grafo::insertarNodo (char nombreNodo) {
	assert (!existeNodo(nombreNodo));

	nombresNodos.append(1, nombreNodo); // Insertamos el nuevo nombre en la lista de nombres

	// Añadimos una columna mas a todas las filas que ya hay. Ponemos 0 en ella
	// Complejidad temporal: O(n^2), porque cada insercion al final es O(n) pues puede que haya que incrementar capacidad
	for (int i=0; i<n; i++) matriz[i].insertarAlFinal(0);

	// Creamos la nueva fila y la rellenamos con ceros. Fijémonos en que ponemos n+1 elementos
	// Complejidad temporal: O(n^2), porque cada insercion al final es O(n) pues puede que haya que incrementar capacidad
	ListaContigua *nuevaFila = new ListaContigua;
	for (int i=0; i<n+1; i++) nuevaFila->insertarAlFinal(0);

	// Creamos espacio para la nueva matriz de adyacencia
	// Creamos n+1 listas vacías. Complejidad temporal: O(n)
	ListaContigua *nuevaMatriz = new ListaContigua[n+1];

	// Copiamos la antigua matriz y la nueva fila en el nuevo espacio
	// Complejidad temporal: O(n^2)
	for (int i=0; i<n; i++) nuevaMatriz[i].concatenar(&matriz[i]);
	nuevaMatriz[n].concatenar(nuevaFila);

	// Liberamos el antiguo espacio, la nueva fila y ajustamos variables
	delete[] matriz;
	delete nuevaFila;

	// Hacemos que el atributo "matriz" apunte al nuevo espacio de memoria
	matriz = nuevaMatriz;
	
	// Incrementamos n
	n++;
}

void Grafo::insertarArco (char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));
	int posicionNodoOrigen = obtenerIndice(nodoOrigen);
	int posicionNodoDestino = obtenerIndice(nodoDestino);
	matriz[posicionNodoOrigen].setValor(posicionNodoDestino, 1);
}

void Grafo::borrarArco (char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));
	int posicionNodoOrigen = obtenerIndice(nodoOrigen);
	int posicionNodoDestino = obtenerIndice(nodoDestino);
	matriz[posicionNodoOrigen].setValor(posicionNodoDestino, 0);
}

void Grafo::borrarNodo (char nombreNodo) {
	assert(existeNodo(nombreNodo));

	int posicionNodo = obtenerIndice(nombreNodo); // Indice del nodo
	nombresNodos.erase(posicionNodo, 1); // Borrar el nombre de la lista de nombres

	// Creo un nuevo espacio para la matriz resultante de borrar la fila del nodo
	ListaContigua *nuevaMatriz = new ListaContigua[n-1];

	// Copiamos la antigua matriz (excepto la fila borrada) en el nuevo espacio
	for (int i=0; i<posicionNodo; i++) nuevaMatriz[i].concatenar(&matriz[i]);
	for (int i=posicionNodo+1; i<n; i++) nuevaMatriz[i-1].concatenar(&matriz[i]);

	// Actualizamos n
	n--;

	// Borramos la columna
	for (int i=0; i<n; i++) nuevaMatriz[i].eliminar(posicionNodo);

	// Liberamos el antiguo espacio de la matriz y reasignamos el atributo
	delete[] matriz;
	matriz = nuevaMatriz;
}

Grafo::~Grafo() {
	delete[] matriz;
}
