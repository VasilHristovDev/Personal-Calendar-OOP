#ifndef PERSONAL_CALENDAR_OOP_HOUR_H
#define PERSONAL_CALENDAR_OOP_HOUR_H

#include <iostream>

///Time class that interprets the time for the events to happen
///The class consists of two properties : hours and minutes
class Time {
private:
    unsigned int hours;
    unsigned int minutes;
public:
    ///Default constructor for the needs of the Event default constructor and other usages
    Time();

    Time(unsigned int hour, unsigned int minutes);

    ///Two setters for the properties of the class
    void setHour(unsigned int hour);

    void setMinutes(unsigned int minutes);

    ///Two getters for the properties of the class
    unsigned int getHour() const;

    unsigned int getMinutes() const;

    ///A print method that displays the information about the created object
    void print(std::ostream &out = std::cout) const;
    void read(std::istream &in = std::cin);

    ///Operators for comparison, needed for determining the time spans
    bool operator==(const Time &time) const;

    bool operator<(const Time &time) const;

    bool operator>(const Time &time) const;

    bool operator<=(const Time &time) const;

    bool operator>=(const Time &time) const;

    ///Assignment operator
    Time &operator=(const Time &other);

    ///operator that reads time from the console
    friend std::istream &operator>>(std::istream &in, Time &time);

};

///A checker determining whether an entered time is valid or not
bool isValidTime(const Time &time);

///Helper boolean telling whether two periods of time are overlapping
static bool
areOverlapping(const Time &startingTime1, const Time &endingTime1, const Time &startingTime2, const Time &endingTime2);

#endif //PERSONAL_CALENDAR_OOP_HOUR_H
