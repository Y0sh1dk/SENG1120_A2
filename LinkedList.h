#include "Node.h"

#ifndef MY_LINKEDLIST
#define MY_LINKEDLIST

class LinkedList {
    public:
        typedef Node::value_type value_type;
    //Pre-Condition: None
    // Creates a empty LL
    //Post-Condition: None
        LinkedList();

        //Pre-Condition: None
        // Loops through whole LL, deleting nodes
        //Post-Condition: None
        ~LinkedList();

        //Pre-Condition: Takes a string to be split into words and added to the LL
        //
        //Post-Condition: None
        void add(const value_type& s);

        //Pre-Condition: Takes a string, either a single word or sentence to be removed from LL
        //
        //Post-Condition: None
        void remove(const value_type& s);

        //Pre-Condition: Takes a string to be split into words and added to the LL
        //
        //Post-Condition: None
        void removeWord(const value_type& s);

        //Pre-Condition: called by remove(), removes a single word
        //
        //Post-Condition: None
        void removeSentence(const value_type& s);

        //Pre-Condition: None
        //Sorts the LL alphabetically
        //Post-Condition: None
        void sort();

        //Pre-Condition: takes a single word as a string and adds it to the head of LL
        //
        //Post-Condition: None
        void addToHead(value_type& item);

        //Pre-Condition: takes a single word as a string and adds it to the tail of LL
        //
        //Post-Condition: None
        void addToTail(value_type item);

        //Pre-Condition: takes a single word as a string and adds it after the current ptr
        //
        //Post-Condition: None
        void addAfterCurrent(value_type& item);

        //Pre-Condition: Removes head node
        //
        //Post-Condition: None
        void removeHead();

        //Pre-Condition: Removes tail node
        //
        //Post-Condition: None
        void removeTail();

        //Pre-Condition: removes node at current ptr
        //
        //Post-Condition: None
        void removeCurrent();

        //Pre-Condition: None
        //
        //Post-Condition: returns the data stored in the head node
        value_type getHead() const;

        //Pre-Condition: None
        //
        //Post-Condition: returns the data stored in the tail node
        value_type getTail() const;

        //Pre-Condition: None
        //
        //Post-Condition: returns the data stored in the current node
        value_type getCurrent() const;

        //Pre-Condition: None
        //Sets current pointer to the head of the LL
        //Post-Condition: None
        void start();

        //Pre-Condition: None
        //Sets current pointer to the tail of the LL
        //Post-Condition: None
        void end();

        //Pre-Condition: None
        //Moves current pointer along one, to the next node
        //Post-Condition: None
        void forward();

        //Pre-Condition: None
        //Moves current pointer back one, to the previous node
        //Post-Condition: None
        void back();

        //Pre-Condition: takes a string to count how many times it occurs in the LL
        //
        //Post-Condition: returns a unsigned int of how many times
        unsigned int const count(const value_type& s);

        //Pre-Condition: None
        //
        //Post-Condition: Returns a unsigned int of how many nodes are in the LL
        unsigned int const size(); // can only be positive so unsigned

        //Pre-Condition: A second list to concatenate to the current
        //
        //Post-Condition: None
        void operator += (LinkedList& l2);

    private:
        Node* head; // store ptr to head node of the LL
        Node* tail; // store ptr to tail node of the LL
        Node* current; // store ptr to 'current' node of the LL

};

//Pre-Condition: None
//
//Post-Condition: Returns a string representation of the LL class
std::ostream& operator << (std::ostream& out, LinkedList& l);

#endif