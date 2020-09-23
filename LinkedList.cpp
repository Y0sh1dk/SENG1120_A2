#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedList.h"

LinkedList::LinkedList() {
    current = NULL;
    head = NULL;
    tail = NULL;
}

/**********************************************************************************************************************/

LinkedList::~LinkedList() {
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

void LinkedList::addToHead(value_type& item) {
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

void LinkedList::addToTail(value_type item) { // cannot take reference because of how its called
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

void LinkedList::addAfterCurrent(value_type& item) { // insert after 'current'
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

void LinkedList::removeHead() {
    head = head->getNext();
    delete(head->getPrev());
    head->setPrev(NULL);
}

/**********************************************************************************************************************/

void LinkedList::removeTail() {
    tail = tail->getPrev();
    delete(tail->getNext());
    tail->setNext(NULL);
}

/**********************************************************************************************************************/

void LinkedList::removeCurrent() {
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

void LinkedList::add(const LinkedList::value_type& s) {
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

void LinkedList::remove(const value_type& s) {
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

void LinkedList::removeWord(const LinkedList::value_type& s) {
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

void LinkedList::removeSentence(const LinkedList::value_type& s) {
    start();
    LinkedList::value_type firstWord;
    LinkedList::value_type lastWord;
    int numOfWords = 1; // always atleast 1 word

    int pos = -1;
//    Find first word of string to remove
    for (unsigned long int i = 0; i <= s.length(); i++) {
        if (isspace(s[i])) {
            firstWord = s.substr(pos+1, i-pos-1);
            break;
        }
    }
//    Find last word of string to remove
    for (unsigned long int i = s.length(); i >= 0; i--) { // loop from end forwards
        if (isspace(s[i])) {
            lastWord = s.substr(i-pos, s.length()+1);
            break;
        }
    }
//    Find number of words
    for (unsigned long int i = 0; i < s.length(); i++) { // loop from end forwards
        if (isspace(s[i])) {
            numOfWords++;
        }
    }
    bool sentenceFound = true;
    while (sentenceFound) {
        Node* firstNode = NULL;
        Node* lastNode = NULL;

        //    Find the node of the first and last word in the LL
        start();
        while (current != NULL) { // runs through till hits end
            if (getCurrent() == firstWord) {
                firstNode = current;
                break;
            }
            forward();
        }
//    start();
        while (current != NULL) {
            if (getCurrent() == lastWord) {
                lastNode = current;
                break;
            }
            forward();
        }

        if (firstNode == NULL || lastNode == NULL) {
            sentenceFound = false;
            break;
        }


        Node* t = firstNode;
        for (int i = 0; i < numOfWords-1; i++) {
            t = t->getNext();
        }
        start();
        if (t == lastNode) { // sentence found, time to delete it
            Node* temp = firstNode;
            Node* tempNext = temp;
            for (int i = 0; i < numOfWords; i++) {
                current = tempNext;
                tempNext = tempNext->getNext();
                removeCurrent();
                current = tempNext;
            }
        } else {
            sentenceFound = false;
        }
    }
}

/**********************************************************************************************************************/

void LinkedList::sort() {
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

void LinkedList::start() {
    current = head;
}

/**********************************************************************************************************************/

void LinkedList::end() {
    current = tail;
}

/**********************************************************************************************************************/

void LinkedList::forward() {
    current = current->getNext();
}

/**********************************************************************************************************************/

void LinkedList::back() {
    current = current->getPrev();
}

/**********************************************************************************************************************/

LinkedList::value_type LinkedList::getCurrent() const {
    return current->getData();
}

/**********************************************************************************************************************/

LinkedList::value_type LinkedList::getHead() const {
    return head->getData();
}

/**********************************************************************************************************************/

LinkedList::value_type LinkedList::getTail() const{
    return tail->getData();
}

/**********************************************************************************************************************/

unsigned int const LinkedList::size() {
    int a = 0;
    for (current = head; current != NULL; current = current->getNext()) {
        a++;
    }
    start();
    return a;
}

/**********************************************************************************************************************/

unsigned int const LinkedList::count(const LinkedList::value_type& s) {
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

std::ostream& operator << (std::ostream& out, LinkedList& l) {
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

void LinkedList::operator+= (LinkedList& l2) {
    l2.start();
    int l2size = l2.size();
    for (int i = 0; i < l2size; i++) {
        LinkedList::value_type temp = l2.getCurrent();
        addToTail(temp);
        l2.forward();
    }

}