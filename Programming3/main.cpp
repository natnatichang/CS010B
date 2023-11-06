#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here


// creates the date January 1st, 2000.
Date::Date(){

day = 1;
month = 1;
year = 2000;
monthName = "January";

}


/* parameterized constructor: month number, day, year 
- e.g. (3, 1, 2010) will construct the date March 1st, 2010

If any of the arguments are invalid (e.g. 15 for month or 32 for day)
then the constructor will construct instead a valid Date as close
as possible to the arguments provided - e.g. in above example,
Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
In case of such invalid input, the constructor will issue a console error message: 

Invalid date values: Date corrected to 12/31/2010.
(with a newline at the end).
*/

Date::Date(unsigned m, unsigned d, unsigned y){
   bool invalidInput = false;

   if(m > 12){
      invalidInput = true; 
      m = 12;
   }
   if(m < 1){
      invalidInput = true;
      m = 1;
   }
   
   if(d == 0){
      invalidInput = true;
      d = 1;
   }
    if(daysPerMonth(m , y) < d){
      invalidInput = true;
      d = daysPerMonth(m , y);
   }

   
    day = d;
    month = m;
    monthName = name(m);
    year = y;

   if(invalidInput == true){
   cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl; 
   }

}

/* parameterized constructor: month name, day, year
- e.g. (December, 15, 2012) will construct the date December 15th, 2012

If the constructor is unable to recognize the string argument as a valid month name,
then it will issue a console error message: 

Invalid month name: the Date was set to 1/1/2000.
(with a newline at the end).
 
If the day argument is invalid for the given month (but the month name was valid),
then the constructor will handle this error in the same manner as the other
parameterized constructor. 

This constructor will recognize both "december" and "December"
as month name.
*/

Date::Date(const string &mn, unsigned d, unsigned y){
   bool checkDay = false;
   bool checkMonth = false;

   //check months
   if(mn == "January" || mn == "january" ){
      month = number("January");
      monthName = "January";
   }
   else if (mn == "February" || mn == "february" ){
      month = number("February");
      monthName = "February";
   }
   else if(mn == "March" || mn == "march"){
      month = number("March");
      monthName = "March";
   }
   else if(mn == "April" || mn == "april"){
      month = number("April");
      monthName = "April";
   }
   else if(mn == "May" || mn == "may"){
      month = number("May");
      monthName = "May";
   }
   else if(mn == "June" || mn == "june"){
      month = number("June");
      monthName = "June";
   }
   else if(mn == "July" || mn == "july"){
      month = number("July");
      monthName = "July";
   }
   else if(mn == "August" || mn == "august"){
      month = number("August");
      monthName = "August";
   }
   else if(mn == "September" || mn == "september"){
      month = number("September");
      monthName = "September";
   }
   else if(mn == "October" || mn == "october"){
      month = number("October");
      monthName = "October";
   }
   else if(mn == "November" || mn == "november"){
      month = number("November");
      monthName = "November";
   }
   else if(mn == "December" || mn == "december"){
      month = number("December");
      monthName = "December";
   } 
   else {
    day = 1;
    month = number("January");
    year = 2000;
    monthName = "January";

    checkMonth = true;
   }

   if((!checkMonth) && daysPerMonth(month , y) < d){
         day = daysPerMonth(month , y);
         checkDay = true;
      }
   
   if((!checkMonth) && d == 0){
         day = 1;
         checkDay = true;
   }
   

   if(checkMonth == true || checkDay == true){
    if(checkDay == true){
        cout << "Invalid date values: Date corrected to ";
        year = y;
    }
    if(checkMonth == true){
        cout <<  "Invalid month name: the Date was set to ";

    }
   cout << month << "/" << day << "/" << year << "." << endl;
   }
   else {
    day = d;
    year = y;
   }
}


/* 
Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
Does not output a newline at the end.
*/

void Date::printNumeric() const{
cout << month << "/" << day << "/" << year;
}

/* 
Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
The first letter of the month name is upper case, and the month name is
printed in full - January, not Jan, jan, or january. 
Does not output a newline at the end.
*/

void Date::printAlpha() const{
cout << monthName << " " << day << ", " << year;
}


/*
Returns true if the year passed in is a leap year, otherwise returns false.
isLeap: The rule for whether a year is a leap year is:
(year % 4 == 0) implies leap year
except (year % 100 == 0) implies NOT leap year
except (year % 400 == 0) implies leap year
*/

bool Date::isLeap(unsigned y) const {
 if(y % 4 == 0){
      if(y % 100 == 0){
         if(y % 400 == 0){
            return true;
         }
      return false;
      }
    return true;
   }
   return false;
}



/* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
*/

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
// months have 31 days - January, March, May, July, August, October, December
   if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
       return 31; 
   }
//months have 30 days - September, April, June, and November
   else if(m == 4 || m == 6 || m == 9 || m == 11) {
      return 30;
   }
//months that are affected by leap year is February
   else if(isLeap(y)){
        return 29;
   }
   else {
        return 28;
   }
   
   return 34; 
}


/* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
string Date::name(unsigned m) const{

   if(m <= 1){
      return "January"; 
   }
   if (m == 2){
      return "February";
   }
   if(m == 3){
      return "March"; 
   }
   if(m == 4){
      return "April"; 
   }
   if(m == 5){
      return "May"; 
   }
   if(m == 6){
      return "June"; 
   }
   if(m == 7){
      return "July"; 
   }
   if(m == 8){
      return "August"; 
   }
   if(m == 9){
      return "September"; 
   }
   if(m == 10){
      return "October"; 
   }
   if(m == 11){
      return "November"; 
   }
   if(m >= 12){
      return "December"; 
   }
   return " "; 
  
}

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
unsigned Date::number(const string &mn) const{

   if(mn == "January"){
      return 1; 
   }
   if (mn == "February"){
      return 2;
   }
   if(mn == "March"){
      return 3; 
   }
   if(mn == "April"){
      return 4; 
   }
   if(mn == "May"){
      return 5; 
   }
   if(mn == "June"){
      return 6; 
   }
   if(mn == "July"){
      return 7; 
   }
   if(mn == "August"){
      return 8; 
   }
   if(mn == "September"){
      return 9; 
   }
   if(mn == "October"){
      return 10; 
   }
   if(mn == "November"){
      return 11; 
   }
   if(mn == "December"){
      return 12; 
   }  
    return 0; 

}


// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
