//THIS GAVE ME 50 ON THE PROGRAMMING ASSISGNMENT DO NOT TOUCH 


#include <iostream>
#include <string>



#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void printMenu(ShoppingCart cart);

int main(){


string _customerName;
string _currentDate;

cout << "Enter customer's name: ";
getline(cin, _customerName);
cout << endl;
cout << "Enter today's date: ";
getline(cin, _currentDate); 
cout << endl << endl;

ShoppingCart cart(_customerName, _currentDate);


cout << "Customer name: " << cart.customerName() << endl;
cout << "Today's date: " << cart.date() << endl << endl;

printMenu(cart);

return 0;

}


void printMenu(ShoppingCart cart){

char userInput = '!'; 

string _name; 
int _price; 
int _quantity; 
string _description;

cout << "MENU" << endl; 
cout << "a - Add item to cart" << endl;
cout << "d - Remove item from cart" << endl;
cout << "c - Change item quantity" << endl;
cout << "i - Output items' descriptions" << endl;
cout << "o - Output shopping cart" << endl;
cout << "q - Quit" << endl;
cout << endl;


while(userInput != 'q'){
cout << "Choose an option: " << endl;
cin >> userInput;


if(userInput == 'a'){
    //how to clear cin buffer?? keeps giving infinite loop
    cin.ignore();
    cout << endl;
cout << "ADD ITEM TO CART" << endl;

cout << "Enter the item name: " << endl;
getline(cin, _name);

cout << "Enter the item description: " << endl;
getline(cin, _description);

cout << "Enter the item price: " << endl;
cin >> _price;

cout << "Enter the item quantity: " << endl << endl;
cin >> _quantity;

ItemToPurchase item (_name, _description, _price, _quantity);
cart.addItem(item);


cout << "MENU" << endl; 
cout << "a - Add item to cart" << endl;
cout << "d - Remove item from cart" << endl;
cout << "c - Change item quantity" << endl;
cout << "i - Output items' descriptions" << endl;
cout << "o - Output shopping cart" << endl;
cout << "q - Quit" << endl;
cout << endl;

 //cout << "Choose an option: " << endl;

}
else if(userInput == 'd'){
cin.ignore();
cout << endl;
cout << "REMOVE ITEM FROM CART" << endl << "Enter name of item to remove: " << endl;
getline(cin, _name);
cart.removeItem(_name);
//new change
cout << endl;
cout << "MENU" << endl; 
cout << "a - Add item to cart" << endl;
cout << "d - Remove item from cart" << endl;
cout << "c - Change item quantity" << endl;
cout << "i - Output items' descriptions" << endl;
cout << "o - Output shopping cart" << endl;
cout << "q - Quit" << endl;
cout << endl;

 //cout << "Choose an option: " << endl;

}
else if(userInput == 'c'){
cin.ignore();
ItemToPurchase testing;
cout << endl;
cout << "CHANGE ITEM QUANTITY" << endl << "Enter the item name: " << endl;
getline(cin, _name);
cout << "Enter the new quantity: " << endl;

cin >> _quantity;

testing.setName(_name);
testing.setQuantity(_quantity);
cart.modifyItem(testing);


cout << "MENU" << endl; 
cout << "a - Add item to cart" << endl;
cout << "d - Remove item from cart" << endl;
cout << "c - Change item quantity" << endl;
cout << "i - Output items' descriptions" << endl;
cout << "o - Output shopping cart" << endl;
cout << "q - Quit" << endl;
cout << endl;
 
 //cout << "Choose an option: " << endl;

}
else if(userInput == 'i'){
cin.ignore();
cart.printDescriptions();

cout << "MENU" << endl; 
cout << "a - Add item to cart" << endl;
cout << "d - Remove item from cart" << endl;
cout << "c - Change item quantity" << endl;
cout << "i - Output items' descriptions" << endl;
cout << "o - Output shopping cart" << endl;
cout << "q - Quit" << endl;
cout << endl;

//cout << "Choose an option: " << endl;
}
else if(userInput == 'o'){

cin.ignore();    
cout << endl;
cout << "OUTPUT SHOPPING CART" << endl;
//why not printing? 
cart.printTotal();
cout << endl;

cout << "MENU" << endl; 
cout << "a - Add item to cart" << endl;
cout << "d - Remove item from cart" << endl;
cout << "c - Change item quantity" << endl;
cout << "i - Output items' descriptions" << endl;
cout << "o - Output shopping cart" << endl;
cout << "q - Quit" << endl;
cout << endl;
 
 
// cout << "Choose an option: " << endl;

}
else if(userInput == 'q'){
    break;
}

}
}





