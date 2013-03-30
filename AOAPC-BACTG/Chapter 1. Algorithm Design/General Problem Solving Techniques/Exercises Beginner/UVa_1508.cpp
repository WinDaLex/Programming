// UVa 1508
// Equipment
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10002;

int N, K;
int r[MAXN][5];

int id[MAXN];
int score[MAXN][5];
int ans;
bool bo[5];

void compute() {
    memset(bo, false, sizeof(bo));
    for (int i = 0; i < 5; i++) bo[id[i]] = true;
    for (int i = 0; i < K; i++) if (!bo[i]) return;

    memset(score, 0, sizeof(score));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 5; j++)
            score[i][id[j]] += r[i][j];

    int sum = 0;
    for (int i = 0; i < K; i++) {
        int max_val = 0;
        for (int j = 0; j < N; j++)
            max_val = max(score[j][i], max_val);
        sum += max_val;
    }

    ans = max(sum, ans);
}

void search(int x) {
    if (x == 5) {
        compute();
        return;
    }
    
    for (int i = 0; i < K; i++) {
        id[x] = i;
        search(x + 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 5; j++)
                scanf("%d", &r[i][j]);
        
        ans = 0;
        search(0);
        printf("%d\n", ans);
    }

    return 0;
}
