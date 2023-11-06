#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

/* Outputs to a single line all of the int values stored in the list, each separated by a space. 
   This function does NOT output a newline or space at the end.
*/
ostream & operator<<(ostream &out, const IntList &rhs){
   IntNode* newNode = rhs.head;
   out << newNode;
   return out;
}
 
/* Returns true if the integer passed in is contained within the IntList.
   Otherwise returns false.
*/
bool IntList::exists(int passValue) const{
   IntNode* curr = head;
   if(exists(curr, passValue)){
      return true;
   }
   else {
      return false;
   }
}

/* Helper function that returns true if the integer passed in is contained within
   the IntNodes starting from the IntNode whose address is passed in.
   Otherwise returns false.
*/
bool IntList::exists(IntNode *test, int passValue) const{
   if(test == nullptr){
      return false;
   }
   if(test->value == passValue){
      return true;
   }

   test = test->next;
   if(exists(test, passValue)){
      return true;
   }
   else {
      return false;
   }
}

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream &out, IntNode *rhs){

   if(rhs == nullptr){
      return out;
   }
   
   if(rhs->next == nullptr){
      out << rhs->value;
      return out;
   }

   out << rhs->value << " ";
   operator<<(out, rhs->next);
   return out; 
}

