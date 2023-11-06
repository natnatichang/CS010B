#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <string>
#include <vector>


#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart{


public:

ShoppingCart();
ShoppingCart(string customerName, string currentDate);

string customerName() const;
string date() const;

void addItem(ItemToPurchase item);
void removeItem(string itemName);
void modifyItem(ItemToPurchase item);

int numItemsInCart() const;
int costOfCart() const;
void printTotal() const;
void printDescriptions() const;



private:

string _customerName;
string _currentDate;
vector<ItemToPurchase> _cartItems;


};


#endif