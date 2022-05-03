#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "element.hpp"
#include "../tree/bst.hpp"
#include "../graph/Graph.cpp"
class DateParser
{
public:
    DateParser()
    {};
    ~DateParser()
    {};

    void read();

    std::vector<Element> elements();
    std::vector<std::pair<string,  int>> frequencies();
    std::unordered_map<string,  int> frequency_map();
    std::unordered_map <string,  Element> frequency_table();
    BST bst();
    BST* root();
    Graph graph();

private:
    std::vector<Element> element_keys_;
    std::vector<std::pair<string, int>> frequencies_;
    std::unordered_map <string, int> frequency_map_;
    std::unordered_map <string, Element> frequency_table_{};
    BST bst_;
    BST* root_;
    Graph graph_{};
    
};