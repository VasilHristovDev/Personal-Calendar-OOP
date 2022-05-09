#include <iostream>
#include "Container.h"

#ifndef PERSONAL_CALENDAR_OOP_DATE_H
#define PERSONAL_CALENDAR_OOP_DATE_H
enum months {
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12
};

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
    bool operator <=(const Date & date1) const;
    bool operator >=(const Date & date1) const;
    Date & operator++();
    Date operator++(int);
    friend std::istream & operator >> (std::istream & in, Date &date);
    void printDayOfWeek(std::ostream & out = std::cout) const;
};
bool isValid(const Date & date);
bool isLeapYearChecker(unsigned int year);
bool doesNotHaveMoreDays(unsigned int days, months givenMonth, bool isLeap);
unsigned int getDayOfWeek(const Date & date);
Container <Date> getAllDatesFromPeriod(const Date & dateStart, const Date & dateEnd);


#endif //PERSONAL_CALENDAR_OOP_DATE_H
