#ifndef _DLL_INC_
#define _DLL_INC_

/**
 * @file DLL.hpp
 * Modulo que contiene las declaraciones de funciones y atributos de las DLL.
 */

#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<stdbool.h>
#include<assert.h>

typedef struct Node
{
	void* data;
	struct Node* next;
	struct Node* prev;
} Node;

typedef Node* NodePtr;

typedef struct DLL
{
	NodePtr first;
	NodePtr last;
	NodePtr cursor;
    size_t TADtam;
	size_t len;
}DLL;

typedef struct
{
    int id;
    std::string nombre = ""; //Nombre del jugador
	int dinero; //Dinero inicial que tiene
	int dineroFinal; //Suma del dinero con el costo de sus propiedades
    std::string casilla;
	DLL* propiedades;
	//lista de tarjetas
}Jugador;

typedef int Item;
enum{ ASCENDING, DESCENDING };

void print( Item list[], size_t tam, char* msg );

void swap( Jugador* val1, Jugador* val2 );

DLL* DLL_New();

void DLL_Delete( DLL* thi );

bool DLL_InsertFront( DLL* thi, void* _data );

bool DLL_InsertBack( DLL* thi, void* _data );

bool DLL_RemoveFront( DLL* thi, void* _data_back );

bool DLL_RemoveBack( DLL* thi, void* _data_back );

size_t DLL_Len( DLL* thi );

bool DLL_IsEmpty( DLL* thi );

void DLL_MakeEmpty( DLL* thi );

bool DLL_Peek( DLL* thi, void* _data_back );

void DLL_CursorFirst( DLL* thi );

void DLL_CursorLast( DLL* thi );

void DLL_CursorPrev( DLL* thi );

void DLL_CursorNext( DLL* thi );

#endif
