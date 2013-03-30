// UVaOJ 146
// ID Codes
// by A Code Rabbit

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int LIMITS = 52;

char code[LIMITS];
int len;
bool is_last;

bool Cmp(char ch_a, char ch_b) {
    return ch_a > ch_b;
}

int main() {
    while (gets(code), strcmp(code, "#")) {
        len = strlen(code);
        if (next_permutation(code, code + len)) {
            puts(code);
        } else {
            printf("No Successor\n");
        }
    }

    return 0;
}
