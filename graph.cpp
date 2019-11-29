
/**
 * @file graph.cpp
 * Modulo de las funciones para manejar un Grafo
 */ 

#include "graph.hpp"
#include "Monopoly.hpp"
/**
 * @brief Constructor de la clase Graph
 */

Graph::Graph()
{
	// nada (por el momento)
}

/**
 * @brief Agrega un vertice al grafo
 * @param v Vertice que se agregara al grafo
 *  
 */

bool Graph::add_vertex( Vertex v )
{
	auto ret = vertices.insert( { v.get_name(), v } );
	// 'map' no permite duplicados, así que no hay necesidad de buscarlos
	
	return ret.second;
}

/**
 * @brief Agrega una arista al grafo
 * @param edge1 vertice que se conectara edge 2 vertice que se conectara.
 * @return Se llevo a cabo exitosamente o no.
 */

bool Graph::add_edge( std::string edge1, std::string edge2 )
{
	bool res = false;
	// uno, o ambos nodos, no existen

	auto v1 = this->vertices.find( edge1 );
	auto v2 = this->vertices.find( edge2 );

	if( v1 != this->vertices.end() and v2 != this->vertices.end() ){

		v1->second.add_neighbor( v2->second );
		v2->second.add_neighbor( v1->second );

		return true;
	}

	return res;
}
/**
 * @brief Une dos vertices mediante una arista.
 * @param edge1 primer vertice edge2 vecino de edge1. 
 * @return Se llevo a cabo exitosamente o no.
 */
bool Graph::add_edge_directed( std::string edge1, std::string edge2 )
{
	bool res = false;
	// uno, o ambos nodos, no existen

	auto v1 = this->vertices.find( edge1 );
	auto v2 = this->vertices.find( edge2 );

	if( v1 != this->vertices.end() and v2 != this->vertices.end() )
    {
		v1->second.add_neighbor( v2->second );

		return true;
	}

	return res;
}

/**
 * @brief Imprime el grafo.
 * 
 */ 
void Graph::print()
{
	for( auto v : this->vertices ){
		std::cout << "\n" << v.second.get_name() << ": ";
		v.second.print_neighbors();
	}
	std::cout << "\n";
}

/**
 * @brief Busqueda en Anchura
 * @param name Comienzo del grafo
 */ 

void Graph::bfs( std::string name )
{
    auto start = this->vertices.find( name );

    for( auto v : this->vertices )
    {
        v.second.set_color( Vertex::Colors::BLACK ); //El vértice no ha sido descubierto;
        v.second.set_distance( 0 );
        v.second.set_predecesor( "Nil" );
        v.second.print();
    }

    start->second.set_color( Vertex::Colors::GRAY );
    start->second.set_distance( 0 );
    start->second.set_predecesor( "Nil" );
    std::list<Vertex> queue;

    queue.push_back( start->second );

    while( queue.empty() != true )
    {
        auto v = queue.front(); 
        queue.pop_front();
        auto tmpv = this->vertices.find( v.get_name() );
        tmpv->second.print();

        for( auto tmp : v.get_neighbors() )
        { 
            auto w = this->vertices.find( tmp.get_name() );
            if( w->second.get_color() == Vertex::Colors::BLACK )
            { 
                w->second.set_color( Vertex::Colors::GRAY );
                w->second.set_distance( v.get_distance() + 1 );
                w->second.set_predecesor( v.get_name() );
                queue.push_back( w->second );
            }
            
        }
        
        tmpv->second.set_color( Vertex::Colors::WHITE );
    }

    for( auto v : this->vertices )
    {
        v.second.print();
    }
}
/**
 * @brief Recorrido de la Busqueda en Altura
 * @param name Comienzo del grafo, time Tiempo de encuentro.
 */ 
