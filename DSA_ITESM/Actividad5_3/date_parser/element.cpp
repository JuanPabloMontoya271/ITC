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
    key_ip_ = NULL;
    freq_ = 0;
}
Element::Element(Date date, std::string content, std::string message, int numeric_ip, int key_ip, std::string ip)
{

    date_ = date;
    content_ = content;
    message_ = message;
    key_ = generate_key();
    numeric_ip_ = numeric_ip;
    ip_ = ip;
    key_ip_ = key_ip;
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
int Element::key_ip()
{
    return key_ip_;
}
void Element::set_key(int key)
{
    key_ = key;
}
void line(int l)
{
    for (int i =0 ; i< l; i++)
    {
        cout << "-";
    }
    cout << endl;
}
void Element::display()
{
    int l = 50;
    line(l);
    cout << "Element : " << ip_ << endl;
    line(l);
    cout << "Date : " << endl
         << "\tDay :" << date_.day << endl
         << "\tMonth : " << date_.month << endl
         << "\tTime : " << endl
         << "\t\tHour : " << date_.time.hour << endl
         << "\t\tMinutes : " << date_.time.minutes << endl
         << "\t\tSeconds : " << date_.time.seconds << endl;

    line(l);
    cout << "Content : " << content_ << endl
         << "Message : " << message_ << endl
         << "Frequency : " << freq_ << endl
         << "Key : " << key_ << endl;
    line(l);

    
    
}
void Element::increment_freq()
{
    freq_++;
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