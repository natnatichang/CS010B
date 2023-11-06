#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector{

public:


IntVector(unsigned capacity = 0, int value = 0); 
~IntVector(); 

unsigned size() const; 
unsigned capacity() const; 

bool empty() const; 

const int & at(unsigned index) const; 
int & at(unsigned index); 

const int & front() const; 
int & front(); 

const int & back() const; 
int & back(); 

void insert(unsigned index, int value);
void erase(unsigned index);


void push_back(int value);
void pop_back();
void clear();
void resize(unsigned n, int value = 0);
void reserve(unsigned n);
void assign(unsigned n, int value);


private:

// stores the size of the IntVector (the number of elements currently being used to store the user's values).
unsigned _size;

// store the size of the array (therefore must always be >= to _size).
unsigned _capacity;

//  a pointer that stores the address of the dynamically-allocated array of integers
int *_data;

void expand(); 

void expand(unsigned amount); 

};


#endif
