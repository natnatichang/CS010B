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
    _data = new int [_capacity];

    for(unsigned int i = 0; i < _capacity; ++i){
        _data[i] = value;
    }

}

//destructor should delete any remaining allocated memory, array is poitned by the pointer named _data
IntVector::~IntVector(){
    cout << "Deconstructing" << endl;
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
    //
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}


//non const does the exact same thing const version does 
int & IntVector::at(unsigned index){
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


//non const does the exact same thing const version does 
int & IntVector::front(){
    return _data[0];
}

//function  will return the value stored in the last element of the intvector
//does not check the size of the intvector or the array
//if intvector is empty, calling function causes undefined behavior
const int & IntVector::back() const{
    return _data[_size - 1];
}


//non const does the exact same thing const version does 
int & IntVector::back(){
    return _data[_size - 1];
}


//function will double the capacity of the vector
//should reallocate memory and update the value of capacity
//handles cases if capacity is 0
void IntVector::expand(){
    //
    if(_capacity == 0){
        _capacity = 1;
    }
    else{
        _capacity *= 2; 
    }

    int* allocateTemp = new int[_capacity];

    for(unsigned int i = 0; i < _size; ++i){
        allocateTemp[i] = _data[i];
    } 

    delete[] _data; 
    _data = allocateTemp;
    allocateTemp = nullptr; 

}

//unsigned version of expand but will expand the capacity of the vector by the amount passeed in 
void IntVector::expand(unsigned amount){
    
    _capacity += amount; 

    int* allocateTemp = new int[_capacity];

    for(unsigned int i = 0; i < _size; ++i){
        allocateTemp[i]  = _data[i];
    } 

    delete[] _data; 
    _data = allocateTemp;
    allocateTemp = nullptr; //prevent dangling

}


//function inserts data at postion index, all values at position index and greater are shifted to the right by 1
//size increased by 1, but if size is larger than capacity, function needs to first double the capacty
//if capacity and size are both 20, function must incrase capacty to 40
//can call expand to do so
//should also through out of range 
void IntVector::insert(unsigned index, int value){
    
    if (index > _size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    
    if (_size == _capacity) {
        expand();
    }

    int* allocateTemp = new int[_capacity];

    for (unsigned int i = 0; i < index; i++) {
        allocateTemp[i] = _data[i];
    }

    allocateTemp[index] = value;

    for (unsigned int i = index + 1; i <= _size; i++) {
    allocateTemp[i] = _data[i - 1];
    }

    delete[] _data;
    _data = allocateTemp;
    allocateTemp = nullptr; 

    _size++;


}

//function should remove the value at position index, shift all of the values at position greater than index to the left by one
//to the element right before its current position
//size decrease by 1
//throw out of range
void IntVector::erase(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }

    int* allocateTemp = new int[_size];
    for(unsigned int i = 0; i < _size; ++i){
        allocateTemp[i] = _data[i];
    }

     for(unsigned int i = index; i < _size; ++i){
        _data[i] = allocateTemp[i+1];
    }
    _size--;
    delete[] allocateTemp;
    allocateTemp = nullptr; 
}

//inserts a value at the back end of the array
//size is increased by 1
//if size is larger than the capacity, need to increase the capacity
//
void IntVector::push_back(int value){
    _size++;
    if(_size >= _capacity){
        expand();
    }
    _data[_size - 1] = value; 
}

//function just needs to decrease size by 1
//function never throw an exception 
void IntVector::pop_back(){
    _size--; 
}

//funcction reduces the size of the vector to 0
void IntVector::clear(){
    _size = 0; 
}

//function resizes the vector 
//if size is smaller than the current _size, then function just reduces _size to size
//if size is greater than the current _size, then appropriate number of elements are inserted at the end of the vector
//gives all of the new elements the valye passed into the second parameter
//if new value of size will be larger than the capaciyt, the capacity needs to be expanded by doubling or increasing capacity by certain amount
void IntVector::resize(unsigned n, int value){
    if(n < _size){
        _size = n;
    }
    if(_capacity < n){
        if(n < _capacity * 2 && _capacity != 0){
            expand();
        }
        else{
            expand(n - _capacity);
        }
    }

    int *allocateTemp = _data;
    _data = new int[n];

    for(unsigned int i = 0; i < n; ++i){
        _data[i] = allocateTemp[i];
    }

    for(unsigned int i = _size; i < n; ++i){
        _data[i] = value;
    }

    _size = n;
    delete[] allocateTemp; 
    allocateTemp = nullptr; 
    
}

//function should request that the capacity be set to n minimum
//function should never reduce the size of vector
//if n is learger than the current capacity, then the capacity will expand to n
//call to function never affects elements in the vector or vector size

void IntVector::reserve(unsigned n){

    if(_capacity < n){

      int* allocateNew = new int[n];
        if (_data) {
            for (unsigned i = 0; i < _size; ++i) {
                allocateNew[i] = _data[i];
            }
            delete[] _data;
            _data = nullptr; 
        }
        _data = allocateNew;
        _capacity = n;

      
    }

}

//assigns new content to the vector object
//drops all elements contained in the vector before call and replace them by those specified in the parameter
//new value of size will be n and all values stored in the vector will have the value of the second parameter
//if the new value of size will be larger than the capacity, the function must first expand capacity

void IntVector::assign(unsigned n, int value){

    if(_capacity < n){
        expand();
        if(_capacity < n){
            expand(n - _capacity);
        }
    }

    int *allocateTemp = _data;
    _data = new int[n];
    for(unsigned int i = 0; i < n; ++i){
        _data[i] = value;
    }

    _size = n;
    delete[] allocateTemp; 
    allocateTemp = nullptr; 

}