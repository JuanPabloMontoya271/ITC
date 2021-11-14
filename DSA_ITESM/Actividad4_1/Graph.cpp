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



// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212 

bool Graph::isCyclicUtil(int v, bool visited[], bool* recStack)

{

    if (visited[v] == false)

    {

        // Mark the current node as visited and part of recursion stack 

        visited[v] = true;

        recStack[v] = true;



        //Iterators are used to point at the memory addresses of STL containers. They are primarily used in sequence of numbers, characters etc. They reduce the complexity and execution time of program.

        list<int>::iterator i;

        for (i = adj[v].begin(); i != adj[v].end(); ++i)

        {

            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))  // ya lo visite y ademas pude regresar y por lo que encontre un ciclo

            {

                return true;

            }

            else if (recStack[*i])  // esta esta visitado y lo encontre en el recstack, por lo tango, pos ya

            {

                return true;

            }

        }



    }

    recStack[v] = false;  // remove the vertex from recursion stack 

    return false;

}



// Returns true if the graph contains a cycle, else false. 

// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 

bool Graph::isCyclic()

{

    // Mark all the vertices as not visited and not part of recursion 

    // stack 

    bool* visited = new bool[V];

    bool* recStack = new bool[V];

    for (int i = 0; i < V; i++)

    {

        visited[i] = false;

        recStack[i] = false;

    }



    // Call the recursive helper function to detect cycle in different 

    // DFS trees 

    for (int i = 0; i < V; i++)

        if (isCyclicUtil(i, visited, recStack))

        {

            return true;

        }



    return false;

}