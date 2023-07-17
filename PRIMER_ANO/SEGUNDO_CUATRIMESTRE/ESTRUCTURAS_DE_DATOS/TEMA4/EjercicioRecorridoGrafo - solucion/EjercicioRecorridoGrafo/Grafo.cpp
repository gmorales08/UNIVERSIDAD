#include "Grafo.h"
#include "cstdlib"
#include "cassert"
#include "string"
#include "iostream"

using namespace std;

bool Grafo::existeArco(int indiceNodoOrigen, int indiceNodoDestino) {
	assert(indiceNodoOrigen >= 0 && indiceNodoOrigen <= n - 1);
	assert(indiceNodoDestino >= 0 && indiceNodoDestino <= n - 1);
	if (matriz[indiceNodoOrigen].getValor(indiceNodoDestino) > 0) return true;
	else return false;
}

bool Grafo::existeNodo(char nombreNodo) {
	// Si find() no encuentra el caracter, devuelve string::npos, que suele ser -1.
	// Si lo encuentra, devuelve su posición en el string (empezando por 0)
	if (string::npos == nombresNodos.find(nombreNodo)) return false;
	else return true;
}

int Grafo::obtenerIndice(char nombreNodo) {
	assert(existeNodo(nombreNodo));
	// Si find() no encuentra el caracter, devuelve string::npos, que suele ser -1.
	// Si lo encuentra, devuelve su posición en el string (empezando por 0)
	int posicion = nombresNodos.find(nombreNodo);
	return (posicion);
}

string Grafo::recorrerEnProfundidadRecursivo(int indiceNodoInicial, bool *vistos) {
	assert (indiceNodoInicial >= 0 && indiceNodoInicial <= n-1);
	assert (vistos != NULL);

	string resultado; // Resultado que contendrá el recorrido
	char nombreNodoInicial = nombresNodos[indiceNodoInicial]; // Nombre del nodo inicial

	resultado.append(1, nombreNodoInicial); // Añadimos al recorrido el nodo inicial
	vistos[indiceNodoInicial] = true; // Guardamos que el nodo inicial ya ha sido visto

	// Vemos los nodos inmediatamente consecutivos al inicial y nos llamamos recursivamente
	// con cualquiera de ellos que aún no hayamos visto
	for (int indiceNodoDestino=0; indiceNodoDestino<n; indiceNodoDestino++) {

		// Si el posible nodo consecutivo no está aún visto
		if (vistos[indiceNodoDestino] == false) {

			// Si existe un arco del nodo origen al nodo destino "no visto", nos llamamos recursivamente
			// con el nodo destino como nuevo origen
			if (existeArco(indiceNodoInicial, indiceNodoDestino)) 
				resultado.append(recorrerEnProfundidadRecursivo(indiceNodoDestino, vistos));
		}
	}
	return (resultado);
}

Grafo::Grafo() {
	matriz = NULL;
	n = 0;
}

void Grafo::imprimir() {

	// Si el grafo está vacio, imprimimos mensaje informativo
	if (n == 0) cout << "La matriz esta vacia\n";

	// En caso contrario, imprimimos la matriz de adyacencia bien alineada
	else {

		// Imprimimos la primera línea de la matriz, con los nombres de los nodos
		cout << "  "; // Imprimimos espacio de la esquina superior izquierda de la matriz	
		for (int i = 0; i < n; i++) cout << nombresNodos[i] << " "; // Imprimimos el nombre de los nodos en las columnas
		cout << endl;

		// Imprimimos las filas
		for (int i = 0; i < n; i++) {
			cout << nombresNodos[i] << " "; // Imprimimos el nombre del nodo de la fila
			for (int j = 0; j < n; j++) cout << existeArco(i, j) << " ";
			cout << endl;
		}
		cout << endl;
	}
}

