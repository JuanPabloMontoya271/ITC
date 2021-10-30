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
            auto key = element.ip();
            element_keys_.push_back(element);
            if (frequency_map_.find(element.ip()) == frequency_map_.end())
            {
                frequency_map_[key] = 1;
                frequency_table_[key] = element;
            }

            else
                frequency_map_[key] += 1;
        }
        std::unordered_map<std::string, int>::iterator it = frequency_map_.begin();
        root_ = bst_.Insert(root_, it->second, it->first);
        it++;
        while (it != frequency_map_.end())
        {
            bst_.Insert(root_, it->second, it->first);
            it++;
        }
        
        myfile.close();
    }

    else std::cout << "Unable to open file";
}
std::unordered_map <std::string, Element> DateParser::frequency_table()
{
    return frequency_table_;
}
std::vector<Element> DateParser::elements()
{
    return element_keys_;
}
std::unordered_map<std::string, int> DateParser::frequency_map()
{
    return frequency_map_;
}
std::vector<std::pair<std::string, int>> DateParser::frequencies()
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