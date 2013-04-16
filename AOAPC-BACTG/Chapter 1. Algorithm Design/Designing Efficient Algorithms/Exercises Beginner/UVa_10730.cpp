// UVa 10730
// Antiarithmetic
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

struct Number {
    int x, y;
    bool operator<(Number rhs) const { return this->x < rhs.x; }
};

const int MAXN = 10002;

int N;
Number a[MAXN];

bool check() {
    for (int i = 1; i < N / 2; i++)
        for (int j = i; j < N - i; j++)
            if (a[j - i].y < a[j].y && a[j].y < a[j + i].y ||
                    a[j - i].y > a[j].y && a[j].y > a[j + i].y)
                return false;
    return true;
}

int main() {
    while (scanf("%d", &N) && N) {
        getchar();
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i].x);
            a[i].y = i;
        }

        sort(a, a + N);
    
        puts(check() ? "yes" : "no");
    }

    return 0;
}
