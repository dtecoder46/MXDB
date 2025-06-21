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

    // store_usernames() start

    ifstream json("usernames.json");

    while (getline (json, previous_content)) {
        previous_content2 += previous_content;
    }

    // removes the curly brackets

    previous_content2.replace(0,1,""); 
    previous_content2.replace(previous_content2.length()-1,1,"");

    char id = previous_content2[5] + 1; // temporary

    // integrating the username data into the JSON syntax

    string new_content = previous_content2 + ",\t\"" + id + "\": \"" + username + "\"";

    string json_str = "{\n" + new_content + "\n}";

    ofstream json2("usernames.json");

    json2 << json_str; // stores the usernames into JSON

    json2.close();

    // store_usernames() end

    // store_passwords() start

    // generates random number from 1 to 897

    int random_num = rand() % 897 + 1;

    /*
    max random number is 897, which limits the biggest possible new_decimal value to reach 512, 
    the limit I set for the list of powers of 2 used to convert to binary 
    */ 

    string binary = "";

    int power2[10] = {512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

    for (int index = 0; index < password.length(); index++) {
        char pass_char = password[index];

        int decimal = (pass_char - '0') + 48; 
        /* password character converted to decimal format by subtracing '0', 
        decimnal value for '0' (48) is added back 
        to get the decimal value for the password character */

        int new_decimal = decimal + random_num; // the random number is added to the decimal values to confuse hackers

        // binary conversion

        /*
        Algorithm:
        1. Loop over the powers of 2 list
        2. if new_decimal > power of 2, add 1 to the binary string, else add 0
        3. Repeat
        */

        for (int index2 = 0; index2 < sizeof(power2)/sizeof(power2[0]); index2++) {
            if (new_decimal > power2[index2]) {
                binary += "1 ";
            }
            else {
                binary += "0 ";
            }
        }

        binary += "\n\n";
        cout << binary;
    }

}