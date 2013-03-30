// UVa 1335
// Beijing Guards
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100002;

int N;
int award[MAXN];

bool check(int x) {
    int num_left = award[0], num_right = x - award[0];
    int cur_left = num_left, cur_right = 0;

    for (int i = 1; i < N; i++)
        if (i % 2) {
            cur_left = min(num_left - cur_left, award[i]);
            cur_right = award[i] - cur_left;
        } else {
            cur_right = min(num_right - cur_right, award[i]);
            cur_left = award[i] - cur_right;
        }

    return cur_left == 0;
}

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++)
            scanf("%d", &award[i]);
        award[N] = award[0];

        if (N == 1) {
            printf("%d\n", award[0]);
            continue;
        }

        int max_val = 0;
        for (int i = 0; i < N; i++)
            max_val = max(award[i] + award[i + 1], max_val);

        if (N % 2 == 0) {
            printf("%d\n", max_val);
            continue;
        }

        int l = max_val, r = MAXN * 3;
        while (l < r) {
            int m = (l + r) / 2;
            if (!check(m)) l = m + 1;
            else r = m;
        }

        printf("%d\n", l);
    }

    return 0;
}
