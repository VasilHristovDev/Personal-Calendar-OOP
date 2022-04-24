#include <iostream>

#ifndef PERSONAL_CALENDAR_OOP_DATE_H
#define PERSONAL_CALENDAR_OOP_DATE_H


class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date();
    Date(unsigned int day, unsigned int month, unsigned int year);
    void print(std::ostream & out);
//    void read(std::ifstream & in);
    friend bool isValid(const Date & date);
};


#endif //PERSONAL_CALENDAR_OOP_DATE_H
