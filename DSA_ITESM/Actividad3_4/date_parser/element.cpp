#include "element.hpp"

Element::Element()
{
    Time t;
    t.hour = 0;
    t.minutes = 0;
    t.seconds = 0;
    Date d;
    d.month = 0;
    d.day = 0;
    d.time = t;
    content_ = "";
    message_ = "";
    key_ = generate_key();
    ip_ = "";
}
Element::Element(Date date, std::string content, std::string message, int numeric_ip, std::string ip)
{

    date_ = date;
    content_ = content;
    message_ = message;
    key_ = generate_key();
    numeric_ip_ = numeric_ip;
    ip_ = ip;
}
Date Element::date()
{
    return date_;
}
int Element::key()
{
    return key_;
}
int Element::numeric_ip()
{
    return numeric_ip_;
}
void Element::set_key(int key)
{
    key_ = key;
}
std::string Element::content()
{
    return content_;
}
std::string Element::ip()
{
    return ip_;
}
std::string Element::message()
{
    return message_;
}

int Element::generate_key()
{
    return date_.month * 31 * 24 * 3600 + date_.day * 24 * 3600 + date_.time.hour * 3600 + date_.time.minutes * 60 + date_.time.seconds;
}