void Graph::dfs_traverse( std::string name, size_t* time )
{
	*time += 1;
	auto v = this->vertices.find( name );

	v->second.set_discovery_time( *time );
	v->second.set_color( Vertex::Colors::GRAY );

	for( auto tmp : v->second.get_neighbors() )
	{
		auto u = this->vertices.find( tmp.get_name() );
		if( u->second.get_color() == Vertex::Colors::BLACK )
		{
			u->second.set_predecesor( v->second.get_name() );
			Graph::dfs_traverse( u->second.get_name(), time );
		}
	}

	v->second.set_color( Vertex::Colors::WHITE );

	*time += 1;
	v->second.set_finish_time( *time );
}
/**
 * @brief Busqueda en Altura
 * @param name Comienzo del grafo
 */ 
void Graph::dfs( std::string name )
{
	auto start = this->vertices.find( name );
	for( auto v : this->vertices )
    {
        v.second.set_color( Vertex::Colors::BLACK ); //El vértice no ha sido descubierto;
        v.second.set_distance( 0 );
        v.second.set_predecesor( "Nil" );
    }

    start->second.set_color( Vertex::Colors::BLACK ); //El vértice no ha sido descubierto;
    start->second.set_distance( 0 );
    start->second.set_predecesor( "Nil" );

    size_t time = 0;

    if( start->second.get_color() == Vertex::Colors::BLACK )
    {
        Graph::dfs_traverse( start->second.get_name(), &time );
    }

    for( auto tmo : this->vertices )
    {
    	tmo.second.print();
    }
}
/**
 * @brief Recorrido de la Busqueda en Altura topologico.
 * @param name Comienzo del grafo, list Encuentro de los vertices, time Tiempo de encuentro.
 */ 
void Graph::dfs_traverse_to( std::string name, std::vector<Vertex>* list, size_t* time )
{
	*time += 1;
	auto v = this->vertices.find( name );

	v->second.set_discovery_time( *time );
	v->second.set_color( Vertex::Colors::GRAY );

	for( auto tmp : v->second.get_neighbors() )
	{
		auto u = this->vertices.find( tmp.get_name() );
		if( u->second.get_color() == Vertex::Colors::BLACK )
		{
			u->second.set_predecesor( v->second.get_name() );
			Graph::dfs_traverse_to( u->second.get_name(), list, time );
		}
	}

	v->second.set_color( Vertex::Colors::WHITE );

	*time += 1;
	v->second.set_finish_time( *time );

	list->push_back( v->second );
}
/**
 * @brief Busqueda en Altura Topologico.
 * @param name Comienzo del grafo
 */ 

std::vector<Vertex> Graph::dfs_to( std::string name )
{
	auto start = this->vertices.find( name );
	for( auto v : this->vertices )
    {
        v.second.set_color( Vertex::Colors::BLACK ); //El vértice no ha sido descubierto;
        v.second.set_distance( 0 );
        v.second.set_predecesor( "Nil" );
    }

    start->second.set_color( Vertex::Colors::BLACK ); //El vértice no ha sido descubierto;
    start->second.set_distance( 0 );
    start->second.set_predecesor( "Nil" );

    size_t time = 0;

    std::vector<Vertex> list;

    if( start->second.get_color() == Vertex::Colors::BLACK )
    {
        Graph::dfs_traverse_to( start->second.get_name(), &list, &time );
    }

    std::sort( list.begin(), list.end(), []( Vertex& lhs, Vertex& rhs ){ return lhs.get_finish_time() > rhs.get_finish_time(); } );

    for( auto tmp : list )
    {
        tmp.print();
    }

    return list;
}
/**
 * @brief Recorrido del grafo del tablero.
 * @param a Jugador que viaja, casillas Casillas que avanza.
 */ 
void Graph::traverse( Jugador* a, int casillas )
{
    int i = 0;
    while( i < casillas )
    {
        auto lugar = this->vertices.find( a->casilla )->second.get_neighbors();
        a->casilla = lugar.front().get_name();
        if( a->casilla.compare("Tienda UNAM") == true )
        {
            Banco( a );
        }
        i++;
    }
}
