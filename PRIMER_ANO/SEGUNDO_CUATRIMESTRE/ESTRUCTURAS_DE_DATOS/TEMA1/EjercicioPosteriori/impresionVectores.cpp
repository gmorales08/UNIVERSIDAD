#include "cassert"
#include "iostream"
#include "impresionVectores.h"
using namespace std;

void escribir(int *vector, int n) {
	assert(vector != NULL);
	// Escribimos solo si el tamano del vector es aceptable para sacarlo por pantalla
	if (n<10)
		for (int i = 0; i<n; i++)
			cout << vector[i] << " ";
	else cout << "Vector demasiado grande para ser mostrado";
}