#include "Vertex.hpp"

void Vertex::add_neighbor( Vertex v )
{
	this->neighbors.push_back( v );
}

std::list<Vertex> Vertex::get_neighbors()
{
    return this->neighbors;
}

void Vertex::set_distance( int distance )
{
	this->distance = distance;
}

int Vertex::get_distance()
{
	return this->distance;
}

void Vertex::set_discovery_time( size_t discovery_time )
{
	this->discovery_time = discovery_time;
}

size_t Vertex::get_discovery_time()
{
	return this->discovery_time;
}

void Vertex::set_finish_time( size_t finish_time )
{
	this->finish_time = finish_time;
}

size_t Vertex::get_finish_time()
{
	return this->finish_time;
}

void Vertex::set_color( Vertex::Colors color )
{
	this->color = color; 
}

Vertex::Colors Vertex::get_color()
{
	return this->color;
}

void Vertex::set_predecesor( std::string predecesor )
{
	this->predecesor = predecesor;
}

std::string Vertex::get_predecesor( )
{
	return this->predecesor;
}

void Vertex::print_neighbors()
{
	for( auto v : this->neighbors )
    {
		std::cout << v.get_name() << "-> ";
    }
	
    std::cout << "Nil";
}

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

std::string Vertex::get_name()
{
	return this->name;
}

void Vertex::set_descripcion( std::string descripcion )
{
    this->descripcion = descripcion;
}

std::string Vertex::get_descripcion()
{
    return this->descripcion;
}

void Vertex::set_jugador( Jugador* propietario )
{
    this->propietario = propietario;
}

Jugador* Vertex::get_jugador()
{
    return this->propietario;
}

void Vertex::set_renta( int renta )
{
    this->renta = renta;
}

int Vertex::get_renta()
{
    return this->renta;
}

void Vertex::set_costo( int costo )
{
    this->costo = costo;
}

int Vertex::get_costo()
{
    return this->costo;
}

void Vertex::set_costoCasa( int costoCasa )
{
    this->costoCasa = costoCasa;
}

int Vertex::get_costoCasa()
{
    return this->costoCasa;
}

void Vertex::set_area( int area )
{
    this->area = area;
}

int Vertex::get_area()
{
    return this->area;
}

void Vertex::set_numeroCasa( int numeroCasa )
{
    this->numeroCasa = numeroCasa;
}

int Vertex::get_numeroCasa()
{
    return this->numeroCasa;
}

void Vertex::set_precios( int* precios )
{
    this->precios = precios;
}

int* Vertex::get_precios()
{
    return this->precios;
}

void Vertex::set_status( int status )
{
    this->status = status;
}

int Vertex::get_status()
{
    return this->status;
}
