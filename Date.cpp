#include "Date.h"
#include "Helper.h"
#include <cmath>
//enum variable that hold the values for each day of the week that helps us determine which day of the week a given date is
enum dayOfWeek {
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
    SUNDAY = 0
};
//enum variable that holds how many dates a given month has ( used for validation )
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
//function that returns whether a year is leap or not
bool isLeapYearChecker(unsigned int year)
{
    if ((year % 400 == 0 || year % 4 == 0) && year % 100 != 0 ) {
        return true;
    }
    return false;
}
// function that validates whether a given date is correct ( checks if the given days are valid for the given month )
bool doesNotHaveMoreDays(unsigned int days, months givenMonth, bool isLeap)
{
    switch (givenMonth) {
        case JANUARY:
            if (days > JANUARY_DAYS) return false;
            break;
        case FEBRUARY:
            if ((isLeap && days > FEBRUARY_DAYS + 1) || (!isLeap && days > FEBRUARY_DAYS)) return false;
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
//The validator function returns if a date is valid or not
bool isValid(const Date &date) {
    months givenMonth = (months) (date.getMonth());
    unsigned int days = date.getDay();
    unsigned int year = date.getYear();
    bool isLeapYear = isLeapYearChecker(year);

    return doesNotHaveMoreDays(days,givenMonth,isLeapYear);
}
/*
 * A function that I wanted to implement
 * The reference that helped me is on this link : https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
 * It is only for aesthetic purposes
 * The formula I used to calculate is displayed in the website
 * Also I found a period that is not being calculated well ( 1st Jan 2005 - 4 th Jan 2005 )
 */
unsigned int getDayOfWeek(const Date &date) {

    unsigned int day = date.getDay();
    unsigned int month = date.getMonth();
    if (month >= MARCH)
        month -= Helper::MONTH_DIFFERENCE_CONST;
    else {
        month += 10;
    }
    int century = date.getYear() / 100;
    int year;
    if (month == 11 || month == 12)
        year = date.getYear() % 100 - 1;
    else
        year = date.getYear() % 100;
    int yearByFour = floor(year / 4);
    int centuryByFour = floor(century / 4);
    int monthManipulation = floor(2.6 * month - 0.2);

    return (day + monthManipulation - 2 * century + year + yearByFour + centuryByFour) % 7;

}
//constructors
Date::Date() : day(1), month(1), year(2001) {}
Date::Date(unsigned int day, unsigned int month, unsigned int year) : day(day), month(month), year(year) {}

//print method
void Date::print(std::ostream &out) const {
    out << "date: ";
    this->printDayOfWeek(out);
    out << (this->day < 10 ? "0" : "") << this->day << Helper::DATE_SEPARATOR << (this->month < 10 ? "0" : "")
        << this->month << Helper::DATE_SEPARATOR << this->year;
}
//setters
void Date::setDay(unsigned int _day) {
    this->day = _day;
}

void Date::setMonth(unsigned int _month) {
    this->month = _month;
}

void Date::setYear(unsigned int _year) {
    this->year = _year;
}
//getters
unsigned int Date::getDay() const {
    return this->day;
}

unsigned int Date::getMonth() const {
    return this->month;
}

unsigned int Date::getYear() const {
    return this->year;
}
//operator that checks whether two dates are the same
bool Date::operator==(const Date &date1) const {
    return this->day == date1.getDay() && this->month == date1.getMonth() && this->year == date1.getYear();
}
//assignment operator
Date &Date::operator=(const Date &other) {
    if (this != &other && isValid(other)) {
        this->setDay(other.getDay());
        this->setMonth(other.getMonth());
        this->setYear(other.getYear());
    }
    return *this;
}
//operator for reading date from the console
std::istream &operator>>(std::istream &in, Date &date) {
    std::cout << Helper::DATE_INPUT_HELPER_MESSAGE << std::endl;
    in >> date.day;
    //ignore the date separator
    in.ignore(1);
    in >> date.month;
    //ignore the date separator
    in.ignore(1);
    in >> date.year;
    if (!isValid(date)) {
        std::cerr << Helper::INVALID_DATE_MESSAGE << std::endl;
    }
    return in;
}
//method that prints which day of the week a date is
void Date::printDayOfWeek(std::ostream &out) const {
    switch (getDayOfWeek(*this)) {
        case MONDAY:
            out << "Mon ";
            break;
        case TUESDAY:
            out << "Tue ";
            break;
        case WEDNESDAY:
            out << "Wed ";
            break;
        case THURSDAY:
            out << "Thu ";
            break;
        case FRIDAY:
            out << "Fri ";
            break;
        case SATURDAY:
            out << "Sat ";
            break;
        case SUNDAY:
            out << "Sun ";
            break;
        default:
            out << "Invalid day of week ";
            break;
    }
}
//operator for checking whether a date is before or it matches a given date
bool Date::operator<=(const Date &date1) const {
    if(this->year < date1.getYear())
    {
        return true;
    }
    else if(this->year == date1.getYear())
    {
        if(this->month < date1.getMonth())
            return true;
        else if(this->month == date1.getMonth())
        {
            if(this->day <= date1.getDay())
            {
                return true;
            }
            else
                return false;
        }
        else {
            return false;
        }
    }
    return false;
}
//operator for checking whether a date is after or it matches a given date
bool Date::operator>=(const Date &date1) const {
    if(this->year > date1.getYear())
    {
        return true;
    }
    else if(this->year == date1.getYear())
    {
        if(this->month > date1.getMonth())
            return true;
        else if(this->month == date1.getMonth())
        {
            if(this->day >= date1.getDay())
            {
                return true;
            }
            else
                return false;
        }
        else {
            return false;
        }
    }
    return false;
}
//operator for incrementation of a date ( prefix )
Date &Date::operator++() {
    unsigned int monthReturnable = this->month;
    unsigned int daysReturnable = this->day;
    unsigned int yearReturnable = this->year;
    //we check if the next date is after the given month
    if(!doesNotHaveMoreDays(daysReturnable + 1, (months) monthReturnable, isLeapYearChecker(yearReturnable)))
    {
        //if it does we check if the month is the next after december
        if((months)(monthReturnable + 1) > DECEMBER)
        {
            //if it is the date becomes 1/1 of the next year
            yearReturnable++;
            monthReturnable = 1;
            daysReturnable = 1;
        }
        else
        {
            //if it is not we increment the month and set the days to 1
            daysReturnable = 1;
            monthReturnable++;
        }
    }
    else
    {
        //we simply increment the days
        daysReturnable++;
    }
    this->setYear(yearReturnable);
    this->setMonth(monthReturnable);
    this->setDay(daysReturnable);

    return *this;
}
//a postfix operator for the date
Date Date::operator++(int) {
    Date old = *this;
    operator++();
    return old;
}

bool Date::operator>(const Date &date1) const {
    if ( year == date1.year)
    {
        if(month == date1.month)
        {
            return day > date1.day;
        }
        else
        {
            return month > date1.month;
        }
    }
    return year > date1.year;
}

bool Date::operator<(const Date &date1) const {
    return !(*this > date1);
}

void Date::read(std::istream &in) {
    in.ignore(10);
    in>>this->day;
    in.ignore(1);
    in>>this->month;
    in.ignore(1);
    in>>this->year;
}

//a method that returns a container with all the dates from a given period
Container<Date> getAllDatesFromPeriod(const Date & dateStart, const Date & dateEnd)
{
    Date currDate = dateStart;
    Container<Date> returnableDates;

    while(currDate <= dateEnd)
    {
        //here we use the postfix operator for date incrementation
        returnableDates.add(currDate++);
    }

    return returnableDates;
}



