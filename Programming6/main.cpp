#include <iostream>

using namespace std;

#include "IntVector.h"

int main(){

    //testing vectors with no parameter
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


    //testing vectors with one parameter
    IntVector oneParameter(1);
    cout << "Test functions with size 1" << endl;  
    cout << "Testing size function: " << oneParameter.size() << endl;
    cout << "Testing capacity function: " << oneParameter.capacity() << endl;
    cout << "Testing empty function: " << boolalpha << oneParameter.empty() << endl;
    cout << "Testing to check what is inside the vector: " << endl;
    for(unsigned int i = 0; i < oneParameter.size(); ++i){
        cout << "Index " << i << ": " << oneParameter.at(i) << endl;
    }
    cout << endl;

    //testing vector with two parameter
    IntVector outOfRangeVector(14, 10);
    cout << "Test functions with size 14 and values 10: " << endl;  
    cout << "Testing size function: " << outOfRangeVector.size() << endl;
    cout << "Testing capacity function: " << outOfRangeVector.capacity() << endl;
    cout << "Testing empty function: " << boolalpha << outOfRangeVector.empty() << endl;
    cout << "Testing to check what is inside the vector: " << endl;
    for(unsigned int i = 0; i < outOfRangeVector.size(); ++i){
        cout << "Index " << i << ": " << outOfRangeVector.at(i) << endl;
    }
    cout << endl;


    //testing vector for outofrange message 
    //cout << "Testing for out of range index: " << outOfRangeVector.at(10000) << endl;
    //cout << endl;
    
    //testing front and back function
    IntVector frontAndBack(10, 12);
    cout << "Testing front function: " << frontAndBack.front() << endl;
    cout << "Testing back function: " << frontAndBack.back() << endl;
    cout << endl;



    //testing the insert function
    // IntVector insertFunc(5, 0);
    // insertFunc.insert(2, 1);
    // cout << "Testing to check what is inside the vector after inserting 1 at index 2: " << endl;
    // for(unsigned int i = 0; i < insertFunc.size(); ++i){
    //     cout << "Index: " << i << ": " << insertFunc.at(i) << endl;
    // }
    // cout << endl;

    //testing the erase function 
    IntVector eraseFunc(4,1);
    eraseFunc.insert(2,6);
    cout << "Testing to check what is inside the vector before erasing" << endl;
    for(unsigned int i = 0; i < eraseFunc.size(); ++i){
        cout << "Index: " << i << ": " << eraseFunc.at(i) << endl;
    }

    eraseFunc.erase(2);
    cout << "Testing to check what is inside the vector after erasing" << endl;
    for(unsigned int i = 0; i < eraseFunc.size(); ++i){
        cout << "Index: " << i << ": " << eraseFunc.at(i) << endl;
    }
    cout << endl;


    //testing pushback function 
    IntVector pushFun(2,1);
    cout << "Testing to check what is inside the vector before pushback" << endl;
    for(unsigned int i = 0; i < pushFun.size(); ++i){
        cout << "Index: " << i << ": " << pushFun.at(i) << endl;
    }

    pushFun.push_back(10);
    cout << "Testing to check what is inside the vector after pushback" << endl;
    for(unsigned int i = 0; i < pushFun.size(); ++i){
        cout << "Index: " << i << ": " << pushFun.at(i) << endl;
    }
    cout << endl;


    //testing popback function 
    IntVector popFun(2,1);
    cout << "Testing to check what is inside the vector before popback" << endl;
    for(unsigned int i = 0; i < popFun.size(); ++i){
        cout << "Index: " << i << ": " << pushFun.at(i) << endl;
    }

    popFun.pop_back();
    cout << "Testing to check what is inside the vector after popback" << endl;
    for(unsigned int i = 0; i < popFun.size(); ++i){
        cout << "Index: " << i << ": " << pushFun.at(i) << endl;
    }
    cout << endl;

    //testing clear function 
    IntVector clearFun(2,1);
    cout << "Testing to check what is inside the vector before popback" << endl;
    for(unsigned int i = 0; i < clearFun.size(); ++i){
        cout << "Index: " << i << ": " << clearFun.at(i) << endl;
    }

    clearFun.clear();
    cout << "Testing to check what is inside the vector after popback" << endl;
    for(unsigned int i = 0; i < clearFun.size(); ++i){
        cout << "Index: " << i << ": " << clearFun.at(i) << endl;
    }
    cout << endl;


    //testing resize function 
    IntVector resizeFun(2);
    cout << "Testing to check what is inside the vector before resize" << endl;
    for(unsigned int i = 0; i < resizeFun.size(); ++i){
        cout << "Index: " << i << ": " << resizeFun.at(i) << endl;
    }

    resizeFun.resize(10);
    cout << "Testing to check what is inside the vector after resize" << endl;
    for(unsigned int i = 0; i < resizeFun.size(); ++i){
        cout << "Index: " << i << ": " << resizeFun.at(i) << endl;
    }
    cout << endl;


    //testing reserve function 
    IntVector reserveFun;
    cout << "Testing to check what is inside the vector before reserve" << endl;
    for(unsigned int i = 0; i < reserveFun.size(); ++i){
        cout << "Index: " << i << ": " << reserveFun.at(i) << endl;
    }
    reserveFun.push_back(2);
    reserveFun.push_back(43);
    reserveFun.reserve(100);
    cout << "Testing to check what is inside the vector after reserve" << endl;
    for(unsigned int i = 0; i < reserveFun.size(); ++i){
        cout << "Index: " << i << ": " << reserveFun.at(i) << endl;
    }
    cout << "Check the capacity of the function: " << reserveFun.capacity(); 
    cout << endl << endl;

    //testing assign function 
    IntVector assignFun(2, 1);
    cout << "Testing to check what is inside the vector before assign" << endl;
    for(unsigned int i = 0; i < assignFun.size(); ++i){
        cout << "Index: " << i << ": " << reserveFun.at(i) << endl;
    }

    assignFun.assign(2 , 3);
    cout << "Testing to check what is inside the vector after assign" << endl;
    for(unsigned int i = 0; i < assignFun.size(); ++i){
        cout << "Index: " << i << ": " << assignFun.at(i) << endl;
    }
    cout << endl;

    return 0;


}