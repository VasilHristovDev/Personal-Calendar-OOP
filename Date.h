#include <iostream>
#include "Container.h"

#ifndef PERSONAL_CALENDAR_OOP_DATE_H
#define PERSONAL_CALENDAR_OOP_DATE_H
///Helper enum variable that helps us use a date's month like a constant and not using numbers
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

///Date class that consists on three properties: day, month and year
class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:

    ///default constructor used for default constructor of the Event class
    Date();
    ///constructor with parameters
    Date(unsigned int day, unsigned int month, unsigned int year);

    ///setters
    void setDay(unsigned int day);
    void setMonth(unsigned int month);
    void setYear(unsigned int year);

    ///getters
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;

    ///print method that helps us display information for the date
    void print(std::ostream & out = std::cout) const;
    ///comparison operator related to : telling whether two dates are the same
    bool operator == (const Date & date1) const;

    ///comparison operators related to: determining a period of time between two dates
    bool operator <=(const Date & date1) const;
    bool operator >=(const Date & date1) const;

    ///incrementation operators changing the date to the next
    Date & operator++();
    Date operator++(int);

    ///operator for assignment
    Date & operator = (const Date & other);

    ///operator for reading the date from the console
    friend std::istream & operator >> (std::istream & in, Date &date);

    ///miscellaneous function printing the day of the week of the date
    void printDayOfWeek(std::ostream & out = std::cout) const;
};
///checker telling whether a given date is valid or not
bool isValid(const Date & date);

///checker telling whether the year in a date is leap or not
bool isLeapYearChecker(unsigned int year);

///checker that tells us whether a date has more days than it is supposed to
bool doesNotHaveMoreDays(unsigned int days, months givenMonth, bool isLeap);

///function that calculates which day of the week a given date is
unsigned int getDayOfWeek(const Date & date);

///function that returns container with all dates from a given start and end date
Container <Date> getAllDatesFromPeriod(const Date & dateStart, const Date & dateEnd);


#endif //PERSONAL_CALENDAR_OOP_DATE_H
