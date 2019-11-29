#ifndef _BUBBLE_INC_
#define _BUBBLE_INC_

/**
 * @file bubble.hpp
 * Modulo que contiene las declaraciones de las funciones de bubble.cpp.
 */

#include<stdio.h>
#include<stdlib.h>
#include"DLL.hpp"

void bubble_desc( Jugador list[], size_t num_elems );

void bubble_asc( Jugador list[], size_t num_elems );

void BubbleSort( Jugador list[], size_t num_elems, int direction );

#endif
