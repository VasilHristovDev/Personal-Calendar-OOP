#include "Event.h"

#ifndef PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H
#define PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H

const unsigned int MAX_EVENTS = 100;
const unsigned int DEFAULT_CAP = 10;

template<class Type = Event>
class EventContainer {
private:
    void resize();

    Type *arr;
    unsigned int size;
    unsigned int capacity;
public:
    EventContainer();

    EventContainer(const Type *arr, unsigned int size, unsigned int capacity = DEFAULT_CAP);

    void add(Type element);
    void pop();

    void remove(unsigned int index);

};

template<class Type>
void EventContainer<Type>::add(Type element) {
    this->arr[this->size++] = element;
}

template<class Type>
EventContainer<Type>::EventContainer(const Type *arr, unsigned int size, unsigned int capacity):arr((Event *) arr), size(size), capacity(capacity) {}

template<class Type>
EventContainer<Type>::EventContainer():arr(nullptr), size(0), capacity(DEFAULT_CAP) {}

template<class Type>
void EventContainer<Type>::remove(unsigned int index) {
    for (int i = 0; i < this->size ; ++i) {
        if(i == index) {
            for (int j = i; j < size; ++j) {
                arr[j] = arr[j+1];
            }
        }
    }
}

template<class Type>
void EventContainer<Type>::pop() {
    size--;
}


#endif //PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H
