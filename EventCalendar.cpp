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
    if (checkIfDateFree(event.getDate(), event.getStartingTime(), event.getEndingTime(), this->events)) {
        this->events.add(event);
    } else {
        std::cerr << Helper::DATE_NOT_FREE_ERROR_MESSAGE << std::endl;
    }

}

void EventCalendar::removeEvent(const Event &event) {
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
    for (int i = 0; i < eventSize; ++i) {
        bool containsName = this->events[i].getName().contains(string.getText());
        bool containsComment = this->events[i].getComment().contains(string.getText());
        if (containsName || containsComment)
            this->events[i].print(std::cout);
    }
}


bool checkIfDateFree(const Date &date, const Time &startingTime, const Time &endingTime, Container<Event> &events) {
    unsigned int eventSize = events.getSize();

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
    for (int i = 0; i < eventSize; ++i) {
        if (this->events[i].getDate() == date) {
            eventContainer.add(this->events[i]);
        }
    }
    unsigned int eventsInThatDaySize = eventContainer.getSize();
    sortEventsByStartingHour(eventContainer);
    for (int i = 0; i < eventsInThatDaySize; ++i) {
        eventContainer[i].print(std::cout);
    }
}

void EventCalendar::changeEvent(const Event &event) {
    std::cout << Helper::HELPER_MESSAGE_CHANGE_EVENT << std::endl;
    String command;
    std::cin.ignore();
    std::cin >> command;
    unsigned int index = this->events.getIndex(event);
    std::cout << index << std::endl;
    if (index == Helper::ERROR_INDEX) {
        std::cerr << Helper::EVENT_NOT_FOUND_ERROR << std::endl;
        return;
    } else {
        std::cout << Helper::EVENT_FOUND_MESSAGE << std::endl;
    }

    if (strstr(command.getText(), "d")) {
        Date date;
        std::cin >> date;
        Time startingHour;
        std::cin >> startingHour;
        Time endingHour;
        std::cin >> endingHour;
        if (checkIfDateFree(date, startingHour, endingHour, this->events)) {
            this->events[index].setDate(date);
            this->events[index].setStartingTime(startingHour);
            this->events[index].setEndingTime(endingHour);
        } else {
            std::cerr << Helper::DATE_NOT_FREE_ERROR_MESSAGE << std::endl;
        }

    } else if (strstr(command.getText(), "c")) {
        char *comment = nullptr;
        std::cin >> comment;
        this->events[index].setComment(comment);
    } else if (strstr(command.getText(), "n")) {
        char *name = nullptr;
        std::cin >> name;
        this->events[index].setName(name);
    } else {
        std::cerr << Helper::UNKNOWN_COMMAND_USED << std::endl;
    }

}

EventCalendar::EventCalendar() : events(Container<Event>()) {}


void EventCalendar::writeEvents(const char *filename) {

    std::ofstream out;
    out.open(filename);
    if (out) {
        unsigned int size = this->events.getSize();
        for (int i = 0; i < size; ++i) {
            out << std::endl;
            out << i + 1 << ": " << std::endl;
            this->events[i].save(out);
        }
    }
    out.close();

}

String constructFileName(const Date &startDate) {
    char *yearStr = new char[5];
    unsigned int year = startDate.getYear();
    yearStr[0] = year / 1000 + '0';
    yearStr[1] = year / 100 % 10 + '0';
    yearStr[2] = year / 10 % 10 + '0';
    yearStr[3] = year % 10 + '0';
    yearStr[4] = '\0';

    char *monthStr = new char[3];
    unsigned int month = startDate.getMonth();
    monthStr[0] = (month < OCTOBER ? '0' : (month / 10 % 10 + '0'));
    monthStr[1] = month % 10 + '0';
    monthStr[2] = '\0';

    char *dayStr = new char[3];
    unsigned int day = startDate.getDay();
    dayStr[0] = (day < 10 ? '0' : (day / 10 % 10 + '0'));
    dayStr[1] = day % 10 + '0';
    dayStr[2] = '\0';

    String returnableStr("stats");
    returnableStr = returnableStr + "-" + yearStr + "-" + monthStr + "-" + dayStr + ".txt";
    delete[] dayStr;
    delete[] monthStr;
    delete[] yearStr;
    return returnableStr;
}

void EventCalendar::outputScheduleFromTo(const Date &dateStart, const Date &dateEnd) {
    String filename = constructFileName(dateStart);
    std::ofstream out;
    out.open(filename.getText());
    if (out) {
        unsigned int size = this->events.getSize();
        Container<Event> eventsToBeShown;
        for (int i = 0; i < size; ++i) {
            if (this->events[i].getDate() >= dateStart && this->events[i].getDate() <= dateEnd) {
                eventsToBeShown.add(this->events[i]);
            }
        }
        sortEventsByDuration(eventsToBeShown);
        Container<Date> dates = getAllDatesFromPeriod(dateStart, dateEnd);
        int *durations = sortDatesFromBusiestAndGetDurations(eventsToBeShown, dates);
        unsigned int sizeReturnable = dates.getSize();
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

void EventCalendar::findFreeTime(const Date &dateStart, const Date &dateEnd, const Time &startTime, const Time &endTime,
                                 const int duration) {
    Container<Event> eventsInPeriod;
    unsigned int sizeEvents = this->events.getSize();
    for (int i = 0; i < sizeEvents; ++i) {
        if (this->events[i].getDate() >= dateStart && this->events[i].getDate() <= dateEnd)
            eventsInPeriod.add(this->events[i]);
    }
    Container<Date> dates = getAllDatesFromPeriod(dateStart, dateEnd);
    unsigned int sizeEventsInPeriod = eventsInPeriod.getSize();
    unsigned int sizeDatesInPeriod = dates.getSize();
    bool dateIsTaken = false;
    for (int i = 0; i < sizeDatesInPeriod; ++i) {
        dateIsTaken = false;
        for (int j = 0; j < sizeEventsInPeriod; ++j) {
            if (dates[i] == eventsInPeriod[j].getDate()) {
                dateIsTaken = true;
                if (checkIfDateFree(dates[i], startTime, endTime, eventsInPeriod)) {
                    dates[i].print();
                    std::cout << Helper::DATE_FREE << std::endl;
                } else {
                    dates[i].print();
                    std::cout << Helper::DATE_BUSY << std::endl;
                }
            }
        }
        if (!dateIsTaken) {
            dates[i].print();
            std::cout << Helper::DATE_FREE << std::endl;
        }
    }
}

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

int *sortDatesFromBusiestAndGetDurations(Container<Event> &givenEvents, Container<Date> &givenDates) {
    unsigned int sizeEvents = givenEvents.getSize();
    unsigned int sizeDates = givenDates.getSize();
    int *arrayWithDurations = new int[sizeDates];
    for (int i = 0; i < sizeDates; ++i) {
        arrayWithDurations[i] = 0;
    }
    for (int i = 0; i < sizeDates; ++i) {
        for (int j = 0; j < sizeEvents; ++j) {
            if (givenDates[i] == givenEvents[j].getDate()) {
                arrayWithDurations[i] += getDuration(givenEvents[j]);
            }
        }
    }
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

