#include <iostream>
#include <cstring>
#include "EventCalendar.cpp"

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
    Event event({10,2,2004},"meeting","Meeting with Christian",{10,20},{10,30});
    Event event1({10,2,2004},"meeting","Meeting with Christian",{10,20},{10,30});
    Event event2({10,2,2004},"meeting","Meeting with Christian",{10,20},{10,30});
    Event event3({10,2,2004},"meeting","Meeting with Christian",{10,20},{10,30});
    Event event4({10,2,2004},"meeting","Meeting with Christian",{10,20},{10,30});
    Event event5({10,2,2004},"meeting","Meeting with Christian",{10,20},{10,30});
    Event * events = new Event[6];
    events[0] = event;
    events[1] = event1;
    events[2] = event2;
    events[3] = event3;
    events[4] = event4;
    events[5] = event5;
    EventCalendar calendar(events,6,10);
    calendar.addEvent(event1);
    calendar.printDayList({10,2,2004});

}
