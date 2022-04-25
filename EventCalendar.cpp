#include "EventCalendar.h"
const char * EVENT_NOT_FOUND_ERROR = "Event with this information was not found!";


EventCalendar::EventCalendar() {
    this->events = nullptr;
    this->numberEvents = 0;
    this->maxEvents = DEFAULT_CAP;
}

EventCalendar::EventCalendar(const Event *events, const int numberEvents, const int maxEvents) {
    this->setEvents(events, numberEvents);
    this->setNumberEvents(numberEvents);
    this->setMaxEvents(maxEvents);
}

void EventCalendar::setMaxEvents(int _maxEvents) {
    this->maxEvents = _maxEvents;
}

void EventCalendar::setEvents(const Event * _events, int size) {
    this->numberEvents = size;
    this->events = new Event[size];
    for (int i = 0; i < this->numberEvents ; ++i) {
        this->events[i].setDate(_events[i].getDate());
        this->events[i].setName(_events[i].getName());
        this->events[i].setComment(_events[i].getComment());
        this->events[i].setStartingHour(_events[i].getStartingHour());
        this->events[i].setEndingHour(_events[i].getEndingHour());
    }
}

void EventCalendar::setNumberEvents(int _numberEvents) {
    this->numberEvents = _numberEvents;
}

void EventCalendar::addEvent(const Event &event) {
    this->events[this->numberEvents].setDate(event.getDate());
    this->events[this->numberEvents].setName(event.getName());
    this->events[this->numberEvents].setComment(event.getComment());
    this->events[this->numberEvents].setStartingHour(event.getStartingHour());
    this->events[this->numberEvents].setEndingHour(event.getEndingHour());
    this->numberEvents++;
}

void EventCalendar::removeEvent(const Event &event) {
    bool flag = false;
    for (int i = 0; i < numberEvents ; ++i) {
        if(this->events[i] == event)
        {
            this->events[i] = this->events[i+1];
            this->numberEvents--;
            flag = true;
        }
    }
    if(!flag) std::cerr<<EVENT_NOT_FOUND_ERROR<<std::endl;

}

const Event &EventCalendar::searchEvent(Date date, Hour startingHour, Hour endingHour) {
    for (int i = 0; i < numberEvents ; ++i) {
        if(this->events[i].getStartingHour() == startingHour && this->events[i].getEndingHour() == endingHour && this->events[i].getDate() == date)
        {
            return this->events[i];
        }
    }
     std::cout<<EVENT_NOT_FOUND_ERROR<<std::endl;
}
EventCalendar::~EventCalendar() {
    delete [] this->events;
}

