#include "Date.h"
#include "Helper.h"

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
    //TODO: Implement correct logic for leap year!!!!
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
Date::Date():day(1),month(1),year(2001) {}
Date::Date(unsigned int day, unsigned int month, unsigned int year):day(day),month(month),year(year){}


void Date::print(std::ostream &out) const {
    out<<"date: ";
    out << this->day << Helper::DATE_SEPARATOR << this->month << Helper::DATE_SEPARATOR << this->year << std::endl;
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

bool Date::operator==(const Date &date1) const {
    return this->day == date1.getDay() && this->month == date1.getMonth() && this->year == date1.getYear();
}

Date &Date::operator=(const Date &other) {
    if(this != &other && isValid(other)) {
        this->setDay(other.getDay());
        this->setMonth(other.getMonth());
        this->setYear(other.getYear());
    }
    return *this;
}

std::istream &operator>>(std::istream &in, Date &date) {
    std::cout << Helper::DATE_INPUT_HELPER_MESSAGE << std::endl;
    in >> date.day;
    in.ignore(1);
    in >> date.month;
    in.ignore(1);
    in >> date.year;
    if(!isValid(date)) {
        std::cerr<<Helper::INVALID_DATE_MESSAGE<<std::endl;
    }
    return in;
}

