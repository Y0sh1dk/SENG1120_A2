/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 */

#include "Queue.h"

template <typename value_type>
Queue<value_type>::Queue() {
    data = new LinkedList<value_type>;
}

/**********************************************************************************************************************/

template <typename value_type>
Queue<value_type>::~Queue() {
    delete(data);
}

/**********************************************************************************************************************/

template <typename value_type>
void Queue<value_type>::enqueue(value_type givenData) {
    data->start();
    data->addToTail(givenData);
}

/**********************************************************************************************************************/

template <typename value_type>
value_type Queue<value_type>::dequeue() {
    if (data->size() > 0) {
        data->start();
        value_type temp = data->getHead();
        data->removeHead();
        return temp;
    }
    throw std::logic_error("Empty");
}

/**********************************************************************************************************************/

template <typename value_type>
value_type& Queue<value_type>::front() {
    data->start();
    return data->getCurrent();
}

/**********************************************************************************************************************/

template <typename value_type>
int Queue<value_type>::size() {
    return data->size();
}