#ifndef PERSONAL_CALENDAR_OOP_PROGRAM_H
#define PERSONAL_CALENDAR_OOP_PROGRAM_H

#include "EventCalendar.cpp"
#include "Commands.h"

const char *OUTPUT_FILENAME = "EventCalendar.txt";

class Program {
private:
    EventCalendar *calendar;
public:
    Program();

    void run();

    ~Program();
};

Program::Program() {
    this->calendar = new EventCalendar();
}

void Program::run() {
    String command;
    std::cout << Helper::COMMANDS_HELPER_MESSAGE << std::endl;
    while (stringToCommands(command) != EXIT_COMMAND) {
        std::cin >> command;
        commands COMMAND = stringToCommands(command);
        Event event;
        Date date;
        String string;
        switch (COMMAND) {
            case SHOW_COMMANDS:
                std::cout << Helper::COMMANDS_HELPER_MESSAGE << std::endl;
                break;
            case MAKE_APPOINTMENT:
                std::cin >> event;
                this->calendar->addEvent(event);
                break;
            case CANCEL_APPOINTMENT:
                std::cin >> event;
                this->calendar->removeEvent(event);
                break;
            case DAY_SCHEDULE:
                std::cin >> date;
                this->calendar->printDayList(date);
                break;
            case CHANGE_APPOINTMENT:
                std::cin >> event;
                this->calendar->changeEvent(event);
                break;
            case SEARCH_APPOINTMENT:
                std::cin >> string;
                this->calendar->searchEvent(string);
                break;
            case WORKLOAD:
                //TODO: Implement showing workload
                break;
            case FIND_FREE_TIME:
                //TODO: Implement finding free time
                break;
            case WRONG_COMMAND:
                std::cout << Helper::UNKNOWN_COMMAND_USED << std::endl;
            default:
                break;
        }
    }
    std::cout << Helper::EXIT_MESSAGE << OUTPUT_FILENAME << std::endl;

    //TODO: Implement writing to a file
//    this->calendar.writeFile();
}

Program::~Program() {
    delete[] this->calendar;
}


#endif //PERSONAL_CALENDAR_OOP_PROGRAM_H