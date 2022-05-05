#include "Event.h"

#ifndef PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H
#define PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H

const unsigned int MAX_EVENTS = 100;
const unsigned int DEFAULT_CAP = 10;


template <class Type = Event>
class Container {
private:
    Type *arr;
    unsigned int size;
    unsigned int capacity;
public:
    Container();

    Container(const Type *arr, unsigned int size, unsigned int capacity = DEFAULT_CAP);

    void add(Type element);
    void swap(Type element1, Type element2);
    void pop();
    unsigned int getIndex(Type element);
    void remove(unsigned int index);
    unsigned int getSize() const;

    Type & operator [] (unsigned index);


};

template<class Type>
void Container<Type>::add(Type element) {
    if(size + 1 <= capacity) {
        this->arr[this->size++] = element;
    }
    else {
        std::cerr<<Helper::MAX_CAPACITY_REACHED_ERROR<<std::endl;
    }
}

template<class Type>
Container<Type>::Container(const Type *arr, unsigned int size, unsigned int capacity):arr((Event *) arr), size(size), capacity(capacity) {}

template<class Type>
Container<Type>::Container():arr(nullptr), size(0), capacity(DEFAULT_CAP) {}

template<class Type>
void Container<Type>::remove(unsigned int index) {
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
void Container<Type>::pop() {
    size--;
}

template<class Type>
unsigned int Container<Type>::getSize() const {
    return this->size;
}

template<class Type>
Type & Container<Type>::operator[](unsigned int index) {
    return this->arr[index];
}

template<class Type>
void Container<Type>::swap(Type element1, Type element2) {
    Type temp = element1;
    element1 = element2;
    element2 = temp;
}

template<class Type>
unsigned int Container<Type>::getIndex(Type element) {
    for (int i = 0; i < size ; ++i) {
        if(arr[i] == element)
            return i;
    }
    return Helper::ERROR_INDEX;
}


#endif //PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H
