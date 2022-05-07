#ifndef PERSONAL_CALENDAR_OOP_COMMANDS_H
#define PERSONAL_CALENDAR_OOP_COMMANDS_H
#include "String.h"

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
commands stringToCommands(String & command)
{
    if(strcmp(command.getText(), "help") == 0)
        return SHOW_COMMANDS;
    if(strcmp(command.getText(), "make") == 0)
        return MAKE_APPOINTMENT;
    if(strcmp(command.getText(), "cancel") == 0)
        return CANCEL_APPOINTMENT;
    if(strcmp(command.getText(), "show:day") == 0)
        return DAY_SCHEDULE;
    if(strcmp(command.getText(), "change") == 0)
        return CHANGE_APPOINTMENT;
    if(strcmp(command.getText(), "search") == 0)
        return SEARCH_APPOINTMENT;
    if(strcmp(command.getText(), "show:busy") == 0)
        return WORKLOAD;
    if(strcmp(command.getText(), "free") == 0)
        return FIND_FREE_TIME;
    if(strcmp(command.getText(), "exit") == 0)
        return EXIT_COMMAND;

    return WRONG_COMMAND;
}




#endif //PERSONAL_CALENDAR_OOP_COMMANDS_H
