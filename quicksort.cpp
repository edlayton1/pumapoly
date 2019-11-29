#include"quicksort.hpp"
/**
 * @file quicksort.cpp
 * Modulo que contiene el algoritmo QuickSort.
 */

/**
 * @brief Algoritmo QuickSort Ascendente
 * @param list lista de jugadores, first Primer elemento de la lista, last Ultimo elemento de la lista.
 */
void quick_sort_asc( Jugador list[], size_t first, size_t last )
{
    size_t mid = (first+last)/2;
    Item piv = list[mid].dineroFinal;
    size_t x0 = first;
    size_t x1 = last;

    while( x0 <= x1 )
    {
        while( list[x0].dineroFinal < piv )
        {
            x0++;
        }

        while( list[x1].dineroFinal > piv )
        {
            x1--;
        }

        if( x0 <= x1 )
        {
            swap( &list[x0], &list[x1] );
            x0++;
            x1--;
        }
    }

    if( first < x1 )
    {
        quick_sort_asc( list, first, x1 );
    }

    if( x0 < last )
    {
        quick_sort_asc( list, x0, last );
    }
}
/**
 * @brief Algoritmo QuickSort Descendente
 * @param list lista de jugadores, first Primer elemento de la lista, last Ultimo elemento de la lista.
 */
void quick_sort_desc( Jugador list[], size_t first, size_t last )
{
    size_t mid = (first+last)/2;
    Item piv = list[mid].dineroFinal;
    size_t x0 = first;
    size_t x1 = last;

    while( x0 <= x1 )
    {
        while( list[x0].dineroFinal > piv )
        {
            x0++;
        }

        while( list[x1].dineroFinal < piv )
        {
            x1--;
        }

        if( x0 <= x1 )
        {
            swap( &list[x0], &list[x1] );
            x0++;
            x1--;
        }
    }

    if( first < x1 )
    {
        quick_sort_desc( list, first, x1 );
    }

    if( x0 < last )
    {
        quick_sort_desc( list, x0, last );
    }
}
/**
 * @brief Algoritmo QuickSort Funcion activadora.
 * @param list lista de jugadores, num_elems tamaño de la lista, direction direccion que toma Quick.
 */
void Quick_Sort( Jugador list[], size_t num_elems, int direction )
{
	if(direction == ASCENDING)
	{
		quick_sort_asc( list, 0, num_elems-1 );
	}
	else
	{
		quick_sort_desc( list, 0, num_elems-1 );
	}
}
