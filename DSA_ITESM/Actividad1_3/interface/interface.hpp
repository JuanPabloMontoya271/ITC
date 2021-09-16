#include <iostream>
#include <vector>
#include <fstream>
#include "../date_parser/element.hpp"
#include "../database/Find.hpp"
#include "../database/Sort.hpp"
#include "../database/SortFreq.hpp"
class Interface
{
public:
    Interface(std::vector<Element>, std::vector<std::pair<int, int>>, std::unordered_map<int, Element>);
    void show_content(std::vector<Element>);
    void Run();

private:
    void SortByFrequencies();
    void SortElements();
    void Continue();
    void show_content();
    void dump_to_file(std::vector<std::pair<int, int>>, std::string path);
    void dump_to_file(std::vector<Element>, std::string path);
    std::vector<Element> filter_vector(std::vector<Element>);
    std::vector<Element> elements_;
    std::vector<Element> sorted_elements_;
    std::unordered_map<int, Element> frequency_table_;
    std::vector <std::pair<int, int>> frequencies_;
    std::vector <std::pair<int, int>> sorted_frequencies_;
    int generate_date();

};