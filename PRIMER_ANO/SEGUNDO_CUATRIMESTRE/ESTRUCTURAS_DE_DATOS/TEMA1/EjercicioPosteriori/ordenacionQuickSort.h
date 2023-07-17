#pragma once

// Función para comparar dos numeros enteros, utilizada por la función "qsort()"
// Parámetros: 
// - punteroAOperando1 apunta al primer entero
// - punteroAOperando2 apunta al segundo entero
// Retorno: devuelve negativo si el primer entero es menor que el segundo, 0 si son iguales, y positivo si el primer entero es mayor que el segundo
// Precondición: punteroAOperando1 != NULL && punteroAOperando2 != NULL
int compararEnteros(const void *punteroAOperando1, const void *punteroAOperando2);
