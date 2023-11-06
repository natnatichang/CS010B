#include "SortedSet.h"

using namespace std;



SortedSet::SortedSet() : IntList(){} 

SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) {}

SortedSet::SortedSet(const IntList &cpy) : IntList(cpy){
    remove_duplicates();
    selection_sort();
}

//deallocate any dyncamilly allocated memory that the SortedSet class manages
//no need to deallocate memory that is managed by IntList
SortedSet::~SortedSet(){
    clear(); 
}

const bool SortedSet::in(int value) const{
    for(IntNode *curr = head; curr != nullptr; curr = curr->next){
        if(value == curr->value){
            return true;
        }
    }
    return false; 
}

const SortedSet SortedSet::operator|(const SortedSet &sset2){
    SortedSet returnSet; 

    for(IntNode *curr = head; curr != nullptr; curr = curr->next){
        if(!returnSet.in(curr->value)){
            returnSet.insert_ordered(curr->value);
        }
    }

    for(IntNode *curr = sset2.head; curr != nullptr; curr = curr->next){
        if(!returnSet.in(curr->value)){
            returnSet.insert_ordered(curr->value);
        }
    }

    return returnSet;
}


const SortedSet SortedSet::operator&(const SortedSet &sset2){
    SortedSet returnSet;

    for(IntNode *curr = head; curr != nullptr; curr = curr->next){
        if(sset2.in(curr->value)){
            returnSet.add(curr->value);
        }
    }

    return returnSet; 
}

//only loop through it once 
void SortedSet::add(int value){
    
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
    IntNode* curr = head; 

    while(curr != nullptr && curr->value < value){
        prev = curr;
        curr = curr->next;
    }

    if(curr != nullptr && curr->value == value){
        return;
    }

    newNode->next = curr;
    prev->next = newNode;

}
void SortedSet::push_front(int value){
    add(value);
}
void SortedSet::push_back(int value){
    add(value);
}
void SortedSet::insert_ordered(int value){
    add(value);
}

SortedSet SortedSet::operator|=(const SortedSet &rhs){
    for (IntNode* curr = rhs.head; curr != nullptr; curr = curr->next) {
            push_back(curr->value);
        }

        selection_sort();
        remove_duplicates();

        return *this;
}

SortedSet SortedSet::operator&=(const SortedSet &rhs){
    SortedSet returnSet;
    for (IntNode* curr = head; curr != nullptr; curr = curr->next) {
        if (rhs.in(curr->value)) {
            returnSet.push_back(curr->value);
        }
    }
    *this = returnSet;
    return *this;
}

