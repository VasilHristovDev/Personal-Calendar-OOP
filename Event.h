#ifndef PERSONAL_CALENDAR_OOP_EVENT_H
#define PERSONAL_CALENDAR_OOP_EVENT_H

#include "Date.cpp"
#include "Hour.cpp"

class Event {
private:
    Date date;
    char *name{};
    char *comment{};
    Hour startingHour;
    Hour endingHour;
public:
    //constructors
    Event();
    Event(Date date, const char *name, const char *comment, Hour startingHour, Hour endingHour);

    //mutators
    void setDate(Date);
    void setName(const char *name);
    void setComment(const char *comment);
    void setStartingHour(Hour hour);
    void setEndingHour(Hour hour);

    //selectors
    const Date getDate() const;
    const char * getName() const;
    const char * getComment() const;
    Hour getStartingHour() const;
    Hour getEndingHour() const;

    void print(std::ostream & out);

    bool operator == (const Event & event) const;
    Event & operator = (const Event & other);
    //destructor
    ~Event();
};


#endif //PERSONAL_CALENDAR_OOP_EVENT_H
