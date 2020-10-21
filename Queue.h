//
// Created by Yosiah on 23/09/2020.
//

#include "LinkedList.h"

#ifndef UNTITLED2_QUEUE_H
#define UNTITLED2_QUEUE_H

template <typename value_type>
class Queue {
public:

    Queue();

    ~Queue();

    void enqueue(value_type data);

    value_type dequeue();

    value_type& front();

    int size(); // size cannot be negative

private:
    LinkedList<value_type>* data;

};

#include "Queue.hpp"

#endif
