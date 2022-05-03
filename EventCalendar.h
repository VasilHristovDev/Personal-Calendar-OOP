#ifndef PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
#define PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
#include "Event.cpp"
#include "EventContainer.h"


class EventCalendar {
private:
    EventContainer<Event> events;
    bool checkIfDateFree(const Date & date, const Hour & startingHour, const Hour & endingHour);
public:
    //constructor
    EventCalendar();
    EventCalendar(const Event * events, int numberEvents, int maxEvents);

    //logic
    void addEvent(const Event & event);
    void removeEvent(const Event & event);
    void searchEvent(const char * string);
    void changeEvent(const Event& event);
    void printDayList(const Date & date);


    //mutators
    void setEvents(const Event * events, int size, int maxSize = DEFAULT_CAP);

};
static EventContainer<Event> sortEventsByStartingHour(const Event * events, unsigned int numberOfEvents);

#endif //PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
