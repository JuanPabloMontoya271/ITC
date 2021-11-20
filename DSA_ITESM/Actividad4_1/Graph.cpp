#include "Graph.hpp"
Graph::Graph(int V)

{

    this->V = V;

    adj = new list<int>[V];

}



void Graph::addEdge(int v, int w)

{

    adj[v].push_back(w); // Add w to v�s list. 

}



