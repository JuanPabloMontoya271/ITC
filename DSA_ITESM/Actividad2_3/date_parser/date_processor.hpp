

#pragma once
#include "date_struct.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include "element.hpp"
class DateProcessor
{

public:
    DateProcessor(std::string);
    Element content();
private:
    Time time(int, int, int);
    Date date(int, int, Time);
    std::unordered_map<std::string, int> map_;
    std::string line_;
};