//
// Created by VasilHristovDev on 23.4.2022 г..
//
#include "Date.h"

const char DATE_SEPARATOR = '/';

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
enum daysMonths {
    JANUARY_DAYS = 31,
    FEBRUARY_DAYS = 28,
    MARCH_DAYS = 31,
    APRIL_DAYS = 30,
    MAY_DAYS = 31,
    JUNE_DAYS = 30,
    JULY_DAYS = 31,
    AUGUST_DAYS = 31,
    SEPTEMBER_DAYS = 30,
    OCTOBER_DAYS = 31,
    NOVEMBER_DAYS = 30,
    DECEMBER_DAYS = 31
};

bool isValid(const Date &date) {
    months givenMonth = (months) (date.getMonth());
    unsigned int days = date.getDay();
    unsigned int year = date.getYear();
    
    bool isLeapYear = year % 4 == 0 || year % 400 == 0;
    switch (givenMonth) {
        case JANUARY:
            if (days > JANUARY_DAYS) return false;
            break;
        case FEBRUARY:
            if ((isLeapYear && days > FEBRUARY_DAYS + 1) || (!isLeapYear && days > FEBRUARY_DAYS)) return false;
            break;
        case MARCH:
            if (days > MARCH_DAYS) return false;
            break;
        case APRIL:
            if (days > APRIL_DAYS) return false;
            break;
        case MAY:
            if (days > MAY_DAYS) return false;
            break;
        case JUNE:
            if (days > JUNE_DAYS) return false;
            break;
        case JULY:
            if (days > JULY_DAYS) return false;
            break;
        case AUGUST:
            if (days > AUGUST_DAYS) return false;
            break;
        case SEPTEMBER:
            if (days > SEPTEMBER_DAYS) return false;
            break;
        case OCTOBER:
            if (days > OCTOBER_DAYS) return false;
            break;
        case NOVEMBER:
            if (days > NOVEMBER_DAYS) return false;
            break;
        case DECEMBER:
            if (days > DECEMBER_DAYS) return false;
            break;
        default:
            return false;
    }
    return true;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}


void Date::print(std::ostream &out) const {
    out << this->day << DATE_SEPARATOR << this->month << DATE_SEPARATOR << this->year << std::endl;
}

Date::Date() {
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

void Date::setDay(unsigned int _day) {
    this->day = _day;
}

void Date::setMonth(unsigned int _month) {
    this->month = _month;
}

void Date::setYear(unsigned int _year) {
    this->year = _year;
}

unsigned int Date::getDay() const {
    return this->day;
}

unsigned int Date::getMonth() const {
    return this->month;
}

unsigned int Date::getYear() const {
    return this->year;
}