#ifndef ESTRUCTURASDATOS_H_INCLUDED
#define ESTRUCTURASDATOS_H_INCLUDED
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
//Pila
struct TADPILA{
	int top;
	int capacidad;
	int *v;
	int err;
};
typedef struct TADPILA Pila;
//Cola Doblemente Ligada

struct NODO {
    void *TAD;
    struct NODO *ant;
    struct NODO *sig;
};
typedef struct NODO Nodo;

struct TADCOLA {
    size_t TADTam;
    Nodo *inicio;
    Nodo *fin;
};
typedef struct TADCOLA Cola;

struct Jugador{
	int id;
	char nombre[30]; //Nombre del jugador
	int dinero; //Dinero inicial que tiene
	int dineroFinal; //Suma del dinero con el costo de sus propiedades
	Nodo *casilla;
	Cola *propiedades;
	//lista de tarjetas
};
typedef struct Jugador Jugador;

struct Lugar{
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
	};
typedef struct Lugar Lugar;


Nodo *nodoNuevo(void *info, size_t tam);
Cola *TADColaCrear(size_t tamInfo);
int TADColaVacia(Cola *cola);
void TADColaAgregar(Cola *cola,void *info);
int TADColaRetirar(Cola *cola, void *info);
void TADColaIterar(Cola *cola, void (funcion)(void *TAD, int *suma), int *sumaT);
Nodo *nodoNuevoC(void *info, size_t tam);
Cola *TADColaCrearC(size_t tamInfo);
int TADColaVaciaC(Cola *cola);
void TADColaAgregarC(Cola *cola,void *info);
int TADColaRetirarC(Cola *cola, void *info);
void TADColaIterarC(Cola *cola, void (funcion)(void *TAD));
Pila *Crear(int n,size_t tam);
int PilaVacia(Pila *p);
int PilaLlena(Pila *p);
void PilaPush(Pila *p, int x);
int PilaPop(Pila *p);
int elegirTarjeta(int tarjetas[]);
int elegirTarjeta();
void Seleccion(int tarjeta,Jugador *a);
void Tarjeta1();
void Tarjeta2();
void Tarjeta3();
void Tarjeta4();
void Tarjeta5();
int lanzarDados();
void avanzar(Cola *tablero,int movimientos,int jugador);
void comprarLugar(Jugador *a,Lugar *l, int casaExtra);
void imprimircasilla(void *e,Jugador *o,Pila *cartas);
Cola *crearTablero();

#endif


