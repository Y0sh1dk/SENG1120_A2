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
            Node* next;
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
    Node* newNode = new Node(item, head, NULL);
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
        Node* temp = new Node(item);
        head = temp;
        tail = temp;
        start();
        temp = NULL;
    } else { // atleast one node
       Node* temp = new Node(item);
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
    Node* newNode = new Node(item);
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
    head = head->getNext();
    delete(head->getPrev());
    head->setPrev(NULL);
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
void LinkedList<value_type>::add(const value_type& s) {
    int pos = -1;
    for (unsigned long int i = 0; i <= s.length(); i++) {
        if (isspace(s[i])) {
            addToTail(s.substr(pos+1, i-pos-1));
            pos = i;
        }
    }
    LinkedList::value_type lastWord =  s.substr(pos+1, s.length());
    addToTail(lastWord);
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::remove(const value_type& s) {
    bool sentence = false; // tries to remove sentence if there is a space
    for (unsigned long int i = 0; i <= s.length(); i++) {
        if (isspace(s[i])) {
            sentence = true;
        }
    }
    if (sentence) {
        removeSentence(s);
    } else {
        removeWord(s);
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
void LinkedList<value_type>::sort() {
    start();
    int s = size();
    bool ordered = false;
    while (!ordered) {
        start();
        bool order = true;
        for (int i = 0; i < s-1; i++) {
            LinkedList::value_type currentString = getCurrent();
            forward();
            LinkedList::value_type nextString = getCurrent();

//        Find smallest word
            int minWordSize = 0;
            if (currentString.length() > nextString.length()) {
                minWordSize = nextString.length();
            } else if (currentString.length() < nextString.length()) {
                minWordSize = currentString.length();
            } else { // same size
                minWordSize = currentString.length();
            }

            for (int i = 0; i < minWordSize; i++) {
                if (currentString.at(i) > nextString.at(i)) {
//                swap two nodes
                    LinkedList::value_type temp = current->getData();
                    removeCurrent();
                    addToHead(temp);
                    order = false;
                    break;
                } else if (currentString.at(i) < nextString.at(i)) {
                    break;
                }
            }
        }
        if (order) {
            ordered = true;
        }
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
unsigned int const LinkedList<value_type>::size() {
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
std::ostream& operator << (std::ostream& out, LinkedList<value_type>& l) {
    l.start(); // set current pointer to head
    LinkedList::value_type sentence;
    int size = l.size();
    for (int i = 0; i < size; i++) {
        sentence += l.getCurrent();
        sentence += " ";
        l.forward();
    }
    out << sentence;
    return out;
}

/**********************************************************************************************************************/

template <typename value_type>
void LinkedList<value_type>::operator+= (LinkedList& l2) {
    l2.start();
    int l2size = l2.size();
    for (int i = 0; i < l2size; i++) {
        LinkedList::value_type temp = l2.getCurrent();
        addToTail(temp);
        l2.forward();
    }

}