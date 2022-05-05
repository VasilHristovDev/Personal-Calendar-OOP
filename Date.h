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
    void print(std::ostream & out = std::cout) const;
    void setDay(unsigned int day);
    void setMonth(unsigned int month);
    void setYear(unsigned int year);

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    bool operator == (const Date & date1) const;
    Date & operator = (const Date & other);
    friend std::istream & operator >> (std::istream & in, Date &date);
};
bool isValid(const Date & date);


#endif //PERSONAL_CALENDAR_OOP_DATE_H
