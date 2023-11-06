#include <iostream>

using namespace std;

#include "IntVector.h"

int main(){


    IntVector testingVector;
    
    cout << "Test harness for empty vector" << endl; 
    cout << "Testing size function: " << testingVector.size() << endl;
    cout << "Testing capacity function: " << testingVector.capacity() << endl;
    cout << "Testing empty function: " << boolalpha << testingVector.empty() << endl;
    cout << endl;
    cout << "Testing to check what is inside the vector: " << endl;
    for(unsigned int i = 0; i < testingVector.size(); ++i){
        cout << "Index: " << i << ": " << testingVector.at(i) << endl;
    }



    IntVector oneParameter(1);
    cout << "Test functions with size 1" << endl;  

    cout << "Testing size function: " << oneParameter.size() << endl;
    cout << "Testing capacity function: " << oneParameter.capacity() << endl;
    cout << "Testing empty function: " << boolalpha << oneParameter.empty() << endl;
    
    cout << "Testing to check what is inside the vector: " << endl;
    for(unsigned int i = 0; i < oneParameter.size(); ++i){
        cout << "Index: " << i << ": " << oneParameter.at(i) << endl;
    }


    IntVector outOfRangeVector(14, 10);
    cout << "Test functions with size 14 and values 10: " << endl;  

    cout << "Testing size function: " << outOfRangeVector.size() << endl;
    cout << "Testing capacity function: " << outOfRangeVector.capacity() << endl;
    cout << "Testing empty function: " << boolalpha << outOfRangeVector.empty() << endl;
    
    cout << "Testing to check what is inside the vector: " << endl;
    for(unsigned int i = 0; i < outOfRangeVector.size(); ++i){
        cout << "Index: " << i << ": " << outOfRangeVector.at(i) << endl;
    }

    cout << "Testing for out of range index: " << outOfRangeVector.at(10000) << endl;
    cout << endl;
    
    IntVector frontAndBack(10, 12);

    cout << "Testing front function: " << frontAndBack.front() << endl;
    cout << "Testing back function: " << frontAndBack.back() << endl;
    cout << endl;

    return 0;


}