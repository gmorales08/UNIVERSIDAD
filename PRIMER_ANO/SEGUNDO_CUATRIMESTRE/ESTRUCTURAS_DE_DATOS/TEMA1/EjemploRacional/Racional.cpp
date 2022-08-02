// En este archivo pondremos el código de los métodos de nuestra clase Racional

#include "Racional.h" // Para saber de qué clase estamos hablando y cual es su definicion
#include "iostream" // Para poder usar cout y cin
#include "cmath" // Para usar "abs()"
#include "cassert" // Para utilizar la macro "assert()"
using namespace std;

// Es necesario poner "Racional::" delante del nombre del método para especificar que este método está
// declarado dentro de la clase "Racional". 
int Racional::calcularMaximoComunDivisor(int operando1, int operando2) {
	// assert sirve para comprobar que la precondición se cumple. Se pone como único parámetro
	// una expresión booleana. Si se evalúa como verdadero, no ocurre nada. Si se evalúa como falso,
	// se interrumpe el programa y se indica la precondición violada
	assert(operando1 >= 0 && operando2 >= 0);

	// Calculamos el máximo común divisor de dos naturales usando el algoritmo de Euclides
	while (operando2 != 0) {
		int resto = operando1 % operando2; // Resto de la división entera entre los dos operandos
		operando1 = operando2;
		operando2 = resto;
	}
	return(operando1);
}

Racional::Racional(int nuevoNumerador, int nuevoDenominador) {
	assert(nuevoDenominador != 0);

	// Calculamos el signo de la fracción y lo ponemos en el numerador
	// Por lo tanto hacemos que el denominador siempre sea positivo
	if (nuevoDenominador < 0) {
		nuevoDenominador = -nuevoDenominador;
		nuevoNumerador = -nuevoNumerador;
	}

	// Guardamos el numerador y el denominador en el objeto actual
	numerador = nuevoNumerador;
	denominador = nuevoDenominador;
}

Racional Racional::sumar(Racional sumando) {
	// Sumamos dos fracciones: la del objeto actual (this) y la pasada como parámetro
	// Para simplificar, las llamaremos numerador1/denominador1 y numerador2/denominador2
	int numerador1 = numerador;
	int denominador1 = denominador;
	int numerador2 = sumando.getNumerador();
	int denominador2 = sumando.getDenominador();

	int nuevoDenominador; // Nuevo denominador de la fraccion resultante
	int nuevoNumerador;   // Nuevo numerador de la fracción resultante

	// El nuevo denominador común del resultado idealmente seria el mínimo comun múltiplo, pero
	// para simplificar hacemos que sea la multiplicación de ambos denominadores
	nuevoDenominador = denominador1 * denominador2;

	// A partir del nuevo denominador común, calculamos los nuevos numeradores de los sumandos
	numerador1 = numerador1 * denominador2;
	numerador2 = numerador2 * denominador1;

	// Calculamos el numerador del resultado
	nuevoNumerador = numerador1 + numerador2;

	// Creamos la fracción resultado y lo devolvemos
	Racional resultado(nuevoNumerador, nuevoDenominador);
	return (resultado);
}

Racional Racional::multiplicar(Racional multiplicador) {
	// Calculamos el nuevo numerador y denominador del resultado
	int nuevoNumerador = numerador * multiplicador.getNumerador();
	int nuevoDenominador = denominador * multiplicador.getDenominador();

	// Creamos el resultado y lo devolvemos
	Racional resultado(nuevoNumerador, nuevoDenominador);
	return (resultado);
}

int Racional::getNumerador() {
	return(numerador);
}

int Racional::getDenominador() {
	return(denominador);
}

void Racional::simplificar() {
	int maximoComunDivisor; // máximo común divisor del valor absoluto del denominador y del valor absoluto del denominador
	maximoComunDivisor = calcularMaximoComunDivisor(abs(numerador), abs(denominador));
	numerador = numerador / maximoComunDivisor;
	denominador = denominador / maximoComunDivisor;
}

void Racional::escribir() {
	if (numerador == 0 || denominador == 1) cout << numerador;
	else cout << numerador << "/" << denominador; // Se imprimen tres cosas seguidas por la pantalla
}
