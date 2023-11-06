#include <iostream>
#include <string>


using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here

void flipString(string &s){

    if(s.size() <= 1){
        return;
    }
   
    //cout << "this is substring: " << s.substr(0, s.size() - 1) << endl;
    string test = s.substr(0, s.size() - 1);
    //cout << "before recursion: " << test << endl << endl;
    flipString(test);
    //cout << "this is back: " << s.back() << endl;
    //cout << "this is test: " << test << endl << endl;
    s = s.back() + test;
    //cout << "s after: " << s << endl << endl;
}
