#include "Stack.h"

Stack *Stack_New( size_t _capacity )
{
	Stack * s = (Stack*)malloc(sizeof(Stack));
    if( NULL != s )
	{
        s->stack = (int *)malloc(_capacity * sizeof(int));
		if( NULL == s->stack )
		{
			free(s); 
			s = NULL; 
		}
        else
		{
            s->top = 0;
            s->capacity = _capacity;
        }
    }
    	return s;
}

void Stack_Delete( Stack *thi )
{
    	free( thi->stack );
    	free( thi );
}

bool Stack_IsEmpty( Stack *thi )
{
	if( thi->top == 0 )
	{
    		return true;
	}
	else
	{
		return false;
	}
}

bool Stack_IsFull( Stack *thi )
{
	if( thi->top == thi->capacity )
    {
		return true;
	}
	else
	{
		return false;
	}
}

void Stack_Push( Stack *thi, int _data )
{
    assert( thi->top < thi->capacity );
    thi->stack[thi->top] = _data;
    thi->top++;
}

int Stack_Pop( Stack *thi )
{
    assert( thi->top > 0 );
    thi->top--;
    return thi->stack[thi->top];
}

int Stack_Peek( Stack *thi )
{
    assert( thi->top > 0 );
    return thi->stack[thi->top - 1];
}

size_t Stack_Capacity( Stack *thi )
{
    return thi->capacity;
}

size_t Stack_Len( Stack *thi )
{
    return thi->top;
}

void Stack_MakeEmpty( Stack *thi )
{
    thi->top = 0;
}

