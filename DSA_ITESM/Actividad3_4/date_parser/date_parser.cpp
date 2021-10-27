#include "date_parser.hpp"
#include "date_processor.cpp"

void DateParser::read()
{
    std::string line;
    std::ifstream myfile("bitacora.txt");
    if (myfile.is_open())
    {
        std::cout << "Reading" << std::endl;
        while (getline(myfile, line))
        {
            auto date = DateProcessor(line);
            auto element = date.content();
            auto key = element.numeric_ip();
            element_keys_.push_back(element);
            if (frequency_map_.find(element.key()) == frequency_map_.end())
            {
                frequency_map_[key] = 0;
                frequency_table_[key] = element;
            }

            else
                frequency_map_[key] += 1;
        }
        for (auto el : frequency_map_)
        {
            frequencies_.push_back(el);
        }
        std::cout << frequencies_.size() << std::endl;
        myfile.close();
    }

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