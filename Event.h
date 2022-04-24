#ifndef PERSONAL_CALENDAR_OOP_EVENT_H
#define PERSONAL_CALENDAR_OOP_EVENT_H

#include "Date.h"
#include "Hour.h"

class Event {
private:
    Date date;
    char *name;
    char *comment;
    Hour startingHour;
    Hour endingHour;
public:
    //constructors
    Event();
    Event(const Date date, const char *name, const char *comment, const Hour startingHour, const Hour endingHour);

    //mutators
    void setDate(const Date);
    void setName(const char *name);
    void setComment(const char *comment);
    void setStartingHour(const Hour hour);
    void setEndingHour(const Hour hour);

    //selectors
    const Date getDate() const;
    const char * getName() const;
    const char * getComment() const;
    const Hour getStartingHour() const;
    const Hour getEndingHour() const;

    //destructor
    ~Event();
};


#endif //PERSONAL_CALENDAR_OOP_EVENT_H
