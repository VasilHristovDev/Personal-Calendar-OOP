#include <iostream>

#ifndef PERSONAL_CALENDAR_OOP_DATE_H
#define PERSONAL_CALENDAR_OOP_DATE_H

static const char * INVALID_DATE_MESSAGE = "The date u entered is invalid!";

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date();
    Date(unsigned int day, unsigned int month, unsigned int year);
    void print(std::ostream & out) const;
    void setDay(unsigned int day);
    void setMonth(unsigned int month);
    void setYear(unsigned int year);

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
//    void read(std::ifstream & in);
    bool operator == (const Date & date1) const;
    Date & operator = (const Date & other);
};
bool isValid(const Date & date);


#endif //PERSONAL_CALENDAR_OOP_DATE_H
