#include "Event.h"

#ifndef PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H
#define PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H

const unsigned int MAX_EVENTS = 100;
const unsigned int DEFAULT_CAP = 10;


template<class Type = Event>
class Container {
private:
    Type *arr;
    unsigned int size;
    unsigned int capacity;
public:
    Container();

    Container(unsigned int cap);
    Container(const Container<Type> & container);

    void add(const Type &element);

    void swap(Type &element1, Type &element2);

    unsigned int getIndex(const Type & element);

    void remove(unsigned int index);

    unsigned int getSize() const;

    Type &operator[](unsigned index);
    Container<Type> & operator=(const Container<Type> & other);
    ~Container();

};

template<class Type>
void Container<Type>::add(const Type & element) {
    if (size + 1 <= capacity) {
        arr[size++] = element;
    } else {
        std::cerr << Helper::MAX_CAPACITY_REACHED_ERROR << std::endl;
    }
}

template<class Type>
Container<Type>::Container(unsigned int cap) {
    capacity = cap;
    size = 0;
    arr = new Type[capacity];
}

template<class Type>
Container<Type>::Container() {
    capacity = 2;
    size = 0;
    arr = new Type[capacity];
}

template<class Type>
void Container<Type>::remove(unsigned int index) {
    if (index <= size) {
        for (int i = 0; i < size; ++i) {
            if (i == index) {
                for (int j = i; j < size; ++j) {
                    arr[j] = arr[j + 1];
                }
            }
        }
        size--;
    } else {
        std::cerr << Helper::EVENT_NOT_FOUND_ERROR << std::endl;
    }
}

template<class Type>
unsigned int Container<Type>::getSize() const {
    return size;
}

template<class Type>
Type &Container<Type>::operator[](unsigned int index) {
    return arr[index];
}

template<class Type>
void Container<Type>::swap(Type &element1, Type &element2) {
    std::swap(element1, element2);
}

template<class Type>
unsigned int Container<Type>::getIndex(const Type &element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element)
            return i;
    }
    return Helper::ERROR_INDEX;
}

template<class Type>
Container<Type>::~Container() {
    delete[] arr;
}

template<class Type>
Container<Type> &Container<Type>::operator=(const Container<Type> &other) {
    if(this != &other)
    {
        delete [] arr;
        capacity = other.capacity;
        arr = new Type [capacity];
        size = other.getSize();
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template<class Type>
Container<Type>::Container(const Container<Type> &container) {
    capacity = container.capacity;
    arr = new Type[capacity];
    size = container.size;

    for (int i = 0; i < size; ++i) {
        arr[i] = container.arr[i];
    }
}


#endif //PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H
