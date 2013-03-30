// UVa 10878
// Decode the tape.
// by A Code Rabbit

#include <iostream>
using namespace std;

const int BIN[] = {
    0, 0, 64, 32, 16, 8, 0, 4, 2, 1, 0,
};

string str;

int main() {
    getline(cin, str);
    while (getline(cin, str) && str[0] != '_') {
        char ch = 0;
        for (int i = 2; i <= 9; i++)
            if (str[i] == 'o')
                ch += BIN[i];
        cout << ch;
    }
    
    return 0;
}
