#include "Event.h"
Event::Event() {
    this->date = Date::Date();
    this->name = nullptr;
    this->comment = nullptr;
    this->startingHour = Hour::Hour();
    this->endingHour = Hour::Hour();
}

Event::Event(const Date date, const char *name, const char *comment, const Hour startingHour, const Hour endingHour) {
    this->setDate(date);
    this->setName(name);
    this->setComment(comment);
    this->setStartingHour(startingHour);
    this->setEndingHour(endingHour);
}

const Date Event::getDate() const {
    return this->date;
}

const char *Event::getName() const {
    return this->name;
}

const char *Event::getComment() const {
    return this->comment;
}

const Hour Event::getStartingHour() const {
    return this->startingHour;
}

const Hour Event::getEndingHour() const {
    return this->endingHour;
}

void Event::setDate(const Date date1) {
    if(isValid(date1))
    {
        this->date = date1;
    }

}