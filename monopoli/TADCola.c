#include <stdio.h>
#include "EstructurasDatos.h"
#include <string.h>
#include <stdlib.h>
// Funciones del tipo de dato abstracto Cola doblemente ligada//
Nodo *nodoNuevo(void *info, size_t tam) {
    Nodo *nodo;
    nodo = malloc(sizeof(Nodo));
    nodo->TAD = malloc(tam);
    memcpy(nodo->TAD, info, tam);
    nodo->ant = NULL;
    nodo->sig = NULL;
    return nodo;
}

Cola *TADColaCrearC(size_t tamInfo) {
    Cola *cola;
    cola = malloc(sizeof(Cola));
    cola->TADTam = tamInfo;
    cola->inicio = NULL;
    cola->fin = NULL;
    return cola;
}
int TADColaVacia(Cola *cola) {
    return cola->inicio == NULL || cola->fin == NULL;
}
// --- Doble Nodo ---
void TADColaAgregarC(Cola *cola,void *info) {
    Nodo *nuevo;
    if (info==NULL) {
        printf("ERROR (TADCola.c) TADColaAgregar: Se ha intentado agregar a la lista un apuntador NULL\n");
        printf("Sistema detenido");
        exit(0);
    }
    nuevo = nodoNuevo(info,cola->TADTam);
    if (TADColaVacia(cola)) {
        cola->inicio = nuevo;
        cola->fin = nuevo;
        cola->fin->sig = NULL;
        cola->fin->ant = NULL;
        cola->inicio->ant = NULL;
        cola->inicio->sig = NULL;
        return;
    }
    cola->fin->sig = nuevo;
    nuevo->ant = cola->fin;
	cola->fin = nuevo;

}
// --- Doble Nodo ---
int TADColaRetirar(Cola *cola, void *info) {
    Nodo *p,*q;
    if (TADColaVacia(cola)) {
        return 0;
    }
    if (cola->inicio==cola->fin) {
        p = cola->inicio;
        cola->inicio = NULL;
        cola->fin = NULL;

    } else {

        p = cola->inicio;
        q = p->sig;
        cola->inicio=q;
        q->ant = NULL;
    }
    memcpy(info,p->TAD,cola->TADTam);
    free(p);
    return 1;
}

void TADColaIterar(Cola *cola, void (funcion)(void *TAD, int *suma), int *sumaT) {
    Nodo *p;
    p = cola->inicio;
    while (p!=NULL) {
        (*funcion)(p->TAD, sumaT);
        p = p->sig;
    }
}

void TADColaNavegarC(Cola *Tablero, Jugador *a,int casillas){
	int i;
	for (i=0;i<casillas;i++){
		if(a->casilla->sig == NULL){
			a->casilla = Tablero->inicio;
			Banco(a);
		}
		else
			a->casilla = a->casilla->sig;
	}
}
