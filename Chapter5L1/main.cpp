//include any standard libraries needed
#include <iostream>
#include <fstream>

using namespace std; 

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   if(argc < 2){
      cout << "error" << endl;
      return 1;
   }
   
   // open file and verify it opened

    ifstream inFS;
    inFS.open(argv[1]);

      if(!inFS.is_open()){
         cout << "error" << endl;
         return 1;
      }

   // Declare an array of doubles of size ARR_CAP.
   double testing[ARR_CAP];
    
   double value;  
   int i = 0; 
   //inFS >> value && i < ARR_CAP
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   while(inFS >> value && i < ARR_CAP){
       testing[i] = value;
       i++;
   }
    
   inFS.close();

   // for (int i = 0; i < ARR_CAP; i++) {
   //  cout << testing[i] << " ";
   // }

   // Call the mean function passing it this array and output the 
   // value returned.
   double meanOutput;
   meanOutput = mean(testing, i);
   cout << "Mean: " << meanOutput << endl << endl;
   
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int index;
   cout << "Enter index of value to be removed (0 to "<< i - 1 << "):" << endl << endl;
	cin >> index; 


   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(testing, i);
   cout << endl << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.
   int test = i;
   remove(testing, test, index);
  
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";  
   display(testing, i - 1);
    cout << endl << endl;
   
   // Call the mean function again to get the new mean
 
   double newMeanOutput;
   newMeanOutput = mean(testing, i - 1);
   cout << "Mean: " << newMeanOutput;
   
	return 0;
}


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize){
double sum = 0;
for( int i = 0; i < arraySize; ++i){
   sum += array[i];
}

double mean = sum / arraySize;
return mean;
}


//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index){
 
   // for( int i = index; i < arraySize - 1; ++i){
   //    array[i] = array[i + 1];
   // }
   // arraySize = arraySize - 1;
  
    for( int i = index + 1; i < arraySize; ++i){
      array[i - 1] = array[i];
   }
   arraySize--;

}

// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize){
   for( int i = 0; i < arraySize; ++i){ 
      cout << array[i];
      if(i < arraySize - 1){
         cout << ", ";
      }
   }

}
