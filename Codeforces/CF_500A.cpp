// CF500 A
// New Year Transportation

#include <cstdio>

const int MAXN = 30002;

int n, t;
int a[MAXN];

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &a[i]);

    int x = 0;
    while (x < n - 1) {
       x += a[x];
       if (x == t - 1) {
           puts("YES");
           return 0;
       }
    }

    puts("NO");
    return 0;
}
