#include "DLL.h"
#include "Monopoly.h"

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

static void reset( DLL* thi )
{
	thi->first = thi->last = thi->cursor = NULL;
	thi->len = 0;
}

DLL* DLL_New( size_t tamInfo )
{
	DLL* list = (DLL*)malloc(sizeof(DLL));
	if( list )
	{
		reset( list );
        list->TADtam = tamInfo;
	}
	return list;
}

void DLL_Delete( DLL* thi )
{
	if( thi )
	{
		DLL_MakeEmpty( thi );
		free( thi );
	}
}

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

size_t DLL_Len( DLL* thi )
{
	assert( thi );
	return thi->len;
}

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

void DLL_CursorFirst( DLL* thi )
{
	assert( thi );
	thi->cursor = thi->first;
}

void DLL_CursorLast( DLL* thi )
{
	assert( thi );
	thi->cursor = thi->last;
}

void DLL_CursorPrev( DLL* thi )
{
	assert( thi );
	if( thi->cursor != NULL )
	{
		thi->cursor = thi->cursor->prev;
	}
}

void DLL_CursorNext( DLL* thi )
{
	assert( thi );
	if( thi->cursor != NULL )
	{
		thi->cursor = thi->cursor->next;
	}
}

void DLL_Traverse( DLL* thi, Jugador* a, int casillas )
{
	assert( thi );
    int i;

	for( i = 0; i < casillas; i++ )
	{
		if( a->casilla->next == NULL )
        {
            a->casilla = thi->first;
            Banco( a );
        }
        else
        {
            a->casilla = a->casilla->next;
        }
	}
}

/*bool DLL_FindIf( DLL* thi, Item _key )
{
	assert( thi );
	bool found = false;
	for( NodePtr it = thi->first; it != NULL; it = it->next )
	{
		if( _key == it->data )
		{
			found = true;
			break;
		}
	}
	return found;
}*/

/*bool DLL_Search( DLL* thi, Lugar* _key )
{
	assert( thi );
	bool found = false;
	if( DLL_IsEmpty( thi ) != true )
	{
		int x = 0;
		NodePtr or = thi->cursor;
		DLL_CursorFirst( thi );
		while( thi->cursor != NULL )
		{
			DLL_Peek( thi, &x );
			if( _key->precios == x )
			{
				found = true;
				break;
			}
			DLL_CursorNext( thi );
		}
		thi->cursor = or;
		return found;
	}
	else
	{
		return found;
	}
}*/
