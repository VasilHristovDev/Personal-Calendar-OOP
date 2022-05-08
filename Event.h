#ifndef PERSONAL_CALENDAR_OOP_EVENT_H
#define PERSONAL_CALENDAR_OOP_EVENT_H

#include "Date.cpp"
#include "Time.cpp"
#include "String.h"

class Event {
private:
    Date date;
    String name;
    String comment;
    Time startingTime;
    Time endingTime;
public:
    //constructors
    Event();
    Event(Date date, const char *name, const char *comment, Time startingTime, Time endingTime);

    //mutators
    void setDate(Date);
    void setName(const char *name);
    void setComment(const char *comment);
    void setStartingTime(Time hour);
    void setEndingTime(Time hour);

    //selectors
    Date getDate() const;
    String getName() const;
    String getComment() const;
    Time getStartingTime() const;
    Time getEndingTime() const;

    void print(std::ostream & out = std::cout);
    void save(std::ostream & out);
//    Event & operator=(const Event & other);
    bool operator == (const Event & event) const;
    friend std::istream & operator >> (std::istream & in, Event & event);

};

static unsigned int getDuration(const Event & event) {
    unsigned int hours = event.getEndingTime().getHour() - event.getStartingTime().getHour();
    unsigned int minutes = event.getEndingTime().getMinutes() - event.getStartingTime().getMinutes();

    return hours * 60 + minutes;
}

#endif //PERSONAL_CALENDAR_OOP_EVENT_H
