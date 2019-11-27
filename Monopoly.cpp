#include "Monopoly.h"

int lanzarDados()
{
    srand( time( NULL ) );
    int opcion = rand() % 7+1;
    return opcion;
}

void imprimirCasilla( void* e, Jugador* o, Stack* cartas )
{
    Lugar* a = (Lugar*)e;
    Jugador* j = o;
    int tarjeta;
    int des;
    int casaExtra;

    printf( "\t\t%s\n",a->nombre );
	printf( "\t%s\n",a->descripcion );

    if( a->status == 1 )
    {
        if( a->propietario == j )
        {
            printf( "Este lugar es tuyo\n" );

            if( a->numeroCasa < 3 )
            {
                printf( "Cuentas con: %d PumaDolares\nEl precio por una casa adicional es %d", j->dinero, a->costoCasa );
				printf( "¿Deseas comprar otra casa?\n1)Sí\n2)No\n" );
				scanf( "%d", &des );

                if( des == 1 )
                {
                    casaExtra = 1;
                    comprarLugar( j, a, casaExtra );
                }
            }
        }
        else
        {
            if( a->numeroCasa > 0 )
            {
                printf( "Ups has caído en un lugar con propietario deberás pagar %d PumaDólares", a->precios[a->numeroCasa] );
				j->dinero = j->dinero - a->precios[a->numeroCasa];
				a->propietario->dinero +=  a->precios[a->numeroCasa];
            }
            else
            {
                printf( "Ups has caído en un lugar con propietario deberás pagar %d PumaDólares", a->renta );
				j->dinero = j->dinero - a->renta;
				a->propietario->dinero += a->renta;
            }
        }
    }
    else
    {
        if( a->status == 2 )
        {
            tarjeta = Stack_Pop( cartas );
		    printf( "\n¡Esta es una casilla de tarjeta!\nTu suerte es la siguiente:\n\n" );
		    Seleccion( tarjeta, j );
        }
        else
        {
            if( a->status == 0 )
            {
                printf( "\nEl costo de la propiedad es de: %d PumaDolares\nCuentas con: %d PumaDolares", a->costo, j->dinero );
			    printf( "\nDeseas comprar la propiedad?\n1)Si\n2)No\n" );
			    scanf( "%d", &des );
			    
                if( des == 1 )
                {
				    casaExtra = 0;
				    comprarLugar( j,a, casaExtra );
			    }
            }
        }
    }
}

void comprarLugar( Jugador* a, Lugar* l, int casaExtra )
{
    if( casaExtra )
    {
		if( a->dinero < l->costoCasa )
        {
		    printf( "No cuentas con el dinero suficiente"   );
		    return;
		}
		
        a->dinero = a->dinero - l-> costoCasa;
		l->numeroCasa += 1;
		a->dineroFinal += l-> costoCasa;
		
        printf( "¡Ahora tienes una casa adicional!" );
	}
	else
    {
		if( a->dinero < l->costo )
        {
		    printf( "No cuentas con el dinero suficiente" );
		    return;
		}

		DLL_InsertBack( a->propiedades, (void*)l );
		
        a->dinero = a->dinero - l->costo;
		l->propietario = a;
		l->status = 1;
		a->dineroFinal += l->costo;
	    
        printf( "¡Ahora tienes una propiedad nueva!" );
	}
}

void Banco( Jugador* A )
{
    printf( "\n\t\t¡%s recorriste todo CU y has pasado de nuevo a la Tienda UNAM por lo que ganas 500 PumaDólares!\n Cuentas con %d pumadolares \n", A->nombre, A->dinero += 500 );
	A->dinero += 500; 
}

void elegirTarjeta( int tarjetas[] )
{
    int aux = 0,i;
    srand( time( NULL ) );
#pragma omp parallel for private(aux) shared(i,tarjetas)
    for( i = 0; i < 21; i++ )
    {
        aux = (1 + rand() % 21);
        int aux2 = 0;
        
        while( aux2 < i )
        {
            if( aux != tarjetas[aux2] )
            {
                aux2++;
            }
            else
            {
                aux = (1 + rand() % 21);
                aux2 = 0;
            }
        }

        tarjetas[i] = aux;
    }
}

