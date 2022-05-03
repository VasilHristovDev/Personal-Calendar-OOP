//
// Created by vorte on 24.4.2022 г..
//

#include "Hour.h"

const char HOUR_SEPARATOR = ':';
const char * HOUR_INPUT_HELPER_MESSAGE = "Please enter the hour in the following format: hh:ii";

unsigned int Hour::getHour() const {
    return this->hour;
}

unsigned int Hour::getMinutes() const {
    return this->minutes;
}

void Hour::setHour(const unsigned int _hour) {
    this->hour = _hour;
}

void Hour::setMinutes(const unsigned int _minutes) {
    this->minutes = _minutes;
}

Hour::Hour() {
    this->minutes = 0;
    this->hour = 0;
}

Hour::Hour(unsigned int hour, unsigned int minutes) {
    this->hour = hour;
    this->minutes = minutes;
}

void Hour::print(std::ostream &out) {
    out << (this->hour < 10 ? "0" : "") << this->hour << HOUR_SEPARATOR << (this->minutes < 10 ? "0" : "")
        << this->minutes;
}

bool Hour::operator==(const Hour &hour1) const {
    return this->hour == hour1.getHour() && this->minutes == hour1.getMinutes();
}

Hour &Hour::operator=(const Hour &other) {
    if (this != &other) {
        this->hour = other.hour;
        this->minutes = other.minutes;
    }
    return *this;
}

bool Hour::operator<(const Hour &hour1) const {
    return this->hour < hour1.getHour() || (this->hour == hour1.getHour() && this->minutes < hour1.getMinutes());
}

bool Hour::operator>(const Hour &hour1) const {
    return this->hour > hour1.getHour() || (this->hour == hour1.getHour() && this->minutes > hour1.getMinutes());
}

std::istream &operator>>(std::istream &in, Hour &hour) {
    std::cout<< HOUR_INPUT_HELPER_MESSAGE<<std::endl;
    in >> hour.hour;
    in >> hour.minutes;

    return in;
}
