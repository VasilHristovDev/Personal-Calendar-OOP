#include "Event.h"
#include "Helper.h"

Event::Event() {
    this->setDate(Date());
    this->name = nullptr;
    this->comment = nullptr;
    this->setStartingTime(Time());
    this->setEndingTime(Time());
}

Event::Event(Date date, const char *name, const char *comment, const Time startingTime, const Time endingTime) {
    this->setDate(date);
    this->setName(name);
    this->setComment(comment);
    this->setStartingTime(startingTime);
    this->setEndingTime(endingTime);
}

Date Event::getDate() const {
    return this->date;
}

const char *Event::getName() const {
    return this->name;
}

const char *Event::getComment() const {
    return this->comment;
}

Time Event::getStartingTime() const {
    return this->startingTime;
}

Time Event::getEndingTime() const {
    return this->endingTime;
}

void Event::setDate(Date date1) {
    if (isValid(date1)) {
        this->date.setDay(date1.getDay());
        this->date.setMonth(date1.getMonth());
        this->date.setYear(date1.getYear());
    } else
        std::cerr << Helper::INVALID_DATE_MESSAGE << std::endl;
}

void Event::setName(const char *_name) {
    delete[] this->name;
    this->name = new char[strlen(_name)];
    strcpy(this->name, _name);
}

void Event::setComment(const char *_comment) {
    if (this->comment != nullptr) delete[] this->comment;

    this->comment = new char[strlen(_comment)];
    strcpy(this->comment, _comment);
}

void Event::setStartingTime(Time hour) {
    this->startingTime.setHour(hour.getHour());
    this->startingTime.setMinutes(hour.getMinutes());
}

void Event::setEndingTime(Time hour) {
    this->endingTime.setHour(hour.getHour());
    this->endingTime.setMinutes(hour.getMinutes());;
}

bool Event::operator==(const Event &event) const {
    return this->date == event.getDate() && this->startingTime == event.getStartingTime() && this->endingTime ==
                                                                                             event.getEndingTime();
}

Event &Event::operator=(const Event &other) {
    if (this != &other) {
        this->date = other.getDate();
        this->setName(other.getName());
        this->setComment(other.getComment());
        this->startingTime = other.getStartingTime();
        this->endingTime = other.getEndingTime();
    }
    return *this;
}

void Event::print(std::ostream &out) {
    out << this->name << std::endl << this->comment;
    this->date.print(out);
    this->startingTime.print(out);
    out << " - ";
    this->endingTime.print(out);
}

Event::~Event() {
    delete[] this->name;
    delete[] this->comment;
};


