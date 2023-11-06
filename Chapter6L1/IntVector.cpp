#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntVector.h"


//sets both the size and capacity of the intVector to the value of the parameter passed in
//dynamically allocates array of size
//if capacity is 0, no array
//do not leave any dangling pointer

IntVector::IntVector(unsigned capacity, int value){
 _size = capacity;
 _capacity = capacity;
 _data = nullptr; 

 _data = new int [_capacity];

 for(unsigned int i = 0; i < _capacity; ++i){
    _data[i] = value;
 }

}

// IntVector::IntVector(unsigned capacity, int value)
//     : _size(capacity), 
//    _capacity(capacity), 
//    _data(nullptr); 
// {

//  _data = new int [_capacity];

//  for(unsigned int i = 0; i < _capacity; ++i){
//     _data[i] = value;
//  }

// }


//destructor should delete any remaining allocated memory, array is poitned by the pointer named _data
IntVector::~IntVector(){
    delete[] _data;
}

//function returns current size of the intvector
unsigned IntVector::size() const{
 return _size;
}

//returns returns current capacity of the intvector
unsigned IntVector::capacity() const{
 return _capacity;
}

//returns if vector is empty
bool IntVector::empty() const{
    if(_size == 0){
        return true;    
    }
    return false;
}


//function will return the value stored in the element at the passed in index position
//function should throw an outofrange exception if an invalid index is passed in
//invalid index is index greater than or equal to the size
const int & IntVector::at(unsigned index) const{
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

// return the value stored in the first element of the intvector
//does not check sie of the intvector or array, if empty then calling this function causes undefined behavior
const int & IntVector::front() const{
    return _data[0];
}

//function  will return the value stored in the last element of the intvector
//does not check the size of the intvector or the array
//if intvector is empty, calling function causes undefined behavior
const int & IntVector::back() const{
    return _data[_size - 1];
}