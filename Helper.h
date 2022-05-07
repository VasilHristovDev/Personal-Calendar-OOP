#ifndef PERSONAL_CALENDAR_OOP_HELPER_H
#define PERSONAL_CALENDAR_OOP_HELPER_H


class Helper {
public:
    //date helper constants
    static const char *INVALID_DATE_MESSAGE;
    static const char *DATE_INPUT_HELPER_MESSAGE;
    static const char DATE_SEPARATOR;
    static const char *DATE_NOT_FREE_ERROR_MESSAGE;

    //hour helper constants
    static const char TIME_SEPARATOR;
    static const char *TIME_INPUT_HELPER_MESSAGE;
    static const char *INVALID_TIME_ERROR_MESSAGE;

    //event helper constants
    static const char *EVENT_NOT_FOUND_ERROR;
    static const char *HELPER_MESSAGE_CHANGE_EVENT;

    //misc
    static const char *UNKNOWN_COMMAND_USED;
    static const char *MAX_CAPACITY_REACHED_ERROR;
    static const int ERROR_INDEX;

    //event reading constants
    static const char * NAME_INPUT_HELPER_MESSAGE;
    static const char * COMMENT_INPUT_HELPER_MESSAGE;

    //UI
    static const char * COMMANDS_HELPER_MESSAGE;
    static const char * EXIT_MESSAGE;
};

const char *Helper::INVALID_DATE_MESSAGE = "The date you entered is invalid!";
const char *Helper::DATE_INPUT_HELPER_MESSAGE = "Please enter a date in the correct format dd/mm/yy!";
const char Helper::TIME_SEPARATOR = ':';
const char Helper::DATE_SEPARATOR = '/';
const char *Helper::TIME_INPUT_HELPER_MESSAGE = "Please enter the hour in the following format: hh:ii";
const char *Helper::EVENT_NOT_FOUND_ERROR = "Event with this information was not found!";
const char *Helper::DATE_NOT_FREE_ERROR_MESSAGE = "The event cannot be added because an event with the same date exists!";
const char *Helper::HELPER_MESSAGE_CHANGE_EVENT = "Hello! In order to change information for the event build the string: "
                                                  "\n To change the date: write 'd'"
                                                  "\n To change the name: write 'n'"
                                                  "\n To change the comment: write 'c'"
                                                  "\n Your final string could look like that dnc";
const char *Helper::UNKNOWN_COMMAND_USED = "Unknown command was used!";
const char *Helper::MAX_CAPACITY_REACHED_ERROR = "Max capacity reached!";
const int Helper::ERROR_INDEX = -1;
const char * Helper::NAME_INPUT_HELPER_MESSAGE = "Please enter the name of the event:";
const char * Helper::COMMENT_INPUT_HELPER_MESSAGE = "Please enter the comment of the event:";
const char * Helper::INVALID_TIME_ERROR_MESSAGE = "The entered time is invalid!";
const char * Helper::COMMANDS_HELPER_MESSAGE = "Hello! \n"
                                               "To add an event write: make \n"
                                               "To remove an event write: cancel \n"
                                               "To change information about an event write: change \n"
                                               "To search an event write: search \n"
                                               "To show your schedule for a certain date write: show:day \n"
                                               "To find free time in a certain week write: free \n"
                                               "To see your daily schedule for a certain week write: show:busy \n"
                                               "To exit the program write: exit \n";
 const char * Helper::EXIT_MESSAGE = "Goodbye! \n"
                                           "Your event calendar is currently being saved to: ";


#endif //PERSONAL_CALENDAR_OOP_HELPER_H
