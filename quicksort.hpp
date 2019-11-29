#ifndef _QUICK_INC_
#define _QUICK_INC_
/**
 * @file quicksort.hpp
 * Modulo que contiene declaraciones de las funciones para el algoritmo QuickSort .
 */

#include<stdio.h>
#include<stdlib.h>
#include"DLL.hpp"
#include<iso646.h>

void quick_sort_asc( Jugador list[], size_t first, size_t last );

void quick_sort_desc( Jugador list[], size_t first, size_t last );

void Quick_Sort( Jugador list[], size_t num_elems, int direction );

#endif
