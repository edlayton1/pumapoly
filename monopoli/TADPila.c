// Programa para simular una pila de cartas
//Creaccion de la Pila
#include "EstructurasDatos.h"
#include <stdio.h>
#include <stdlib.h>
//Creacion del tipo Pila
Pila *Crear(int n,size_t tam){
	Pila *Ap;
	Ap = malloc(sizeof(Pila));
	Ap->v = malloc(tam);
	Ap->capacidad = n;
	Ap->top = -1;
	Ap->err = 0;
	return Ap;
}
int PilaVacia(Pila *p){
	if (p->top == -1)
	return 1;
	return 0;
}
int PilaLlena(Pila *p){
	return p->top == p->capacidad-1 ?1:0;
}
void PilaPush(Pila *p, int x){
	if(PilaLlena(p) == 1 ){
		p->capacidad+=10;
		p->v= realloc(p->v,sizeof(int)*(p->capacidad));
	}
	p->top = p->top+1;
	p->v[p->top] = x;
}

int PilaPop(Pila *p){
	int t;
	if(PilaVacia(p)){
	 p->err = 1;
	 return 0;
	}
	t = p->v[p->top];
	p->top= p->top-1;
	return t;
}

