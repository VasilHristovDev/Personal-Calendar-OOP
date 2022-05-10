#ifndef PERSONAL_CALENDAR_OOP_PROGRAM_H
#define PERSONAL_CALENDAR_OOP_PROGRAM_H

#include "EventCalendar.cpp"
#include "Commands.h"

const char *OUTPUT_FILENAME = "EventCalendar.txt";

class Program {
private:
    EventCalendar calendar;
public:
    Program();

    void run();

};

Program::Program() {
    this->calendar =  EventCalendar();
}

void Program::run() {
    String command;
    std::cout << Helper::COMMANDS_HELPER_MESSAGE << std::endl;
    while (stringToCommands(command) != EXIT_COMMAND) {
        std::cin >> command;
        commands COMMAND = stringToCommands(command);
        //Helpers for the program
        Event event;
        Date date;
        Date date2;
        String string;
        Time startingTime;
        Time endingTime;
        int duration;
        switch (COMMAND) {
            case SHOW_COMMANDS:
                std::cout << Helper::COMMANDS_HELPER_MESSAGE << std::endl;
                break;
            case MAKE_APPOINTMENT:
                std::cin >> event;
                this->calendar.addEvent(event);
                break;
            case CANCEL_APPOINTMENT:
                std::cin >> event;
                this->calendar.removeEvent(event);
                break;
            case DAY_SCHEDULE:
                std::cin >> date;
                this->calendar.printDayList(date);
                break;
            case CHANGE_APPOINTMENT:
                std::cin >> event;
                this->calendar.changeEvent(event);
                break;
            case SEARCH_APPOINTMENT:
                std::cout<<Helper::ENTER_STRING<<std::endl;
                std::cin >> string;
                this->calendar.searchEvent(string);
                break;
            case WORKLOAD:
                std::cin>>date;
                std::cin>>date2;
                this->calendar.outputScheduleFromTo(date,date2);
                break;
            case FIND_FREE_TIME:
                std::cin>>date;
                std::cin>>date2;
                std::cin>>startingTime;
                std::cin>>endingTime;
                std::cout<<"Duration:";
                std::cin>>duration;
                this->calendar.findFreeTime(date,date2,startingTime,endingTime,duration);
                break;
            case WRONG_COMMAND:
                std::cout << Helper::UNKNOWN_COMMAND_USED << std::endl;
            default:
                break;
        }
    }
    std::cout << Helper::EXIT_MESSAGE << OUTPUT_FILENAME << std::endl;
    this->calendar.writeEvents(OUTPUT_FILENAME);
}



#endif //PERSONAL_CALENDAR_OOP_PROGRAM_H
