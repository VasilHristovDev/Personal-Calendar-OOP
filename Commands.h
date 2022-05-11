#ifndef PERSONAL_CALENDAR_OOP_COMMANDS_H
#define PERSONAL_CALENDAR_OOP_COMMANDS_H
#include "String.h"
#include "Helper.h"

///commands enum variable that helps me translate string into a command
enum commands {
    SHOW_COMMANDS,
    MAKE_APPOINTMENT,
    CANCEL_APPOINTMENT,
    DAY_SCHEDULE,
    CHANGE_APPOINTMENT,
    SEARCH_APPOINTMENT,
    WORKLOAD,
    FIND_FREE_TIME,
    EXIT_COMMAND,
    WRONG_COMMAND
};

///function that returns enum when comparing strings with a given command
commands stringToCommands(String & command)
{
    if(command == Helper::HELP_COMMAND)
        return SHOW_COMMANDS;
    if(command == Helper::ADD_COMMAND)
        return MAKE_APPOINTMENT;
    if(command == Helper::REMOVE_COMMAND)
        return CANCEL_APPOINTMENT;
    if(command == Helper::SHOW_DAY_COMMAND)
        return DAY_SCHEDULE;
    if(command == Helper::CHANGE_COMMAND)
        return CHANGE_APPOINTMENT;
    if(command == Helper::SEARCH_COMMAND)
        return SEARCH_APPOINTMENT;
    if(command == Helper::SHOW_SCHEDULE_COMMAND)
        return WORKLOAD;
    if(command == Helper::FIND_FREE_TIME_COMMAND)
        return FIND_FREE_TIME;
    if(command == Helper::EXIT_COMMAND_STRING)
        return EXIT_COMMAND;

    return WRONG_COMMAND;
}




#endif //PERSONAL_CALENDAR_OOP_COMMANDS_H
