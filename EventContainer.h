#include "Event.h"

#ifndef PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H
#define PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H

const unsigned int MAX_EVENTS = 100;
const unsigned int DEFAULT_CAP = 10;
const int ERROR_INDEX = -1;

const char * MAX_CAPACITY_REACHED_ERROR = "Max capacity reached!";

template<class Type = Event>
class EventContainer {
private:
    Type *arr;
    unsigned int size;
    unsigned int capacity;
public:
    EventContainer();

    EventContainer(const Type *arr, unsigned int size, unsigned int capacity = DEFAULT_CAP);

    void add(Type element);
    void swap(Type element1, Type element2);
    void pop();
    unsigned int getIndex(Type element);
    void remove(unsigned int index);
    unsigned int getSize() const;

    Type & operator [] (unsigned index);


};

template<class Type>
void EventContainer<Type>::add(Type element) {
    if(size + 1 <= capacity) {
        this->arr[this->size++] = element;
    }
    else {
        std::cerr<<MAX_CAPACITY_REACHED_ERROR<<std::endl;
    }
}

template<class Type>
EventContainer<Type>::EventContainer(const Type *arr, unsigned int size, unsigned int capacity):arr((Event *) arr), size(size), capacity(capacity) {}

template<class Type>
EventContainer<Type>::EventContainer():arr(nullptr), size(0), capacity(DEFAULT_CAP) {}

template<class Type>
void EventContainer<Type>::remove(unsigned int index) {
    for (int i = 0; i < size ; ++i) {
        if(i == index) {
            for (int j = i; j < size; ++j) {
                arr[j] = arr[j+1];
            }
        }
    }
    size --;
}

template<class Type>
void EventContainer<Type>::pop() {
    size--;
}

template<class Type>
unsigned int EventContainer<Type>::getSize() const {
    return this->size;
}

template<class Type>
Type & EventContainer<Type>::operator[](unsigned int index) {
    return this->arr[index];
}

template<class Type>
void EventContainer<Type>::swap(Type element1, Type element2) {
    Type temp = element1;
    element1 = element2;
    element2 = temp;
}

template<class Type>
unsigned int EventContainer<Type>::getIndex(Type element) {
    for (int i = 0; i < size ; ++i) {
        if(arr[i] == element)
            return i;
    }
    return ERROR_INDEX;
}


#endif //PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H
