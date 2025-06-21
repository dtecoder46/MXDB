#include <iostream>
#include "signup.cpp"

using namespace std;

void login() {

}

int main() {
    int exit = 0;

    while (exit != 1) { // allows for the program to repeat the code if the user wants to continue or if the user makes invalid input
        int answer;

        cout << "\nWelcome to the Mysterious Website! What do you want to do (Please input a number)\n1. Sign Up\n2. Log In\n"; // signup/login interface
    
        cin >> answer;

        if (answer == 1) {
            signup();
        }
        else if (answer == 2) {
            login();
        }
        else {
            cout << "Invalid input, please try again\n\n";
        }
    }
}