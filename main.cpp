/**
 * @file main.cpp
 * Modulo de ejecución del programa.
 *
 */



#include "Lugares.hpp"
#include "Monopoly.hpp"
#include "Stack.hpp"
#include "DLL.hpp"
#include "graph.hpp"
#include "quicksort.hpp"
#include "bubble.hpp"
#include <iostream>

/**
 * @fn main
 * @brief Funcion principal, ejecutara las instrucciones.
 */
int main()
{
    int ordenTarjetas[21];
    Stack* cartas = Stack_New( 25 );
    int turnos, i, k, jugadores, dados;

    Jugador* auxiliar, aux;
    Jugador participantes[4];
    Graph* Tablero = crearTablero();
    elegirTarjeta( ordenTarjetas );
#pragma omp parallel for private (i) shared (ordenTarjetas,cartas)
    for( i = 0; i < 21; i++ )
    {
        Stack_Push( cartas, ordenTarjetas[i] );
    }

    std::cout << "\t\t\t\t\t¡Bienvenido a PumaPoly! \n\n¿Cuántos turnos desea jugar?: ";
    std::cin >> turnos;
    std::cout << "\n¿Cuántos jugadores van a jugar? Máximo 4 por partida: ";
    std::cin >> jugadores;

    while( (jugadores > 4) || ( jugadores <= 0) )
    {
        std::cout << "Cantidad no valida, solo se puede 1 a 4 jugadores\n";
        std::cin >> jugadores;
    }

    system( "clear" );

    for( i = 0; i < jugadores; i++ )
    {
        Jugador player;
        std::cout << "Ingresa el nombre del jugador " << (i+1) << ":\n";
        std::cin >> player.nombre;
        player.casilla = Tablero->vertices.find("Tienda UNAM")->second.get_name();
		player.propiedades = DLL_New();
		player.dinero = 1000;
		player.dineroFinal = 0;
        participantes[i] = player;
		system( "clear" );
    }

    for( i = 0; i < turnos; i++ )
    {
		system( "clear" );
        std::cout << "\t\tTurno número " << (i+1) << "\n";
		
        for( k = 0; k < jugadores; k++ )
        {
			auxiliar = &participantes[k];
            std::cout << "\n" << auxiliar->nombre << " es tu turno de lanzar los dados\n";
            std::cout << "Presiona enter para lanzar los dados. ¡Buena suerte!\n";
            getchar();
            getchar();
			dados = lanzarDados();
            std::cout << "\nAl lanzar los dados has sacado " << dados << " y viajaste hasta: \n\n";
			Tablero->traverse( auxiliar, dados );
			imprimirCasilla( &(Tablero->vertices.find( auxiliar->casilla )->second), auxiliar, cartas );
            std::cout << "\n------------------------------PumaPoly-------------------------------------\n";
	    }
		
        getchar();       
        getchar();
	}

    system( "clear" );
    std::cout << "\t\t\tSe han terminado los turnos\nLos resultados son los siguientes:\n";

    for( i = 0; i < jugadores; i++ )
    {
		participantes[i].dineroFinal += participantes[i].dinero;
	}

    if( jugadores > 2)
    {
        Quick_Sort( participantes, jugadores, 1 );
    }
    else
    {
        BubbleSort( participantes, jugadores, 1 );
    }

	for( i = 0; i < jugadores; i++ )
    {
        std::cout << (i+1) << "° lugar:" << participantes[i].nombre << "\n";
        std::cout << "Dinero total: " << participantes[i].dineroFinal <<"\n";
        DLL_Delete( participantes[i].propiedades );
	}

    Stack_Delete( cartas );
}
