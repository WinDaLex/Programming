// UVa 11100
// The Trip, 2007
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 10002;

int N;
int a[MAXN];

int main() {
    bool first = true;
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);

        sort(a, a + N);

        int K = 0, cnt = 1;
        for (int i = 1; i < N; i++) {
            if (a[i] == a[i - 1]) cnt++;
            else cnt = 1;
            K = max(cnt, K);
        }
            
        printf("%s", first ? first = false, "": "\n");
        printf("%d\n", K);
        for (int i = 0; i < K; i++) {
            for (int j = 0; i + K * j < N; j++)
                printf("%s%d", j ? " " : "", a[i + K * j]);
            printf("\n");
        }
    }

    return 0;
}
