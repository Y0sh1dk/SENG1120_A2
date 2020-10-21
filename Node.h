/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 *
 * File: Node.h
 * Description: Node Declaration
 */

#include <cstdlib>

#ifndef MY_NODE
#define MY_NODE

template <typename value_type>
class Node {
    public:
        // Pre-Condition: None
        // Creates a empty node instance
        // Post-Condition: None
        Node();

        // Pre-Condition: None
        // Creates a empty node instance with the given data, can accept ptr's to next and prev node
        // Post-Condition: None
        Node(value_type data, Node* p = NULL, Node* n = NULL);

        // Pre-Condition: None
        // Doesnt do anything, would be used if data was stored as a pointer
        // Post-Condition: None
        ~Node();

        // Pre-Condition: data to be added to a node
        //
        // Post-Condition: None
        void setData(const value_type givenData);

        // Pre-Condition: None
        //
        // Post-Condition: Returns data stored in node of whatever type is defined
        value_type getData() const;

        // Pre-Condition: None
        //
        // Post-Condition: Returns a pointer to the node stored in 'n'
        Node* getNext() const;

        // Pre-Condition: takes a pointer to a node and sets the current nodes next too it
        //
        // Post-Condition: None
        void setNext(Node* n);

        // Pre-Condition: None
        //
        // Post-Condition: Returns a pointer to the node stored in 'p'
        Node* getPrev() const;

        // Pre-Condition: Takes a pointer to a node and sets currents nodes prev too it
        //
        // Post-Condition: Returns a pointer to the node stored in 'p'
        void setPrev(Node* n);

    private:
        value_type data;    // store data
        Node* next;         // store ptr to the next node
        Node* prev;         // store ptr to the previous node
};

#include "Node.hpp"
#endif
