#include "EspacioAereo.h"
#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"
#include "iostream"
#include "cassert"

using namespace std;

bool EspacioAereo::existeAeropuerto(string nombre) {
	if (nodos.buscar(nombre) == -1) return(false);
	else return(true);
}

ListaEnlazada* EspacioAereo::getDestinos(string origen) {
	assert(existeAeropuerto(origen));
	int posicionOrigen = nodos.buscar(origen); // Posición del aeropuerto origen en la lista de nodos
	ListaEnlazada* rutas = nodos.getValor(posicionOrigen).rutasSalientes; // Lista de destinos desde ese nodo
	return(rutas);
}

ListaEnlazada* EspacioAereo::getOrigenes(string destino) {
	assert(existeAeropuerto(destino));
	int posicionDestino = nodos.buscar(destino); // Posición del aeropuerto origen en la lista de nodos
	ListaEnlazada* rutas = nodos.getValor(posicionDestino).rutasEntrantes; // Lista de destinos desde ese nodo
	return(rutas);
}

bool EspacioAereo::existeRuta(string origen, string destino) {
	assert(existeAeropuerto(origen));
	assert(existeAeropuerto(destino));

	if (getDestinos(origen)->buscar(destino) == -1) return(false);
	else return (true);
}

EspacioAereo::EspacioAereo() {
	n = 0;
}

void EspacioAereo::imprimir() {
	if (n == 0) cout << "Grafo vacio\n";
	else {
		// Por cada nodo, imprimimos sus destinos y sus orígenes
		for (int i = 0; i < n; i++) {
			Aeropuerto aeropuerto = nodos.getValor(i);
			cout << "Nodo " << *(aeropuerto.nombre) << ":\n";
			cout << "\tRutas de salida: ";
			imprimirListaEnlazada(nodos.getValor(i).rutasSalientes);
			cout << "\tRutas de entrada: ";
			imprimirListaEnlazada(nodos.getValor(i).rutasEntrantes);
		}
	}
}

void EspacioAereo::insertarAeropuerto(string nuevoNombre) {
	assert(!existeAeropuerto(nuevoNombre)); // Ese aeropuerto no existe previamente
	Aeropuerto *nuevoAeropuerto = new Aeropuerto;
	nuevoAeropuerto->nombre = new string(nuevoNombre);
	nuevoAeropuerto->rutasEntrantes = new ListaEnlazada;
	nuevoAeropuerto->rutasSalientes = new ListaEnlazada;
	nodos.insertarAlFinal(*nuevoAeropuerto);
	n++;
}

void EspacioAereo::insertarRuta(string origen, string destino, int distancia, string empresa) {
	assert(existeAeropuerto(origen));
	assert(existeAeropuerto(destino));
	assert(!existeRuta(origen, destino));
	assert(distancia > 0);

	// Tenemos que añadir la ruta de forma redundante en dos listas: 
	// - La lista de destinos en el origen
	// - La lista de orígenes en el destino

	// Creamos la nueva ruta para añadir a la lista de destinos en el origen
	Ruta *nuevaRuta1 = new Ruta;
	nuevaRuta1->aeropuerto = new string(destino);
	nuevaRuta1->kilometros = distancia;
	nuevaRuta1->empresa = new string(empresa);

	// Añadimos la ruta al principio de la lista de destinos en el origen, para que sea O(1)
	getDestinos(origen)->insertar(0, *nuevaRuta1);

	// Creamos la nueva ruta para añadir a la lista de orígenes en el destino
	Ruta* nuevaRuta2 = new Ruta;
	nuevaRuta2->aeropuerto = new string(origen);
	nuevaRuta2->kilometros = distancia;
	nuevaRuta2->empresa = new string(empresa);

	// Añadimos la ruta al principio de la lista de orígenes en el destino, para que sea O(1)
	getOrigenes(destino)->insertar(0, *nuevaRuta2);
}

void EspacioAereo::eliminarRuta(string origen, string destino) {
	assert(existeAeropuerto(origen));
	assert(existeAeropuerto(destino));
	assert(existeRuta(origen, destino));

	// Primero vamos a la lista del aeropuerto origen y la eliminamos de allí
	int posicion = getDestinos(origen)->buscar(destino);
	getDestinos(origen)->eliminar(posicion);

	// Ahora vamos a la lista del aeropuerto destino y la eliminamos de alli
	posicion = getOrigenes(destino)->buscar(origen);
	getOrigenes(destino)->eliminar(posicion);
}


void EspacioAereo::eliminarAeropuerto(string nombre) {
	assert(existeAeropuerto(nombre));

	// Eliminamos todas las rutas que parten desde el aeropuerto
	// Recordemos que cada una está duplicada dos veces
	ListaEnlazada *destinos = getDestinos(nombre);
	while (destinos->getN() > 0) {
		string origen = nombre;
		string destino = *(destinos->getValor(0).aeropuerto);
		eliminarRuta(origen, destino);
	}

	// Eliminamos todas las rutas que llegan a ese aeropuerto
	// Recordemos que cada una está duplicada dos veces
	ListaEnlazada* origenes = getOrigenes(nombre);
	while (origenes->getN() > 0) {
		string origen = *(origenes->getValor(0).aeropuerto);
		string destino = nombre;
		eliminarRuta(origen, destino);
	}

	// Eliminamos finalmente el aeropuerto
	int posicion = nodos.buscar(nombre);
	nodos.eliminar(posicion);

	// Que no se nos olvide actualizar n
	n--;
}


