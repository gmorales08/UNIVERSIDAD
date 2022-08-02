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



