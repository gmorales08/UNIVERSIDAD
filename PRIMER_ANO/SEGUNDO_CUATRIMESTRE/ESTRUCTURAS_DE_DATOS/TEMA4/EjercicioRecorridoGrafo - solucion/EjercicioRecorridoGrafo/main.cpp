#include "iostream"
#include "Grafo.h"
#include "string"

using namespace std;

// Prueba: introducir el grafo de la diapositiva 19 (OJO: al ser no dirigido, hay que meter los dos sentidos por cada arco) y recorrerlo en profundidad desde C y desde E

void main() {

	// Insertamos los nodos
	Grafo grafo;
	grafo.insertarNodo('A');
	grafo.insertarNodo('B');
	grafo.insertarNodo('C');
	grafo.insertarNodo('D');
	grafo.insertarNodo('E');

	// Insertamos arcos
	grafo.insertarArco('A', 'A');
	grafo.insertarArco('A', 'C');
	grafo.insertarArco('A', 'E');
	grafo.insertarArco('B', 'B');
	grafo.insertarArco('B', 'D');
	grafo.insertarArco('C', 'A');
	grafo.insertarArco('C', 'C');
	grafo.insertarArco('C', 'E');
	grafo.insertarArco('D', 'B');
	grafo.insertarArco('D', 'D');
	grafo.insertarArco('E', 'A');
	grafo.insertarArco('E', 'C');
	grafo.insertarArco('E', 'E');

	// Borramos nodos
	grafo.borrarNodo('B'); 
	grafo.borrarNodo('A'); 
	grafo.borrarNodo('E'); 

	// Insertamos nuevos nodos
	grafo.insertarNodo('H');
	grafo.insertarNodo('G');
	grafo.insertarNodo('F');
	grafo.insertarNodo('E');

	// Borramos los arcos que quedan en el grafo
	grafo.borrarArco('C', 'C');
	grafo.borrarArco('D', 'D');

	// Insertamos varios arcos para formar el grafo del enunciado
	grafo.insertarArco('C', 'D');
	grafo.insertarArco('D', 'C');
	grafo.insertarArco('D', 'G');
	grafo.insertarArco('G', 'D');
	grafo.insertarArco('G', 'H');
	grafo.insertarArco('C', 'E');
	grafo.insertarArco('E', 'C');
	grafo.insertarArco('C', 'F');
	grafo.insertarArco('F', 'C');
	grafo.insertarArco('F', 'G');
	grafo.insertarArco('G', 'F');

	// Recorridos:
	cout << grafo.recorrerEnProfundidad('C') << endl;
	cout << grafo.recorrerEnProfundidad('G') << endl;
	cout << grafo.recorrerEnProfundidad('H') << endl;
	
}
