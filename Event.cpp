#include "Event.h"

Event::Event() {
    this->setDate( Date());
    this->name = nullptr;
    this->comment = nullptr;
    this->setStartingHour(Hour());
    this->setEndingHour(Hour());
}

Event::Event(Date date, const char *name, const char *comment, const Hour startingHour, const Hour endingHour) {
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

 Hour Event::getStartingHour() const {
    return this->startingHour;
}

 Hour Event::getEndingHour() const {
    return this->endingHour;
}

void Event::setDate(const Date date1) {
    if(isValid(date1))
    {
        this->date.setDay(date1.getDay());
        this->date.setMonth(date1.getMonth());
        this->date.setYear(date1.getYear());
    }
    else
        std::cerr<<INVALID_DATE_MESSAGE<<std::endl;
}

void Event::setName(const char * _name) {
    if(this->name != nullptr) delete [] this->name;

    this->name = new char [strlen(_name)];
    strcpy(this->name, _name);
}

void Event::setComment(const char * _comment) {
    if(this->comment != nullptr) delete [] this->comment;

    this->comment = new char [strlen(_comment)];
    strcpy(this->comment, _comment);
}

void Event::setStartingHour(const Hour hour) {
    this->startingHour.setHour(hour.getHour());
    this->startingHour.setMinutes(hour.getMinutes());
}

void Event::setEndingHour(const Hour hour) {
    this->endingHour.setHour(hour.getHour());
    this->endingHour.setMinutes(hour.getMinutes());;
}

bool Event::operator==(const Event &event) const {
    return this->date == event.getDate() && this->startingHour == event.getStartingHour() && this->endingHour == event.getEndingHour();
}

Event & Event::operator=(const Event &other) {
    if(this != &other)
    {
        this->date = other.getDate();
        this->setName(other.getName());
        this->setComment(other.getComment());
        this->startingHour = other.getStartingHour();
        this->endingHour = other.getEndingHour();
    }
    return *this;
}

void Event::print(std::ostream &out) {
    out<<this->name<<std::endl<<this->comment;
    this->date.print(out);
    this->startingHour.print(out);
    out<<" - ";
    this->endingHour.print(out);
}
Event::~Event() = default;


