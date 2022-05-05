#ifndef PERSONAL_CALENDAR_OOP_HELPER_H
#define PERSONAL_CALENDAR_OOP_HELPER_H


class Helper {
public:
    static const char *INVALID_DATE_MESSAGE;
    static const char *DATE_INPUT_HELPER_MESSAGE;
    static const char HOUR_SEPARATOR;
    static const char DATE_SEPARATOR;
    static const char *HOUR_INPUT_HELPER_MESSAGE;
    static const char *EVENT_NOT_FOUND_ERROR;
    static const char *DATE_NOT_FREE_ERROR_MESSAGE;
    static const char *HELPER_MESSAGE_CHANGE_EVENT;
    static const char *UNKNOWN_COMMAND_USED;
    static const char *MAX_CAPACITY_REACHED_ERROR;
    static const int ERROR_INDEX;
};

const char *Helper::INVALID_DATE_MESSAGE = "The date you entered is invalid!";
const char *Helper::DATE_INPUT_HELPER_MESSAGE = "Please enter a date in the correct format dd/mm/yy!";
const char Helper::HOUR_SEPARATOR = ':';
const char Helper::DATE_SEPARATOR = '/';
const char *Helper::HOUR_INPUT_HELPER_MESSAGE = "Please enter the hour in the following format: hh:ii";
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




#endif //PERSONAL_CALENDAR_OOP_HELPER_H
