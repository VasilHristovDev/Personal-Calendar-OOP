#ifndef PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
#define PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H

#include "Event.cpp"
#include "Container.h"

///The main operable class that contains all the logic of the project. It consists only of one property a Container class of type Events
class EventCalendar {
private:
    Container<Event> events;
public:

    ///constructors
    EventCalendar();
    ///Eventually if we start reading events from file in example, we could need that constructor
    EventCalendar(const Event * events, int numberEvents, int maxEvents);

    ///logic for commands that the program must execute
    /// Storing an event inside our EventCalendar
    void addEvent(const Event & event);

    ///Removing an event by given information about it
    void removeEvent(const Event & event);

    ///Printing an event by given string ( the name and the comment of the event are checked if they contain the given string)
    void searchEvent(String & string);

    ///Change information for a given event (date,time, name and comment)
    void changeEvent(const Event& event);

    ///Print all events that are on a given date
    void printDayList(const Date & date);

    ///Output all events sorted by duration for a given time span
    void outputScheduleFromTo(const Date & dateStart, const Date & dateEnd);

    /// Find free time for an event by given date, starting time, ending time and duration
    void findFreeTime(const Date & dateStart, const Date & dateEnd, const Time & startTime, const Time & endTime, int duration);

    ///mutators
    void setEvents(const Event * events, int size, int maxSize = DEFAULT_CAP);
    void writeEvents(const char * filename);
    void readEvents(const char * filename);

};
///Helper static function that sorts given container of events by starting hour
static void sortEventsByStartingHour(Container<Event> & events);

///Helper static function that sorts dates by busiest and returns all dates event durations
static int * sortDatesFromBusiestAndGetDurations(Container<Event> & givenEvents, Container<Date> & givenDates);

///Checker function that tells whether a date by given starting time and ending time is free
bool checkIfDateFree(const Date & date, const Time & startingTime, const Time & endingTime, Container<Event> & events);

///Helper function that constructs the filename for outputting the schedule from a given date
static String constructFileName(const Date & startDate);

///Helper function that sorts events by duration
static void sortEventsByDuration(Container<Event> & container);

#endif //PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
