#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

//define, indef, endef later

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class declaration 

class ItemToPurchase {


public:

//Default Constructor
ItemToPurchase();

ItemToPurchase(string name, string description, int price, int quantity);

//setname function
void setName(string name);
void setPrice(int price);
void setQuantity(int quantity);
void setDescription(string name);

void printItemCost() const; 
void printItemDescription() const;

//accessors aka Get functions

string name() const;
int price() const;
int quantity() const;
string description() const;


private: 

    string _name;
    int _price;
    int _quantity;
    string _description;


};

#endif