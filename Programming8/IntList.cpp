#include <iostream>
#include "IntList.h"

using namespace std;

//Initializes an empty list.
IntList::IntList() 
    : head(nullptr),
      tail(nullptr) 
{
}

//Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
IntList::~IntList() {

    for(IntNode*p = head; p != nullptr;){
        IntNode* nextOne = p->next;
        delete p;
        p = nextOne;     
    }
}

//Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
bool IntList::empty() const {
    return (head == nullptr);
}

//Inserts a data value (within a new node) at the front end of the list.
void IntList::push_front(int value) {

    IntNode * n = new IntNode(value); 
    n->next = head; 
    head = n; 

    if(tail == nullptr){ 
        tail = n; 
    }
}

/*Removes the value (actually removes the node that contains the value) at the front end of the list. 
Does nothing if the list is already empty.*/
void IntList::pop_front() {
    
    if(empty()) return;

    IntNode* victim = head; 
    head = head->next;
    delete victim; 

    if(empty()){
        head = nullptr; 
        tail = nullptr; 
    }
}

/*Returns a reference to the first value in the list. 
Calling this on an empty list causes undefined behavior.*/
const int& IntList::front() const {

    return head->value;
}

/*Returns a reference to the last value in the list. 
Calling this on an empty list causes undefined behavior.*/
const int& IntList::back() const {

    return tail->value;
}

/*A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. 
This function does NOT send to the stream a newline or space at the end.*/
ostream & operator<<(ostream &out, const IntList &rhs) {

    IntNode *victim = rhs.head;

    if(victim != nullptr){
        out << victim->value;
        victim = victim->next;
    }

    while(victim != nullptr){
        out << " " << victim->value;
        victim = victim->next;
    }

    return out;
}

/*The copy constructor. Make sure this performs deep copy.*/
IntList::IntList(const IntList &cpy) {
 
    if(cpy.head == nullptr){
        head = nullptr;
        return;
    } 
    
    head = new IntNode(cpy.head->value);
    IntNode* curr = head;
    IntNode* cpyCurr = cpy.head->next; 

    while(cpyCurr != nullptr){
        curr->next = new IntNode(cpyCurr->value);
        curr = curr->next;
        cpyCurr = cpyCurr->next;
    }
}

/*The overloaded assignment operator. Make sure this performs deep copy.*/
IntList & IntList::operator=(const IntList &rhs) { 

    if(this != &rhs){
        clear(); 

        if(rhs.head == nullptr){
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = new IntNode(rhs.head->value);
            IntNode* curr = head; 
            IntNode* currRhs = rhs.head->next; 

            while(currRhs != nullptr){
                curr->next = new IntNode(currRhs->value);
                curr = curr->next;
                currRhs = currRhs->next;
            }
            tail = curr; 
        }
    }
    return *this; 
}
	
/*Inserts a data value (within a new node) at the back end of the list.*/
void IntList::push_back(int value) {

    IntNode* newNode = new IntNode(value);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode; 
    }
}
	
/*Removes (deallocates) all IntNodes in the IntList. 
Don't forget to set both head and tail to appropriate values for an empty list. 
DO NOT leave them dangling!*/
void IntList::clear() {

    IntNode* curr = head;
    while (curr != nullptr) {
        IntNode* victim = curr;
        curr = curr->next;
        delete victim;
    }
    head = nullptr;
    tail = nullptr;
    
}
	
/*Sorts the integers in the list into ascending order.
Do NOT move the nodes, just the integers.*/
void IntList::selection_sort() {
    if(head == nullptr || head->next == nullptr){
        return;
    }
    else {

        IntNode* minNode = nullptr;
        int temp = 0;

        for(IntNode* i = head; i->next != nullptr; i = i->next){
            minNode = i;

            for(IntNode* j = i->next; j != nullptr; j = j->next){
                if(minNode->value > j->value){
                    minNode = j;
                }
            }
            temp = i->value;
            i->value = minNode->value;
            minNode->value = temp; 
        }

    }
}

/* Inserts a data value (within a new node) in an ordered list. 
Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.) 
This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location. 
This function may NOT ever sort the list.*/
void IntList::insert_ordered(int value) {

    IntNode* newNode = new IntNode(value);

    if(head == nullptr){
        head = newNode;
        tail = newNode; 
        return;
    }
    
    if(value < head->value){
        newNode->next = head;
        head = newNode;
        return;
    }

    if(value > tail->value){
        tail->next = newNode;
        tail = newNode; 
        return; 
    }

    IntNode* prev = head; 
    IntNode* curr = head->next; 

    while(curr != nullptr && curr->value < value){
        prev = curr;
        curr = curr->next;
    }
    
    newNode->next = curr;
    prev->next = newNode; 
}

/*Removes all duplicate data values (actually removes the nodes that contain the values) within the list.
Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list.*/
void IntList::remove_duplicates() {

    IntNode* curr = head;
    while (curr != nullptr) {
        IntNode* prev = curr;
        IntNode* checker = curr->next;
        while (checker != nullptr) {
            if (checker->value == curr->value) {
                prev->next = checker->next; 
                if (checker == tail) {
                    tail = prev;
                }
                IntNode* temp = checker;
                checker = prev->next;
                delete temp; 
            } else {
                prev = checker;
                checker = checker->next;
            }
        }
        curr = curr->next;
    }
}


IntNode * min(IntNode *head){
    return nullptr; 
}
	
	
void copy(const IntList &cpy){

}