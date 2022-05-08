#include "Event.h"
#include "Helper.h"

Event::Event():date(), name(), comment(),startingTime(),endingTime(){
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

String Event::getName() const {
    return this->name;
}

String Event::getComment() const {
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
    this->name = _name;
}

void Event::setComment(const char *_comment) {
    this->comment = _comment;
}

void Event::setStartingTime(Time hour) {
    if(isValidTime(hour)) {
        this->startingTime.setHour(hour.getHour());
        this->startingTime.setMinutes(hour.getMinutes());
    }
    else {
        std::cerr<<Helper::INVALID_TIME_ERROR_MESSAGE<<std::endl;
    }

}

void Event::setEndingTime(Time hour) {
    if(isValidTime(hour)) {
        this->endingTime.setHour(hour.getHour());
        this->endingTime.setMinutes(hour.getMinutes());
    }
    else {
        std::cerr<<Helper::INVALID_TIME_ERROR_MESSAGE<<std::endl;
    }

}

bool Event::operator==(const Event &event) const {
    return this->date == event.getDate() && this->startingTime == event.getStartingTime() && this->endingTime ==
                                                                                             event.getEndingTime();
}

//Event &Event::operator=(const Event &other) {
//    if(this != &other)
//    {
//        this->date = other.date;
//        this->name = other.name;
//        this->comment = other.comment;
//        this->startingTime = other.startingTime;
//        this->endingTime = other.endingTime;
//    }
//    return *this;
//}

void Event::print(std::ostream &out) {
    out <<"name: "<< this->name <<std::endl;
    out<<"comment:  "<< this->comment<<std::endl;
    this->date.print(out);
    out<<"time: ";
    this->startingTime.print(out);
    out << " - ";
    this->endingTime.print(out);
    std::cout << std::endl;
}

std::istream &operator>>(std::istream &in, Event &event) {
    in>>event.date;
    std::cout<<Helper::NAME_INPUT_HELPER_MESSAGE<<std::endl;
    in.ignore();
    in>>event.name;
    std::cout<<Helper::COMMENT_INPUT_HELPER_MESSAGE<<std::endl;
    in>>event.comment;
    in>>event.startingTime;
    in>>event.endingTime;
    return in;
}

void Event::save(std::ostream & out) {
    this->print(out);
}


