
#include <iostream>
#include <string>
#include <vector>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

using namespace std;


ShoppingCart::ShoppingCart(){
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date){
    _customerName = name;
    _currentDate = date;
}

string ShoppingCart::customerName() const{
    return _customerName;

}

string ShoppingCart::date() const{
    return _currentDate;
}

void ShoppingCart::addItem(ItemToPurchase item){
    _cartItems.push_back(item);
    

}
void ShoppingCart::removeItem(string itemName){
    bool checker = false;

    ItemToPurchase makeRemove;

    for(unsigned int i = 0; i < _cartItems.size(); ++i){
        if(_cartItems.at(i).name() == itemName && (!checker)){
            
            makeRemove = _cartItems.at(i);
            for(unsigned int j = i; j < _cartItems.size(); ++j){
                _cartItems.at(i) = _cartItems.at(i + 1);
            }
            _cartItems.at(_cartItems.size() - 1) = makeRemove;
            _cartItems.pop_back(); 

            checker = true;
        }
    }

    if(!checker){

        cout << "Item not found in cart. Nothing removed." << endl;
    
    }
}

void ShoppingCart::modifyItem(ItemToPurchase item){
bool checker = false;

// use for loop, go through and look for the name, based on the name you just need to change the quantity of it
// if the name is not found, then output statement....do i need to look at testing 

/* modifyItem()
Modifies an item's description, price, and/or quantity. Has a parameter of type ItemToPurchase. Does not return anything.
If item can be found (by name) in cart, check if parameter variable has default values for description, price, and/or quantity. 
For each of the non-default values in parameter, set the item in the cart to the non-default value. 
For example, if the parameter has non-default values for quantity and price but a default value for the description, 
then just set the quantity and price in the cart item to the parameter's values for quantity and price and leave the cart item's description alone.
If item cannot be found (by name) in cart, output this message: Item not found in cart. Nothing modified.*/


for(unsigned int i = 0; i < _cartItems.size(); ++i){

    if((_cartItems.at(i).name() == item.name())){
        cout << endl;
        if((item.description() != "none")){
        }
        else {
           item.setDescription(_cartItems.at(i).description()); 
        }
            
        if (item.price() !=0){
        }
        else {
            item.setPrice(_cartItems.at(i).price());
        }
        
        if(item.quantity() != 0){
        }
        else {
            item.setQuantity(_cartItems.at(i).quantity());
        }
            _cartItems.at(i) = item;
            checker = true;
        }
            
     }

    if(!checker){
        cout << "Item not found in cart. Nothing modified." << endl << endl;
    }

}

int ShoppingCart::numItemsInCart() const{
    int numItem = 0;

    for(unsigned int i = 0 ; i < _cartItems.size(); ++i){
        numItem += _cartItems.at(i).quantity();
    }
    return numItem;

}

int ShoppingCart::costOfCart() const{
    int totalCart = 0;
    for(unsigned int i = 0 ; i < _cartItems.size(); ++i){
        totalCart += ( _cartItems.at(i).price()) * (_cartItems.at(i).quantity());
    }
    return totalCart;
}
void ShoppingCart::printTotal() const{
    int total = 0;
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl << endl;

    if(_cartItems.size() == 0){
        cout << "SHOPPING CART IS EMPTY" << endl;
    } 
    else{
     for(unsigned int i = 0; i < _cartItems.size(); ++i){
        cout << _cartItems.at(i).name() << " " << _cartItems.at(i).quantity() << " @ $" << _cartItems.at(i).price() << " = $" << (_cartItems.at(i).price() * _cartItems.at(i).quantity()) << endl;
        total += (_cartItems.at(i).price() * _cartItems.at(i).quantity());
        }
    }
    cout << endl << "Total: $" << total << endl;
}


void ShoppingCart::printDescriptions() const{
    cout << endl;
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
     cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << endl << "Item Descriptions";
    for (unsigned int i = 0; i < _cartItems.size(); i++) {
        cout << endl << _cartItems.at(i).name() << ": " << _cartItems.at(i).description();
    }
    /// add new 
    cout << endl; 
    cout << endl;

}


