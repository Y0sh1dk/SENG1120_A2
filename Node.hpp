/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 */

#include "Node.h"

template <typename value_type>
Node<value_type>::Node() {
    data = ""; // string cannot be made null
    next = NULL;
    prev = NULL;
}

/**********************************************************************************************************************/

template <typename value_type>
Node<value_type>::Node(value_type d, Node* n, Node* p) {
    data = d;
    next = n;
    prev = p;
}

/**********************************************************************************************************************/

template <typename value_type>
Node<value_type>::~Node() {
//    delete next;
//    delete prev;
//    Cannot do this ^ or deleting one node will delete them all
}

/**********************************************************************************************************************/

template <typename value_type>
value_type Node<value_type>::getData() const {
    return data;
}

/**********************************************************************************************************************/

template <typename value_type>
void Node<value_type>::setData(const value_type givenData) {
    data = givenData;
}

/**********************************************************************************************************************/

template <typename value_type>
Node<value_type>* Node<value_type>::getNext() const {
    return next;
}

/**********************************************************************************************************************/

template <typename value_type>
void Node<value_type>::setNext(Node* n) {
    next = n;
}

/**********************************************************************************************************************/

template <typename value_type>
Node<value_type>* Node<value_type>::getPrev() const {
    return prev;
}

/**********************************************************************************************************************/

template <typename value_type>
void Node<value_type>::setPrev(Node* n) {
    prev = n;
}