
/**
 * @file bubble.cpp
 * Modulo que contiene el algoritmo BubbleSort.
 */

#include"bubble.hpp"

/**
 * @brief Imprime el dinero que tienen los jugadores
 * @param list lista de jugadores, tam numero de jugadores.
 */
void print( Jugador* list, size_t tam )
{
	for(size_t i = 0; i < tam; ++i)
	{
		printf("%d, ", list[ i ].dineroFinal );
	}
	printf("\n");
}

/**
 * @brief Cambia los puestos de dos lugares en un arreglo.
 * @param val1 Jugador 1 val2 Jugador 2
 */
void swap( Jugador* val1, Jugador* val2 )
{
	Jugador tmp = *val1;

	*val1 = *val2;
	*val2 = tmp;
}
/**
 * \brief Algoritmo BubbleSort Ascendente
 * \param list lista de jugadores, num_elems tamaño de la lista.
 */
void bubble_desc( Jugador list[], size_t num_elems )
{
	bool done = false;

	for(size_t i = 0; i < num_elems-1 && done == false; i++)
	{
		done = true;

		for(size_t j = num_elems-1; j > i; j--)
		{
			if( list[j].dineroFinal > list[j-1].dineroFinal )
			{
				swap( &list[j], &list[j-1] );
				done = false;
			}
		}
	}
}
/**
 * @brief Algoritmo BubbleSort Ascendente
 * @param list lista de jugadores, num_elems tamaño de la lista.
 */
void bubble_asc( Jugador list[], size_t num_elems )
{
	bool done = false;

	for(size_t i = 0; i < num_elems-1 && done == false; i++)
	{
		done = true;

		for(size_t j = num_elems-1; j > i; j--)
		{
			if( list[j].dineroFinal < list[j-1].dineroFinal )
			{
				swap( &list[j], &list[j-1] );
				done = false;
			}
		}
	}
}
/**
 * @brief Algoritmo BubbleSort Funcion activadora.
 * @param list lista de jugadores, num_elems tamaño de la lista, direction direccion que toma Bubble.
 */
void BubbleSort( Jugador list[], size_t num_elems, int direction )
{
	if(direction == ASCENDING)
	{
		bubble_asc( list, num_elems );
	}
	else
	{
		bubble_desc( list, num_elems );
	}
}
