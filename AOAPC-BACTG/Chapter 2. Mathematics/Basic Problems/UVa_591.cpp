// UVa 591
// Box of Bricks
// by A Code Rabbit

#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 52;

int T, N;
int H[MAXN];

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++)
            scanf("%d", &H[i]);

        int avg = 0;
        for (int i = 0; i < N; i++)
            avg += H[i];
        avg /= N;

        int ans = 0;
        for (int i = 0; i < N; i++)
            ans += abs(H[i] - avg);

        printf("Set #%d\n", ++T);
        printf("The minimum number of moves is %d.\n", ans / 2);
        printf("\n");
    }

    return 0;
}
