#include "Punto2D.h"
#include "iostream"

using namespace std;

void main() {
	float x, y; // Coordenadas que introduciremos por teclado
	
	cout << "Introduce las dos coordenadas de un punto, separadas por espacio: ";
	cin >> x;
	cin >> y;

	Punto2D miPunto(x, y);
	cout << "El punto introducido es: ";
	miPunto.visualizar();
	cout << endl;
	cout << "La distancia al origen es: " << miPunto.calcularDistanciaAlOrigen() << endl;

	float desplazamientoX, desplazamientoY;
	cout << "Introduzca el desplazamiento x: ";
	cin >> desplazamientoX;
	cout << "Introduzca el desplazamiento y: ";
	cin >> desplazamientoY;

	miPunto.desplazar(desplazamientoX, desplazamientoY);
	cout << "El nuevo punto desplazado es: ";
	miPunto.visualizar();
	cout << "\n";

}