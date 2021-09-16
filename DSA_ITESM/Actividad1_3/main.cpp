#include "date_parser/date_parser.cpp"
#include <memory>
#include "database/Sort.cpp"
#include "database/SortFreq.cpp"
#include "database/Find.cpp"
#include "interface/interface.cpp"
#include <vector>
#include <unordered_set>
int generate_date();
std::vector<Element> filter_vector(std::vector<Element> curr_vector);
void show_vector(std::vector<Element> elements);
int main()
{
    DateParser parser;
    parser.read();

    auto elements = parser.elements();
    auto frequencies = parser.frequencies();
    auto frequency_table = parser.frequency_table();


    auto interface = Interface(elements, frequencies, frequency_table);
    interface.Run();
    // auto sorter = Sort(elements);
    // auto sorted = sorter.mergeSort();
    // sorter.show();
    // auto filtered_vector = filter_vector(sorted);
    // show_vector(filtered_vector);
    return 0;
}
void show_vector(std::vector<Element> elements)
{
    for (auto element : elements)
    {
        auto date = element.date();
        auto time = date.time;
        std::cout << "Month : " << date.month << ", Day : " << date.day << ", Time : "
            << time.hour << 'h' << time.minutes << 'm' << time.seconds << 's' << std::endl;
        std::cout << "Content : " << element.content() << " Message : " << element.message() << std::endl;
    }
}
