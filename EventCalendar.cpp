#include "EventCalendar.h"
#include <cstring>

const char * EVENT_NOT_FOUND_ERROR = "Event with this information was not found!";
const char * DATE_NOT_FREE_ERROR_MESSAGE = "The event cannot be added because an event with the same date exists!";


EventCalendar::EventCalendar() {
    this->events = EventContainer<>();
}
/**
 *
 * @param events
 * @param numberEvents
 * @param maxEvents
 */
EventCalendar::EventCalendar(const EventContainer<> *events, const int numberEvents, const int maxEvents) {
    this->setEvents(events, numberEvents);
    this->setMaxEvents(maxEvents);
}
/**
 *
 * @param _maxEvents
 */

/**
 *
 * @param _events
 * @param size
 */
void EventCalendar::setEvents(const Event * _events, int size) {
    this->events = EventContainer<Event>( _events, size);
    for (int i = 0; i < this->events ; ++i) {
        this->events->add(_events[i]);
    }
}
/**
 *
 * @param _numberEvents
 */
void EventCalendar::setNumberEvents(int _numberEvents) {
    this->numberEvents = _numberEvents;
}
/**
 *
 * @param Event event
 */
void EventCalendar::addEvent(const Event &event) {
    if(this->checkIfDateFree(event.getDate(), event.getStartingHour(), event.getEndingHour()))
    {
        this->events[this->numberEvents] = event;
        this->numberEvents++;
    }
    else {
        std::cerr<<DATE_NOT_FREE_ERROR_MESSAGE<<std::endl;
    }

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
/**
 *
 * @param string
 */
void EventCalendar::searchEvent(const char *string) {
    for (int i = 0; i < this->numberEvents ; ++i) {
        char * commentStr = strstr(this->events[i].getComment(), string);
        char * nameStr = strstr(this->events[i].getName(), string);
        if(commentStr || nameStr)
            this->events[i].print(std::cout);
    }
}
/**
 *
 */
EventCalendar::~EventCalendar() {
    delete [] this->events;
}
/**
 *
 * @param Date date
 * @param Hour startingHour
 * @param Hour endingHour
 * @return bool
 */
bool EventCalendar::checkIfDateFree( const Date &date, const Hour &startingHour, const Hour &endingHour) {
    for (int i = 0; i < this->numberEvents ; ++i) {
        if(this->events[i].getDate() == date)
        {
            if(this->events[i].getStartingHour() < startingHour && this->events[i].getEndingHour() > startingHour)
                return false;
        }
    }
    return true;
}

void EventCalendar::printDayList(const Date &date) {
    int counterEvents = 0;
    for (int i = 0; i < this->numberEvents ; ++i) {
        if(this->events[i].getDate() == date)
        {
            counterEvents++;
        }
    }

    Event * eventsForDay = new Event[counterEvents];
    int tempC = 0;
    for (int i = 0; i < this->numberEvents; ++i) {
        if(this->events[i].getDate() == date)
        {
            eventsForDay[tempC++] = this->events[i];
        }
    }

    for (int i = 0; i < counterEvents ; ++i) {
        for (int j = i + 1; j < counterEvents; ++j) {
           if(eventsForDay[i].getStartingHour() > eventsForDay[j].getStartingHour())
           {
               Event tempEvent = eventsForDay[i];
               eventsForDay[i] = eventsForDay[j];
               eventsForDay[j] = tempEvent;
           }
        }
    }

    for (int i = 0; i < counterEvents ; ++i) {
        eventsForDay[i].print(std::cout);
    }
    delete [] eventsForDay;

}

Event *EventCalendar::sortEventsByStartingHour(const Event *events, unsigned int numberEvents) {
    Event * eventsSorted = new Event [numberEvents];
    for (int i = 0; i < numberEvents ; ++i) {

    }
}

