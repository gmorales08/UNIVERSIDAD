#pragma once

// Devuelve la posición del menor elemento encontrado entre la posicion "inicio" y la posicion "fin" de un vector, ambos límites inclusive
// Parámetros:
// - vector: puntero al inicio del vector
// - n: número de componentes del vector
// - inicio: posición (inclusive) desde la que buscar el mínimo
// - fin: posición (inclusive) hasta la cual buscar el mínimo
// Retorno: posición del mínimo encontrado en el rango [inicio,fin]
// Precondiciones: inicio >= 0 && fin < n && inicio <= fin && vector != NULL
int buscarMinimo(int *vector, int n, int inicio, int fin);

// Ordena un vector de menor a mayor usando el método de selección
// (https://es.wikipedia.org/wiki/Ordenamiento_por_selecci%C3%B3n)
// Parámetros:
// - vector: puntero al inicio del vector
// - n: numero de componentes del vector
// Precondición: vector != NULL
void ordenarPorSeleccion(int *vector, int n);
