#include "Punto2D.h"
#include "cmath"
#include "iostream"

using namespace std;

Punto2D::Punto2D(float nuevoX, float nuevoY) {
	x = nuevoX;
	y = nuevoY;
}

void Punto2D::desplazar(float desplazamientoX, float desplazamientoY) {
	x = x + desplazamientoX;
	y = y + desplazamientoY;
}

float Punto2D::calcularDistanciaAlOrigen() {
	float distancia; // Contendrá la distancia del punto al origen
	distancia = sqrt(x * x + y * y);
	return(distancia);
}

void Punto2D::visualizar() {
	cout << "(" << x << "," << y << ")";
}