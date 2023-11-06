#include <iostream>
#include <cmath>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here

//design a rational number class named rational whose values will be a fraction with appropriate constructors and member functions
//member variables should be private and accessed using the accessor and mutator functions

/*
Constructors : 
Create 3 constructors:
a constructor with two parameters (numerator and denominator)
a constructor with one parameter (denominator set to 1)
a constructor with no parameters (0/1)

Accessor Functions : 
add
subtract
multiply
divide
display

Mutator Function : 
simplify
The following are a list of the rules of arithmetic for fractions:

(a/b) + (c/d) = (ad + bc) / (b*d)
(a/b) - (c/d) = (ad - bc) / (b*d)
(a/b) * (c/d) = (ac) / (bd)
(a/b) / (c/d) = (ad) / (cb)
*/



// 2 parameters (numerator & denominator)
// return Rational(numer, denom);
Rational::Rational(int numer, int denom){
   numerator = numer;
   denominator = denom;
   return;
}

// 1 parameter (numerator)
// return Rational(numer);
Rational::Rational(int numer){
   numerator = numer;
   denominator = 1; 
   return;
}

// 0 parameters (default)
// return Rational();
Rational::Rational(){
   numerator = 0;
   denominator = 1; 

}


//key 
//a = numerator
//b = denominator
//c = test.numerator
//d = test.denominator

//(a/b) + (c/d) = (ad + bc) / (b*d)
Rational Rational::add(const Rational &test) const{

//declare Rational object
Rational testing;
//"." operator known as the member access operator invokes function on an object
testing.numerator = ((numerator * test.denominator) + (denominator * test.numerator));
testing.denominator = (test.denominator * denominator);


return testing;
}


//(a/b) - (c/d) = (ad - bc) / (b*d)
Rational Rational::subtract(const Rational &test) const{

Rational testing;
testing.numerator = ((numerator * test.denominator) - (denominator * test.numerator));
testing.denominator = (test.denominator * denominator);

return testing;
}

//(a/b) * (c/d) = (ac) / (bd)
Rational Rational::multiply(const Rational &test) const{

Rational testing;
testing.numerator = (test.numerator * numerator);
testing.denominator = (test.denominator * denominator);

return testing;
} 

//(a/b) / (c/d) = (ad) / (cb)
Rational Rational::divide(const Rational &test) const{

Rational testing;
testing.numerator = (test.denominator * numerator);
testing.denominator = (test.numerator * denominator);

return testing;
}



void Rational::simplify(){
   int temp = gcd(numerator, denominator);
   numerator = numerator / temp;
   denominator = denominator / temp;

}

void Rational::display() const{
   cout << numerator << " / " << denominator;
}

//calling private class 
int Rational::gcd(int numerator, int denominator) const{

//recursive version 

if(denominator == 0){
    return numerator;
}
else {
    return gcd(denominator, numerator % denominator);
}

}


// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

