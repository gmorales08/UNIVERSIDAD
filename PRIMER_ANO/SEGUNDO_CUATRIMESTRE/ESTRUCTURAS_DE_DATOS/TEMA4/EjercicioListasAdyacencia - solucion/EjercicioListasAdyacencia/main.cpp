#include "iostream"
#include "EspacioAereo.h"
using namespace std;


void main () {

	// Grafo que guardará el espacio aéreo
	EspacioAereo grafo;
	grafo.imprimir();
	cout << endl;

	// Insertamos los aeropuertos
	cout << "Insertamos aeropuertos: " << endl;
	grafo.insertarAeropuerto("Barajas");
	grafo.insertarAeropuerto("Prat");
	grafo.insertarAeropuerto("Heathrow");
	grafo.insertarAeropuerto("JFK");
	grafo.insertarAeropuerto("Frankfurt");
	grafo.imprimir();
	cout << endl;

	// Insertamos rutas
	cout << "Insertamos rutas:" << endl;
	grafo.insertarRuta("Barajas", "Prat", 300, "Vueling");
	grafo.insertarRuta("Prat", "Barajas", 350, "Iberia");
	grafo.insertarRuta("Barajas", "Heathrow", 900, "Iberia");
	grafo.insertarRuta("Barajas", "JFK", 3000, "Iberia");
	grafo.insertarRuta("JFK", "Heathrow", 2500, "Iberia");
	grafo.imprimir();
	cout << endl;

	// Borro Frankfurt
	cout << "Borro Frankfurt:" << endl;
	grafo.eliminarAeropuerto("Frankfurt");
	grafo.imprimir();
	cout << endl;

	// Borro ruta de Prat a Barajas
	cout << "Borro ruta de Prat a Barajas:\n";
	grafo.eliminarRuta("Prat", "Barajas");
	grafo.imprimir();
	cout << endl;

	// Borro Barajas
	cout << "Borro Barajas:" << endl;
	grafo.eliminarAeropuerto("Barajas");
	grafo.imprimir();
	cout << endl;
}


