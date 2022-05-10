#include "Event.h"
#include "Helper.h"

#ifndef PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H
#define PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H

///constants helping us maintain the container elements
const unsigned int MAX_CAP = 100;
const unsigned int DEFAULT_CAP = 10;

///template container class needed for Event and Date classes
///the container class is represented by three properties : array with elements from the given type, current size and capacity
template<class Type>
class Container {
private:
    Type *arr;
    unsigned int size;
    unsigned int capacity;

    ///private method that resizes the container twice its current capacity
    void resize();

public:
    ///default constructor
    Container();

    ///constructor with params
    Container(unsigned int cap);

    ///a copy constructor (Good practice when maintaining dynamic memory data)
    Container(const Container<Type> &container);

    ///a method that adds an element inside the container
    void add(const Type &element);

    ///a method that swaps two elements of the constructor
    void swap(Type &element1, Type &element2);

    ///a method that extracts the index of an element inside the container
    unsigned int getIndex(const Type &element);

    ///a method that removes an element standing on a given index inside the container
    void remove(unsigned int index);

    ///a method that returns the current size of the container
    unsigned int getSize() const;

    ///an indexation operator that returns the element standing on the index inside of the container
    Type &operator[](unsigned index);

    ///an assignment operator (good practise when using dynamic allocated memory)
    Container<Type> &operator=(const Container<Type> &other);

    ///a destructor handling all dynamic memory data ( deleting all allocated properties of the class)
    ~Container();

};

template<class Type>
void Container<Type>::add(const Type &element) {
    if (size + 1 >= capacity) {
        resize();
    }
    if (size + 1 >= MAX_CAP)
        std::cerr << Helper::MAX_CAPACITY_REACHED_ERROR << std::endl;
    else
        arr[size++] = element;
}

template<class Type>
Container<Type>::Container(unsigned int cap) {
    capacity = cap;
    size = 0;
    arr = new Type[capacity];
}

template<class Type>
Container<Type>::Container() {
    capacity = DEFAULT_CAP;
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
    Type temp = element1;
    element1 = element2;
    element2 = temp;
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
    if (this != &other) {
        delete[] arr;
        capacity = other.capacity;
        arr = new Type[capacity];
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

template<class Type>
void Container<Type>::resize() {
    capacity *= 2;
    Type *temp = new Type[capacity];

    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}


#endif //PERSONAL_CALENDAR_OOP_EVENTCONTAINER_H
