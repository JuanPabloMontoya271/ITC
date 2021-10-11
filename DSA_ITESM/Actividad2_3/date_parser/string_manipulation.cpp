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
int StringManipulation::parse_ip(std::string password)
{
    auto splitted_password = StringManipulation::split(password, ':');
    auto ip = splitted_password[0];
    auto splitted_ip = StringManipulation::split(ip, '.');
    auto port = splitted_password[1];
    splitted_ip.push_back(port);
    int numeric_ip = 0;
    for (auto value : splitted_ip)
        numeric_ip += StringManipulation::toInt(value);
    return numeric_ip;
}
int StringManipulation::toInt(std::string str)
{
    return std::atoi(str.c_str());
}