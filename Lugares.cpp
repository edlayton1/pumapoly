#include "Lugares.h"
#include <iostream>
#include <fstream>
#include <vector>

bool read_bin( std::vector <Lugar>& lista )
{
    std::string file_name = "LugaresInfo.bin";
    FILE* file_in = fopen( file_name.c_str(), "rb" );

    if( file_in == NULL ){ std::cout << "El archivo no pudo ser abierto para lectura.\n";
    return false; }
    else
    {
    while(!feof(file_in))
    {
        Lugar a;
        fread(&a, sizeof(Lugar), 1, file_in);

        if(!feof(file_in))
            lista.push_back(a);

    }

    fclose(file_in);
    return true;
    }

}

DLL* crearTablero()
{
    DLL* Tablero = DLL_New( sizeof( Lugar ) );
    std::vector<Lugar> Lugares;

    read_bin(Lugares);

    /*for(auto a : Lugares)
        std::cout << a.nombre << "\n";*/

    for(auto &a : Lugares){
        DLL_InsertBack( Tablero, (void*) &a );
        std::cout << a.nombre << std::endl;
        std::cout << a.descripcion<< std::endl;
    }

    /*Lugar Metro, Bicimetro, Veterinaria, Odontologia, Medicina, Bicimedicina, Quimica, Ingenieria, Arquitectura, Rectoria, Biblioteca, Filosofia, Bicifilosofia, Derecho, Economia, AnexoIngenieria, Contaduria, Ciencias, BiciCiencias, Polacas, Universum, UnidadP, Tienda; 
    //1
    strcpy( Tienda.nombre, "Tienda UNAM" );
    strcpy( Tienda.descripcion, "Lugar en donde puedes cambiar tus PumaDólares por productos" );
    Tienda.status = 3;
    DLL_InsertBack( Tablero, (void*) &Tienda );
    //2
    strcpy( Metro.nombre, "Estación de Metro Universidad" );
	strcpy( Metro.descripcion, "El transporte más usado por los universitarios para trasladarse, y para llegar tarde a las clases" );
    Metro.costo = 650;
    Metro.costoCasa = 200;
    Metro.area = 5; //Area 5 que sean todas las areas 
    Metro.renta = 100;
    Metro.precios[0] = 200;
    Metro.precios[1] = 300;
    Metro.precios[2] = 400;
    Metro.status = 0;
    Metro.numeroCasa = 0;
    Metro.propietario = 0;
    
    DLL_InsertBack (Tablero, (void*) &Metro );
    //3
    strcpy( Bicimetro.nombre , "Bici Estación del Metro CU" );
    strcpy( Bicimetro.descripcion , "Una linda estación de Pumabicis" );
    Bicimetro.status = 2;
    DLL_InsertBack( Tablero, (void*) &Bicimetro );
    //4
    strcpy( Veterinaria.nombre, "Facultad de Medicina Veterinaria y Zootecnia" );
    strcpy( Veterinaria.descripcion, "En esta lugar puedes montar a caballos y acariciar perritos" );
    Veterinaria.costo = 540;
    Veterinaria.costoCasa = 200;
    Veterinaria.area = 2;
    Veterinaria.renta = 100;
    Veterinaria.precios[0] = 190;
    Veterinaria.precios[1] = 250;
    Veterinaria.precios[2] = 480;
    Veterinaria.status = 0;
    Veterinaria.numeroCasa = 0;
    Veterinaria.propietario = 0;
    DLL_InsertBack( Tablero, (void*) &Veterinaria );
    //5
    strcpy( Odontologia.nombre, "Facultad de Odontología" );
    strcpy( Odontologia.descripcion, "Facultad dedicada al servicio de la salud bucal, puedes checarte los dientes gratis!" );
    Odontologia.costo = 600;
    Odontologia.costoCasa = 200;
    Odontologia.area = 2;
    Odontologia.renta = 50;
    Odontologia.precios[0] = 100;
    Odontologia.precios[1] = 200;
    Odontologia.precios[2] = 400;
    Odontologia.status = 0;
    Odontologia.numeroCasa = 0;
    Odontologia.propietario = 0;
    DLL_InsertBack( Tablero, (void*) &Odontologia );
    //6
    strcpy( Medicina.nombre, "Facultad de Medicina" );
    strcpy( Medicina.descripcion, "Una de las mejores facultades del pais, siempre con compromiso y con pocas horas de sueño" );
    Medicina.costo = 950;
    Medicina.costoCasa = 200;
    Medicina.area = 2;
    Medicina.renta = 50;
    Medicina.precios[0] = 100;
    Medicina.precios[1] = 200;
    Medicina.precios[2] = 450;
    Medicina.status = 0;
    Medicina.numeroCasa = 0;
    Medicina.propietario = 0;
    DLL_InsertBack( Tablero, (void*) &Medicina );
    //7
    strcpy( Bicimedicina.nombre, "Bici Estación de Medicina" );
    strcpy( Bicimedicina.descripcion ,"Una linda estación de Pumabicis" );
    Bicimedicina.status = 2;
    DLL_InsertBack( Tablero, (void*) &Bicimedicina );
    //8
    strcpy( Quimica.nombre, "Facultad de Química" );
    strcpy( Quimica.descripcion, "La mejor facultad para llegar a ser como Heinserberg" );
    Quimica.costo = 600;
    Quimica.costoCasa = 200;
    Quimica.area = 2;
    Quimica.renta = 50;
    Quimica.precios[0] = 100;
    Quimica.precios[1] = 200;
    Quimica.precios[2] = 450;
    Quimica.status = 0;
    Quimica.numeroCasa = 0;
    Quimica.propietario = 0;
    DLL_InsertBack( Tablero, (void*) &Quimica );
    //9
    strcpy( Ingenieria.nombre , "Facultad de Ingeniería" );
    strcpy( Ingenieria.descripcion,"Una de las primeras facultades en construirse en Ciudad Universitaria, fuente de grandes ideas y personas" );
    Ingenieria.costo = 850;
    Ingenieria.costoCasa = 200;
    Ingenieria.area = 1;
    Ingenieria.renta = 50;
    Ingenieria.precios[0] = 100;
    Ingenieria.precios[1] = 200;
    Ingenieria.precios[2] = 450;
    Ingenieria.propietario = 0;
    Ingenieria.status = 0;
    Ingenieria.numeroCasa = 0;
    DLL_InsertBack( Tablero, (void*) &Ingenieria );
    //10
    strcpy( Arquitectura.nombre,"Facultad de Arquitectura" );
    strcpy( Arquitectura.descripcion, "Bella facultad que se encuentra alrededor de las Islas" );
    Arquitectura.costo = 280;
    Arquitectura.costoCasa = 200;
    Arquitectura.area = 1;
    Arquitectura.renta = 50;
    Arquitectura.precios[0] = 100;
    Arquitectura.precios[1] = 200;
    Arquitectura.precios[2] = 450;
    Arquitectura.status = 0;
    Arquitectura.propietario = 0;
    Arquitectura.numeroCasa = 0;
    DLL_InsertBack( Tablero, (void*) &Arquitectura );


    strcpy( Rectoria.nombre ,"Torre de rectoría" );
    strcpy( Rectoria.descripcion, "Lugar en donde se concentra la mayoria de la población estudiantil durante los paros o marchas" );
    Rectoria.costo = 350;
    Rectoria.costoCasa = 200;
    Rectoria.area = 5;
    Rectoria.precios[0] = 50;
    Rectoria.precios[1] = 150;
    Rectoria.precios[2] = 400;
    Rectoria.status = 0;
    Rectoria.propietario = 0;
    Rectoria.numeroCasa = 0;
    DLL_InsertBack( Tablero, (void*) &Rectoria );

    strcpy( Biblioteca.nombre ,"Biblioteca Central" );
    strcpy( Biblioteca.descripcion ,"La mejor Biblioteca en América Latina, santuario de innumerables libros" );
    Biblioteca.costo = 400;
    Biblioteca.costoCasa = 200;
    Biblioteca.area = 5;
    Biblioteca.renta = 50;
    Biblioteca.precios[0] = 100;
    Biblioteca.precios[1] = 200;
    Biblioteca.precios[2] = 400;
    Biblioteca.status = 0;
    Biblioteca.propietario = 0;
    Biblioteca.numeroCasa = 0;
    DLL_InsertBack( Tablero, (void*) &Biblioteca );

    strcpy( Filosofia.nombre , "Facultad de Filosofía y Letras" ); 
    strcpy( Filosofia.descripcion, "Facultad en donde las malas lenguas dicen que huele particular" );
    Filosofia.costo = 200;
    Filosofia.costoCasa = 200;
    Filosofia.area = 3;
    Filosofia.renta = 50;
    Filosofia.precios[0] = 100;
    Filosofia.precios[1] = 200;
    Filosofia.precios[2] = 400;
    Filosofia.status = 0;
    Filosofia.propietario = 0;
    Filosofia.numeroCasa = 0;
    DLL_InsertBack( Tablero, (void*) &Filosofia );

    strcpy( Bicifilosofia.nombre, "Bici Estación de Filosofia" );
    strcpy( Bicifilosofia.descripcion, "Una linda estación con Pumabicis" );
    Bicifilosofia.status = 2;
    DLL_InsertBack( Tablero, (void*) &Bicifilosofia );

    strcpy( Derecho.nombre,"Facultad de Derecho" );
    strcpy( Derecho.descripcion, "Facultad en donde el traje es una prueba de tu finura" );
    Derecho.costo = 270;
    Derecho.costoCasa = 200;
    Derecho.area = 3;
    Derecho.renta = 50;
    Derecho.precios[0] = 100;
    Derecho.precios[1] = 200;
    Derecho.precios[2] = 400;
    Derecho.status = 0;
    Derecho.numeroCasa = 0;
    Derecho.propietario = 0;
    DLL_InsertBack( Tablero, (void*) &Derecho );

    strcpy( Economia.nombre, "Facultad de Economía" );
    strcpy( Economia.descripcion, "Facultad con lindo paisaje y excelente ambiente" );
    Economia.costo = 290;
    Economia.costoCasa = 200;
    Economia.area = 3;
    Economia.renta = 50;
    Economia.precios[0] = 100;
    Economia.precios[1] = 190;
    Economia.precios[2] = 400;
    Economia.status = 0;
    Economia.numeroCasa = 0;
    Economia.propietario = 0;
    DLL_InsertBack( Tablero, (void*) &Economia );
    
    strcpy( AnexoIngenieria.nombre, "Anexo de Ingeniería" );
    strcpy( AnexoIngenieria.descripcion, "Gloriosa carcel de conocimientos básicos" );
    AnexoIngenieria.costo = 400;
    AnexoIngenieria.costoCasa = 200;
    AnexoIngenieria.area = 1;
    AnexoIngenieria.renta = 100;
    AnexoIngenieria.precios[0] = 200;
    AnexoIngenieria.precios[1] = 400;
    AnexoIngenieria.precios[2] = 900;
    AnexoIngenieria.status = 0;
    AnexoIngenieria.propietario = 0;
    AnexoIngenieria.numeroCasa = 0;
    DLL_InsertBack( Tablero, (void*) &AnexoIngenieria );

    strcpy( Contaduria.nombre ,"Facultad de Contaduría" );
    strcpy( Contaduria.descripcion ,"Al parecer en este sitio nunca dejan de contar ba dum tss" );
    Contaduria.costo = 260;
    Contaduria.costoCasa = 200;
    Contaduria.area = 3;
    Contaduria.renta = 40;
    Contaduria.precios[0] = 100;
    Contaduria.precios[1] = 190;
    Contaduria.precios[2] = 400;
    Contaduria.status = 0;
    Contaduria.numeroCasa = 0;
    Contaduria.propietario = 0;
    DLL_InsertBack( Tablero, (void*) &Contaduria );

    strcpy( Ciencias.nombre , "Facultad de Ciencias" );
    strcpy( Ciencias.descripcion , "Facultad antagónica a Ingeniería, pero con deliciosa comida" );
    Ciencias.costo = 600;
    Ciencias.costoCasa = 200;
    Ciencias.area = 1;
    Ciencias.renta = 50;
    Ciencias.precios[0] = 90;
    Ciencias.precios[0] = 200;
    Ciencias.precios[0] = 400;
    Ciencias.numeroCasa = 0;
    Ciencias.status = 0;
    Ciencias.propietario = 0;
    DLL_InsertBack( Tablero, (void*) &Ciencias );

    strcpy( BiciCiencias.nombre, "Bici Estación de Ciencias" );
    strcpy( BiciCiencias.descripcion, "Una linda estación con Pumabicis" );
    BiciCiencias.status = 2;
    DLL_InsertBack( Tablero, (void*) &BiciCiencias );

    strcpy( Polacas.nombre, "Facultad de Ciencias Políticas y Sociales" );
    strcpy( Polacas.descripcion , "Facultad con mas izquierda que derecha" );
    Polacas.costo = 350;
    Polacas.costoCasa = 200;
    Polacas.area = 3;
    Polacas.renta = 40;
    Polacas.precios[0] = 100;
    Polacas.precios[1] = 220;
    Polacas.precios[2] = 400;
    Polacas.status = 0;
    Polacas.propietario = 0;
    Polacas.numeroCasa = 0;
    DLL_InsertBack( Tablero, (void*) &Polacas );

    strcpy( Universum.nombre, "Museo de las Ciencias de la UNAM (UNIVERSUM)" );
    strcpy( Universum.descripcion, "Lugar que todo universitario ha pisado" );
    Universum.costo = 500;
    Universum.costoCasa = 200;
    Universum.area = 5;
    Universum.renta = 50;
    Universum.precios[0] = 110;
    Universum.precios[1] = 240;
    Universum.precios[2] = 500;
    Universum.status = 0;
    Universum.numeroCasa = 0;
    Universum.propietario = 0;
    DLL_InsertBack( Tablero, (void*) &Universum );
    
    strcpy( UnidadP.nombre, "Unidad de Posgrado" );
    strcpy( UnidadP.descripcion, "Lugar donde las becas son el pan de todos los dias" );
    UnidadP.costo = 580;
    UnidadP.costoCasa = 200;
    UnidadP.area = 5;
    UnidadP.renta = 40;
    UnidadP.precios[0] = 100;
    UnidadP.precios[1] = 199;
    UnidadP.precios[2] = 400;
    UnidadP.status=0;
    UnidadP.propietario = 0;
    UnidadP.numeroCasa = 0;
    DLL_InsertBack( Tablero, (void*) &UnidadP );
    */
    return Tablero; 
}
