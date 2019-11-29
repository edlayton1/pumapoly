
/**
 * @file Stack.cpp
 * Modulo que contiene las funciones para el Stack de cartas (Pila) .
 */

#include "Stack.hpp"
/**
 * @brief Crea un nuevo Stack.
 * @param capacity: Capacidad que tiene el stack.
 * @return El Stack que acabamos de crear.
 */
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
/**
 * @brief Elimina el stack.
 * @param thi : Dirección del stack que vamos a eliminar.
 * 
 */
void Stack_Delete( Stack *thi )
{
        free( thi->stack );
        free( thi );
}
/**
 * @brief Determina si esta vacio el stack.
 * @param thi : Dirección que tiene el stack que se va a manejar.
 * @return Regresa true si esta vacia.
 */

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
/**
 * @brief Determina si esta lleno el stack.
 * @param thi : Dirección que tiene el stack que se va a manejar.
 * @return Regresa true si esta lleno.
 */
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
/**
 * @brief Ingresa un dato en el stack.
 * @param thi : Dirección que tiene el stack que se va a manejar.
 * @param _data : Datos que se van a agregar al stack.
 * 
 */
void Stack_Push( Stack *thi, int _data )
{
    assert( thi->top < thi->capacity );
    thi->stack[thi->top] = _data;
    thi->top++;
}
/**
 * @brief Saca el dato que esta hasta arriba en el stack.
 * @param thi : Dirección que tiene el stack que se va a manejar.
 * @return Regresa el dato que esta hasta arriba en el stack.
 */
int Stack_Pop( Stack *thi )
{
    assert( thi->top > 0 );
    thi->top--;
    return thi->stack[thi->top];
}
/**
 * @brief Nos regresa el penultimo elemento.
 * @param thi : Dirección que tiene el stack que se va a manejar.
 * @return Regresa el penultimo dato del stack.
 */
int Stack_Peek( Stack *thi )
{
    assert( thi->top > 0 );
    return thi->stack[thi->top - 1];
}
/**
 * @brief Muestra la capacidad que tiene el stack
 * @param thi : Dirección que tiene el stack que se va a manejar.
 * @return Regresa el la capacidad del stack.
 */
size_t Stack_Capacity( Stack *thi )
{
    return thi->capacity;
}
/**
 * @brief Muestra el numero de elementos que tiene agregados por el momento.
 * @param thi : Dirección que tiene el stack qque se va a manejar.
 * @return Regresa el numero de elementos actuales.
 */
size_t Stack_Len( Stack *thi )
{
    return thi->top;
}
/**
 * @brief Vacia el Stack.
 * @param thi : Dirección que tiene el stack qque se va a manejar.
 * 
 */
void Stack_MakeEmpty( Stack *thi )
{
    thi->top = 0;
}

