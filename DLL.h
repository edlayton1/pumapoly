#ifndef _DLL_INC_
#define _DLL_INC_

#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
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
	char nombre[30]; //Nombre del jugador
	int dinero; //Dinero inicial que tiene
	int dineroFinal; //Suma del dinero con el costo de sus propiedades
	Node* casilla;
	DLL* propiedades;
	//lista de tarjetas
}Jugador;

typedef struct
{
    char nombre[50]; //Nombre del lugar
	char descripcion[200]; //Descripcion general de sitio y area
	Jugador *propietario;  //Jugador  que la tiene
	int renta; //Costo de renta si sólo ha comprado la propiedad y aún no construye casas
	int costo; //Costo de compra
	int costoCasa;//Costo por cada casa adicional
	int area; //Area a la que pertenece
	int numeroCasa; //Numero de casas en propiedad
	int precios[3]; // 0 sin casas,1 con una casa,2 con dos casas
	int status; //0 Casa sin Comprar,1 Comprada,2 Biciestacion,3 Teinda UNAM 
}Lugar;

DLL* DLL_New( size_t tamInfo );

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

void DLL_Traverse( DLL* thi, Jugador* a, int casillas );

/*bool DLL_FindIf( DLL* thi, Lugar* _key );

bool DLL_Search( DLL* thi, Lugar* _key );*/

#endif
