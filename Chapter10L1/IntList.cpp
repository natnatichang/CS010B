#include "IntList.h"

bool IntList::bubbleUp() {
   return bubbleUp(head); 
}

bool IntList::bubbleUp(IntNode *curr) {

   bool checker = false;

   if(curr == nullptr || curr->next == nullptr){
      return false;
   }

   // want so that when the next number is smaller, stop sorting the previous num
   checker = bubbleUp(curr->next);
   
   if(curr->next->value < curr->value){
      //swaps value of two variables 
      swap(curr->value, curr->next->value);
      return true;
   }
   return checker;
}





