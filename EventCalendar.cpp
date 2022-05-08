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

