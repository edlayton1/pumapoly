/** @file Monopoly.cpp
 * Modulo que contiene las funciones propias de un monopoly.
 */


#include "Monopoly.hpp"
#include <iostream>
#include<stdio.h>
#include <omp.h>

/**
 * @fn lanzarDados
 * @brief De manera random elige un numero del 1 al 6
 * @return Devuelve un numero entero del 1 al 6
 */
int lanzarDados()
{
    srand( time( NULL ) );
    int opcion = rand() % 7+1;
    
    return opcion;
}
/**
 * @brief rellena la lista de tarjetas 
 * @param tarjetas la lista de tarjetas de suerte
 */
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
/**
 * @brief Rellena el stack de tarjetas.
 * @param cartas Stack de tarjetas a rellenar.
 */
void rellenarStack(Stack* cartas){
    int ordenTarjetas[21],i;
    elegirTarjeta( ordenTarjetas );
    
    #pragma omp parallel for private (i) shared (ordenTarjetas,cartas)
        for( i = 0; i < 21; i++ )
        {
            Stack_Push( cartas, ordenTarjetas[i] );
        }

}

/**
 * 
 * @brief Imprime las diversas casillas
 * @param e Casilla en la que cae, o jugador que cae en la casilla, cartas lista de cartas
 */

void imprimirCasilla( Vertex* e, Jugador* o, Stack* cartas )
{
    auto a = e;
    Jugador* j = o;
    int tarjeta;
    int des;
    int casaExtra;

    std::cout << "\t\t" << a->get_name() << "\n";
    std::cout << "\t" << a->get_descripcion() << "\n";

    if( a->get_status() == 1 )
    {
        if( a->get_jugador() == j )
        {
            std::cout << "Este lugar es tuyo\n";

            if( a->get_numeroCasa() < 3 )
            {
                std::cout << "Cuentas con: " << j->dinero << " PumaDolares\nEl precio por una casa adicional es " << a->get_costoCasa();
                std::cout << "¿Deseas comprar otra casa?\n1)Si\n2)No\n";
                std::cin >> des;

                if( des == 1 )
                {
                    casaExtra = 1;
                    comprarLugar( j, a, casaExtra );
                }
            }
        }
        else
        {
            if( a->get_numeroCasa() > 0 )
            {
                std::cout << "Ups has caído en un lugar con propietario deberás pagar " << a->get_precios()[a->get_numeroCasa()] << " PumaDolares";
				j->dinero = j->dinero - a->get_precios()[a->get_numeroCasa()];
				a->get_jugador()->dinero +=  a->get_precios()[a->get_numeroCasa()];
            }
            else
            {
                std::cout << "Ups has caído en un lugar con propietario deberás pagar " << a->get_renta() << " PumaDolares";
				j->dinero = j->dinero - a->get_renta();
				a->get_jugador()->dinero += a->get_renta();
            }
        }
    }
    else
    {
        if( a->get_status() == 2 )
        {

            tarjeta = Stack_Pop( cartas );
            std::cout << "\n¡Esta es una casilla de tarjeta!\nTu suerte es la siguiente:\n\n";
            Seleccion( tarjeta, j );

            
        }
        else
        {
            if( a->get_status() == 0 )
            {
                std::cout << "\nEl costo de la propiedad es de: " << a->get_costo() << " Pumadolares\nCuentas con: " << j->dinero << " PumaDolares";
                std::cout << "\nDeseas comprar la propiedad?\n1)Si\n2)No\n";
                std::cin >> des;
			    
                if( des == 1 )
                {
				    casaExtra = 0;
				    comprarLugar( j,a, casaExtra );
			    }
            }
        }
    }
}

/**
 * 
 * @brief Compra la casilla y la agrega como propiedad
 * @param a jugador que comprara, l propiedad, casaExtra dice que si quiere comprar otra casa
 */
void comprarLugar( Jugador* a, Vertex* l, int casaExtra )
{
    if( casaExtra )
    {
		if( a->dinero < l->get_costoCasa() )
        {
            std::cout << "No cuentas con el dinero suficiente";
		    return;
		}
		
        a->dinero = a->dinero - l->get_costoCasa();
		l->set_numeroCasa( l->get_numeroCasa() + 1 );
		a->dineroFinal += l->get_costoCasa();
		
        std::cout << "¡Ahora tienes una casa adicional!";
	}
	else
    {
		if( a->dinero < l->get_costo() )
        {
            std::cout << "No cuentas con el dinero suficiente";
		    return;
		}

		DLL_InsertBack( a->propiedades, (void*)l );
		
        a->dinero = a->dinero - l->get_costo();
		l->set_jugador( a );
		l->set_status( 1 );
		a->dineroFinal += l->get_costo();
	    
        std::cout << "¡Ahora tienes una propiedad nueva!";
	}
}
///
/// \brief Le da al jugador dinero si llega a Tienda UNAM
/// \param Jugador a quien se le sumara dinero
///
void Banco( Jugador* A )
{
    std::cout << "\n\t\t¡" << A->nombre << " recorriste todo CU y has pasado de nuevo a la Tienda UNAM por lo que ganas 500 PumaDólares!\n\t\tCuentas con " << (A->dinero += 500) << " PumaDólares\n";
}

