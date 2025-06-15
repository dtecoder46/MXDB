#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string username;
    string password;
    string previous_content;

    cout << "\nEnter your username: ";
    cin >> username;

    cout << "\nEnter your password: ";
    cin >> password;

    ifstream json("usernames.json");

    while (getline (json, previous_content)) {
        cout << previous_content;
    }
}