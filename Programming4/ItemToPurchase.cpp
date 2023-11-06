
/*Build the ItemToPurchase class with the following specifications:

Default constructor
Public class functions (mutators & accessors)
setName() & name()
setPrice() & price()
setQuantity() & quantity()
Private data members
string _name - Initialized in default constructor to "none"
int _price - Initialized in default constructor to 0
int _quantity - Initialized in default constructor to 0
*/


#include <iostream>
#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

//class definition 


ItemToPurchase::ItemToPurchase(){
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){
    _name = name;
    _description = description;
    _price = price;
    _quantity = quantity;
}


void ItemToPurchase::setName(string name){
    _name = name;
}

void ItemToPurchase::setPrice(int price){

    _price = price;
}

void ItemToPurchase::setQuantity(int quantity){

    _quantity = quantity;

}

void ItemToPurchase::setDescription(string description){
    _description = description; 
}


void ItemToPurchase::printItemCost() const{

    cout << _name << " " << _quantity << " @ $" << _price << " = $" << _quantity * _price << endl;
}
void ItemToPurchase::printItemDescription() const{

    cout << _name << ": " << _description << endl;
}


string ItemToPurchase::name() const{
    return _name;
}

int ItemToPurchase::price() const{
    return _price;
}

int ItemToPurchase::quantity() const{
    return _quantity;
}

string ItemToPurchase::description() const{
    return _description;
}