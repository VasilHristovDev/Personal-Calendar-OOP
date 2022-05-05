#ifndef PERSONAL_CALENDAR_OOP_EVENT_H
#define PERSONAL_CALENDAR_OOP_EVENT_H

#include "Date.cpp"
#include "Time.cpp"

class Event {
private:
    Date date;
    char *name{};
    char *comment{};
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
    const char * getName() const;
    const char * getComment() const;
    Time getStartingTime() const;
    Time getEndingTime() const;

    void print(std::ostream & out);

    bool operator == (const Event & event) const;
    Event & operator = (const Event & other);

    //destructor
    ~Event();
};


#endif //PERSONAL_CALENDAR_OOP_EVENT_H
