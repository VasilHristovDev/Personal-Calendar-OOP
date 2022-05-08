#include "EventCalendar.h"
#include <cstring>
#include <fstream>


/**
 *
 * @param events
 * @param numberEvents
 * @param maxEvents
 */
EventCalendar::EventCalendar(const Event *events, const int numberEvents, const int maxEvents) {
    this->setEvents(events, numberEvents, maxEvents);
}

/**
 *
 * @param _events
 * @param size
 */
void EventCalendar::setEvents(const Event *_events, int size, int maxSize) {
    this->events = Container<Event>(maxSize);
    for (int i = 0; i < size; ++i) {
        this->addEvent(_events[i]);
    }
}

/**
 *
 * @param Event event
 */
void EventCalendar::addEvent(const Event &event) {
    if (this->checkIfDateFree(event.getDate(), event.getStartingTime(), event.getEndingTime())) {
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

/**
 *
 * @param string
 */
void EventCalendar::searchEvent(String &string) {
    unsigned int eventSize = this->events.getSize();
    for (int i = 0; i < eventSize; ++i) {
        char *commentStr = strstr(this->events[i].getComment().getText(), string.getText());
        char *nameStr = strstr(this->events[i].getName().getText(), string.getText());
        if (commentStr || nameStr)
            this->events[i].print(std::cout);
    }
}

/**
 *
 * @param Date date
 * @param Hour startingTime
 * @param Hour endingTime
 * @return bool
 */
bool EventCalendar::checkIfDateFree(const Date &date, const Time &startingTime, const Time &endingTime) {
    unsigned int eventSize = this->events.getSize();

    for (int i = 0; i < eventSize; ++i) {
        if (this->events[i].getDate() == date) {
            if (this->events[i].getStartingTime() < startingTime && this->events[i].getEndingTime() > startingTime)
                return false;
        }
    }
    return true;
}

void EventCalendar::printDayList(const Date &date) {
    int counterEvents = 0;
    unsigned int eventSize = this->events.getSize();

    for (int i = 0; i < eventSize; ++i) {
        if (this->events[i].getDate() == date) {
            counterEvents++;
        }
    }
    Container<Event> eventContainer(counterEvents);
    for (int i = 0; i < eventSize; ++i) {
        if (this->events[i].getDate() == date) {
            eventContainer.add(this->events[i]);
        }
    }
    eventContainer = sortEventsByStartingHour(eventContainer, counterEvents);
    for (int i = 0; i < counterEvents; ++i) {
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
    }

    if (strstr(command.getText(), "d")) {
        Date date;
        std::cin >> date;
        Time startingHour;
        std::cin >> startingHour;
        Time endingHour;
        std::cin >> endingHour;
        if (checkIfDateFree(date, startingHour, endingHour)) {
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
String constructFileName(const Date & startDate) {
    char * yearStr = new char [5];
    unsigned int year = startDate.getYear();
    yearStr[0] = year / 1000  + '0';
    yearStr[1] = year / 100 % 10 + '0';
    yearStr[2] = year / 10 % 10 + '0';
    yearStr[3] = year % 10 + '0';
    yearStr[4] = '\0';

    char * monthStr = new char [3];
    unsigned int month = startDate.getMonth();
    monthStr[0] = (month < OCTOBER ? '0': (month / 10 % 10 + '0'));
    monthStr[1] = month % 10 + '0';
    monthStr[2] = '\0';

    char * dayStr = new char [3];
    unsigned int day = startDate.getDay();
    dayStr[0] = (day < 10 ? '0': (day / 10 % 10 + '0'));
    dayStr[1] = day % 10 + '0';
    dayStr[2] = '\0';

    std::cout<<yearStr<<"-"<<monthStr<<"-"<<dayStr<<std::endl;
    String returnableStr("stats");
    returnableStr = returnableStr + "-" +yearStr + "-" +monthStr + "-"+dayStr+".txt";
    std::cout<<returnableStr.getText();
    delete [] dayStr;
    delete [] monthStr;
    delete [] yearStr;
    return returnableStr;
}

void EventCalendar::outputScheduleFromTo(const Date &dateStart, const Date &dateEnd) {
    String filename = constructFileName(dateStart);
    std::ofstream out;
    out.open(filename.getText());
    if(out)
    {
        unsigned int size = this->events.getSize();
        Container<Event> eventsToBeShown;
        for (int i = 0; i < size ; ++i) {
            if(this->events[i].getDate() >= dateStart && this->events[i].getDate() <= dateEnd)
            {
                eventsToBeShown.add(this->events[i]);
            }
        }
        sortEventsByDuration(eventsToBeShown);
        unsigned int sizeReturnable = eventsToBeShown.getSize();
        for (int i = 0; i < sizeReturnable ; ++i) {
            eventsToBeShown[i].print(out);
        }
        out.close();
    }
}

void sortEventsByDuration(Container<Event> & events)
{
    unsigned int size = events.getSize();
    for (int i = 0; i < size ; ++i) {
        for (int j = i + 1; j < size ; ++j) {
            if(getDuration(events[i]) < getDuration(events[j]))
            {
                events.swap(events[i], events[j]);
            }
        }
    }
}

Container<Event> sortEventsByStartingHour(Container<Event> &events, unsigned int numberEvents) {
    Container<Event> returnableEvents(numberEvents);
    for (int i = 0; i < numberEvents; ++i) {
        returnableEvents.add(events[i]);
    }
    for (int i = 0; i < numberEvents; ++i) {
        for (int j = i + 1; j < numberEvents; ++j) {
            if (returnableEvents[i].getStartingTime() > returnableEvents[j].getStartingTime()) {
                returnableEvents.swap(returnableEvents[i], returnableEvents[j]);
            }
        }
    }
    return returnableEvents;
}

