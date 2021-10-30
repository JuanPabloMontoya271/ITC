#pragma once
#include <iostream>
#include <string>
#include "date_struct.hpp"

class Element
{
public:
    Element();
    Element(Date, std::string, std::string, int, std::string);
    int key();
    int numeric_ip();
    std::string ip();
    void set_key(int);
    Date date();
    std::string content();
    std::string message();

private:
    Date date_;
    std::string content_;
    std::string message_;
    int numeric_ip_;
    std::string ip_;
    int key_;
    int generate_key();
};