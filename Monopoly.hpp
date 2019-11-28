#ifndef _MONOPOLY_INC_
#define _MONOPOLY_INC_

#include<time.h>
#include "Vertex.hpp"
#include "DLL.hpp"
#include "Stack.hpp"

int lanzarDados();

void imprimirCasilla( Vertex* e, Jugador* o, Stack* cartas );

void comprarLugar( Jugador* a, Vertex* l, int casaExtra );

void Banco( Jugador* A );

void elegirTarjeta( int tarjetas[] );

void Seleccion( int tarjeta, Jugador* a );

#endif
