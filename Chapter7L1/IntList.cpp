#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() 
    : head(nullptr),
      tail(nullptr) 
{
}

IntList::~IntList(){

    //pure traversal 
    IntNode* p = head; 
    
    while(p != nullptr){
        IntNode* nextLink = p->next; 
        delete p; //if you delete and then use it, this is dangling pointer 
        p = nextLink; //p is a traversal pointer  
    }
}

bool IntList::empty() const{
    return (head == nullptr);
}

void IntList::push_front(int value){

    IntNode * n = new IntNode(value); 
  
    n->next = head; 
    // have to do this first, head is pointing to original list, change next pointer on the new node
    //head is pointer at the rest of the list, make it point at the same thing

    head = n; //make head point at the same place as n 

    // edge case because head was null, assign n next = head is fine but tail is different matter, first time need to set tail, but if continue to push front no need to change tail 
    if(tail == nullptr){ 
        tail = n; 
    }

}


void IntList::pop_front(){

    //if nothing in the list, nothing to pop
    if(empty()) return;

   //this is the thing i want to delete
    IntNode* victim = head; 
    head = head->next;
    delete victim; 

    if(empty()){
        tail = nullptr; 
    }
}

const int& IntList::front() const{
    return head->value;
}


const int& IntList::back() const{
    return tail->value;
}


ostream & operator<<(ostream &out, const IntList &rhs){

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

 

IntList::IntList(const IntList &cpy){

    
}