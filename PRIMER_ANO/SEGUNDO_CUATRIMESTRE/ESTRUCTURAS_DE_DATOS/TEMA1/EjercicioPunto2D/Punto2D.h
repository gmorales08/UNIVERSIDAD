// Clase que implementa el TAD punto en 2 dimensiones
class Punto2D {

private:
	float x, y; // Coordenadas del punto

public:

	// Constructor
	// Parámetros:
	// - nuevoX: coordenada inicial X que queremos que tenga el punto
	// - nuevoY: coordenada inicial Y que queremos que tenga el punto
	Punto2D(float nuevoX, float nuevoY);

	// Modifica las coordenadas del punto actual, añadiendo un desplazamiento
	// a cada una de ellas
	// Parámetros:
	// - desplazamientoX: desplazamiento que se sumará a la coordenada X actual del punto
	// - desplazamientoY: desplazamiento que se sumará a la coordenada Y actual del punto
	void desplazar(float desplazamientoX, float desplazamientoY);

	// Calcula la distancia que hay desde el origen de coordenadas (0,0) hasta nuestro punto
	// Retorno: distancia del punto hasta (0,0)
	float calcularDistanciaAlOrigen();

	// Visualiza el punto por pantalla de la forma (x,y)
	void visualizar();
};