// UVa 11039
// Building designing
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 500002;

int T;
int N;
int a[MAXN]; 

bool cmp(int a, int b) { return abs(a) < abs(b); }

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);

        sort(a, a + N, cmp);

        int ans = 1;
        for (int i = 0; i < N - 1; i++)
            if (abs(a[i] + a[i + 1]) < abs(a[i]) + abs(a[i + 1]))
                ans++;

        printf("%d\n", ans);
    }

    return 0;
}
