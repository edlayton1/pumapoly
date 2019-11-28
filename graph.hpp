#ifndef _GRAPH_INC_
#define _GRAPH_INC_

#include "Vertex.hpp"

class Graph
{
public:
	std::map<std::string, Vertex> vertices; ///< lista de vértices en el grafo
	// asociamos un vértice (value) a una cadena (key):
	// vertices[ string ] = a_vertex

public:
	Graph();
//	Graph( std::vector<Vertex> vertices ); 
	bool add_vertex( Vertex v );
	bool add_edge( std::string edge1, std::string edge2 );
    bool add_edge_directed( std::string edge1, std::string edge2 );
    void bfs( std::string start );
    void dfs_traverse( std::string name, size_t* time );
    void dfs( std::string name );
    void dfs_traverse_to( std::string name, std::vector<Vertex>* list, size_t* time );
    std::vector<Vertex> dfs_to( std::string name );
    void traverse( Jugador* a, int casillas );
	void print();
};

#endif
