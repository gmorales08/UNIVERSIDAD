#pragma once

// Nodo del árbol binario de búsqueda AVL
class Nodo {
private:

	int contenido; // Contenido del nodo
	Nodo *padre; // Apunta al padre, o NULL si no tiene
	Nodo *hijoIzquierdo; // Apunta al hijo izquierdo, o NULL si no tiene hijo izquierdo
	Nodo *hijoDerecho; // Apunta al hijo derecho, o NULL si no tiene hijo derecho
	int altura;

	// Calcula la altura del subárbol izquierdo, o -1 si no hay subárbol izquierdo
	// Retorno: altura del subárbol izquierdo, o -1 si no hay
	// Complejidad temporal: O(1)
	int getAlturaSubarbolIzquierdo();

	// Calcula la altura del subárbol derecho, o -1 si no hay subárbol derecho
	// Retorno: altura del subárbol derecho, o -1 si no hay
	// Complejidad temporal: O(1)
	int getAlturaSubarbolDerecho();

public:

	// Constructor. Crea un nodo con el elemento dado
	// Parámetro: elemento con el que queremos llenar el contenido del nodo
	// Complejidad temporal: O(1)
	Nodo(int nuevoElemento);

	// Establecer el contenido
	// Parámetro: el nuevo valor del contenido
	// Complejidad temporal: O(1)
	void setContenido (int nuevoContenido);

	// Conecta el nodo actual con un nuevo padre. 
	// No podemos hacer que el padre nos apunte porque no sabemos
	// si vamos a ser su hijo izquierdo o derecho
	// Parámetro: puntero al nuevo padre
	// Complejidad temporal: O(1)
	void setPadre (Nodo *nuevoPadre);

	// Conecta el nodo actual con un nuevo hijo izquierdo
	// Hace que apuntemos al nuevo hijo y que él nos apunte a nosotros
	// Parámetro: puntero al nuevo hijo
	// Complejidad temporal: O(1)
	void setHijoIzquierdo (Nodo *nuevoHijoIzquierdo);

	// Conecta el nodo actual con un nuevo hijo derecho
	// Hace que apuntemos al nuevo hijo y que él nos apunte a nosotros
	// Parámetro: puntero al nuevo hijo
	// Complejidad temporal: O(1)
	void setHijoDerecho (Nodo *nuevoHijoDerecho);

	// Actualiza la altura del nodo, cogiendo el máximo de las alturas
	// de sus dos hijos y sumándole uno
	// Complejidad temporal: O(1)
	void actualizarAltura();

	// Obtiene el factor de equilibrio del nodo, restando las alturas de sus dos subárboles
	// Returno: el factor de equilibrio actual del nodo. Pertenece a [-2,2]
	// Complejidad temporal: O(1)
	int getFactorEquilibrio();

	// Métodos para ver los atributos
	// Retorno: una copia del atributo respectivo
	// Complejidad temporal: O(1)
	int getContenido();
	Nodo *getPadre();
	Nodo *getHijoIzquierdo();
	Nodo *getHijoDerecho();
	int getAltura();

	// Destructor. Actualiza a NULL el puntero de nuestro padre que nos apunta
	// Precondición: los dos hijos ya han sido previamente eliminados (hijoIzquierdo==NULL && hijoDerecho==NULL)
	// Complejidad temporal: O(1)
	Nodo::~Nodo();

};

