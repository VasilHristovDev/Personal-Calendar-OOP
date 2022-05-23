#ifndef PERSONAL_CALENDAR_OOP_PROGRAM_H
#define PERSONAL_CALENDAR_OOP_PROGRAM_H

#include "EventCalendar.cpp"
#include "Commands.h"

const char *OUTPUT_FILENAME = "EventCalendar.txt";
///Class containing the main structure in my project - EventCalendar
///Which uses the main logic of the project
class Program {
private:
    ///The only property needed for this class is of type EventCalendar
    EventCalendar calendar;
public:
    ///Default Constructor that initializes the EventCalendar
    Program();
    ///run method that interprets the dialog mode of the project
    void run();

};
///Using the default constructor of EventCalendar
Program::Program() {
    this->calendar =  EventCalendar();
}

void Program::run() {
    ///Command - Action based dialog mode
    String command;
    this->calendar.readEvents(OUTPUT_FILENAME);

    std::cout << Helper::COMMANDS_HELPER_MESSAGE << std::endl;
    ///entering commands until the exit command string is entered
    while (stringToCommands(command) != EXIT_COMMAND) {
        std::cout<<Helper::ENTER_COMMAND_MESSAGE;
        std::cin >> command;
        commands COMMAND = stringToCommands(command);
        ///Helper variables for the program to run correctly
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
                std::cin.ignore();
                break;
            case CANCEL_APPOINTMENT:
                std::cin >> event;
                this->calendar.removeEvent(event);
                std::cin.ignore();
                break;
            case DAY_SCHEDULE:
                std::cin >> date;
                this->calendar.printDayList(date);
                std::cin.ignore();
                break;
            case CHANGE_APPOINTMENT:
                std::cin >> event;
                this->calendar.changeEvent(event);
                std::cin.ignore();
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
                std::cin.ignore();
                break;
            case FIND_FREE_TIME:
                std::cin>>date;
                std::cin>>date2;
                std::cin>>startingTime;
                std::cin>>endingTime;
                std::cout<<"Duration:";
                std::cin>>duration;
                this->calendar.findFreeTime(date,date2,startingTime,endingTime,duration);
                std::cin.ignore();
                break;
            case WRONG_COMMAND:
                std::cout << Helper::UNKNOWN_COMMAND_USED << std::endl;
            default:
                break;

        }
    }
    ///After entering the exit command the calendar is being saved to a file
    std::cout << Helper::EXIT_MESSAGE << OUTPUT_FILENAME << std::endl;
    this->calendar.writeEvents(OUTPUT_FILENAME);
}



#endif //PERSONAL_CALENDAR_OOP_PROGRAM_H
