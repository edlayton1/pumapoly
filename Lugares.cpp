
/**
 * @file Lugares.cpp
 * Modulo que contiene crear el Tablero.
 */


#include "Lugares.hpp"

///
/// \brief Crea el tablero del monopoly
/// 
///

Graph* crearTablero()
{
    Graph* Tablero = new Graph();

    Vertex* Tienda = new Vertex();
    Tienda->name = "Tienda UNAM";
    Tienda->set_descripcion( "Lugar en donde puedes cambiar tus PumaDólares por productos" );
    Tienda->set_status( 3 );
    Tablero->add_vertex( *Tienda );

    Vertex* Metro = new Vertex();
	Metro->name = "Estación de Metro Universidad";
    Metro->set_descripcion( "El transporte más usado por los universitarios para trasladarse, y para llegar tarde a las clases" );
    Metro->set_costo( 650 );
    Metro->set_costoCasa( 200 );
    Metro->set_area( 5 );  //Area 5 que sean todas las areas 
    Metro->set_renta( 100 );
    int precios1[3] = {200, 300, 400};
    Metro->set_precios( precios1 );
    Metro->set_status( 0 );
    Metro->set_numeroCasa( 0 );
    Metro->set_jugador( NULL );
    Tablero->add_vertex( *Metro );

    Vertex* Bicimetro = new Vertex();
    Bicimetro->name = "Bici Estación del Metro CU";
    Bicimetro->set_descripcion( "Una linda estación de Pumabicis" );
    Bicimetro->set_status( 2 );
    Tablero->add_vertex( *Bicimetro );

    Vertex* Veterinaria = new Vertex();
    Veterinaria->name = "Facultad de Medicina Veterinaria y Zootecnia";
    Veterinaria->set_descripcion( "En este lugar puedes montar a caballos y acariciar perritos" );
    Veterinaria->set_costo( 540 );
    Veterinaria->set_costoCasa( 200 );
    Veterinaria->set_area( 2 );
    Veterinaria->set_renta( 100 );
    int precios2[3] = {190, 250, 480};
    Veterinaria->set_precios( precios2 );
    Veterinaria->set_status( 0 );
    Veterinaria->set_numeroCasa( 0 );
    Veterinaria->set_jugador( NULL );
    Tablero->add_vertex( *Veterinaria );

    Vertex* Odontologia = new Vertex();
    Odontologia->name = "Facultad de Odontología";
    Odontologia->set_descripcion( "Facultad dedicada al servicio de la salud bucal, puedes checarte los dientes gratis!" );
    Odontologia->set_costo( 600 );
    Odontologia->set_costoCasa( 200 );
    Odontologia->set_area( 2 );
    Odontologia->set_renta( 50 );
    int precios3[3] = {100, 200, 400};
    Odontologia->set_precios( precios3 );
    Odontologia->set_status( 0 );
    Odontologia->set_numeroCasa( 0 );
    Odontologia->set_jugador( NULL );
    Tablero->add_vertex( *Odontologia );

    Vertex* Medicina = new Vertex();
    Medicina->name = "Facultad de Medicina";
    Medicina->set_descripcion( "Una de las mejores facultades del pais, siempre con compromiso y con pocas horas de sueño" );
    Medicina->set_costo( 950 );
    Medicina->set_costoCasa( 200 );
    Medicina->set_area( 2 );
    Medicina->set_renta( 50 );
    int precios4[3] = {100, 200, 450};
    Medicina->set_precios( precios4 );
    Medicina->set_status( 0 );
    Medicina->set_numeroCasa( 0 );
    Medicina->set_jugador( NULL );
    Tablero->add_vertex( *Medicina );

    Vertex* Bicimedicina = new Vertex();
    Bicimedicina->name = "Bici Estación de Medicina";
    Bicimedicina->set_descripcion( "Una linda estación de Pumabicis" );
    Bicimedicina->set_status( 2 );
    Tablero->add_vertex( *Bicimedicina );

    Vertex* Quimica = new Vertex();
    Quimica->name = "Facultad de Química";
    Quimica->set_descripcion( "La mejor facultad para llegar a ser como Heinserberg" );
    Quimica->set_costo( 600 );
    Quimica->set_costoCasa( 200 );
    Quimica->set_area( 2 );
    Quimica->set_renta( 50 );
    int precios5[3] = {100, 200, 450};
    Quimica->set_precios( precios5 );
    Quimica->set_status( 0 );
    Quimica->set_numeroCasa( 0 );
    Quimica->set_jugador( NULL );
    Tablero->add_vertex( *Quimica );

    Vertex* Ingenieria = new Vertex();
    Ingenieria->name = "Facultad de Ingeniería";
    Ingenieria->set_descripcion( "Una de las primeras facultades en construirse en Ciudad Universitaria, fuente de grandes ideas y personas" );
    Ingenieria->set_costo( 850 );
    Ingenieria->set_costoCasa( 200 );
    Ingenieria->set_area( 1 );
    Ingenieria->set_renta( 50 );
    int precios6[3] = {100, 200, 450};
    Ingenieria->set_precios( precios6 );
    Ingenieria->set_jugador( NULL );
    Ingenieria->set_status( 0 );
    Ingenieria->set_numeroCasa( 0 );
    Tablero->add_vertex( *Ingenieria );

    Vertex* Arquitectura = new Vertex();
    Arquitectura->name = "Facultad de Arquitectura";
    Arquitectura->set_descripcion( "Bella facultad que se encuentra alrededor de las Islas" );
    Arquitectura->set_costo( 280 );
    Arquitectura->set_costoCasa( 200 );
    Arquitectura->set_area( 1 );
    Arquitectura->set_renta( 50 );
    int precios7[3] = {100, 200, 450};
    Arquitectura->set_precios( precios7 );
    Arquitectura->set_status( 0 );
    Arquitectura->set_jugador( NULL );
    Arquitectura->set_numeroCasa( 0 );
    Tablero->add_vertex( *Arquitectura );

    Vertex* Rectoria = new Vertex();
    Rectoria->name = "Torre de rectoría";
    Rectoria->set_descripcion( "Lugar en donde se concentra la mayoria de la población estudiantil durante los paros o marchas" );
    Rectoria->set_costo( 350 );
    Rectoria->set_costoCasa( 200 );
    Rectoria->set_area( 5 );
    int precios8[3] = {50, 150, 400};
    Rectoria->set_precios( precios8 );
    Rectoria->set_status( 0 );
    Rectoria->set_jugador( NULL );
    Rectoria->set_numeroCasa( 0 );
    Tablero->add_vertex( *Rectoria );

    Vertex* Biblioteca = new Vertex();
    Biblioteca->name = "Biblioteca Central";
    Biblioteca->set_descripcion( "La mejor Biblioteca en América Latina, santuario de innumerables libros" );
    Biblioteca->set_costo( 400 );
    Biblioteca->set_costoCasa( 200 );
    Biblioteca->set_area( 5 );
    Biblioteca->set_renta( 50 );
    int precios9[3] = {100, 200, 400};
    Biblioteca->set_precios( precios9 );
    Biblioteca->set_status( 0 );
    Biblioteca->set_jugador( NULL );
    Biblioteca->set_numeroCasa( 0 );
    Tablero->add_vertex( *Biblioteca );

    Vertex* Filosofia = new Vertex();
    Filosofia->name = "Facultad de Filosofía y Letras";
    Filosofia->set_descripcion( "Facultad en donde las malas lenguas dicen que huele particular" );
    Filosofia->set_costo( 200 );
    Filosofia->set_costoCasa( 200 );
    Filosofia->set_area( 3 );
    Filosofia->set_renta( 50 );
    int precios10[3] = {100, 200, 400};
    Filosofia->set_precios( precios10 );
    Filosofia->set_status( 0 );
    Filosofia->set_jugador( NULL );
    Filosofia->set_numeroCasa( 0 );
    Tablero->add_vertex( *Filosofia );

    Vertex* Bicifilosofia = new Vertex();
    Bicifilosofia->name = "Bici Estación de Filosofia";
    Bicifilosofia->set_descripcion( "Una linda estación con Pumabicis" );
    Bicifilosofia->set_status( 2 );
    Tablero->add_vertex( *Bicifilosofia );

    Vertex* Derecho = new Vertex();
    Derecho->name = "Facultad de Derecho";
    Derecho->set_descripcion( "Facultad en donde el traje es una prueba de tu finura" );
    Derecho->set_costo( 270 );
    Derecho->set_costoCasa( 200 );
    Derecho->set_area( 3 );
    Derecho->set_renta( 50 );
    int precios11[3] = {100, 200, 400};
    Derecho->set_precios( precios11 );
    Derecho->set_status( 0 );
    Derecho->set_numeroCasa( 0 );
    Derecho->set_jugador( NULL );
    Tablero->add_vertex( *Derecho );

    Vertex* Economia = new Vertex();
    Economia->name = "Facultad de Economía";
    Economia->set_descripcion( "Facultad con lindo paisaje y excelente ambiente" );
    Economia->set_costo( 290 );
    Economia->set_costoCasa( 200 );
    Economia->set_area( 3 );
    Economia->set_renta( 50 );
    int precios12[3] = {100, 190, 400};
    Economia->set_precios( precios12 );
    Economia->set_status( 0 );
    Economia->set_numeroCasa( 0 );
    Economia->set_jugador( NULL );
    Tablero->add_vertex( *Economia );
   
    Vertex* AnexoIngenieria = new Vertex();
    AnexoIngenieria->name = "Anexo de Ingeniería";
    AnexoIngenieria->set_descripcion( "Gloriosa carcel de conocimientos básicos" );
    AnexoIngenieria->set_costo( 400 );
    AnexoIngenieria->set_costoCasa( 200 );
    AnexoIngenieria->set_area( 1 );
    AnexoIngenieria->set_renta( 100 );
    int precios13[3] = {200, 400, 900};
    AnexoIngenieria->set_precios( precios13 );
    AnexoIngenieria->set_status( 0 );
    AnexoIngenieria->set_jugador( NULL );
    AnexoIngenieria->set_numeroCasa( 0 );
    Tablero->add_vertex( *AnexoIngenieria );

    Vertex* Contaduria = new Vertex();
    Contaduria->name = "Facultad de Contaduría";
    Contaduria->set_descripcion( "Al parecer en este sitio nunca dejan de contar ba dum tss" );
    Contaduria->set_costo( 260 );
    Contaduria->set_costoCasa( 200 );
    Contaduria->set_area( 3 );
    Contaduria->set_renta( 40 );
    int precios14[3] = {100, 190, 400};
    Contaduria->set_precios( precios14 );
    Contaduria->set_status( 0 );
    Contaduria->set_numeroCasa( 0 );
    Contaduria->set_jugador( NULL );
    Tablero->add_vertex( *Contaduria );

    Vertex* Ciencias = new Vertex();
    Ciencias->name = "Facultad de Ciencias";
    Ciencias->set_descripcion( "Facultad antagónica a Ingeniería, pero con deliciosa comida" );
    Ciencias->set_costo( 600 );
    Ciencias->set_costoCasa( 200 );
    Ciencias->set_area( 1 );
    Ciencias->set_renta( 50 );
    int precios15[3] = {90, 200, 400};
    Ciencias->set_precios( precios15 );
    Ciencias->set_numeroCasa( 0 );
    Ciencias->set_status( 0 );
    Ciencias->set_jugador( NULL );
    Tablero->add_vertex( *Ciencias );

    Vertex* BiciCiencias = new Vertex();
    BiciCiencias->name = "Bici Estación de Ciencias";
    BiciCiencias->set_descripcion( "Una linda estación con Pumabicis" );
    BiciCiencias->set_status( 2 );
    Tablero->add_vertex( *BiciCiencias );

    Vertex* Polacas = new Vertex();
    Polacas->name = "Facultad de Ciencias Políticas y Sociales";
    Polacas->set_descripcion( "Facultad con mas izquierda que derecha" );
    Polacas->set_costo( 350 );
    Polacas->set_costoCasa( 200 );
    Polacas->set_area( 3 );
    Polacas->set_renta( 40 );
    int precios16[3] = {100, 220, 400};
    Polacas->set_precios( precios16 );
    Polacas->set_status( 0 );
    Polacas->set_jugador( NULL );
    Polacas->set_numeroCasa( 0 );
    Tablero->add_vertex( *Polacas );

    Vertex* Universum = new Vertex();
    Universum->name = "Museo de las Ciencias de la UNAM (UNIVERSUM)";
    Universum->set_descripcion( "Lugar que todo universitario ha pisado" );
    Universum->set_costo( 500 );
    Universum->set_costoCasa( 200 );
    Universum->set_area( 5 );
    Universum->set_renta( 50 );
    int precios17[3] = {110, 240, 500};
    Universum->set_precios( precios17 );
    Universum->set_status( 0 );
    Universum->set_numeroCasa( 0 );
    Universum->set_jugador( NULL );
    Tablero->add_vertex( *Universum );
   
    Vertex* UnidadP = new Vertex();
    UnidadP->name = "Unidad de Posgrado";
    UnidadP->set_descripcion( "Lugar donde las becas son el pan de todos los dias" );
    UnidadP->set_costo( 580 );
    UnidadP->set_costoCasa( 200 );
    UnidadP->set_area( 5 );
    UnidadP->set_renta( 40 );
    int precios18[3] = {100, 199, 400};
    UnidadP->set_precios( precios18 );
    UnidadP->set_status( 0 );
    UnidadP->set_jugador( NULL );
    UnidadP->set_numeroCasa( 0 );
    Tablero->add_vertex( *UnidadP );

    Tablero->add_edge_directed("Tienda UNAM" , "Estación de Metro Universidad");
    Tablero->add_edge_directed("Estación de Metro Universidad" , "Bici Estación del Metro CU");
    Tablero->add_edge_directed("Bici Estación del Metro CU" , "Facultad de Medicina Veterinaria y Zootecnia");
    Tablero->add_edge_directed("Facultad de Medicina Veterinaria y Zootecnia" , "Facultad de Odontología");
    Tablero->add_edge_directed("Facultad de Odontología" , "Facultad de Medicina");
    Tablero->add_edge_directed("Facultad de Medicina" , "Bici Estación de Medicina");
    Tablero->add_edge_directed("Bici Estación de Medicina" , "Facultad de Química");
    Tablero->add_edge_directed("Facultad de Química" , "Facultad de Ingeniería");
    Tablero->add_edge_directed("Facultad de Ingeniería" , "Facultad de Arquitectura");
    Tablero->add_edge_directed("Facultad de Arquitectura" , "Torre de rectoría");
    Tablero->add_edge_directed("Torre de rectoría" , "Biblioteca Central");
    Tablero->add_edge_directed("Biblioteca Central" , "Facultad de Filosofía y Letras");
    Tablero->add_edge_directed("Facultad de Filosofía y Letras" , "Bici Estación de Filosofia");
    Tablero->add_edge_directed("Bici Estación de Filosofia" , "Facultad de Derecho");
    Tablero->add_edge_directed("Facultad de Derecho" , "Facultad de Economía");
    Tablero->add_edge_directed("Facultad de Economía" , "Anexo de Ingeniería");
    Tablero->add_edge_directed("Anexo de Ingeniería" , "Facultad de Contaduría");
    Tablero->add_edge_directed("Facultad de Contaduría" , "Facultad de Ciencias");
    Tablero->add_edge_directed("Facultad de Ciencias" , "Bici Estación de Ciencias");
    Tablero->add_edge_directed("Bici Estación de Ciencias" , "Facultad de Ciencias Políticas y Sociales");
    Tablero->add_edge_directed("Facultad de Ciencias Políticas y Sociales" , "Museo de las Ciencias de la UNAM (UNIVERSUM)");
    Tablero->add_edge_directed("Museo de las Ciencias de la UNAM (UNIVERSUM)" , "Unidad de Posgrado");
    Tablero->add_edge_directed("Unidad de Posgrado" , "Tienda UNAM");
     
    return Tablero; 
}
