#include "EventCalendar.h"
#include <cstring>
#include <fstream>


EventCalendar::EventCalendar(const Event *events, const int numberEvents, const int maxEvents) {
    this->setEvents(events, numberEvents, maxEvents);
}


void EventCalendar::setEvents(const Event *_events, int size, int maxSize) {
    this->events = Container<Event>(maxSize);
    for (int i = 0; i < size; ++i) {
        this->addEvent(_events[i]);
    }
}


void EventCalendar::addEvent(const Event &event) {
    //If the date desired is free
    //We add the event to the list
    if (checkIfDateFree(event.getDate(), event.getStartingTime(), event.getEndingTime(), this->events)) {
        this->events.add(event);
    } else {
        //We print an error
        std::cerr << Helper::DATE_NOT_FREE_ERROR_MESSAGE << std::endl;
    }

}

void EventCalendar::removeEvent(const Event &event) {
    //Flag to say whether the desired event was found in the list
    bool flag = false;
    unsigned int eventsSize = this->events.getSize();
    for (int i = 0; i < eventsSize; ++i) {
        if (this->events[i] == event) {
            this->events.remove(i);
            flag = true;
        }
    }
    if (!flag) std::cerr << Helper::EVENT_NOT_FOUND_ERROR << std::endl;
}


void EventCalendar::searchEvent(String &string) {
    unsigned int eventSize = this->events.getSize();
    // iterate through the whole list of events in the calendar
    for (int i = 0; i < eventSize; ++i) {
        //if the event's name contains the string
        bool containsName = this->events[i].getName().contains(string.getText());
        //if the event's comment contains the string
        bool containsComment = this->events[i].getComment().contains(string.getText());
        // print the event if the string is contained either in its name or in its comment
        if (containsName || containsComment)
            this->events[i].print(std::cout);
    }
}


bool checkIfDateFree(const Date &date, const Time &startingTime, const Time &endingTime, Container<Event> &events) {
    unsigned int eventSize = events.getSize();
    //iterate through all given events and where date is the same as the given
    //we check if the given starting and ending time overlaps with the event's starting and ending time
    for (int i = 0; i < eventSize; ++i) {
        if (events[i].getDate() == date) {
            if (areOverlapping(events[i].getStartingTime(), events[i].getEndingTime(), startingTime, endingTime))
                return false;
        }
    }
    return true;
}

void EventCalendar::printDayList(const Date &date) {
    unsigned int eventSize = this->events.getSize();
    Container<Event> eventContainer;
    //Fill a new container with events consisting only on events that have the same date as given
    for (int i = 0; i < eventSize; ++i) {
        if (this->events[i].getDate() == date) {
            eventContainer.add(this->events[i]);
        }
    }
    unsigned int eventsInThatDaySize = eventContainer.getSize();
    //Sort the events by starting hour
    sortEventsByStartingHour(eventContainer);
    for (int i = 0; i < eventsInThatDaySize; ++i) {
        eventContainer[i].print(std::cout);
        std::cout<<std::endl;
    }
}

