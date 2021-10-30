#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include "../date_parser/element.hpp"
#include "../database/Find.hpp"
#include "../database/Sort.hpp"
#include "../database/SortFreq.hpp"
#include "../tree/bst.hpp"
class Interface
{
public:
    Interface(std::vector<Element>, std::vector<std::pair<std::string, int>>, std::unordered_map<std::string, Element>);
    Interface(BST, BST*);
    void show_content(std::vector<Element>);
    void Run();

private:
    void SortByFrequencies();
    void SortElements();
    void Continue();
    void show_content();
    void dump_to_file(std::vector<std::pair<std::string, int>>, std::string path);
    void dump_to_file(std::vector<Element>, std::string path);
    void generate_ip_bounds();
    std::vector<Element> filter_vector(std::vector<Element>);
    std::vector<Element> filter_vector_by_ips(std::vector<Element>);
    std::vector<Element> elements_;
    std::vector<Element> sorted_elements_;
    std::unordered_map<std::string, Element> frequency_table_;
    std::vector <std::pair<std::string, int>> frequencies_;
    std::vector <std::pair<std::string, int>> sorted_frequencies_;
    std::pair<int,int> ip_bounds_;
    int generate_date();
    BST bst_;
    BST* root_;
    

};