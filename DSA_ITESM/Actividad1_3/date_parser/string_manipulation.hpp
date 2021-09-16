#pragma once
#include <vector>
#include <string>
#include <sstream>

class StringManipulation
{
public:
    StringManipulation();
    static std::vector<std::string> split(std::string, char);
    static std::string join(std::vector<std::string>, char);
    static int toInt(std::string);
};