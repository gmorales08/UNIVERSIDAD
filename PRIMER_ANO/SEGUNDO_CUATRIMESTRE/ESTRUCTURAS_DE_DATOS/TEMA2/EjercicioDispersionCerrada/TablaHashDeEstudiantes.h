#pragma once
#include "string"

using namespace std;

// Tabla hash que guarda los nombres de los estudiantes de una universidad. Utiliza dispersi�n cerrada 
// y exploraci�n lineal para resolver colisiones.
class TablaHashDeEstudiantes
{

protected:

	int capacidad; // Capacidad de la tabla. Permanece invariante a lo largo de la vida del objeto
	int n; // Numero actual de elementos de la tabla. Precondici�n: n pertenece a [0,capacidad]

	// Vectores que guardar�n la informaci�n de la tabla hash
	string *nombres; // Vector con los nombres de los estudiantes
	bool *vacias;   // Vector con los flags que indican si una posici�n est� vac�a (true) o no (false). Si esta vacia, tiene basura.
	int *claves; // Vector con las claves de los estudiantes
	bool *borradas; // Vector con los flags que indican si una posicion vacia ha sido borrada (true) o aun no (false). Si una casilla est� borrada, entonces est� vacia

	// M�todo de hashing
	// Par�metro: la clave del estudiante (es su n�mero de matr�cula)
	// Retorno: la posici�n donde el estudiante deber�a estar o ponerse en la tabla hash
	// Complejidad temporal en todos los casos: O(1)
	int obtenerPosicion (int clave);

	// M�todo que obtiene la posicion real de un estudiante en la tabla
	// Par�metro: la clave del estudiante
	// Retorno: posicion real en la tabla en donde el estudiante est�, o -1 si no se encuentra
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	int buscarEstudiante (int clave);

	// Busca el hueco adecuado para meter un estudiante. Empieza por la posici�n ideal y sigue buscando secuencialmente
	// (exploraci�n lineal) mientras haya colisi�n
	// Par�metro: la clave del estudiante que se quiere meter
	// Retorno: posici�n real en la tabla en donde el estudiante se puede meter
	// Precondici�n: la tabla no est� llena
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	int buscarHueco (int clave);

public:

	// Constructor
	// Par�metro: la capacidad (capacidad) de la lista
	// Complejidad temporal: O(capacidad) en todos los casos (porque hay que inicializar los flags)
	TablaHashDeEstudiantes(int capacidad);

	// Comprueba si un estudiante est� o no en la tabla hash
	// Par�metro: la clave del estudiante
	// Retorno: true si est�, false si no
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	bool existeEstudiante (int clave);

	// Obtiene un estudiante (su nombre) a partir de su clave
	// Par�metro: la clave del estudiante
	// Retorno: el nombre del estudiante
	// Precondici�n: el estudiante debe estar en la tabla hash
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	string getEstudiante (int clave);

	// Inserta un estudiante en la tabla
	// Par�metros:
	// - clave: el n�mero de matr�cula del estudiante
	// - estudiante: el nombre del estudiante
	// Precondici�n: la tabla no est� llena y el estudiante no existe en la tabla
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	void introducirEstudiante (int clave, string estudiante);

	// Elimina un estudiante de la tabla
	// Par�metro: la clave del estudiante a eliminar
	// Precondici�n: el estudiante debe estar en la tabla hash
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	void eliminarEstudiante (int clave);

	// Imprime toda la tabla hash. Ojo: viola el principio de separaci�n entre
	// interfaz y modelo
	// Complejidad temporal: O(capacidad) en todos los casos
	void imprimir();

	// Nos dice si la tabla est� llena o no
	// Retorno: true si est� llena, false si no lo est�
	// Complejidad temporal: O(1) en todos los casos
	bool isLlena();

	// Destructor
	// Complejidad temporal: O(1) en todos los casos
	~TablaHashDeEstudiantes();

};

