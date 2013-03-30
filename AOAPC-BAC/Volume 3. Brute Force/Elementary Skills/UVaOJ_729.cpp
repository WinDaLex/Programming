// UVaOJ 729
// The Hamming Distance Problem
// by A Code Rabbit

#include <algorithm>
#include <cstdio>

using namespace std;

const int LIMITS = 18;

int t;
int n, h;

char str[LIMITS];

bool is_first = true;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &h);
        for (int i = 0; i < n; ++i) {
            str[i] = n - i <= h ? '1' : '0';
        }
        str[n] = '\0';
        if (is_first) {
            is_first = false;
        } else {
            printf("\n");
        }
        do {
            puts(str);
        } while (next_permutation(str, str + n));
    }

    return 0;
}
