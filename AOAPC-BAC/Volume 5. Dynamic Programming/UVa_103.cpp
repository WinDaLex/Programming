// UVa 103
// Stacking Boxes
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXK = 32;
const int MAXN = 12;

int N, K;
int A[MAXK][MAXN];

bool adj[MAXK][MAXK];
int f[MAXK];
int ans, idx;

int dp(int x) {
    int &res = f[x];
    if (res) return res;

    for (int i = 1; i <= K; i++)
        if (adj[x][i]) res = max(dp(i) + 1, res);
   
    return res;
}

void print_ans(int x) {
    for (int i = 1; i <= K; i++) {
        if (adj[x][i] && f[i] == f[x] - 1) {
            printf(" %d", i);
            print_ans(i);
            break;
        }
    }
}

int main() {
    while (scanf("%d%d", &K, &N) != EOF) {
        for (int i = 1; i <= K; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &A[i][j]);

        for (int i = 1; i <= K; i++)
            sort(A[i], A[i] + N);

        for (int i = 1; i <= K; i++) {
            for (int j = 1; j <= K; j++) {
                adj[i][j] = true;
                for (int k = 0; k < N; k++) {
                    if (A[i][k] >= A[j][k]) {
                        adj[i][j] = false;
                        break;
                    }
                }
            }
        }

        memset(f, 0, sizeof(f));
        ans = idx = 0;
        for (int i = 1; i <= K; i++)
            if (dp(i) > ans)
                ans = dp(idx = i);

        printf("%d\n", ans + 1);
        printf("%d", idx);
        print_ans(idx);
        printf("\n");
    }

    return 0;
}
