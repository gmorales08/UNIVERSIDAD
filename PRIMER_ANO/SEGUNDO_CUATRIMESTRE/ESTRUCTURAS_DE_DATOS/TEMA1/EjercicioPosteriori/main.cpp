// Bibliotecas nuestras
#include "impresionVectores.h" // Funciones nuestras para imprimir vectores
#include "ordenacionQuickSort.h" // Funciones nuestras para ordenar por QuickSort
#include "ordenacionSeleccion.h" // Funciones nuestras para imprimir por Seleccion

// Bibliotecas estándar
#include "ctime" // Para usar "time()" y "clock()"
#include "cstdlib" // Para usar "srand()" y "qsort()"
#include "iostream"
#include "cassert"
#include "cstring"

using namespace std;

int main() {

	int n; // Tamaño del vector

	// Inicializamos el generador de numeros aleatorios con el numero de segundos transcurrido desde 1970
	srand(time(NULL));

	// Pedimos el tamaño del vector
	cout << "Introduce el tamano del vector (numero mayor o igual que 1): ";
	cin >> n;

	// Creamos el vector y lo rellenamos con números aleatorios
	int *vectorSinOrdenar = (int*)malloc(n*sizeof(int));
	for (int i = 0; i<n; i++) vectorSinOrdenar[i] = rand();

	// Copiamos el vector en otros dos vectores, cada uno de ellos para ordenarlo con un método
	int *vectorParaSeleccion = (int*)malloc(n*sizeof(int)); // Origen y resultado del algoritmo de selección
	int *vectorParaQuickSort = (int*)malloc(n*sizeof(int)); // Origen y resultado del algoritmo QuickSort
	memcpy(vectorParaSeleccion, vectorSinOrdenar, sizeof(int)*n);
	memcpy(vectorParaQuickSort, vectorSinOrdenar, sizeof(int)*n);

	// Imprimimos el vector original
	cout << "\nEl vector original es el siguiente:\n";
	escribir(vectorSinOrdenar, n);
	cout << endl << endl;

	// Lo ordenamos por seleccion
	unsigned long int numeroClicksInicio = clock();
	cout << "Clocks de inicio con ordenacion por seleccion: " << numeroClicksInicio << endl;
	ordenarPorSeleccion(vectorParaSeleccion, n);
	unsigned long int numeroClicksFin = clock();
	cout << "Clocks de fin con ordenacion por seleccion:    " << numeroClicksFin << endl;
	cout << "CLOCK_PER_SEC:                                 " << CLOCKS_PER_SEC << endl;

	// Calculamos el tiempo que ha llevado la ordenación
	// Hacemos el divisor float para que la división sea real y no entera
	// La cte CLOKS_PER_SEC (en ctime) nos dice el numero de clocks por segundo
	float segundosTranscurridos = (numeroClicksFin - numeroClicksInicio) / (float)CLOCKS_PER_SEC; 

	// Imprimimos el tiempo transcurrido con tres decimales
	printf ("Con ordenacion por seleccion he tardado %.3f segundos en ordenarlo.\nEl vector resultado es:\n", segundosTranscurridos);
	escribir(vectorParaSeleccion, n);
	cout << endl << endl;

	// Lo ordenamos por QuickSort
	numeroClicksInicio = clock();
	cout << "Clocks de inicio con ordenacion por QuickSort: " << numeroClicksInicio << endl;
	qsort(vectorParaQuickSort, n, sizeof(int), compararEnteros);
	numeroClicksFin = clock();
	cout << "Clocks de fin con ordenacion por QuickSort:    " << numeroClicksFin << endl;
	cout << "CLOCK_PER_SEC:                                 " << CLOCKS_PER_SEC << endl;

	// Calculamos el tiempo que ha llevado la ordenación
	// Hacemos el divisor float para que la división sea real y no entera
	// La cte CLOKS_PER_SEC (en ctime) nos dice el numero de clocks por segundo
	segundosTranscurridos = (numeroClicksFin - numeroClicksInicio) / (float)CLOCKS_PER_SEC;

	// Imprimimos el tiempo transcurrido con tres decimales
	printf ("Con ordenacion por QuickSort he tardado %.3f segundos en ordenarlo.\nEl vector resultado es:\n", segundosTranscurridos);
	escribir(vectorParaQuickSort, n);
	cout << endl << endl;

    return 0;   
}



