#include <stdio.h>
#include <stdlib.h>
#include "EstructurasDatos.h"
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	setlocale(LC_ALL, "spanish");
	int ordenTarjetas[20];
	Pila *cartas;
	cartas = Crear(25,sizeof(int));
	int turnos,i,k,jugadores,dados;
	Jugador *auxiliar,player1,player2,player3,player4, aux;
	Jugador participantes[4] = {player1,player2,player3,player4};
	Cola *Tablero = crearTablero();
	elegirTarjeta(ordenTarjetas);
	for (i=0;i<20;i++){
		PilaPush(cartas,ordenTarjetas[i]);
	}
	printf("\t\t\t\t\t¡Bienvenido a PumaPoly! \n\n¿Cuántos turnos desea jugar? ");
	scanf("%d",&turnos);
	printf("\n¿Cuántos jugadores van a jugar? Máximo 4 por partida: ");
	scanf("%d",&jugadores);
	while(jugadores>4||jugadores<=0){
		printf("Cantidad no valida, solo se puede 1 a 4 jugadores\n");
		scanf("%d",&jugadores);
		}
	system("cls");
	for(i=0;i<jugadores;i++){
		printf("Ingresa el nombre del jugador %d:\n",i+1);
		scanf("%s",participantes[i].nombre);
		participantes[i].casilla =Tablero->inicio;
		participantes[i].propiedades = TADColaCrearC(sizeof(Lugar));
		participantes[i].dinero = 1000;
		participantes[i].dineroFinal = 0;
		system("cls");
		}
	for(i=0;i<turnos;i++){
		system("cls");
		printf("\t\tTurno número %d\n",i+1);
		for(k=0;k<jugadores;k++){
			auxiliar=&(participantes[k]);
			printf("\n%s es tu turno de lanzar los dados\n",auxiliar->nombre);
			printf("Presiona enter para lanzar los dados. ¡Buena suerte!\n");
			system("pause");
			dados = lanzarDados();
			printf("\nAl lanzar los dados has sacado %d y viajaste hasta: \n\n",dados);
			TADColaNavegarC(Tablero, auxiliar,dados);
			imprimircasilla(auxiliar->casilla->TAD, auxiliar,cartas);
			printf("\n------------------------------PumaPoly-------------------------------------\n");
			}
		system("pause");
		}
	system("cls");
	printf("\t\t\tSe han terminado los turnos\nLos resultados son los siguientes:\n");

	for(i=0;i<jugadores;i++){
		participantes[i].dineroFinal += participantes[i].dinero;
	}

	for(i = 0; i < jugadores; i++){
        for(k = i + 1; k < jugadores; k ++){
            if(participantes[i].dineroFinal < participantes[k].dineroFinal){
                aux = participantes[i];
                participantes[i] = participantes[k];
                participantes[k] = aux;
            }
        }
	}
	for(i = 0; i < jugadores; i++){
        printf("%i° lugar: %s\n", i + 1, participantes[i].nombre);
        printf("Dinero total: %i\n", participantes[i].dineroFinal);
	}
}

