#include "input_validation.h"

string input_choice() {
    string choice;
    cout << "Choose decimal input or hex input (enter 'd' for decimal, enter 'h' for hex):" << endl;
    getline(cin, choice);
    while (choice!= "d" and choice != "h") {
        cout << "Incorrect input. Enter 'd' or 'h'." << endl;
        cout << "Choose decimal input or hex input (enter 'd' for decimal, enter 'h' for hex):" << endl;
        getline(cin, choice);
    }
    return choice;
}