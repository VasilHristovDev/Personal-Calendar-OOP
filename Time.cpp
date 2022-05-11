#include "Time.h"
#include "Helper.h"

unsigned int Time::getHour() const {
    return this->hours;
}

unsigned int Time::getMinutes() const {
    return this->minutes;
}

void Time::setHour(const unsigned int _hour) {
    this->hours = _hour;
}

void Time::setMinutes(const unsigned int _minutes) {
    this->minutes = _minutes;
}

Time::Time() {
    this->minutes = 0;
    this->hours = 0;
}

Time::Time(unsigned int hour, unsigned int minutes) {
    this->hours = hour;
    this->minutes = minutes;
}

void Time::print(std::ostream &out) const {
    //added ternary statements to help the time printing look like a digital clock
    out << (this->hours < 10 ? "0" : "") << this->hours << Helper::TIME_SEPARATOR << (this->minutes < 10 ? "0" : "")
        << this->minutes;
}

bool Time::operator==(const Time &hour1) const {
    return this->hours == hour1.getHour() && this->minutes == hour1.getMinutes();
}

Time &Time::operator=(const Time &other) {
    if (this != &other) {
        this->hours = other.hours;
        this->minutes = other.minutes;
    }
    return *this;
}

bool Time::operator<(const Time &hour1) const {
    return this->hours < hour1.getHour() || (this->hours == hour1.getHour() && this->minutes < hour1.getMinutes());
}

bool Time::operator>(const Time &hour1) const {
    return this->hours > hour1.getHour() || (this->hours == hour1.getHour() && this->minutes > hour1.getMinutes());
}

std::istream &operator>>(std::istream &in, Time &hour) {
    std::cout << Helper::TIME_INPUT_HELPER_MESSAGE << std::endl;
    in >> hour.hours;
    in.ignore(1);
    in >> hour.minutes;
    if(!isValidTime(hour))
        std::cerr<<Helper::INVALID_TIME_ERROR_MESSAGE<<std::endl;
    return in;
}

bool Time::operator<=(const Time &time) const {
    if(this->hours <= time.getHour())
    {
        if(this->minutes <= time.getMinutes())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Time::operator>=(const Time &time) const {
    if(this->hours >= time.getHour())
    {
        if(this->minutes >= time.getMinutes())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
//validator for time
bool isValidTime(const Time & time)
{
    unsigned int hour = time.getHour();
    unsigned int minutes = time.getMinutes();

    return hour <= 23 && hour >= 0 && minutes <= 59 && minutes >= 0 ;
}
//helper function for checking if two time spans are overlapping
bool areOverlapping(const Time & startingTime1, const Time & endingTime1, const Time & startingTime2, const Time & endingTime2)
{
    return !((endingTime1 < startingTime2 && startingTime1 < startingTime2) || (endingTime2 < startingTime1 && startingTime2 < startingTime1));
}
