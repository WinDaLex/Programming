// UVaOJ 10098
// Generating Fast
// by A Code Rabbit

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int LIMITS = 12;

int n;
char str[LIMITS];

int main() {
    scanf("%d", &n);
    getchar();
    while (n--) {
        gets(str);
        int len = strlen(str);
        while (prev_permutation(str, str + len)) {
        }
        next_permutation(str, str + len);
        do {
            puts(str);
        } while (next_permutation(str, str + len));
        printf("\n");
    }

    return 0;
}
