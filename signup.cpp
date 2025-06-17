#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string username;
    string password;
    string previous_content;
    string previous_content2;

    cout << "\nEnter your username: ";
    cin >> username;

    cout << "\nEnter your password: ";
    cin >> password;

    ifstream json("usernames.json");

    while (getline (json, previous_content)) {
        previous_content2 += previous_content;
    }

    // removes the curly brackets

    previous_content2.replace(0,1,""); 
    previous_content2.replace(previous_content2.length()-1,1,"");

    char id = previous_content2[5] + 1;

    string new_content = previous_content2 + ",\t\"" + id + "\": \"" + username + "\"";

    string json_str = "{\n" + new_content + "\n}";

    ofstream json2("usernames.json");

    json2 << json_str;

    json2.close();
}