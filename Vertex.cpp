
/**
 * @file Vertex.cpp
 * Modulo de las funciones para manejar un Vertice
 */ 

#include "Vertex.hpp"
/**
 * @brief Agrega un vecino
 * @param v Vertice vecino nuevo.
 */ 
void Vertex::add_neighbor( Vertex v )
{
	this->neighbors.push_back( v );
}
/**
 * @brief Obtienes los vecinos
 * 
 */ 
std::list<Vertex> Vertex::get_neighbors()
{
    return this->neighbors;
}
/**
 * @brief Agrega la distancia.
 * @param distance distancia entre nodo principal y el mismo.
 */ 
void Vertex::set_distance( int distance )
{
	this->distance = distance;
}
/**
 * @brief Obtiene la distancia.
 * 
 */ 
int Vertex::get_distance()
{
	return this->distance;
}
/**
 * @brief Agrega el tiempo de descubrimiento.
 * @param discovery_time tiempo de descubrimiento.
 */ 
void Vertex::set_discovery_time( size_t discovery_time )
{
	this->discovery_time = discovery_time;
}
/**
 * @brief Obtiene el tiempo de descubrimiento.
 * 
 */ 
size_t Vertex::get_discovery_time()
{
	return this->discovery_time;
}
/**
 * @brief Agrega el tiempo de completado.
 * @param finish_time tiempo de finalización.
 */ 
void Vertex::set_finish_time( size_t finish_time )
{
	this->finish_time = finish_time;
}
/**
 * @brief Obtiene el tiempo de finalizacion
 * 
 */ 
size_t Vertex::get_finish_time()
{
	return this->finish_time;
}
/**
 * @brief Agrega el color del vertice.
 * @param color Color que tendra el vertice.
 */ 
void Vertex::set_color( Vertex::Colors color )
{
	this->color = color; 
}
/**
 * @brief Obtiene el color del vecino.
 * 
 */ 
Vertex::Colors Vertex::get_color()
{
	return this->color;
}
/**
 * @brief Agrega un predecesor al vertice.
 * @param predecesor de nuestro vertice.
 */ 
void Vertex::set_predecesor( std::string predecesor )
{
	this->predecesor = predecesor;
}
/**
 * @brief Obtiene el predecesor.
 * 
 */ 
std::string Vertex::get_predecesor( )
{
	return this->predecesor;
}
/**
 * @brief Imprime los vecinos del vertice.
 * 
 */ 
void Vertex::print_neighbors()
{
	for( auto v : this->neighbors )
    {
		std::cout << v.get_name() << "-> ";
    }
	
    std::cout << "Nil";
}
/**
 * @brief Imprime la información del vertice.
 * 
 */ 
void Vertex::print()
{
	std::string color_as_string;

	switch( this->color )
	{
		case Vertex::Colors::BLACK: color_as_string = "BLACK"; break;
		case Vertex::Colors::GRAY: color_as_string = "GRAY"; break;
		case Vertex::Colors::WHITE: color_as_string = "WHITE"; break;
	}

	std::cout << "Nombre: " << this->name <<" ";
	std::cout << "Distancia: " << this->distance << " ";
    std::cout << "Discovery time: " << this->discovery_time << " ";
    std::cout << "Finish time: " << this->finish_time << " ";
	std::cout << "Color: " << color_as_string << " ";
	std::cout << "Predecesor: " << this->predecesor << "\n";
}
/**
 * @brief Obtiene el nombre del lugar.
 * 
 */ 
std::string Vertex::get_name()
{
	return this->name;
}
/**
 * @brief Agrega una descripción.
 * @param descripcion La descripcion del lugar.
 */ 
void Vertex::set_descripcion( std::string descripcion )
{
    this->descripcion = descripcion;
}
/**
 * @brief Obtiene una descripción.
 * 
 */ 
std::string Vertex::get_descripcion()
{
    return this->descripcion;
}
/**
 * @brief Agrega un propietario.
 * @param propietario Propietario del lugar.
 */ 
void Vertex::set_jugador( Jugador* propietario )
{
    this->propietario = propietario;
}
/**
 * @brief Obtiene al propietario del lugar.
 * 
 */ 
Jugador* Vertex::get_jugador()
{
    return this->propietario;
}
/**
 * @brief Agrega el valor de la renta.
 * @param renta El valor de la renta.
 */ 
void Vertex::set_renta( int renta )
{
    this->renta = renta;
}
/**
 * @brief Obtiene el valor de la renta.
 * 
 */ 
int Vertex::get_renta()
{
    return this->renta;
}
/**
 * @brief Agrega el costo del Lugar.
 * @param costo Cuanto cuesta el lugar.
 */ 
void Vertex::set_costo( int costo )
{
    this->costo = costo;
}
/**
 * @brief Obtiene cuanto cuesta el lugar.
 * 
 */ 
int Vertex::get_costo()
{
    return this->costo;
}
/**
 * @brief Agrega el costo por una casa.
 * @param costoCasa Cuanto cuesta una casa.
 */ 
void Vertex::set_costoCasa( int costoCasa )
{
    this->costoCasa = costoCasa;
}
/**
 * @brief Obtiene el costo de una Casa.
 * 
 */ 
int Vertex::get_costoCasa()
{
    return this->costoCasa;
}
/**
 * @brief Agrega el area  a la que pertenece el lugar.
 * @param area Area que se le asigna.
 */ 
void Vertex::set_area( int area )
{
    this->area = area;
}
/**
 * @brief Obtiene el area del lugar.
 * 
 */ 
int Vertex::get_area()
{
    return this->area;
}
/**
 * @brief Agrega el numero de casas que tiene la propiedad.
 * @param numeroCasa numero de casas.
 */ 
void Vertex::set_numeroCasa( int numeroCasa )
{
    this->numeroCasa = numeroCasa;
}
/**
 * @brief Obtiene el numero de casas en la propiedad.
 * 
 */ 
int Vertex::get_numeroCasa()
{
    return this->numeroCasa;
}
/**
 * @brief Agrega los precios dependiendo del numero de casas.
 * @param precios Lista que contiene los precios dependiendo de las casas.
 */ 
void Vertex::set_precios( int* precios )
{
    this->precios = precios;
}
/**
 * @brief Obtiene la lista de precios por casas.
 * 
 */ 
int* Vertex::get_precios()
{
    return this->precios;
}
/**
 * @brief Agrega el estatus de la propiedad.
 * @param status Estado de la propiedad.
 */ 
void Vertex::set_status( int status )
{
    this->status = status;
}
/**
 * @brief Obtiene el estatus de la propiedad.
 *
 */ 
int Vertex::get_status()
{
    return this->status;
}