void EventCalendar::changeEvent(const Event &event) {
    // Made a whole dialog for users to make them change what they desire in the given event
    std::cout << Helper::HELPER_MESSAGE_CHANGE_EVENT << std::endl;
    String command;
    std::cin.ignore();
    std::cin >> command;
    //Search the index of the event
    unsigned int index = this->events.getIndex(event);
    std::cout << index << std::endl;
    //If the event was not found on the list
    if (index == Helper::ERROR_INDEX) {
        //print an error and exit function
        std::cerr << Helper::EVENT_NOT_FOUND_ERROR << std::endl;
        return;
    } else {
        //event found message print
        std::cout << Helper::EVENT_FOUND_MESSAGE << std::endl;
    }
    //if the constructed string by the user contains letter d
    // we edit the date of the given event and its starting and ending time
    if (strstr(command.getText(), "d")) {
        Date date;
        std::cin >> date;
        Time startingHour;
        std::cin >> startingHour;
        Time endingHour;
        std::cin >> endingHour;
        // before editing it we check if the desired date, starting and ending hours are free
        if (checkIfDateFree(date, startingHour, endingHour, this->events)) {
            this->events[index].setDate(date);
            this->events[index].setStartingTime(startingHour);
            this->events[index].setEndingTime(endingHour);
        } else {
            //If they are not free, we print error message
            std::cerr << Helper::DATE_NOT_FREE_ERROR_MESSAGE << std::endl;
        }

    }
    // the letter c indicates that the user wants to change the comment of the event
    else if (strstr(command.getText(), "c")) {
        String comment;
        std::cin >> comment;
        this->events[index].setComment(comment.getText());
    }
    //the letter n indicates that the user wants to change the event's name
    else if (strstr(command.getText(), "n")) {
        String name;
        std::cin >> name;
        this->events[index].setName(name.getText());
    } else {
        std::cerr << Helper::UNKNOWN_COMMAND_USED << std::endl;
    }

}

EventCalendar::EventCalendar() : events(Container<Event>()) {}

// simple writing to a file
void EventCalendar::writeEvents(const char *filename) {

    std::ofstream out;
    out.open(filename);
    if (out) {
        unsigned int size = this->events.getSize();
        out<<"Number of events in the calendar: "<<size;
        for (int i = 0; i < size; ++i) {
            out << std::endl;
            out << i + 1 << ": " << std::endl;
            this->events[i].save(out);
        }
    }
    out.close();

}
//Constructing the filename for the show:busy action
String constructFileName(const Date &startDate) {
    char *yearStr = new char[5];
    unsigned int year = startDate.getYear();
    //build yearString
    yearStr[0] = year / 1000 + '0';
    yearStr[1] = year / 100 % 10 + '0';
    yearStr[2] = year / 10 % 10 + '0';
    yearStr[3] = year % 10 + '0';
    yearStr[4] = '\0';
    //build monthString
    char *monthStr = new char[3];
    unsigned int month = startDate.getMonth();
    monthStr[0] = (month < OCTOBER ? '0' : (month / 10 % 10 + '0'));
    monthStr[1] = month % 10 + '0';
    monthStr[2] = '\0';
    //build dayString
    char *dayStr = new char[3];
    unsigned int day = startDate.getDay();
    dayStr[0] = (day < 10 ? '0' : (day / 10 % 10 + '0'));
    dayStr[1] = day % 10 + '0';
    dayStr[2] = '\0';

    String returnableStr("stats");
    //concatenation
    returnableStr = returnableStr + "-" + yearStr + "-" + monthStr + "-" + dayStr + ".txt";
    delete[] dayStr;
    delete[] monthStr;
    delete[] yearStr;
    return returnableStr;
}
//outputting the schedule for a given period of time
void EventCalendar::outputScheduleFromTo(const Date &dateStart, const Date &dateEnd) {
    String filename = constructFileName(dateStart);
    std::ofstream out;
    out.open(filename.getText());
    if (out) {
        unsigned int size = this->events.getSize();
        Container<Event> eventsToBeShown;
        //filling a new event container with events that are going to happen in the given period of time
        for (int i = 0; i < size; ++i) {
            if (this->events[i].getDate() >= dateStart && this->events[i].getDate() <= dateEnd) {
                eventsToBeShown.add(this->events[i]);
            }
        }
        //we sort the events by duration ( from biggest to smallest)
        sortEventsByDuration(eventsToBeShown);
        // construct a container with all the dates from the period
        Container<Date> dates = getAllDatesFromPeriod(dateStart, dateEnd);
        //take all durations of events on given dates
        int *durations = sortDatesFromBusiestAndGetDurations(eventsToBeShown, dates);
        unsigned int sizeReturnable = dates.getSize();
        //print all dates and their corresponding durations
        for (int i = 0; i < sizeReturnable; ++i) {
            dates[i].print(out);
            out << " - " << durations[i] << " min";
            out << std::endl;
        }
        out.close();
        delete[] durations;
    }
    std::cout << Helper::SAVED_WORKLOAD << filename << std::endl;
}

