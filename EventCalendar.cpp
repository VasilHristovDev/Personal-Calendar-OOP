#include "EventCalendar.h"
#include <cstring>

const char *EVENT_NOT_FOUND_ERROR = "Event with this information was not found!";
const char *DATE_NOT_FREE_ERROR_MESSAGE = "The event cannot be added because an event with the same date exists!";
const char *HELPER_MESSAGE_CHANGE_EVENT = "Hello! In order to change information for the event build the string: "
                                          "\n To change the date: write 'd'"
                                          "\n To change the name: write 'n'"
                                          "\n To change the comment: write 'c'"
                                          "\n Your final string could look like that dnc";
const char *UNKNOWN_COMMAND_USED = "Unknown command was used!";


EventCalendar::EventCalendar() {
    this->events = EventContainer<>();
}

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
 * @param _maxEvents
 */

/**
 *
 * @param _events
 * @param size
 */
void EventCalendar::setEvents(const Event *_events, int size, int maxSize) {
    this->events = EventContainer<Event>(_events, size, maxSize);
    unsigned int eventSize = this->events.getSize();
    for (int i = 0; i < eventSize; ++i) {
        this->events.add(_events[i]);
    }
}

/**
 *
 * @param Event event
 */
void EventCalendar::addEvent(const Event &event) {
    if (this->checkIfDateFree(event.getDate(), event.getStartingHour(), event.getEndingHour())) {
        this->events.add(event);
    } else {
        std::cerr << DATE_NOT_FREE_ERROR_MESSAGE << std::endl;
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
    if (!flag) std::cerr << EVENT_NOT_FOUND_ERROR << std::endl;
}

/**
 *
 * @param string
 */
void EventCalendar::searchEvent(const char *string) {
    unsigned int eventSize = this->events.getSize();
    for (int i = 0; i < eventSize; ++i) {
        char *commentStr = strstr(this->events[i].getComment(), string);
        char *nameStr = strstr(this->events[i].getName(), string);
        if (commentStr || nameStr)
            this->events[i].print(std::cout);
    }
}

/**
 *
 * @param Date date
 * @param Hour startingHour
 * @param Hour endingHour
 * @return bool
 */
bool EventCalendar::checkIfDateFree(const Date &date, const Hour &startingHour, const Hour &endingHour) {
    unsigned int eventSize = this->events.getSize();

    for (int i = 0; i < eventSize; ++i) {
        if (this->events[i].getDate() == date) {
            if (this->events[i].getStartingHour() < startingHour && this->events[i].getEndingHour() > startingHour)
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

    auto *eventsForDay = new Event[counterEvents];
    int tempC = 0;
    unsigned int sizeEvents = this->events.getSize();
    for (int i = 0; i < sizeEvents; ++i) {
        if (this->events[i].getDate() == date) {
            eventsForDay[tempC++] = this->events[i];
        }
    }

    EventContainer<Event> eventContainer = sortEventsByStartingHour(eventsForDay, counterEvents);
    for (int i = 0; i < counterEvents; ++i) {
        eventContainer[i].print(std::cout);
    }
    delete[] eventsForDay;

}

void EventCalendar::changeEvent(const Event &event) {

    std::cout << HELPER_MESSAGE_CHANGE_EVENT << std::endl;
    char *command = nullptr;
    std::cin >> command;
    unsigned int index = this->events.getIndex(event);

    if (index == ERROR_INDEX) {
        std::cerr << EVENT_NOT_FOUND_ERROR << std::endl;
        return;
    }

    if (strstr(command, "d")) {
        Date date;
        std::cin >> date;
        Hour startingHour;
        std::cin >> startingHour;
        Hour endingHour;
        std::cin >> endingHour;
        if(checkIfDateFree(date, startingHour, endingHour)) {
            this->events[index].setDate(date);
            this->events[index].setStartingHour(startingHour);
            this->events[index].setStartingHour(endingHour);
        }
        else {
            std::cerr<<DATE_NOT_FREE_ERROR_MESSAGE<<std::endl;
        }

    } else if (strstr(command, "c")) {
        char *comment = nullptr;
        std::cin >> comment;
        this->events[index].setComment(comment);
    } else if (strstr(command, "n")) {
        char *name = nullptr;
        std::cin >> name;
        this->events[index].setName(name);
    } else {
        std::cerr << UNKNOWN_COMMAND_USED << std::endl;
    }

}


EventContainer<Event> sortEventsByStartingHour(const Event *_events, unsigned int numberEvents) {
    EventContainer<Event> returnableEvents(_events, numberEvents);
    for (int i = 0; i < numberEvents; ++i) {
        for (int j = i + 1; j < numberEvents; ++j) {
            if (returnableEvents[i].getStartingHour() > returnableEvents[j].getStartingHour()) {
                returnableEvents.swap(returnableEvents[i], returnableEvents[j]);
            }
        }
    }
    return returnableEvents;
}

