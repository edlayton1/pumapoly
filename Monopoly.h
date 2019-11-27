#ifndef _MONOPOLY_INC_
#define _MONOPOLY_INC_

#include<time.h>
#include "DLL.h"
#include "Stack.h"

int lanzarDados();

void imprimirCasilla( void* e, Jugador* o, Stack* cartas );

void comprarLugar( Jugador* a, Lugar* l, int casaExtra );

void Banco( Jugador* A );

void elegirTarjeta( int tarjetas[] );

void Seleccion( int tarjeta, Jugador* a );

#endif
