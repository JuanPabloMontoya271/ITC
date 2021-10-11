#include "string_manipulation.hpp"

StringManipulation::StringManipulation()
{};
std::vector<std::string> StringManipulation::split(std::string str, char chr)
{
    std::vector<std::string> result;
    std::string temp = "";
    for (auto s : str)
    {
        if (s == chr)
        {
            result.push_back(temp);
            temp = "";
        }

        else
            temp += s;
    }
    result.push_back(temp);
    return result;
}
std::string StringManipulation::join(std::vector<std::string> strs, char chr)
{

    std::string result = "";
    for (auto s : strs)
        result += (s + chr);
    return result;
}
int StringManipulation::toInt(std::string str)
{
    return std::atoi(str.c_str());
}