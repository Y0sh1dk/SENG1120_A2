/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A2
 *
 * File: LinkedList.hpp
 * Description: LinkedList Implementation
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedList.h"

template <typename value_type>
LinkedList<value_type>::LinkedList() {
    current = NULL;
    head = NULL;
    tail = NULL;
}

/**********************************************************************************************************************/

template <typename value_type>
LinkedList<value_type>::~LinkedList() {
    if (size() > 0) {
        start();
        while(1) {
            Node<value_type>* next;
            if (current->getNext() != NULL) {
                next = current->getNext();
            } else {
                break;
            }
            delete current;
            current = next;
        }
    }
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::addToHead(value_type& item) {
    Node<value_type>* newNode = new Node<value_type>(item, head, NULL);
    if (head != NULL) {
        head->setPrev(newNode);
    }
    head = newNode;
    if (tail == NULL) {
        tail = head;
    }
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::addToTail(value_type item) { // cannot take reference because of how its called
    if (tail == NULL) {
        Node<value_type>* temp = new Node<value_type>(item);
        head = temp;
        tail = temp;
        start();
        temp = NULL;
    } else { // atleast one node
       Node<value_type>* temp = new Node<value_type>(item);
       tail->setNext(temp);
       temp->setPrev(tail);
       tail = temp;
       start();
       temp = NULL;
    }
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::addAfterCurrent(value_type& item) { // insert after 'current'
    if (current == NULL) { // cannot insert after a NULL
        return;
    }
    Node<value_type>* newNode = new Node<value_type>(item);
    if (current == tail) {
        tail = newNode;
    }
    newNode->setNext(current->getNext());
    current->setNext(newNode);
    newNode->setPrev(current);
    if (newNode->getNext() != NULL) {
        newNode->getNext()->setPrev(newNode);
    }
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::removeHead() {
    if (head != tail) {
        head = head->getNext();
        delete(head->getPrev());
        head->setPrev(NULL);
    } else {
        delete(head);
        head = NULL;
        tail = NULL;
        current = NULL;
    }
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::removeTail() {
    tail = tail->getPrev();
    delete(tail->getNext());
    tail->setNext(NULL);
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::removeCurrent() {
    if (current != tail) {
        current->getPrev()->setNext(current->getNext());
        current->getNext()->setPrev(current->getPrev());
        delete current;
        start();
    } else {
        current->getPrev()->setNext(NULL);
        delete current;
        start();
    }
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::removeWord(const value_type& s) {
    start();
    while (current != NULL) { // runs through till hits end
        if (getCurrent() == s) {
            removeCurrent();
            start();
        }
        forward();
    }
}


/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::start() {
    current = head;
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::end() {
    current = tail;
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::forward() {
    current = current->getNext();
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::back() {
    current = current->getPrev();
}

/**********************************************************************************************************************/

template <typename value_type>
value_type LinkedList<value_type>::getCurrent() const {
    return current->getData();
}

/**********************************************************************************************************************/

template <typename value_type>
value_type LinkedList<value_type>::getHead() const {
    return head->getData();
}

/**********************************************************************************************************************/

template <typename value_type>
value_type LinkedList<value_type>::getTail() const{
    return tail->getData();
}

/**********************************************************************************************************************/

template <typename value_type>
int const LinkedList<value_type>::size() {
    int a = 0;
    for (current = head; current != NULL; current = current->getNext()) {
        a++;
    }
    start();
    return a;
}

/**********************************************************************************************************************/

template <typename value_type>
unsigned int const LinkedList<value_type>::count(const value_type& s) {
    start();
    int a = 0;
    while (current != NULL) {
        if (getCurrent() == s) {
            a++;
        }
        forward();
    }
    return a;
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::operator+= (LinkedList& l2) {
    l2.start();
    int l2size = l2.size();
    for (int i = 0; i < l2size; i++) {
        value_type temp = l2.getCurrent();
        addToTail(temp);
        l2.forward();
    }

}