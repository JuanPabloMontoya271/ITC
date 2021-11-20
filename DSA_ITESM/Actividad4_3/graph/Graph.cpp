#include "Graph.hpp"
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
  
void Graph::DFS(int v, std::unordered_map <int, int> frequency_map_)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
    auto elem = frequency_map_.find(v);
    if (elem == frequency_map_.end())
    {
        std::cout << "Element Not Present\n";
    }    
    else
    {
        if (elem->second > max_value[1])
        {
            max_value[0] = elem->first;
            max_value[1] = elem->second;
        }
        
        std::cout << "Present : " << elem->first << elem->second << std::endl;
    }
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, frequency_map_);
}



