#include "interface.hpp"
#include "../date_parser/string_manipulation.hpp"
Interface::Interface(std::vector<Element> elements, std::vector<std::pair<int, int>>frequencies, std::unordered_map<int, Element> frequency_table)
{
    elements_ = elements;
    frequencies_ = frequencies;
    frequency_table_ = frequency_table;
}
void Interface::Run()
{
    SortElements();
    SortByFrequencies();
    auto filtered_vector = filter_vector_by_ips(sorted_elements_);
    show_content(filtered_vector);
    show_content();

}

void Interface::SortElements()
{
    std::cout << "Ordenamiento de los Datos Basado en la IP : " << std::endl;
    Continue();
    auto sorter = Sort(elements_);
    auto sorted = sorter.mergeSort();
    sorted_elements_ = sorted;
    sorter.show();
    dump_to_file(sorted_elements_, "out/sorted.txt");
    Continue();

}
void Interface::show_content()
{
    std::cout << "Mostrar requests por orden de frecuencia";
    for (auto elem : frequencies_)
    {
        auto element = frequency_table_[elem.first];
        auto date = element.date();
        auto time = date.time;
        std::cout <<"Numeric IP : " << element.numeric_ip() << ", Key : " << element.key() << "Month : " << date.month << ", Day : " << date.day << ", Time : " << time.hour << "h" << time.minutes << "m" << time.seconds << "s" << std::endl;
        std::cout << "Content : " << element.content() << ", Message : " << element.message() << std::endl;
    }
    Continue();
}
void Interface::SortByFrequencies()
{
    std::cout << "Ordenamiento de los Datos Basado en la frecuencia de aparicion : " << std::endl;
    Continue();
    auto sort_freq = SortFreq(frequencies_);
    auto sorted_freq = sort_freq.mergeSort();
    sorted_frequencies_ = sorted_freq;
    sort_freq.show();
    dump_to_file(sorted_freq, "out/sorted_freq.txt");
    Continue();
}
void Interface::Continue()
{
    bool Continuar = 0;
    std::cout << "Desea continuar : " << std::endl;;
    std::cin >> Continuar;
    if (Continuar)
    {
        std::cout << "Continuando ..." << std::endl;;
    }
    else
    {
        std::cout << "Gracias por utilizar nuestro programa" << std::endl;
        std::exit(1);
    }
}
void Interface::generate_ip_bounds()
{
    std::string min_ip_input;
    std::string max_ip_input;
    std::cout << "Introduzca una ip minima con el siguiente formato _._._._:_ " << std::endl;
    std::cin >> min_ip_input;
    std::cout << "Introduzca una ip minima con el siguiente formato _._._._:_ " << std::endl;
    std::cin >> max_ip_input; 
    
    auto min_ip = StringManipulation::parse_ip(min_ip_input);
    auto max_ip  = StringManipulation::parse_ip(max_ip_input);
    ip_bounds_ = std::make_pair(min_ip, max_ip);
}
int Interface::generate_date()
{
    std::cout << "Seleccione un mes : " << std::endl;
    int mes;
    std::cin >> mes;
    std::cout << "Seleccione un dia : " << std::endl;
    int dia;
    std::cin >> dia;
    std::cout << "Seleccione una hora : " << std::endl;
    int hora;
    std::cin >> hora;
    std::cout << "Seleccione un minuto : " << std::endl;
    int min;
    std::cin >> min;
    std::cout << "Seleccione un segundo : " << std::endl;
    int seg;
    std::cin >> seg;

    return mes * 31 * 24 * 3600 + dia * 24 * 3600 + hora * 3600 + min * 60 + seg;
}
std::vector<Element> Interface::filter_vector(std::vector<Element> curr_vector)
{
    std::cout << "La medida del vector es : " << curr_vector.size() << std::endl;
    std::cout << "Filtrado de los datos basado en la fecha : " << std::endl;
    Continue();
    std::cout << "Define una fecha minima : " << std::endl;

    auto lower_bound = generate_date();
    auto finder = Find(curr_vector, lower_bound);
    auto lower_bound_index = finder.binary();

    std::cout << "Lower Bound : " << lower_bound_index << std::endl;

    std::cout << "Define una fecha maxima : " << std::endl;

    auto upper_bound = generate_date();
    finder = Find(curr_vector, upper_bound);
    auto upper_bound_index = finder.binary();

    std::cout << "Upper Bound : " << upper_bound_index << std::endl;
    auto filtered_vector = std::vector<Element>(curr_vector.begin() + lower_bound_index, curr_vector.begin() + upper_bound_index);
    std::cout << "Size : " << filtered_vector.size() << std::endl;
    dump_to_file(filtered_vector, "out/filtered.txt");
    Continue();
    return filtered_vector;
}
std::vector<Element> Interface::filter_vector_by_ips(std::vector<Element> curr_vector)
{
    std::cout << "La medida del vector es : " << curr_vector.size() << std::endl;
    std::cout << "Filtrado de los datos basado en la IP : " << std::endl;
    Continue();
    generate_ip_bounds();
    std::cout << "First : " << ip_bounds_.first << ", Second : " << ip_bounds_.second <<std::endl;

    auto lower_bound = ip_bounds_.first;
    auto finder = Find(curr_vector, lower_bound);
    auto lower_bound_index = finder.binary();

    std::cout << "Lower Bound : " << lower_bound_index << std::endl;

    auto upper_bound = ip_bounds_.second;
    finder = Find(curr_vector, upper_bound);
    auto upper_bound_index = finder.binary();

    std::cout << "Upper Bound : " << upper_bound_index << std::endl;
    auto filtered_vector = std::vector<Element>(curr_vector.begin() + lower_bound_index, curr_vector.begin() + upper_bound_index);
    std::cout << "Size : " << filtered_vector.size() << std::endl;
    dump_to_file(filtered_vector, "out/filtered.txt");
    Continue();
    return filtered_vector;
}
void Interface::dump_to_file(std::vector<Element> elements, std::string path)
{
    std::cout << "Writing to file" << path << std::endl;
    std::ofstream myfile;
    myfile.open(path);


    for (auto element : elements)
    {
        auto date = element.date();
        auto time = date.time;
        myfile << "Numeric IP : " << element.numeric_ip() << std::endl;
        myfile << "Month : " << date.month << ", Day : " << date.day << ", Time : "
            << time.hour << 'h' << time.minutes << 'm' << time.seconds << 's' << std::endl;
        myfile << "Content : " << element.content() << " Message : " << element.message() << std::endl;
    }
    myfile.close();
}
void Interface::dump_to_file(std::vector<std::pair<int, int>> element, std::string path)
{
    std::cout << "Writing to file" << path << std::endl;
    std::ofstream myfile;
    myfile.open(path);
    for (auto value : element)
    {
        myfile << value.second << std::endl;
    }
    myfile.close();

}
void Interface::show_content(std::vector<Element> elements)
{
    for (auto element : elements)
    {
        auto date = element.date();
        auto time = date.time;
        std::cout <<"Numeric IP : " << element.numeric_ip()<< "Month : " << date.month << ", Day : " << date.day << ", Time : "
            << time.hour << 'h' << time.minutes << 'm' << time.seconds << 's' << std::endl;
        std::cout << "Content : " << element.content() << " Message : " << element.message() << std::endl;
    }
}