///
/// \brief Dependiendo de la tarjeta lleva a cabo un efecto
/// \param tarjeta el numero de tarjeta que se llevara a cabo, a Jugador al que se le aplica
///
void Seleccion( int tarjeta, Jugador* a )
{
    switch( tarjeta )
    {
	    case 1:
        {
            std::cout << "El rector te condenó enérgicamente. Pierdes 50 PumaDólares";
		    a->dinero -= 50;
	        break;
        }
	    case 2:
        {
            std::cout << "Don Rata te dio mal el cambio.¡Ganas 200 PumaDólares!";
		    a->dinero += 200;
	        break;
        }
	    case 3:
        {
            std::cout << "Invitaste a la niña que te gusta al Universum.\nPierdes 250 PumaDólares.\nTambién fuiste Friendzoneado...";
		    a->dinero -= 250;
	        break;
        }
	    case 4:
        {
            std::cout << "Pasas a comer a Ciencias y te dan Paperas. Te indemnizan con 150 PumaDólares.";
		    a->dinero += 150;
	        break;
        }
	    case 5:
        {
		    std::cout << "Pasabas por el estacionamiento de ingeniería y te cayó una camioneta del cielo, ganas 200 PumaDólares por el seguro contra accidentes del estacionamiento de Ingeniería";
		    a->dinero += 200;
	        break;
        }
	    case 6:
        {
		    std::cout << "Estabas en las islas pero llegaron los porros y te quitaron 100 PumaDólares.";
		    a->dinero -= 100;
	        break;
        }
	    case 7:
        {
		    std::cout << "La bicipuma en donde ibas no tenía frenos, para que no digas nada te sobornan con 200 PumaDólares. Eso puede que cure tus heridas.";
		    a->dinero += 200;
	        break;
        }
	    case 8:
        {
		    std::cout << "Reprobaste todas tus materias. Vas a tomar tanto que gastas 400 PumaDólares.";
		    a->dinero -= 400;
	        break;
        }
	    case 9:
        {
		    std::cout << "Decidiste ir a moto por cerveza, pero tu amigo te abandonó y te robaron tu mochila. Ganas 100 PumaDólares de tu amigo porque se siente culpable";
		    a->dinero += 100;
	        break;
        }
	    case 10:
        {
		    std::cout << "Tu amigo el foráneo te invita a una fiesta en su casa. ¡Él invita! Aquí tienes 150 PumaDólares por ser como la familia que extraña";
		    a->dinero += 150;
	        break;
        }
	    case 11:
        {
		    std::cout << "No le entiendes a Álgebra Lineal, decides pagar cursos que cuestan 100 PumaDólares.";
		    a->dinero -= 100;
	        break;
        }
	    case 12:
        {
		    std::cout << "Estás en las islas y decides comprar panquesitos, tienes el viaje de tu vida pero te roban todo. Pierdes 100 PumaDólares pero ganas diversión";
		    a->dinero -= 100;
	        break;
        }
	    case 13:
        {
		    std::cout << "Te fue muy bien este semestre ganas 200 PumaDólares, pero te quitamos 50 por barquear.";
		    a->dinero += 150;
	        break;
        }
	    case 14:
        {
		    std::cout << "¡Oh no! te acercaste al Che y te robaron tu mochila, pierdes 100 PumaDólares.";
		    a->dinero -= 150;
	        break;
        }
	    case 15:
        {
		    std::cout << "Vas a nadar a la alberca pero el agua está verde. La DGAS te da 100 PumaDólares para evitar tu muerte";
		    a->dinero += 100;
	        break;
        }
	    case 16:
        {
		    std::cout << "Seguridad UNAM te sorprende en tus actos ilegales. Pero no te preocupes, no pasa nada. Aquí tienes 70 PumaDólares para que continúes";
		    a->dinero += 70;
	        break;
        }
        case 17:
        {
		    std::cout << "Por tu gran desempeño ganas una beca. ¡Ganas 590 PumaDólares! ";
		    a->dinero += 590;
            break;
        }
	    case 18:
        {
		    std::cout << "Por impuntual dejaste mal estacionado tu carro. Le dan un balonazo y además se lo lleva la PumaGrúa. Paga 300 PumaDólares Para reparar los daños";
		    a->dinero -= 300;
	        break;
        }
	    case 19:
        {
		    std::cout << "Estás en el caracol del metrobús Ciudad Universitaria. Te desesperas porque llevas prisa y te avientas, pero te rompes la pierna. Pierdes 50 PumaDólares en costos médicos";
		    a->dinero -= 50;
	        break;
        }
	    case 20:
        {
		    std::cout << "Hiciste todo el trabajo de tu equipo sin ayuda. Entre todos te dan 600 PumaDólares para que no los saques del equipo";
		    a->dinero += 600;
	        break;
        }
	    case 21:
        {
		    std::cout << "¡Felicidades hoy es tu cumpleaños! Toma 400 PumaDólares para celebrar con tus amigos";
		    a->dinero += 400;
	        break;
        }
	    default:
        {
		    break;
        }
	}
}
