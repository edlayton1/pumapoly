#ifndef _MONOPOLY_INC_
#define _MONOPOLY_INC_
/**
 * @file Monopoly.hpp
 * Modulo que contiene las declaraciones de las funciones de Monopoly.cpp .
 */
#include<time.h>
#include "Vertex.hpp"
#include "DLL.hpp"
#include "Stack.hpp"

int lanzarDados();

void elegirTarjeta( int tarjetas[] );

void rellenarStack(Stack* cartas);

void imprimirCasilla( Vertex* e, Jugador* o, Stack* cartas );

void comprarLugar( Jugador* a, Vertex* l, int casaExtra );

void Banco( Jugador* A );

void Seleccion( int tarjeta, Jugador* a );

#endif
