#ifndef PERSONAL_CALENDAR_OOP_EVENT_H
#define PERSONAL_CALENDAR_OOP_EVENT_H

#include "Date.cpp"
#include "Time.cpp"
#include "String.h"

///The main class that drives the program
///Everything inside this project is dependant on events, being saved
///The class consists on five properties : date, name, comment, startingTime, endingTime
class Event {
private:
    Date date;
    String name;
    String comment;
    Time startingTime;
    Time endingTime;
public:
    ///constructors
    Event();
    Event(Date date, const char *name, const char *comment, Time startingTime, Time endingTime);

    ///mutators
    void setDate(Date);

    void setName(const char *name);

    void setComment(const char *comment);

    void setStartingTime(Time hour);

    void setEndingTime(Time hour);

    ///selectors
    Date getDate() const;

    String getName() const;

    String getComment() const;

    Time getStartingTime() const;

    Time getEndingTime() const;

    ///Print and save operations, helping us write events on the console or to a file
    void print(std::ostream &out = std::cout);
    void save(std::ostream &out);

    ///operator for comparison telling us whether two events are the same
    bool operator==(const Event &event) const;

    ///operator for reading an event from the console
    friend std::istream &operator>>(std::istream &in, Event &event);

};

///helper static method giving us the duration of an event in minutes
static unsigned int getDuration(const Event &event) {
    unsigned int hours = event.getEndingTime().getHour() - event.getStartingTime().getHour();
    unsigned int minutes = event.getEndingTime().getMinutes() - event.getStartingTime().getMinutes();

    return hours * 60 + minutes;
}

#endif //PERSONAL_CALENDAR_OOP_EVENT_H
