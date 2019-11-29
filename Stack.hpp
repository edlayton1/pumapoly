#ifndef _PILA_INC_
#define _PILA_INC_

/**
 * @file Stack.hpp
 * Modulo que contiene las declaraciones del stack y de sus funciones.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int *stack;
    size_t top;
    size_t capacity;
} Stack;

Stack* Stack_New( size_t _capacity );

void Stack_Delete( Stack *thi );

void Stack_MakeEmpty( Stack *thi );

void Stack_Push( Stack *thi, int _val );

int Stack_Pop( Stack *thi );

int Stack_Peek( Stack *thi );

bool Stack_IsEmpty( Stack *thi );

bool Stack_IsFull( Stack *thi );

size_t Stack_Len( Stack *thi );

size_t Stack_Capacity( Stack *thi );

#endif

