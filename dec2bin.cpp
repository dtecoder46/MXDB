#include <iostream>

using namespace std;

string dec2bin(int number, string binary, int power2[10]) {
    for (int index2 = 0; index2 < 10; index2++) {
        if (number > power2[index2]) {
            binary += "1 ";
        }
        else {
            binary += "0 ";
        }
    }

    return binary;
}