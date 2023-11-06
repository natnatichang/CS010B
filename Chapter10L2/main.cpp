#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

bool rCopy(string fileOne, string fileTwo);
bool rCopyHelp(ifstream& in, ofstream& out);


int main(int argc, char *argv[]){

    string fileOne;
    string fileTwo;

    fileOne = argv[1];
    fileTwo = argv[2];


    ifstream fileOpen;
    fileOpen.open(fileOne);

    if(!fileOpen.is_open()){
        cout << "Error opening " << fileOne << endl;
        cout << "Copy not completed" << endl;
        exit(1);
    }

    ofstream fileOut;
    fileOut.open(fileTwo);

    if(!fileOut.is_open()){
        cout << "Error opening " << fileTwo << endl;

        exit(1);
    }

    rCopy(fileOne, fileTwo);


    fileOpen.close();
    fileOut.close(); 

    return 0;


}



bool rCopy(string fileOne, string fileTwo){
    rCopyHelp(fileOne, fileTwo);
}



bool rCopyHelp(ifstream& in, ofstream& out){

char charInput;

if(in.get(charInput)){
    out << charInput;
}

return true;

}
