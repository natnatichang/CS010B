#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;


   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   
   
   ifstream fileOpen;
   fileOpen.open(inputFile);

   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!fileOpen.is_open()){
      cout << "Error opening " << inputFile << endl;
      exit(1);
   }

   vector<int> vectorThing;
   char commaCount;
   int value;

   // Read in integers from input file to vector.
   while(fileOpen >> value >> commaCount){
      vectorThing.push_back(value);
   }
   fileOpen >> value >> commaCount;
   vectorThing.push_back(value);
   // Close input stream.
   fileOpen.close();
   // Get integer average of all values read in.
   double averageVal;
   int totalVal = 0;
   for(unsigned int i = 0; i < vectorThing.size(); ++i){
      totalVal = totalVal + vectorThing.at(i);
   }

   averageVal = totalVal/vectorThing.size();

   // Convert each value within vector to be the difference between the original value and the average.

   for(unsigned int i = 0; i < vectorThing.size(); ++i){
      vectorThing.at(i) = vectorThing.at(i) - averageVal;
   }
   
   // Create output stream and open/create output csv file.

   ofstream fileOut;
   fileOut.open(outputFile);


   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   
   
   if(!fileOut.is_open()){
      cout << "Error opening " << outputFile << endl;
      exit(1);
   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(unsigned int i = 0; i < vectorThing.size(); ++i){
      fileOut << vectorThing.at(i);
      if(i < vectorThing.size() - 1){
         fileOut << ',';
      }
   }
   // Close output stream.
   fileOut.close();
   
   return 0;
}