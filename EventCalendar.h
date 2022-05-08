#ifndef PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
#define PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H

#include "Event.cpp"
#include "Container.h"


class EventCalendar {
private:
    Container<Event> events;
    bool checkIfDateFree(const Date & date, const Time & startingTime, const Time & endingTime);
public:
    //constructor
    EventCalendar();
    EventCalendar(const Event * events, int numberEvents, int maxEvents);

    //logic
    void addEvent(const Event & event);
    void removeEvent(const Event & event);
    void searchEvent(String & string);
    void changeEvent(const Event& event);
    void printDayList(const Date & date);

    //mutators
    void setEvents(const Event * events, int size, int maxSize = DEFAULT_CAP);
    void writeEvents(const char * filename);

};
static Container<Event> sortEventsByStartingHour(Container<Event> & events, unsigned int numberOfEvents);

#endif //PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
