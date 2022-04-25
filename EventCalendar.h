#ifndef PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
#define PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
#include "Event.cpp"

const unsigned int MAX_EVENTS = 100;
const unsigned int DEFAULT_CAP = 10;

class EventCalendar {
private:
    Event * events;
    int numberEvents = 0;
    int maxEvents = 0;
public:
    //constructor
    EventCalendar();
    EventCalendar(const Event * events, int numberEvents, int maxEvents);

    //logic
    void addEvent(const Event & event);
    void removeEvent(const Event & event);
    const Event & searchEvent(Date date, Hour startingHour, Hour endingHour);


    //mutators
    void setEvents(const Event * events, int size);
    void setNumberEvents(int numberEvents);
    void setMaxEvents(int maxEvents);

    //destructor
    ~EventCalendar();
};

#endif //PERSONAL_CALENDAR_OOP_EVENTCALENDAR_H