void Seleccion( int tarjeta, Jugador* a )
{
    switch( tarjeta )
    {
	    case 1:
        {
		    printf("El rector te condenó enérgicamente. Pierdes 50 PumaDólares");
		    a->dinero -= 50;
	        break;
        }
	    case 2:
        {
		    printf("Don Rata te dio mal el cambio.¡Ganas 200 PumaDólares!");
		    a->dinero += 200;
	        break;
        }
	    case 3:
        {
		    printf("Invitaste a la niña que te gusta al Universum.\nPierdes 250 PumaDólares.\nTambién fuiste Friendzoneado...");
		    a->dinero -= 250;
	        break;
        }
	    case 4:
        {
		    printf("Pasas a comer a Ciencias y te dan Paperas. Te indemnizan con 150 PumaDólares.");
		    a->dinero += 150;
	        break;
        }
	    case 5:
        {
		    printf("Pasabas por el estacionamiento de ingeniería y te cayó una camioneta del cielo, ganas 200 PumaDólares por el seguro contra accidentes del estacionamiento de Ingeniería");
		    a->dinero += 200;
	        break;
        }
	    case 6:
        {
		    printf("Estabas en las islas pero llegaron los porros y te quitaron 100 PumaDólares.");
		    a->dinero -= 100;
	        break;
        }
	    case 7:
        {
		    printf("La bicipuma en donde ibas no tenía frenos, para que no digas nada te sobornan con 200 PumaDólares. Eso puede que cure tus heridas.");
		    a->dinero += 200;
	        break;
        }
	    case 8:
        {
		    printf("Reprobaste todas tus materias. Vas a tomar tanto que gastas 400 PumaDólares.");
		    a->dinero -= 400;
	        break;
        }
	    case 9:
        {
		    printf("Decidiste ir a moto por cerveza, pero tu amigo te abandonó y te robaron tu mochila. Ganas 100 PumaDólares de tu amigo porque se siente culpable");
		    a->dinero += 100;
	        break;
        }
	    case 10:
        {
		    printf("Tu amigo el foráneo te invita a una fiesta en su casa. ¡Él invita! Aquí tienes 150 PumaDólares por ser como la familia que extraña");
		    a->dinero += 150;
	        break;
        }
	    case 11:
        {
		    printf("No le entiendes a Álgebra Lineal, decides pagar cursos que cuestan 100 PumaDólares.");
		    a->dinero -= 100;
	        break;
        }
	    case 12:
        {
		    printf("Estás en las islas y decides comprar panquesitos, tienes el viaje de tu vida pero te roban todo. Pierdes 100 PumaDólares pero ganas diversión");
		    a->dinero -= 100;
	        break;
        }
	    case 13:
        {
		    printf("Te fue muy bien este semestre ganas 200 PumaDólares, pero te quitamos 50 por barquear.");
		    a->dinero += 150;
	        break;
        }
	    case 14:
        {
		    printf("¡Oh no! te acercaste al Che y te robaron tu mochila, pierdes 100 PumaDólares.");
		    a->dinero -= 150;
	        break;
        }
	    case 15:
        {
		    printf("Vas a nadar a la alberca pero el agua está verde. La DGAS te da 100 PumaDólares para evitar tu muerte");
		    a->dinero += 100;
	        break;
        }
	    case 16:
        {
		    printf("Seguridad UNAM te sorprende en tus actos ilegales. Pero no te preocupes, no pasa nada. Aquí tienes 70 PumaDólares para que continúes");
		    a->dinero += 70;
	        break;
        }
        case 17:
        {
		    printf("Por tu gran desempeño ganas una beca. ¡Ganas 590 PumaDólares! ");
		    a->dinero += 590;
            break;
        }
	    case 18:
        {
		    printf("Por impuntual dejaste mal estacionado tu carro. Le dan un balonazo y además se lo lleva la PumaGrúa. Paga 300 PumaDólares Para reparar los daños");
		    a->dinero -= 300;
	        break;
        }
	    case 19:
        {
		    printf("Estás en el caracol del metrobús Ciudad Universitaria. Te desesperas porque llevas prisa y te avientas, pero te rompes la pierna. Pierdes 50 PumaDólares en costos médicos");
		    a->dinero -= 50;
	        break;
        }
	    case 20:
        {
		    printf("Hiciste todo el trabajo de tu equipo sin ayuda. Entre todos te dan 600 PumaDólares para que no los saques del equipo");
		    a->dinero += 600;
	        break;
        }
	    case 21:
        {
		    printf("¡Felicidades hoy es tu cumpleaños! Toma 400 PumaDólares para celebrar con tus amigos");
		    a->dinero += 400;
	        break;
        }
	    default:
        {
		    break;
        }
	}
}
