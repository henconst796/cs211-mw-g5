#include <iostream>
#include <string>
#include "luhn.h"
using namespace std;

int main()
{
    cout << "=== Luhn Checksum Checker ===" << endl;
    cout << "This program checks whether a 16-digit number passes the Luhn checksum." << endl;
    cout << "Note: passing does NOT mean a real card exists." << endl << endl;

    string number;

    cout << "Enter a 16-digit number (or Q to quit): ";

    
    while (getline(cin, number))
    {
        if (number == "Q" || number == "q")
        {
            break;   
        }
        else if (isValidFormat(number) == false)
        {
            cout << "Invalid format: please enter exactly 16 digits (0-9)," << endl;
            cout << "with no spaces, letters, or symbols." << endl;
        }
        else if (checkLuhn(number) == true)
        {
            cout << "Correct format. Checksum PASSES." << endl;
        }
        else
        {
            cout << "Correct format. Checksum FAILS." << endl;
        }

        cout << endl << "Enter a 16-digit number (or Q to quit): ";
    }

    cout << endl << "Goodbye!" << endl;
    return 0;
}