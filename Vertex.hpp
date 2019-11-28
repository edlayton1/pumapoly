#ifndef _VERTEX_INC_
#define _VERTEX_INC_

#include<iostream>
#include<string>
#include<algorithm>
#include<list>
#include<vector>
#include<array>
#include<map>
#include<stdbool.h>
#include<assert.h>
#include "DLL.hpp"

class Vertex
{
public:
	enum class Colors { BLACK, GRAY, WHITE };
    std::string name = ""; ///< campo de texto. Se utilizará como key

private:
    std::string descripcion = "";
    Jugador* propietario;
    int renta;
    int costo;
    int costoCasa;
    int area;
    int numeroCasa;
    int* precios;
    int status;

	std::list<Vertex> neighbors; ///< lista de vértices adyacentes

	int distance{ 0 };

	Colors color{ Colors::BLACK };

	std::string predecesor;

	size_t discovery_time{ 0 };

	size_t finish_time{ 0 };

public:
	std::string get_name();

    void set_descripcion( std::string descripcion );

    std::string get_descripcion();

    void set_jugador( Jugador* propietario );

    Jugador* get_jugador();

    void set_renta( int renta );

    int get_renta();

    void set_costo( int costo );

    int get_costo();

    void set_costoCasa( int costoCasa );

    int get_costoCasa();

    void set_area( int area );

    int get_area();

    void set_numeroCasa( int numeroCasa );

    int get_numeroCasa();

    void set_precios( int* precios );

    int* get_precios();

    void set_status( int status );

    int get_status();

	void set_distance( int distance );

	int get_distance();

	void set_discovery_time( size_t discovery_time );

	size_t get_discovery_time( );

	void set_finish_time( size_t finish_time );

	size_t get_finish_time( );

	void set_color( Vertex::Colors color );

	Colors get_color();

	void set_predecesor( std::string predecesor );

	std::string get_predecesor( );

	void add_neighbor( Vertex v );

    std::list<Vertex> get_neighbors();

	void print_neighbors();

	void print();
};

#endif
