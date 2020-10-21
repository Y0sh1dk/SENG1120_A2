/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 *
 * File: Queue.h
 * Description: Queue Declaration
 */

#include "LinkedList.h"

#ifndef UNTITLED2_QUEUE_H
#define UNTITLED2_QUEUE_H

template <typename value_type>
class Queue {
public:

    // Pre-Condition: None
    // Creates a empty Queue instance
    // Post-Condition:
    Queue();

    // Pre-Condition: None
    // Deletes the private data instance properly
    // Post-Condition: None
    ~Queue();

    // Pre-Condition: An object of the value_type to append to bottom of queue
    //
    // Post-Condition: None
    void enqueue(value_type data);

    // Pre-Condition: None
    //
    // Post-Condition: Returns the Object at the top of the queue, removing it from the queue
    value_type dequeue();

    // Pre-Condition: None
    //
    // Post-Condition: Returns a reference to the object at the top of the queue
    value_type& front();

    // Pre-Condition: None
    //
    // Post-Condition: Returns a int value of the size of the queue
    int size();

private:
    LinkedList<value_type>* data; // Instance of LinkedList class of given value type

};

#include "Queue.hpp"

#endif
