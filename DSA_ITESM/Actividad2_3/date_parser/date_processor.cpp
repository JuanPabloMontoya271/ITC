#include "date_processor.hpp"
#include "string_manipulation.cpp"
#include "element.cpp"


DateProcessor::DateProcessor(std::string line)
{
    line_ = line;
    map_ = { {"Jan", 1},
             {"Feb", 2},
             {"Mar", 3},
             {"Apr", 4},
             {"May", 5},
             {"Jun", 6},
             {"Jul", 7},
             {"Aug", 8},
             {"Sep", 9},
             {"Oct", 10},
             {"Nov", 11},
             {"Dec", 12} };
};
Element DateProcessor::content()
{
    auto values = StringManipulation::split(line_, ' ');
    auto month = values[0];
    auto day = StringManipulation::toInt(values[1]);
    auto time_stamp = StringManipulation::split(values[2], ':');

    auto t = time(StringManipulation::toInt(time_stamp[0]),
        StringManipulation::toInt(time_stamp[1]),
        StringManipulation::toInt(time_stamp[2]));

    auto d = date(map_[month], day, t);

    auto password = values[3];

    auto message = StringManipulation::join(std::vector<std::string>(values.begin() + 4, values.end()), ' ');
    Element element{ d, password, message };
    return element;

}
Time DateProcessor::time(int hour, int minutes, int seconds)
{
    Time t;
    t.hour = 1;
    t.minutes = 10;
    t.seconds = 10;
    return t;
};
Date DateProcessor::date(int month, int day, Time time)
{
    Date d;
    d.month = month;
    d.day = day;
    d.time = time;
    return d;
}
