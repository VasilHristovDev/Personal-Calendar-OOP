#include <iostream>
#ifndef PERSONAL_CALENDAR_OOP_HOUR_H
#define PERSONAL_CALENDAR_OOP_HOUR_H


class Hour {
private:
    unsigned int hour;
    unsigned int minutes;
public:
    Hour();
    Hour(unsigned int hour, unsigned int minutes);
    void setHour(unsigned int hour);
    void setMinutes(unsigned int minutes);

    unsigned int getHour() const;
    unsigned int getMinutes() const;

    void print(std::ostream & out);
};


#endif //PERSONAL_CALENDAR_OOP_HOUR_H
