/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 *
 * File: LinkedList.h
 * Description: LinkedList Declaration
 */

#include "Node.h"

#include <cstdlib>
#include <iostream>


#ifndef MY_LINKEDLIST
#define MY_LINKEDLIST

template<typename value_type>
class LinkedList {
public:
    // Pre-Condition: None
    // Creates a empty LL
    // Post-Condition: None
    LinkedList();

    // Pre-Condition: None
    // Loops through whole LL, deleting nodes
    // Post-Condition: None
    ~LinkedList();

    // Pre-Condition: takes a single word as a string and adds it to the head of LL
    //
    // Post-Condition: None
    void addToHead(value_type &item);

    // Pre-Condition: takes a single word as a string and adds it to the tail of LL
    //
    // Post-Condition: None
    void addToTail(value_type item);

    // Pre-Condition: takes a single word as a string and adds it after the current ptr
    //
    // Post-Condition: None
    void addAfterCurrent(value_type &item);

    // Pre-Condition: Removes head node
    //
    // Post-Condition: None
    void removeHead();

    // Pre-Condition: Removes tail node
    //
    // Post-Condition: None
    void removeTail();

    // Pre-Condition: removes node at current ptr
    //
    // Post-Condition: None
    void removeCurrent();

    // Pre-Condition: None
    //
    // Post-Condition: returns the data stored in the head node
    value_type getHead() const;

    // Pre-Condition: None
    //
    // Post-Condition: returns the data stored in the tail node
    value_type getTail() const;

    // Pre-Condition: None
    //
    // Post-Condition: returns the data stored in the current node
    value_type getCurrent() const;

    // Pre-Condition: None
    // Sets current pointer to the head of the LL
    // Post-Condition: None
    void start();

    // Pre-Condition: None
    // Sets current pointer to the tail of the LL
    // Post-Condition: None
    void end();

    // Pre-Condition: None
    // Moves current pointer along one, to the next node
    // Post-Condition: None
    void forward();

    // Pre-Condition: None
    // Moves current pointer back one, to the previous node
    // Post-Condition: None
    void back();

    // Pre-Condition: takes a string to count how many times it occurs in the LL
    //
    // Post-Condition: returns a unsigned int of how many times
    unsigned int const count(const value_type &s);

    // Pre-Condition: None
    //
    // Post-Condition: Returns a unsigned int of how many nodes are in the LL
    int const size(); // can only be positive so unsigned

    // Pre-Condition: A second list to concatenate to the current
    //
    // Post-Condition: None
    void operator+=(LinkedList &l2);

private:
    Node<value_type> *head;     // store ptr to head node of the LL
    Node<value_type> *tail;     // store ptr to tail node of the LL
    Node<value_type> *current;  // store ptr to 'current' node of the LL

};

#include "LinkedList.hpp"

#endif