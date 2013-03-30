// UVa 537
// Artificial Intelligence
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const char CONCEPT[] = {'I', 'U', 'P'};

string str;

double real[3];
bool bo[3];

void read(int idx) {
    double val; char ch;
    string tmp = str.substr(idx + 1);
    sscanf(tmp.c_str(), "%lf%c", &val, &ch);

    switch (ch) {
    case 'm': val /= 1000; break;
    case 'k': val *= 1000; break;
    case 'M': val *= 1000000; break;
    }

    char concept = str[idx - 1];
    for (int i = 0; i < 3; i++) {
        if (concept == CONCEPT[i]) {
            real[i] = val;
            bo[i] = true;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    for (int cas = 1; cas <= T; cas++) {
        // Input.
        getline(cin, str);
        // Solve.
        memset(bo, false, sizeof(bo));
        read(str.find_first_of('='));
        read(str.find_last_of('='));
        // Output.
        printf("Problem #%d\n", cas);
        if (!bo[0]) printf("I=%.2lfA\n", real[2] / real[1]);
        else if (!bo[1]) printf("U=%.2lfV\n", real[2] / real[0]);
        else if (!bo[2]) printf("P=%.2lfW\n", real[0] * real[1]);
        printf("\n");
    }

    return 0;
}


