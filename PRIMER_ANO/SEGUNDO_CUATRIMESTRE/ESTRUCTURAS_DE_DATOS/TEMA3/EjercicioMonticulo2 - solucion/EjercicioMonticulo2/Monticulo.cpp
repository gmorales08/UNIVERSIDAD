#include "Monticulo.h"
#include "iostream"
#include "cassert"

using namespace std;

void Monticulo::imprimir() { 
	imprimirRecursivo(1, 0);
}

// Inserta un nuevo elemento en el monticulo
void Monticulo::insertar(int nuevoElemento) {
	// Lo insertamos al final
	vector.insertar(vector.getN(),nuevoElemento);

	// Vamos intercambiando con su padre hasta que sea mayor que su padre o hasta que lleguemos a la raiz (posicion 1)
	int posicion = vector.getN();
	while (posicion > 1 && vector.getValor(posicion-1) < vector.getValor(posicion/2-1)) {
		// Intercambiamos
		int padre = vector.getValor(posicion/2-1);
		vector.setValor(posicion/2-1, vector.getValor(posicion-1));
		vector.setValor(posicion-1, padre);
		
		// Actualizamos la posicion actual del nuevo elemento
		posicion = posicion/2;
	}

	assert(isMonticulo(1)); // Postcondicion
}

void Monticulo::imprimirRecursivo (int raiz, int numeroTabulaciones) {
	assert (raiz >= 1);
	assert (numeroTabulaciones >=0);

	if (raiz <= vector.getN()) {

		// Imprimimos el nodo raiz con el nivel pasado como parametro
		for (int i=0; i<numeroTabulaciones; i++) cout << "\t";
		cout << vector.getValor(raiz-1) << endl;

		// Imprimimos sus hijos con una tabulacion mas
		imprimirRecursivo(raiz*2, numeroTabulaciones+1);
		imprimirRecursivo(raiz*2+1, numeroTabulaciones+1);

	}
}

void Monticulo::borrar() {
	assert(vector.getN() > 0); // Precondicion: hay algo que borrar
	int ultimo = vector.getValor(vector.getN()-1); // Obtenemos el ultimo elemento del monticulo
	vector.setValor(0, ultimo); // Copiamos el ultimo elemento en la raiz
	vector.eliminar(vector.getN()-1); // Borramos el ultimo elemento
	if (vector.getN() >= 2) reestructurar(); // Finalmente, reestructuramos si el arbol tiene al menos dos elementos
}

int Monticulo::getRaiz() {
	assert(vector.getN() > 0);
	return (vector.getValor(0));
}

bool Monticulo::isMonticulo (int raizSubarbol) {
	assert (raizSubarbol >= 1 && raizSubarbol <= vector.getN());

	bool resultado = true; // Resultado del método

	int padre = vector.getValor(raizSubarbol-1);

	// Si existe hijo izquierdo, si éste es menor que el padre o bien el subarbol que empieza en él no es un montículo,
	// entonces nuestro árbol no es un montículo
	if (raizSubarbol*2 <= vector.getN()) {
		if (!isMonticulo(raizSubarbol*2)) resultado=false;
		if (padre > vector.getValor(raizSubarbol*2-1)) resultado=false;
	}

	// Si existe hijo derecho, si éste es menor que el padre o bien el subarbol que empieza en él no es un montículo,
	// entonces nuestro árbol no es un montículo
	if (raizSubarbol*2+1 <= vector.getN()) {
		if (!isMonticulo(raizSubarbol*2+1)) resultado=false;
		if (padre > vector.getValor(raizSubarbol*2+1-1)) resultado=false;
	}

	return (resultado);

}

void Monticulo::reestructurar() {
	int n = vector.getN(); // Numero de elementos del arbol

	assert (n>=2);
	assert (isMonticulo(2)); // El subarbol izquierdo que cuelga de la raiz es un monticulo
	if (n >= 3) assert (isMonticulo(3)); // El subarbol derecho que cuelga de la raiz es un monticulo

	bool esMonticulo = false;
	int posicionPadre = 1;
	while (!esMonticulo) {

		int valorHijoMenor; // Guardará el valor del hijo menor
		int posicionHijoMenor; // Guardará la posición del hijo menor

		// Posicion y valor del padre
		int valorPadre = vector.getValor(posicionPadre-1); // Valor del elemento padre actual
		
		// Calculamos la posición del hijo menor. Si sólo hay un hijo, es ese.
		// Hay al menos un hijo porque, si no lo hubiera, no hubieramos entrado en el bucle. La primera vez
		// que entramos en el bucle lo sabemos porque el padre es 1, y existe la precondición de que al menos
		// el árbol tenga dos nodos. Las siguientes veces es porque, al final de este bucle, se comprueba
		// si hemos llegado a una hoja, y en ese caso no entramos
		if (posicionPadre*2+1 > n) posicionHijoMenor = posicionPadre*2;
		else {
			// Hay dos hijos seguro. Comparamos el valor de ambos
			int valorHijoIzquierdo = vector.getValor(posicionPadre*2-1);
			int valorHijoDerecho = vector.getValor(posicionPadre*2+1-1);
			if (valorHijoIzquierdo < valorHijoDerecho) posicionHijoMenor = posicionPadre*2;
			else posicionHijoMenor = posicionPadre*2+1;
		}

		// Calculamos el valor del hijo menor
		valorHijoMenor = vector.getValor(posicionHijoMenor-1);

		// Intercambiamos con el hijo menor, si es necesario
		if (valorPadre > valorHijoMenor) {
			// Intercambiamos
			vector.setValor(posicionPadre-1, valorHijoMenor);
			vector.setValor(posicionHijoMenor-1, valorPadre);

			// Actualizamos la posicion del padre
			posicionPadre = posicionHijoMenor;

			// Si el nuevo padre ya no tiene hijos, hemos terminado
			if (posicionPadre > n/2) esMonticulo = true;
		} 
		
		// Si no hacía falta intercambiar el padre con su hijo menor, hemos terminado
		else esMonticulo = true;
	}
}
