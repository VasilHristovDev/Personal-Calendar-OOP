#include <iostream>
#include <cstring>

#include "Date.cpp"
#include "Hour.cpp"
#include "Event.h"

enum commands {
    MAKE_APPOINTMENT,
    CANCEL_APPOINTMENT,
    DAY_SCHEDULE,
    CHANGE_APPOINTMENT,
    SEARCH_APPOINTMENT,
    WORKLOAD,
    FIND_FREE_TIME,
    WRONG_COMMAND
};
commands stringToCommands(const char * command)
{
    if(strcmp(command, "make") == 0)
        return MAKE_APPOINTMENT;
    if(strcmp(command, "cancel") == 0)
        return CANCEL_APPOINTMENT;
    if(strcmp(command, "show:day") == 0)
        return DAY_SCHEDULE;
    if(strcmp(command, "change") == 0)
        return CHANGE_APPOINTMENT;
    if(strcmp(command, "search") == 0)
        return SEARCH_APPOINTMENT;
    if(strcmp(command, "show:busy") == 0)
        return WORKLOAD;
    if(strcmp(command, "free") == 0)
        return FIND_FREE_TIME;

    return WRONG_COMMAND;
}
int main() {


}
