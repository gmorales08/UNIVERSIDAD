#include "iostream"
#include "ListaContiguaOrdenada.h"
#include "cstdlib" // Para rand y srand
#include "ctime" // Para time
#include "impresionListasContiguas.h"

using namespace std;

void main() {

	// Lista sobre la que experimentamos
	ListaContiguaOrdenada lista;

	// Opción del menú que introduce el usuario por teclado
	int teclaPulsada;

	// Inicializamos el generador de numeros aleatorios
	srand(time(NULL));

	do {
		int numeroAInsertar; // Numero aleatorio a insertar
		int numeroABuscar; // Numero a buscar
		int numeroAEliminar; // Numero a eliminar
		int posicion; // Posicion ideal del numero a buscar

		// Mostrar el menú
		cout << "0. Salir\n";
		cout << "1. Insertar un numero aleatorio entre 50 y 100\n";
		cout << "2. Buscar un numero\n";
		cout << "3. Eliminar un numero\n";
		cout << "4. Imprimir la lista\n";
		cout << "Introduzca opcion: ";

		// Recogemos la opción		
		cin >> teclaPulsada;

		switch (teclaPulsada) {
		case (0) :
			break;
		case (1) :
			numeroAInsertar = 50 + rand() % 51;
			lista.insertar(numeroAInsertar);
			cout << "Numero " << numeroAInsertar << " insertado correctamente\n";
			break;
		case (2) :
			cout << "Introduzca un numero a buscar: ";
			cin >> numeroABuscar;
			posicion = lista.buscar(numeroABuscar);
			if (posicion == -1) cout << "Elemento no encontrado" << endl;
			else cout << "Elemento encontrado en la posicion " << posicion << endl;
			break;
		case (3) :
			cout << "Introduzca un numero a eliminar (tiene que existir en la lista): ";
			cin >> numeroAEliminar;
			lista.eliminar(numeroAEliminar);
			cout << "Elemento " << numeroAEliminar << " eliminado correctamente" << endl;
			break;
		case (4) :
			imprimirListaContigua(lista.getLista());
			break;
		default:
			cout << "Opcion incorrecta" << endl;
		}
	} while (teclaPulsada != 0);

}