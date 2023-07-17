#include "iostream"
#include "ArbolGenealogico.h"
#include "string"

using namespace std;

void main () {

	// Pedimos nuestro antepasado más lejano y creamos el árbol con él
	string antepasadoMasLejano; // Contendra la raiz del arbol
	cout << "Introduce tu antepasado mas lejano: ";
	cin >> antepasadoMasLejano;
	ArbolGenealogico arbol(antepasadoMasLejano); // Arbol que manejamos en el programa

	int opcion;
	do {
				
		string nuevoNombre; // Nuevo nombre que pedimos al usuario para insertar un nuevo nombre
		string nombrePadre; // Nuevo padre que pedimos al usuario para insertar un nuevo nombre
		
		cout << "0. Salir" << endl;
		cout << "1. Insertar nuevo nombre" << endl;
		cout << "2. Mostrar arbol genealogico" << endl;
		cout << "Introduce opcion: ";
		cin >> opcion;

		switch (opcion) {
		case (0): // Terminar programa
			break;
		case (1):
			cout << "Escriba el nuevo nombre: ";
			cin >> nuevoNombre;
			cout << "Escriba el nombre de su padre: ";
			cin >> nombrePadre;
			arbol.insertarNombre(nuevoNombre, nombrePadre);
			break;
		case (2):
			arbol.imprimir();
			break;
		default:
			cout << "Opcion incorrecta" << endl;
			break;
		}
	} while (opcion != 0);
	
}
