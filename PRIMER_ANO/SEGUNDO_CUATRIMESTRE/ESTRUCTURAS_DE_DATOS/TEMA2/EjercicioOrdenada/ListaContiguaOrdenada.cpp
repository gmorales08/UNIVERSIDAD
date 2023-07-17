#include "ListaContiguaOrdenada.h"
#include "cassert" // Para assert
#include "iostream"

ListaContiguaOrdenada::ListaContiguaOrdenada() {
	lista = new ListaContigua();
}

void ListaContiguaOrdenada::insertar(int nuevoValor) {
	int posicion; // Posicion en donde insertar el nuevo valor
	if (lista->getN() == 0) posicion = 0; // Si la lista esta vacia, insertaremos en la posicion 0
	else posicion = buscarPosicion(nuevoValor, 0, lista->getN()); // Si no, buscamos el hueco en donde meterlo
	lista->insertar(posicion, nuevoValor); // Insertamos en la posicion calculada
}

void ListaContiguaOrdenada::eliminar(int elementoAEliminar) {
	assert(buscar(elementoAEliminar) != -1); // El elemento existe
	int posicion = buscarPosicion(elementoAEliminar, 0, lista->getN());
	lista->eliminar(posicion);
}

int ListaContiguaOrdenada::buscar(int elementoABuscar) {
	if (lista->getN() == 0) return(-1); // Si la lista esta vacia, cualquier busqueda resulta infructuosa
	int posicion = buscarPosicion(elementoABuscar, 0, lista->getN());
	// Si la posicion devuelta es "n", quiere decir que lo buscado no está, y además habría que insertarlo al final
	if (posicion == lista->getN()) return(-1);
	// Si en la posicion devuelta esta el elemento a buscar, entonces lo hemos encontrado
	if (lista->getValor(posicion) == elementoABuscar) return (posicion);
	// Si en la posición devuelta no está el elemento que estamos buscando, entonces es porque no está (y habría que insertarlo ahí llegado el caso)
	else return (-1);
}


int ListaContiguaOrdenada::buscarPosicion(int valorABuscar, int posicionInicioSublista, int nSublista) {

	// Precondiciones
	assert(nSublista >= 1);
	int n = lista->getN(); // Tamaño de la lista entera, representada por el objeto actual en donde está este método
	int posicionFinSublista = posicionInicioSublista + (nSublista-1); // Posición de fin de la sublista
	assert(posicionInicioSublista >= 0 && posicionInicioSublista < n);
	assert(posicionFinSublista >= 0 && posicionFinSublista < n);
	assert(posicionInicioSublista <= posicionFinSublista);

	// Posición del medio de la sublista en donde estamos buscando.
	int posicionMedioSublista = (posicionInicioSublista+posicionFinSublista)/2;

	// Si encontramos el elemento, entonces esa es obviamente la posición en que debería estar
	if (lista->getValor(posicionMedioSublista) == valorABuscar) return (posicionMedioSublista);

	// Si no encontramos el elemento y este es mayor que el valor del medio, seguimos buscando por arriba
	// siempre que aún quede algo de lista por arriba
	else if (valorABuscar > lista->getValor(posicionMedioSublista)) {

		// Calculamos el tamaño del nuevo subvector que representa la mitad superior del subvector actual
		// Es el numero de posiciones desde la posicionMedio+1 hasta posicionFinSublista (ambas inclusive)
		int nNuevoSubvector = posicionFinSublista - (posicionMedioSublista + 1) + 1;

		// Si la mitad superior tiene 0 elementos,
		// entonces está claro que el elemento que estamos buscando no está, y que habría que insertarlo
		// al final de la sublista actual, es decir en su posicion "posicionFinSublista+1"
		if (nNuevoSubvector==0) return (posicionFinSublista + 1);
			
		// En caso de que aún quede parte de sublista a continuación de la posición del medio,
		// seguimos buscando recursivamente por ahí
		else return (buscarPosicion(valorABuscar, posicionMedioSublista + 1, nNuevoSubvector));
	}

	// Si no encontramos el elemento y este es menor que el valor del medio, seguimos buscando por abajo
	// siempre que aún quede algo de lista por abajo (es decir, siempre que la posicion del medio no sea la primera)
	else {

		// Calculamos el tamaño del nuevo subvector que representa la mitad interior del subvector actual
		// Es el numero de posiciones desde la posicionInicioSublista hasta posicionMedioSublista-1 (ambas inclusive)
		int nNuevoSubvector = (posicionMedioSublista-1) - posicionInicioSublista + 1;
		
		// Si la la mitad inferior tiene 0 elementos,
		// entonces está claro que el elemento que estamos buscando no está, y que habría que insertarlo
		// al principio de la sublista actual, es decir en su posicion "posicionInicioSublista"
		if (nNuevoSubvector==0) return (posicionInicioSublista);

		// En caso de que aún quede parte de sublista antes de la posición del medio,
		// seguimos buscando recursivamente por ahí
		else return (buscarPosicion(valorABuscar, posicionInicioSublista, nNuevoSubvector));
	}
}


ListaContigua* ListaContiguaOrdenada::getLista()
{
	return(lista);
}

ListaContiguaOrdenada::~ListaContiguaOrdenada() {
	delete(lista); // Se llama al destructor de "lista" y luego se libera la memoria del objeto "lista"
}


