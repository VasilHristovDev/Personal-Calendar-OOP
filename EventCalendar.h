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
    void outputScheduleFromTo(const Date & dateStart, const Date & dateEnd);

    //mutators
    void setEvents(const Event * events, int size, int maxSize = DEFAULT_CAP);
    void writeEvents(const char * filename);

};
static void sortEventsByStartingHour(Container<Event> & events, unsigned int numberOfEvents);
static int * sortDatesFromBusiestAndGetDurations(Container<Event> & givenEvents, Container<Date> & givenDates);
static String constructFileName(const Date & startDate);
static void sortEventsByDuration(Container<Event> & container);

#endif //PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
