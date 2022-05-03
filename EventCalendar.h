#ifndef PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
#define PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
#include "Event.cpp"
#include "EventContainer.h"


class EventCalendar {
private:
    EventContainer<> events;
    bool checkIfDateFree(const Date & date, const Hour & startingHour, const Hour & endingHour);
    Event * sortEventsByStartingHour(const EventContainer<> * events);
public:
    //constructor
    EventCalendar();
    EventCalendar(const Event * events, int numberEvents, int maxEvents);

    //logic
    void addEvent(const Event & event);
    void removeEvent(const Event & event);
    void searchEvent(const char * string);
    void printDayList(const Date & date);


    //mutators
    void setEvents(const Event * events, int size);
    void setNumberEvents(int numberEvents);
    void setMaxEvents(int maxEvents);

    //destructor
    ~EventCalendar();
};

#endif //PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
