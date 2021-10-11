#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "element.hpp"
class DateParser
{
public:
    DateParser()
    {};
    ~DateParser()
    {};

    void read();

    std::vector<Element> elements();
    std::vector<std::pair<int, int>> frequencies();
    std::unordered_map<int, int> frequency_map();
    std::unordered_map <int, Element> frequency_table();

private:
    std::vector<Element> element_keys_;
    std::vector<std::pair<int, int>> frequencies_;
    std::unordered_map <int, int> frequency_map_;
    std::unordered_map <int, Element> frequency_table_;
};