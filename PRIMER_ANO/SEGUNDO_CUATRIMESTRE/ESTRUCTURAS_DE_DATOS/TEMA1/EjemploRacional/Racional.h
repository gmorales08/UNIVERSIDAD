// Clase que representa la implementación del TAD "Numero racional" (es decir, una fracción)
// Aquí declaramos la clase (decimos los atributos y métodos que va a tener), pero no damos 
// la implementación de sus métodos... eso lo haremos en otro archivo

class Racional // "Racional" será el nombre de la clase
{

// Primero declaramos los atributos. Es decir: los datos interno que forman esta estructura de datos

// Los datos de un TAD son internos (privados), lo cual significa que sólo se pueden ver/modificar ejecutando uno de los
// métodos (algoritmos) del TAD, pero no se pueden modificar directamente desde el main o desde otros TADs
private: // A partir de ahora todo lo que escribamos es privado (sólo se pueden ver/modificar desde los métodos)

	int numerador; // Numerador
	int denominador; // Denominador. Precondición: denominador > 0

	// Ahora vamos a definir un método, que es también privado (sólo lo podemos ejecutar desde otros métodos)

	// Calcula el máximo común divisor de dos operandos naturales, usando el algoritmo de Euclides
	// Parámetros:
	// - operando1: primer operando
	// - operando2: segundo operando
	// Retorno: máximo común divisor de los dos operandos pasados como argumento
	// Precondiciones: operando1 >= 0 && operando2 >= 0
	int calcularMaximoComunDivisor(int operando1, int operando2);

public: // Todo lo que escribamos a partir de ahora será público, es decir, podemos ejecutarlo y acceder desde el main

	/* Constructor que construye un numero racional a partir de su numerador y denominador
	Parámetros:
	- Numerador: el numerador de la fracción
	- Denominador: el denominador de la fracción 
	Precondición: denominador != 0 */
	Racional(int nuevoNumerador, int nuevoDenominador); // El nombre de los constructores tienen que ser el mismo que la clase y no devuelven nada

	/* Suma "sumando" y el objeto actual. Crea un nuevo racional con el resultado y devuelve su copia
	Parámetro: el racional que es el segundo sumando
	Retorno: un nuevo racional, fruto de sumar "sumando" con el objeto actual */
	Racional sumar(Racional sumando);

	/* Multiplica "multiplicador" y el objeto actual. Crea un nuevo racional con el resultado y devuelve su copia
	Parámetro: el racional que es el multiplicador
	Retorno: un nuevo racional, fruto de multiplicar "multiplicador" con el objeto actual */
	Racional multiplicar(Racional multiplicador);

	/* Obtiene el numerador del objeto racional actual
	Retorno: numerador de la fracción del objeto actual */
	int getNumerador();

	/* Obtiene el denominador del objeto racional actual
	Retorno: numerador de la fracción del objeto actual */
	int getDenominador();

	/* Simplifica al maximo la fracción que representa al numero racional actual */
	void simplificar();

	/* Imprime por pantalla la fracción que representa al numero racional actual. Formato n/d.
	Si el numerador es 0 ó el denominador es 1 sólo se escribe el numerador.
	OJO: esto es un método de interfaz, puramente informático, que no estaba en la definición abstracta del TAD */
	void escribir();



};



