#include <iostream>
#ifndef PERSONAL_CALENDAR_OOP_HOUR_H
#define PERSONAL_CALENDAR_OOP_HOUR_H


class Time {
private:
    unsigned int hour;
    unsigned int minutes;
public:
    Time();
    Time(unsigned int hour, unsigned int minutes);
    void setHour(unsigned int hour);
    void setMinutes(unsigned int minutes);

    unsigned int getHour() const;
    unsigned int getMinutes() const;

    void print(std::ostream & out = std::cout) const;
    bool operator ==(const Time & time) const;
    bool operator <(const Time & time) const;
    bool operator >(const Time & time) const;
    Time & operator = (const Time & other);

    friend std::istream & operator >>(std::istream & in, Time & time);

};


#endif //PERSONAL_CALENDAR_OOP_HOUR_H