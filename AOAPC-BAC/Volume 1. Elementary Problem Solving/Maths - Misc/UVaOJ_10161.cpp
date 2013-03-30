// UVaOJ 10161
// Ant on a Chessboard
// by A Code Rabbit

#include <cmath>
#include <cstdio>
#include <cstdlib>

#define SQR(x) ((x)*(x))
#define LL long long 

int n;

int main()
{
    while (scanf("%d", &n) && n) {
        int level = ceil(sqrt(n));
        LL up = SQR(level);
        LL down = SQR(level - 1) + 1;
        LL middle = (up + down) / 2;

        int x, y;
        if ((level % 2 == 1 && n < middle) || (level % 2 == 0 && n >= middle)) {
            x = level;
            y = level - abs(middle - n);
        } else {
            x = level - abs(middle - n);
            y = level;
        }

        printf("%d %d\n", x, y);
    }
 
    return 0;
}
