#include "Lugares.hpp"
#include "Monopoly.hpp"
#include "Stack.hpp"
#include "DLL.hpp"
#include "graph.hpp"
#include <iostream>

void asignar( Jugador* destino, const Jugador* fuente ) //<1>
{
    destino->id = fuente->id;
    destino->nombre = fuente->nombre ;
    destino->dinero = fuente->dinero;
    destino->dineroFinal = fuente->dineroFinal;
    destino->casilla = fuente->casilla;
    destino->propiedades = fuente->propiedades;
}

void intercambiar( Jugador* primero, Jugador* segundo )
{
    Jugador tmp;

    asignar( &tmp, primero );
    asignar( primero, segundo );
    asignar( segundo, &tmp );

}

void quick_sort_asc( Jugador list[], size_t first, size_t last )
{
    size_t mid = (first+last)/2;
    int piv = list[mid].dineroFinal;
    size_t x0 = first;
    size_t x1 = last;

    while(x0 <= x1){
        while(list[x0].dineroFinal < piv)
            ++x0;
        while(list[x1].dineroFinal > piv)
            x1--;
        if(x0<= x1){
            intercambiar(&list[x0], &list[x1]);
            ++x0;
            --x1;
        }
    }
    if(first < x1)
        quick_sort_asc(list, first, x1);
    if(x0 < last)
        quick_sort_asc(list, x0, last);

}

void quick_sort_desc( Jugador list[], size_t first, size_t last )
{
    size_t mid =(first+last)/2;
    int piv = list[mid].dineroFinal;
    size_t x0 = first;
    size_t x1 =last;
    
    while(x0 <= x1){
        while(list[x0].dineroFinal > piv)
            x0++;
        while(list[x1].dineroFinal < piv)
            x1--;
        if (x0 <= x1){
            intercambiar(&list[x0], &list[x1]);
            x0++;
            x1--;
        }
    }
    if(first < x1)
        quick_sort_desc(list,first,x1);
    if (x0 < last)
        quick_sort_desc(list,x0,last);

}


int main()
{
    int ordenTarjetas[21];
    Stack* cartas = Stack_New( 25 );
    int turnos, i, k, jugadores, dados;

    Jugador* auxiliar, aux;
    Jugador participantes[4];
    Graph* Tablero = crearTablero();
    elegirTarjeta( ordenTarjetas );

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

    quick_sort_asc(participantes, 0, jugadores);
    //quick_sort_desc(participantes , 0 , jugadores);

    /* Bajo Remodelacion
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
    */

    for( i = jugadores; i > 0; i-- )
    {
        std::cout << ((jugadores-i)+1) << "° lugar:" << participantes[i-1].nombre << "\n";
        std::cout << "Dinero total: " << participantes[i-1].dineroFinal <<"\n";
        DLL_Delete( participantes[i].propiedades );
    }

    Stack_Delete( cartas );
}