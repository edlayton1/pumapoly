#include "graph.hpp"
#include "Monopoly.hpp"

Graph::Graph()
{
	// nada (por el momento)
}

bool Graph::add_vertex( Vertex v )
{
	auto ret = vertices.insert( { v.get_name(), v } );
	// 'map' no permite duplicados, así que no hay necesidad de buscarlos
	
	return ret.second;
}

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

void Graph::print()
{
	for( auto v : this->vertices ){
		std::cout << "\n" << v.second.get_name() << ": ";
		v.second.print_neighbors();
	}
	std::cout << "\n";
}

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

/*int main()
{
    std::array<std::string,10> vertices = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    std::array<std::string, 11> edges = {"AB", "BF", "FG", "FI", "GC", "GJ", "IH", "HD", "DE", "EH", "EA"};

	Graph g;

    for( auto& v : vertices )
    {
        g.add_vertex( Vertex( v ) );

    }
    
    for ( auto& e: edges )
    {
        g.add_edge_directed( e.substr( 0, 1 ), e.substr( 1, 1 ) );
        // .substr( incio, cuántos_queremos_leer )
    }

    std::vector<Vertex> list = g.dfs_to( "A" );
    //g.dfs( "A" );

    g.print();
}*/
