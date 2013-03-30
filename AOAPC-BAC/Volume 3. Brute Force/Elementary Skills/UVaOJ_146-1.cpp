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
        is_last = true;
        for (int i = len - 2; i >= 0; i--) {
            char* pos = lower_bound(code + i + 1, code + len, code[i], Cmp);
            if (pos != code + i + 1) {
                swap(code[i], *(pos - 1));
                sort(code + i + 1, code + len);
                is_last = false;
                break;
            }
        }
        if (is_last) {
            printf("No Successor\n");
        } else {
            puts(code);
        }
    }

    return 0;
}
