
/**
 * @file DLL.cpp
 * Modulo que contiene las funciones de las DLL.
 */

#include "DLL.hpp"
#include "Monopoly.hpp"
/**
 * @brief Crea un nuevo nodo
 * @param _data Direccion de la informacion que almacena el nodo.
 * @return El nodo nuevo que creamos.
 */
static NodePtr newNode( void* _data )
{
	NodePtr n = (NodePtr)malloc(sizeof(Node));
	if( n )
	{
		n->data = _data;
		n->next = NULL;
		n->prev = NULL;
	}
	return n;
}
/**
 * @brief Resetea la Lista
 * @param thi Dirección de la lista que se va a resetear.
 */
static void reset( DLL* thi )
{
	thi->first = thi->last = thi->cursor = NULL;
	thi->len = 0;
}
/**
 * @brief Crea la lista.
 * @return La lista que creo.
 */
DLL* DLL_New()
{
	DLL* list = (DLL*)malloc(sizeof(DLL));
	if( list )
	{
		reset( list );
	}
	return list;
}
/**
 * @brief Elimina la lista.
 * @param thi Dirección de la lista que se va a borrar.
 */
void DLL_Delete( DLL* thi )
{
	if( thi )
	{
		DLL_MakeEmpty( thi );
		free( thi );
	}
}
/**
 * @brief Inserta por enfrente.
 * @param thi Dirección de la lista que se ocupara.
 * @param _data Dirección de la información que se va a guardar.
 * @return Regresa true si fue posible hacerlo.
 */
bool DLL_InsertFront( DLL* thi, void* _data )
{
	assert( thi );
	bool done = false;
	NodePtr n = newNode( _data );
	if( n )
	{
		done = true;
		if( DLL_IsEmpty( thi ) == true )
		{
			thi->first = thi->last = thi->cursor = n;
		}
		else
		{
			n->next = thi->first;
			thi->first->prev = n;
			thi->first = n;
		}
		++thi->len;
	}
	return done;
}
/**
 * @brief Inserta por detras.
 * @param thi Dirección de la lista que se ocupara, _data Dirección de la información que se va a guardar.
 * @return Regresa si pudo hacerlo o no.
 */
bool DLL_InsertBack( DLL* thi, void* _data )
{
	assert( thi );
	bool done = false;
	NodePtr n = newNode( _data );
	if( n )
	{
		done = true;
		if( DLL_IsEmpty( thi ) == true )
		{
			thi->first = thi->last = thi->cursor = n;
		}
		else
		{
			thi->last->next = n;
			n->prev = thi->last;
			thi->last = n;
		}
		++thi->len;
	}
	return done;
}
/**
 * @brief Remueve por enfrente.
 * @param thi Dirección de la lista que se ocupara, _data Dirección de la información que se va a guardar.
 * @return Regresa si pudo hacerlo o no.
 */
bool DLL_RemoveFront( DLL* thi, void* _data_back )
{
	assert( thi );
	bool done = false;
	if( DLL_IsEmpty( thi ) != true )
	{
		done = true;
        _data_back = thi->first->data;
		NodePtr tmp = thi->first->next;
		free( thi->first );
		thi->first = tmp;
		if( NULL != thi->first )
		{
			thi->first->prev = NULL;
			--thi->len;
		}
		else
		{
			reset( thi );
		}
	}
	return done;
}
/**
 * @brief Remueve por detras.
 * @param thi Dirección de la lista que se ocupara, _data Dirección de la información que se va a guardar.
 * @return Regresa si pudo hacerlo o no.
 */
bool DLL_RemoveBack( DLL* thi, void* _data_back )
{
	assert( thi );
	bool done = false;
	if( DLL_IsEmpty( thi ) != true )
	{
		done = true;
        _data_back = thi->last->data;
		NodePtr tmp = thi->last->prev;
		free( thi->last );
		thi->last = tmp;
		if( NULL != thi->last )
		{
			thi->last->next = NULL;
			--thi->len;
		}
		else
		{
			reset( thi );
		}
	}
	return done;
}
/**
 * @brief Regresa el tamaño del lista.
 * @param thi Dirección de la lista que se ocupara.
 * @return Regresa el tamaño de la lista.
 */
size_t DLL_Len( DLL* thi )
{
	assert( thi );
	return thi->len;
}
/**
 * @brief Define si la lista esta vacio o no.
 * @param thi Dirección de la lista que se ocupara.
 * @return Regresa true si la lista esta vacia.
 */
bool DLL_IsEmpty( DLL* thi )
{
	assert( thi );
	if( thi->len == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**
 * @brief Regresa el tamaño del arreglo.
 * @param thi Dirección de la lista que se ocupara.
 * @return Regresa el tamaño de la lista.
 */
void DLL_MakeEmpty( DLL* thi )
{
	assert( thi );
	while( NULL != thi->first )
	{
		NodePtr tmp = thi->first->next;
		free( thi->first );
		thi->first = tmp;
	}
	reset( thi );
}

/**
 * @brief Revisa el el valor en donde apunta cursor.
 * @param thi Dirección de la lista que se ocupara, _data Dirección de la información que se va a guardar.
 * @return Regresa si pudo hacerlo o no.
 */

bool DLL_Peek( DLL* thi, void* _data_back )
{
	assert( thi );
	if( DLL_IsEmpty( thi ) != true && thi->cursor != NULL )
	{
        _data_back = thi->cursor->data;
		return true;
	}
	return false;
}

/**
 * @brief Mueve el cursor al inicio de la lista
 * @param thi Dirección de la lista que se ocupara
 */

void DLL_CursorFirst( DLL* thi )
{
	assert( thi );
	thi->cursor = thi->first;
}

/**
 * @brief Mueve el cursor al final de la lista
 * @param thi Dirección de la lista que se ocupara
 */

void DLL_CursorLast( DLL* thi )
{
	assert( thi );
	thi->cursor = thi->last;
}

/**
 * @brief Mueve el cursor al nodo previo de donde apunta
 * @param thi Dirección de la lista que se ocupara
 */

void DLL_CursorPrev( DLL* thi )
{
	assert( thi );
	if( thi->cursor != NULL )
	{
		thi->cursor = thi->cursor->prev;
	}
}

/**
 * @brief Mueve el cursor al nodo siguiente de donde apunta
 * @param thi Dirección de la lista que se ocupara
 */

void DLL_CursorNext( DLL* thi )
{
	assert( thi );
	if( thi->cursor != NULL )
	{
		thi->cursor = thi->cursor->next;
	}
}
