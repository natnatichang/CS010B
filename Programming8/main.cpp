#include "IntList.h"
#include "SortedSet.h"
#include <iostream>

using namespace std;

int main(){

    //add test cases for the SortedSet

    //test default constructor
    SortedSet ListS1;
    cout << "ListS1 Default: " << ListS1 << endl << endl;

    //test add
    SortedSet ListS2;
    ListS2.add(3);
    ListS2.add(12);
    ListS2.add(2);
    cout << "ListS2 Add: " << ListS2 << endl << endl; 

    //test copy constructor
    SortedSet ListS3(ListS2);
    cout << "ListS3 Copy from ListS2: " << ListS3 << endl << endl;

    //test constructor from IntList
    IntList testingList1;
    testingList1.push_front(12);
    testingList1.push_front(53);
    testingList1.push_front(14);
    SortedSet ListS4(testingList1);
    cout << "testingList1: " << testingList1 << endl;
    cout << "Constructor from testingList1 to ListS4: " << ListS4 << endl << endl;

    //test destructor 
    {
        SortedSet ListS5;
        ListS5.add(31);
        ListS5.add(14);
        ListS5.add(234);

        cout << "ListS5 before destructor: " << ListS5 << endl << endl;
    }
    SortedSet ListS5;
    cout << "ListS5 after destructor:" << ListS5 << endl << endl;

    //test in accessor
    SortedSet ListS6;
    ListS6.add(65);
    ListS6.add(74);
    ListS6.add(16);
    cout << "Checking if 16 is in set: " << boolalpha << ListS6.in(16) << endl;
    cout << "Checking if 20 is in set: " << boolalpha << ListS6.in(20) << endl;
    cout << "Checking if 65 is in set: " << boolalpha << ListS6.in(65) << endl;
    cout << "Checking if 26 is in set: " << boolalpha << ListS6.in(26) << endl;
    cout << "Checking if 74 is in set: " << boolalpha << ListS6.in(74) << endl;
    cout << "Checking if 965 is in set: " << boolalpha << ListS6.in(965) << endl;
    cout << endl;

    //testing operator|
    SortedSet ListS7;
    ListS7.add(14);
    ListS7.add(344);
    ListS7.add(16);

    SortedSet ListS8 = ListS6 | ListS7;
    cout << "ListS6 | ListS7: " << ListS8 << endl << endl; 

    //test if same value for operator |
    SortedSet ListS9;
    ListS9.add(14);
    ListS9.add(344);
    ListS9.add(16);

    SortedSet ListS10 = ListS9 | ListS7;
    cout << "ListS9 | ListS7: " << ListS10 << endl << endl; 

    //testing operator&
    SortedSet ListS11;
    ListS11.add(23);
    ListS11.add(33);
    ListS11.add(14);

    SortedSet ListS12 = ListS9 & ListS11;
    cout << "ListS9: " << ListS9 << endl;
    cout << "ListS11: " << ListS11 << endl;
    cout << "ListS9 & ListS11: " << ListS12 << endl << endl;

    //testing mutators
    SortedSet ListS13;
    //test add
    ListS13.add(12);
    //test push_front
    ListS13.push_front(23);
    //test push_back
    ListS13.push_back(62);
    cout << "ListS13 with Add, Push_Front, Push_Back: " << ListS13 << endl;
    //test insert_ordered
    ListS13.insert_ordered(14);
    cout << "ListS13 InsertOrdered: " << ListS13 << endl << endl;

    //test operator |=
    SortedSet ListS14;
    ListS14.add(10);
    ListS14.add(20);
    ListS14.add(30);

    cout << "ListS14 before |= : " << ListS14 << endl;
    ListS14 |= ListS12;
    cout << "ListS12: " << ListS12 << endl;
    cout << "ListS14 after |= with S12: " << ListS14 << endl << endl;

    //test operator &=
    SortedSet ListS15;
    ListS15.add(10);
    ListS15.add(34);
    ListS15.add(3);

    cout << "ListS15 before &= : " << ListS15 << endl;
    ListS15 &= ListS14;
    cout << "ListS15 after &= with S14: " << ListS15 << endl;

    return 0;

}