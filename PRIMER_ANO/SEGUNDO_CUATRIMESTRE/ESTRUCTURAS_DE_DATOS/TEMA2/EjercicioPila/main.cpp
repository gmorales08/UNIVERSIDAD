#include "iostream"
#include "Pila.h"
#include "impresionListasEnlazadas.h"

using namespace std;

void main () {

	Pila pila; // Creación de la pila que utilizaremos
	int teclaPulsada; // Contendrá la tecla que pulsamos (de 1 a 4)
	//int numeroIntroducido; // Numero flotante que introduciremos por teclado cuando hagamos push

	// Imprimimos el menú
	cout << "MENU:" << endl;
	cout << "1. Push" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Cima" << endl;
	cout << "4. Salir" << endl;

	do {

		cout << "Por favor, introduce una opcion del 1 al 4: ";

		cin >> teclaPulsada;
		switch (teclaPulsada) {
		case (1) :
			int numeroIntroducido; // Numero que introduciremos por teclado cuando hagamos push
			cout << "Introduce un numero: ";
			cin >> numeroIntroducido;
			pila.push(numeroIntroducido);
			cout << "Pila completa: ";
			imprimirListaEnlazada(pila.getLista());
			break;
		case (2):
			if (pila.isVacia()) cout << "La pila esta vacia, por lo tanto no se puede hacer pop" << endl;
			else cout << "La cima de la pila es " << pila.pop() << endl;
			cout << "Pila completa: ";
			imprimirListaEnlazada(pila.getLista());
			break;
		case (3):
			if (pila.isVacia()) cout << "La pila esta vacia, por lo tanto no se puede ver la cima" << endl;
			else cout << "La cima de la pila es " << pila.verCima() << endl;
			cout << "Pila completa: ";
			imprimirListaEnlazada(pila.getLista());
			break;
		} // Fin switch

	} while (teclaPulsada != 4);

}


