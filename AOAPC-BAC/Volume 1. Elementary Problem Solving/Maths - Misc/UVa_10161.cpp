// UVa 10161
// Ant on a Chessboard
// by A Code Rabbit

#include <cstdio>
#include <cstdlib>
#include <cmath>

typedef long long ll;

#define sqr(x) ((x)*(x))

int N;

int main() {
    while (scanf("%d", &N) && N) {
        int level = ceil(sqrt(N));
        ll up = sqr(level);
        ll down = sqr(level - 1) + 1;
        ll mid = (up + down) / 2;

        int x, y;
        if ((level % 2 == 1 && N < mid) || (level % 2 == 0 && N >= mid)) {
            x = level;
            y = level - abs(mid - N);
        } else {
            x = level - abs(mid - N);
            y = level;
        }

        printf("%d %d\n", x, y);
    }
 
    return 0;
}
