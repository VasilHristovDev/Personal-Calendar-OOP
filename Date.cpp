//
// Created by VasilHristovDev on 23.4.2022 г..
//
#include "Date.h"

static const char *INVALID_DATE_MESSAGE = "The date u entered is invalid!";
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

 bool isValid(const Date & date) {
    months givenMonth = (months) (date.month);
    bool isLeapYear = date.year % 4 == 0 || date.year % 400 == 0;
    switch (givenMonth) {
        case JANUARY:
            if (date.day > JANUARY_DAYS) return false;
            break;
        case FEBRUARY:
            if ((isLeapYear && date.day > FEBRUARY_DAYS + 1) || (!isLeapYear && date.day > FEBRUARY_DAYS)) return false;
            break;
        case MARCH:
            if (date.day > MARCH_DAYS) return false;
            break;
        case APRIL:
            if (date.day > APRIL_DAYS) return false;
            break;
        case MAY:
            if (date.day > MAY_DAYS) return false;
            break;
        case JUNE:
            if (date.day > JUNE_DAYS) return false;
            break;
        case JULY:
            if (date.day > JULY_DAYS) return false;
            break;
        case AUGUST:
            if (date.day > AUGUST_DAYS) return false;
            break;
        case SEPTEMBER:
            if (date.day > SEPTEMBER_DAYS) return false;
            break;
        case OCTOBER:
            if (date.day > OCTOBER_DAYS) return false;
            break;
        case NOVEMBER:
            if (date.day > NOVEMBER_DAYS) return false;
            break;
        case DECEMBER:
            if (date.day > DECEMBER_DAYS) return false;
            break;
        default:
            return false;
    }
    return true;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    if (this->isValid(day, month, year)) {
        this->day = day;
        this->month = month;
        this->year = year;
    } else
        std::cerr << INVALID_DATE_MESSAGE << std::endl;
}


void Date::print(std::ostream &out) {
    out << this->day << DATE_SEPARATOR << this->month << DATE_SEPARATOR << this->year << std::endl;
}

Date::Date() {
    this->day = 0;
    this->month = 0;
    this->year = 0;
}
