#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string filename, char ch);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here

int charCnt(string filename, char ch){
   int counter = 0; 
   char userChar;
   ifstream fileOpen;

   fileOpen.open(filename);

   if(!fileOpen.is_open()){
      cout << "Error opening " << filename << endl;
      exit(1);
   }
   else {
      while(fileOpen.get(userChar)){
               if(userChar == ch){
                  counter++;
               }
            }
   } 
      fileOpen.close();
      return counter; 

}
