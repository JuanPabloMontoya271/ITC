#include "date_parser.hpp"
#include "date_processor.cpp"

void DateParser::read()
{
    std::string line;
    std::ifstream myfile("bitacora.txt");
    root_ = NULL;
    
    
    if (myfile.is_open())
    {
        std::cout << "Reading" << std::endl;
        while (getline(myfile, line))
        {
            auto date = DateProcessor(line);
            auto element = date.content();
            auto key = element.key_ip();
            element_keys_.push_back(element);
            if (frequency_map_.find(element.key_ip()) == frequency_map_.end())
            {
                frequency_map_[key] = 1;
                frequency_table_[key] = element;
            }

            else
                frequency_map_[key] += 1;
        }
        std::unordered_map<int, int>::iterator it = frequency_map_.begin();
        // root_ = bst_.Insert(root_, it->second, it->first);
        // it++;
        while (it != frequency_map_.end())
        {
            // bst_.Insert(root_, it->second, it->first);
            std::cout <<"First : " << it->first << " Second : " << it->second << std::endl;
            it++;
        }
        for (int i = 2; i < 100; i++)
        {
            graph_.addEdge(1, i);
            
        }
        int multiplos[9] = {10,20,30,40,50,60,70,80,90};
        for (auto multiplo: multiplos)
        {
            for (int j = 0; j < 100; j++)
            {
                graph_.addEdge(multiplo, multiplo*10+j);
            }
        }
        myfile.close();
    }
/*
1->99
10-> 100->199
20->200->299
30->300->399

*/
    else std::cout << "Unable to open file";
}
std::unordered_map <int, Element> DateParser::frequency_table()
{
    return frequency_table_;
}
std::vector<Element> DateParser::elements()
{
    return element_keys_;
}
std::unordered_map<int, int> DateParser::frequency_map()
{
    return frequency_map_;
}
std::vector<std::pair<int, int>> DateParser::frequencies()
{
    return frequencies_;
}
BST DateParser::bst()
{
    return bst_;
}
BST* DateParser::root()
{
    return root_;
}
Graph DateParser::graph()
{
    return graph_;
}