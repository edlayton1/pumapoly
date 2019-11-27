#include "Lugares.h"
#include "Monopoly.h"
#include "Stack.h"
#include "DLL.h"
#include <iostream>
#include <stdio.h>

int main()
{
    int ordenTarjetas[21];
    Stack* cartas = Stack_New( 25 );
    int turnos, i, k, jugadores, dados;

    Jugador* auxiliar, aux;
    Jugador participantes[4];
    DLL* Tablero = crearTablero();
    elegirTarjeta( ordenTarjetas );

#pragma omp parallel for private (i) shared (ordenTarjetas,cartas)
    for( i = 0; i< 21; i++ )
    {
        Stack_Push( cartas, ordenTarjetas[i] );
    }

    std::cout << "\t\t\t\t\t¡Bienvenido a PumaPoly! \n\n¿Cuántos turnos desea jugar? " << std::endl;
    //printf( "\t\t\t\t\t¡Bienvenido a PumaPoly! \n\n¿Cuántos turnos desea jugar? " );
	std::cin >> turnos; 
    std::cin.ignore();
    //scanf( "%d", &turnos );
    std::cout << "\n¿Cuántos jugadores van a jugar? Máximo 4 por partida:  " << std::endl;
	//printf( "\n¿Cuántos jugadores van a jugar? Máximo 4 por partida:  ");
	std::cin >> jugadores;
    std::cin.ignore();
    //scanf( "%d", &jugadores );

    while( (jugadores > 4) || ( jugadores <= 0) )
    {
        std::cout << "Cantidad no valida, solo se puede 1 a 4 jugadores\n" << std::endl;
        //printf( "Cantidad no valida, solo se puede 1 a 4 jugadores\n" );
		std::cin >> jugadores;
        std::cin.ignore();
        //scanf( "%d" ,&jugadores );
    }

    system( "clear" );

    for( i = 0; i < jugadores; i++ )
    {
        Jugador player;
        printf( "Ingresa el nombre del jugador %d:\n", i+1 );
        std::cin >> player.nombre;
        std::cin.ignore();
		//scanf( "%s", player.nombre );
		player.casilla = Tablero->first;
		player.propiedades = DLL_New( sizeof( Lugar ) );
		player.dinero = 1000;
		player.dineroFinal = 0;
        participantes[i] = player;
		system( "clear" );
    }

    for( i = 0; i < turnos; i++ )
    {
		system( "clear" );
		printf( "\t\tTurno número %d\n", i+1 );
		
        for( k = 0; k < jugadores; k++ )
        {
			auxiliar = &(participantes[k]);
			printf( "\n%s es tu turno de lanzar los dados\n", auxiliar->nombre );
			printf( "Presiona enter para lanzar los dados. ¡Buena suerte!\n" );
            while ( getchar() != '\n');

            imprimirCasilla( auxiliar->casilla->data, auxiliar, cartas );
            //std::cin.ignore().get();
            //imprimirCasilla( auxiliar->casilla->data, auxiliar, cartas );

			dados = lanzarDados();
			printf( "\nAl lanzar los dados has sacado %d y viajaste hasta: \n\n",dados );
			DLL_Traverse( Tablero, auxiliar, dados );
			imprimirCasilla( auxiliar->casilla->data, auxiliar, cartas );
			printf( "\n------------------------------PumaPoly-------------------------------------\n" );
	    }
	    while ( getchar() != '\n');
	}

    system( "clear" );
	printf( "\t\t\tSe han terminado los turnos\nLos resultados son los siguientes:\n" );

    for( i = 0; i < jugadores; i++ )
    {
		participantes[i].dineroFinal += participantes[i].dinero;
	}

	for( i = 0; i < jugadores; i++ )
    {
        for( k = i + 1; k < jugadores; k ++ )
        {
            if( participantes[i].dineroFinal < participantes[k].dineroFinal )
            {
                aux = participantes[i];
                participantes[i] = participantes[k];
                participantes[k] = aux;
            }
        }
	}

	for( i = 0; i < jugadores; i++ )
    {
        printf("%i° lugar: %s\n", i + 1, participantes[i].nombre);
        printf("Dinero total: %i\n", participantes[i].dineroFinal);
	}

	free(Tablero);
	free(cartas);
}