void Grafo::insertarNodo(char nombreNodo) {
	assert(!existeNodo(nombreNodo));

	nombresNodos.append(1, nombreNodo); // Insertamos el nuevo nombre en la lista de nombres

	// Añadimos una columna mas a todas las filas que ya hay. Ponemos 0 en ella
	// Complejidad temporal: O(n^2)
	// Complejidad espacial: O(n), porque cada vez que insertamos en una fila es posible que haya que copiarla temporalmente en otro lugar
	for (int i = 0; i < n; i++) matriz[i].insertar(n, 0);

	// Creamos la nueva fila y la rellenamos con ceros
	// Complejidad temporal y espacial: O(n)
	ListaContigua* nuevaFila = new ListaContigua;
	for (int i = 0; i <= n; i++) nuevaFila->insertar(0, 0);

	// Creamos espacio para la nueva matriz de adyacencia
	// Creamos n+1 listas vacías. Complejidad temporal y espacial: O(n)
	ListaContigua* nuevaMatriz = new ListaContigua[n + 1];

	// Copiamos la antigua matriz y la nueva fila en el nuevo espacio
	// Complejidad temporal: O(n^2)
	// Complejidad espacial: O(n^2), porque creamos n filas temporales, cada una con n columnas
	for (int i = 0; i < n; i++) nuevaMatriz[i].concatenar(&matriz[i]);
	nuevaMatriz[n].concatenar(nuevaFila);

	// Borramos el antiguo espacio y ajustamos variables
	delete[] matriz;
	delete nuevaFila;
	matriz = nuevaMatriz;

	// Incrementamos n
	n++;
}

void Grafo::insertarArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));
	int posicionNodoOrigen = obtenerIndice(nodoOrigen);
	int posicionNodoDestino = obtenerIndice(nodoDestino);
	matriz[posicionNodoOrigen].setValor(posicionNodoDestino, 1);
}

void Grafo::borrarArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));
	int posicionNodoOrigen = obtenerIndice(nodoOrigen);
	int posicionNodoDestino = obtenerIndice(nodoDestino);
	matriz[posicionNodoOrigen].setValor(posicionNodoDestino, 0);
}

void Grafo::borrarNodo(char nombreNodo) {
	assert(existeNodo(nombreNodo));

	int posicionNodo = obtenerIndice(nombreNodo); // Indice del nodo
	nombresNodos.erase(posicionNodo, 1); // Borrar el nombre de la lista de nombres

	// Creo un nuevo espacio para la matriz resultante de borrar la fila del nodo
	ListaContigua* nuevaMatriz = new ListaContigua[n - 1];

	// Copiamos la antigua matriz (excepto la fila borrada) en el nuevo espacio
	for (int i = 0; i < posicionNodo; i++) nuevaMatriz[i].concatenar(&matriz[i]);
	for (int i = posicionNodo + 1; i < n; i++) nuevaMatriz[i - 1].concatenar(&matriz[i]);

	// Actualizamos n
	n--;

	// Borramos la columna
	for (int i = 0; i < n; i++) nuevaMatriz[i].eliminar(posicionNodo);

	// Borramos el antiguo espacio de la matriz y reasignamos variables
	delete[] matriz;
	matriz = nuevaMatriz;
}

char* Grafo::recorrerEnProfundidad(char nodoInicial) {
	assert(existeNodo(nodoInicial));

	// Indice del nodo inicial
	int indiceNodoInicial = obtenerIndice(nodoInicial); 

	// Creamos el array que nos dice si un nodo ha sido visto o no, y lo inicializamos a falso
	bool *vistos = (bool*) malloc (sizeof(bool)*n); // Array que nos dice si un nodo ha sido visto o no
	for (int i=0; i<n; i++) vistos[i]=false; 

	// Recorremos en profundidad el grafo y guardamos el tamaño del recorrido
	string resultado = recorrerEnProfundidadRecursivo (indiceNodoInicial, vistos); 	
	int longitudRecorrido = resultado.size(); // Numero de nodos que tiene el recorrido
	
	// Liberamos el array de vistos
	free (vistos);

	// Copiamos el string resultado en un array de caracteres. Dejamos un espacio mas
	// para el caracter nulo que hay que poner al final del array para que cout sepa donde parar
	char *recorrido = (char*) malloc (sizeof(char)*(longitudRecorrido+1)); // Recorrido en forma de array de caracteres (será lo que devuelva la función)
	memcpy (recorrido, resultado.data(), longitudRecorrido*sizeof(char)); // Copiamos el array interno del string en el array de caracteres que vamos a devolver
	recorrido[longitudRecorrido] = '\0'; // Ponemos el caracter nulo al final

	// Devolvemos el recorrido
	return (recorrido); // Devolvemos el array de caracteres resultado del recorrido en profundidad
}

int Grafo::getN() {
	return (n);
}

Grafo::~Grafo() {
	delete[] matriz;
}
