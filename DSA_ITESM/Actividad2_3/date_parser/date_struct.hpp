#pragma once
#include <unordered_map>
#include <string>
struct Time
{
    int hour;
    int minutes;
    int seconds;
};
struct Date
{
    int month;
    int day;
    Time time;
};
