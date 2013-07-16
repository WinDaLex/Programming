// UVa 138
// Street Numbers
// by A Code Rabbit

#include <cstdio>
#include <cmath>

typedef long long LL;

int main() {
    int x = 1, y = 0;
    for (int i = 0; i < 10; i++) {
        do {
            x++;
            y = sqrt(((LL)x * x + x) / 2);
        } while ((LL)y * y * 2 != (LL)x * x + x);

        printf("%10d%10d\n", y, x);
    }

    return 0;
}
