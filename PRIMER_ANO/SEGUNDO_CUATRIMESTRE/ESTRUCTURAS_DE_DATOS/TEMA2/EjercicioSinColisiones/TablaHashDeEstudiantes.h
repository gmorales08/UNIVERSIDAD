#pragma once
#include "string"

using namespace std;

// Tabla hash que guarda los nombres de los estudiantes de una universidad
class TablaHashDeEstudiantes
{

protected:
	int capacidad; // Capacidad de la tabla. Permanece invariante a lo largo de la vida del objeto

	// Vectores que guardarán la información de la tabla hash
	string *nombres; // Vector con los nombres de los estudiantes
	bool *ocupada;   // Vector con los flags que indican si una posición está vacía (false) o no (true). Si esta vacia, tiene basura.
	int *claves; // Vector con las claves de los estudiantes

	// Método de hashing
	// Parámetro: la clave del estudiante (es su número de matrícula)
	// Retorno: la posición donde el estudiante debería estar o ponerse en la tabla hash
	// Complejidad temporal: O(1)
	int obtenerPosicion (int clave);

public:

	// Constructor
	// Parámetro: capacidad de la tabla
	// Complejidad temporal: O(capacidad)
	TablaHashDeEstudiantes(int capacidad);

	// Comprueba si un estudiante está o no en la tabla hash
	// Parámetro: la clave del estudiante
	// Retorno: true si está, false si no
	// Complejidad temporal: O(1)
	bool existeEstudiante (int clave);

	// Obtiene un estudiante (su nombre) a partir de su clave
	// Parámetro: la clave del estudiante
	// Retorno: el nombre del estudiante
	// Precondición: el estudiante debe estar en la tabla hash
	// Complejidad temporal: O(1)
	string getEstudiante (int clave);

	// Inserta un estudiante en la tabla
	// Parámetros:
	// - clave: el número de matrícula del estudiante
	// - estudiante: el nombre del estudiante
	// Precondición: la posicion en donde internamente meteremos el estudiante está vacía (no hay colisión)
	// Complejidad temporal: O(1)
	void introducirEstudiante (int clave, string estudiante);

	// Elimina un estudiante de la tabla
	// Parámetro: la clave del estudiante a eliminar
	// Precondición: el estudiante debe estar en la tabla hash
	// Complejidad temporal: O(1)
	void eliminarEstudiante (int clave);

	// Imprime toda la tabla hash. Viola el principio de separación entre interfaz y modelo
	// Complejidad temporal: O(capacidad)
	void imprimir();

	// Destructor
	// Complejidad temporal: O(1)
	~TablaHashDeEstudiantes();

};

