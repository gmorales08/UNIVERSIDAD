#pragma once

#include "iostream"
#include "ListaContigua.h"

// Imprime una lista contigua por pantalla (su "n", su "capacidad" y sus elementos), si es menor que 20 elementos.
// Si es mayor, imprime "demasiados elementos para mostrar"
// Parámetros:
// - lista: puntero a la lista contigua que queremos imprimir
// Precondición: lista!=NULL
// Complejidad temporal: O(n). Realmente es O(1) porque como maximo imprime 20 elementos
void imprimirListaContigua(ListaContigua *lista);

