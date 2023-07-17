#pragma once
#include "string"

using namespace std;

// Tabla hash que guarda los nombres de los estudiantes de una universidad. Utiliza dispersión cerrada 
// y exploración lineal para resolver colisiones.
class TablaHashDeEstudiantes
{

protected:

	int capacidad; // Capacidad de la tabla. Permanece invariante a lo largo de la vida del objeto
	int n; // Numero actual de elementos de la tabla. Precondición: n pertenece a [0,capacidad]

	// Vectores que guardarán la información de la tabla hash
	string *nombres; // Vector con los nombres de los estudiantes
	bool *vacias;   // Vector con los flags que indican si una posición está vacía (true) o no (false). Si esta vacia, tiene basura.
	int *claves; // Vector con las claves de los estudiantes
	bool *borradas; // Vector con los flags que indican si una posicion vacia ha sido borrada (true) o aun no (false). Si una casilla está borrada, entonces está vacia

	// Método de hashing
	// Parámetro: la clave del estudiante (es su número de matrícula)
	// Retorno: la posición donde el estudiante debería estar o ponerse en la tabla hash
	// Complejidad temporal en todos los casos: O(1)
	int obtenerPosicion (int clave);

	// Método que obtiene la posicion real de un estudiante en la tabla
	// Parámetro: la clave del estudiante
	// Retorno: posicion real en la tabla en donde el estudiante está, o -1 si no se encuentra
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	int buscarEstudiante (int clave);

	// Busca el hueco adecuado para meter un estudiante. Empieza por la posición ideal y sigue buscando secuencialmente
	// (exploración lineal) mientras haya colisión
	// Parámetro: la clave del estudiante que se quiere meter
	// Retorno: posición real en la tabla en donde el estudiante se puede meter
	// Precondición: la tabla no está llena
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	int buscarHueco (int clave);

public:

	// Constructor
	// Parámetro: la capacidad (capacidad) de la lista
	// Complejidad temporal: O(capacidad) en todos los casos (porque hay que inicializar los flags)
	TablaHashDeEstudiantes(int capacidad);

	// Comprueba si un estudiante está o no en la tabla hash
	// Parámetro: la clave del estudiante
	// Retorno: true si está, false si no
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	bool existeEstudiante (int clave);

	// Obtiene un estudiante (su nombre) a partir de su clave
	// Parámetro: la clave del estudiante
	// Retorno: el nombre del estudiante
	// Precondición: el estudiante debe estar en la tabla hash
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	string getEstudiante (int clave);

	// Inserta un estudiante en la tabla
	// Parámetros:
	// - clave: el número de matrícula del estudiante
	// - estudiante: el nombre del estudiante
	// Precondición: la tabla no está llena y el estudiante no existe en la tabla
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	void introducirEstudiante (int clave, string estudiante);

	// Elimina un estudiante de la tabla
	// Parámetro: la clave del estudiante a eliminar
	// Precondición: el estudiante debe estar en la tabla hash
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	void eliminarEstudiante (int clave);

	// Imprime toda la tabla hash. Ojo: viola el principio de separación entre
	// interfaz y modelo
	// Complejidad temporal: O(capacidad) en todos los casos
	void imprimir();

	// Nos dice si la tabla está llena o no
	// Retorno: true si está llena, false si no lo está
	// Complejidad temporal: O(1) en todos los casos
	bool isLlena();

	// Destructor
	// Complejidad temporal: O(1) en todos los casos
	~TablaHashDeEstudiantes();

};

