#pragma once
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;
class Graph 
{
public:
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adj;
    int max_value[2] = {-1,0};

    void addEdge(int v, int w);
  
  
    void DFS(int v, std::unordered_map <int, int> frequency_map_);
};
  
