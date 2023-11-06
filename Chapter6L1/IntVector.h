#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector{

public:


IntVector(unsigned capacity = 0, int value = 0); // define in header, put default value, below u don't 
~IntVector();

unsigned size() const;
unsigned capacity() const;

bool empty() const;

const int & at(unsigned index) const;
const int & front() const;
const int & back() const;



private:

// stores the size of the IntVector (the number of elements currently being used to store the user's values).
unsigned _size;

// store the size of the array (therefore must always be >= to _size).
unsigned _capacity;

//  a pointer that stores the address of the dynamically-allocated array of integers
int *_data;



};


#endif
