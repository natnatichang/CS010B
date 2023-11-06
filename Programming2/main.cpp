//libraries that are needed
#include<iostream>
#include<fstream>
#include<vector>
#include <cstdlib>
#include <string>
#include <cmath>


using namespace std;

// function declaration 
void readData(const string&, vector<double> &, vector<double> &);
double interpolation(double, const vector<double>&, const vector<double>&);
bool isOrdered(const vector<double>&);
void reorder(vector<double>&, vector<double> &);


int main(int argc, char *argv[]) {

    //Get from the command line the name of the file that contains the wind tunnel data.
    ifstream inFS;
    string inputFile;
    inputFile = argv[1];
    inFS.open(argv[1]);

    //Checks if the file is correct, if not then output an error
    if(!inFS.is_open()) {
      cout << "Error opening " << inputFile << endl;
      exit(1);
   }

   //create two double vectors where one will store the flight path and the other is the coefficient of Lift 
   vector<double> flightPath;
   vector<double> coeffLift;

   //call the function readData to pass in the numbers from .dat files
   readData(inputFile, flightPath, coeffLift);

   //after reading in the data, check if the flightPath is ordered correctly. If not, then you need to call reorder function
   if(!isOrdered(flightPath)){
   reorder(flightPath, coeffLift);
   }

   //create a string for the userInput, but need to make it yes first so it prompts, otherwise it will go into infinite loop
    string userInput = "Yes"; 
   //create a variable for the angle that the user will input
    double userNum; 

    while(userInput != "No"){
        //user will input flight-path angle, and if it is within the bounds of the data set, then the program will use linear interpolation to output the lift
        cout << "Pleae enter a flight-path angle" << endl;
        cin >> userNum; 
        cout << interpolation(userNum, flightPath, coeffLift) << endl;
        //user can enter another flight-path and if they say yes then continue, otherwise no 
        cout << "Would you like to enter in another flight-path?" << endl;
        cin >> userInput; 
    }

    //close the file in the end
    inFS.close();
    return 0;
}


//function will help to populate the vector with numbers by reading in the files 
void readData(const string &inputFile, vector<double> &flightPath, vector<double> &coeffLift){

    //need to use ifstream to write to the file later
    ifstream fileOpen;
    //this will help populate the vectors
    double angle = 0.0;
    double coeff = 0.0;

    //open the file
    fileOpen.open(inputFile);

    //checks if the file is opened, if not then output an error
    if(!fileOpen.is_open()){
      cout << "Error opening " << inputFile << endl;
      exit(1);
    }

   //let the user to write to the file for the angles and coefficient, and then pushback into the vector
    while(fileOpen >> angle >> coeff){
    flightPath.push_back(angle);
    coeffLift.push_back(coeff);
    }

    //close the file
    fileOpen.close();
}

//function will run to do interpolation after the user is prompted in main
double interpolation(double userNum, const vector<double> &flightPath, const vector<double> &coeffLift){

    double flightPathB;

    //if flight path b already exist then don't need linear interpolation, can just return the flightpath at i
    for(unsigned int i = 0; i < flightPath.size(); ++i){
        if(flightPath.at(i) == userNum){
            return coeffLift.at(i);
        }
    }

    // if flight path at b doesn't exist, use linear interpolation
    for(unsigned int i = 0; i < flightPath.size(); ++i){
        //check that there is at least numbers so that a < b < c and |c - a|
        if(flightPath.at(i) < userNum){
            //use formula to return the flightPath
            //f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a)) 
            flightPathB = coeffLift.at(i) + ((userNum - flightPath.at(i)) / (flightPath.at(i + 1)  - flightPath.at(i)) * (coeffLift.at(i + 1) - coeffLift.at(i)));
        }
    }
    return flightPathB;
}

//function checks if the flightPath is ordered. If not then it needs to return false
bool isOrdered(const vector<double> &flightPath){
    bool checker = true; 
    for(unsigned int i = 1; i < flightPath.size(); ++i){
       if(flightPath.at(i) < flightPath.at(i - 1)){
        return false;
       }
    }
    return checker;
}

//if the previous function isOrdered returned as false, then this function will help to reorder it
void reorder(vector<double> &flightPath, vector<double> &coeffLift){
    //create temporary variables to help with the swap later
    double tempValFlight;
    double tempValCoef;

    //need to use nested for loop so you can check for all the numbers, sort of like bubble sort
    for(unsigned int i = 0; i < flightPath.size(); ++i){
        for(unsigned int i = 1; i < flightPath.size(); ++i){
            if(flightPath.at(i - 1) > flightPath.at(i)){
                //this swaps all the numbers in flightPath
                tempValFlight = flightPath.at(i - 1); 
                flightPath.at(i-1) = flightPath.at(i);
                flightPath.at(i) = tempValFlight;
                
                //this swaps all the numbers in coefficient
                tempValCoef = coeffLift.at(i - 1); 
                coeffLift.at(i-1) = coeffLift.at(i);
                coeffLift.at(i) = tempValCoef;
            }
        }
    }
}