//the method that is responsible for 'free' command action
void EventCalendar::findFreeTime(const Date &dateStart, const Date &dateEnd, const Time &startTime, const Time &endTime,
                                 const int duration) {
    Container<Event> eventsInPeriod;
    unsigned int sizeEvents = this->events.getSize();
    //Get all events that are in the given period of time (Dates)
    for (int i = 0; i < sizeEvents; ++i) {
        if (this->events[i].getDate() >= dateStart && this->events[i].getDate() <= dateEnd)
            eventsInPeriod.add(this->events[i]);
    }
    //get all dates from the period
    Container<Date> dates = getAllDatesFromPeriod(dateStart, dateEnd);
    unsigned int sizeEventsInPeriod = eventsInPeriod.getSize();
    unsigned int sizeDatesInPeriod = dates.getSize();
    bool dateIsTaken = false;
    //iterate though all dates
    for (int i = 0; i < sizeDatesInPeriod; ++i) {
        dateIsTaken = false;
        //Iterate through all events and check whether a date is the same as the event's date
        for (int j = 0; j < sizeEventsInPeriod; ++j) {
            if (dates[i] == eventsInPeriod[j].getDate()) {
                dateIsTaken = true;
                //check if the date is free in the given time span (Time)
                if (checkIfDateFree(dates[i], startTime, endTime, eventsInPeriod)) {
                    dates[i].print();
                    std::cout << Helper::DATE_FREE << std::endl;
                } else {
                    dates[i].print();
                    std::cout << Helper::DATE_BUSY << std::endl;
                }
            }
        }
        //If the date doesn't match to any event's date - it is free
        if (!dateIsTaken) {
            dates[i].print();
            std::cout << Helper::DATE_FREE << std::endl;
        }
    }
}
//We sort all events by their duration
void sortEventsByDuration(Container<Event> &events) {
    unsigned int size = events.getSize();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (getDuration(events[i]) < getDuration(events[j])) {
                events.swap(events[i], events[j]);
            }
        }
    }
}
//sort all events in the given container by their starting hour
void sortEventsByStartingHour(Container<Event> &events) {
    unsigned int numberEvents = events.getSize();
    for (int i = 0; i < numberEvents; ++i) {
        for (int j = i + 1; j < numberEvents; ++j) {
            if (events[i].getStartingTime() > events[j].getStartingTime()) {
                std::swap(events[i], events[j]);
            }
        }
    }
}
//sort the given date container by the event's duration that matches the given date
int *sortDatesFromBusiestAndGetDurations(Container<Event> &givenEvents, Container<Date> &givenDates) {
    unsigned int sizeEvents = givenEvents.getSize();
    unsigned int sizeDates = givenDates.getSize();
    int *arrayWithDurations = new int[sizeDates];
    //init all values with 0
    for (int i = 0; i < sizeDates; ++i) {
        arrayWithDurations[i] = 0;
    }
    //if the date matches the event's date we add to the sum of the durations of the date
    for (int i = 0; i < sizeDates; ++i) {
        for (int j = 0; j < sizeEvents; ++j) {
            if (givenDates[i] == givenEvents[j].getDate()) {
                arrayWithDurations[i] += getDuration(givenEvents[j]);
            }
        }
    }
    // sort the dates and their durations correspondingly
    for (int i = 0; i < sizeDates; ++i) {
        for (int j = i + 1; j < sizeDates; ++j) {
            if (arrayWithDurations[i] < arrayWithDurations[j]) {
                givenDates.swap(givenDates[i], givenDates[j]);
                std::swap(arrayWithDurations[i], arrayWithDurations[j]);
            }
        }
    }
    return arrayWithDurations;
}

