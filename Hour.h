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
    bool operator ==(const Hour & hour1) const;
    bool operator <(const Hour & hour1) const;
    bool operator >(const Hour & hour1) const;
    Hour & operator = (const Hour & other);
};


#endif //PERSONAL_CALENDAR_OOP_HOUR_H
