#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string filename);

//Implement the function fileSum. fileSum is passed in a name of a file. This function should open the file, sum all of the integers within this file, close the file, and then return the sum. 
int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here

int fileSum(string filename){

   ifstream fileOpen;  
   int sum = 0;
   int userInput = 0;

   fileOpen.open(filename);

   if(!fileOpen.is_open()){
      cout << "Error opening " << filename << endl;
      exit(1);
   }

      fileOpen >> userInput; 
      while(!fileOpen.fail()){
      sum = sum + userInput; 
      fileOpen >> userInput;
      } 

      
      // while(fileOpen >> userInput){
      //    cout << userInput << endl;
      //    sum = sum + userInput; 
   
      // } 
   

   fileOpen.close();
   return sum;
   
   }

