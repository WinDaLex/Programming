// Google Code Jam 2015 Qualification Round C
// Dijkstra

#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const int LEN = 1e4 + 2;

int T, L;
ll X;
int S[LEN];

int period;

// i->2, j->3, k->4
const int table[5][5] = {
    {0,  0,  0,  0,  0},
    {0,  1,  2,  3,  4},
    {0,  2, -1,  4, -3},
    {0,  3, -4, -1,  2},
    {0,  4,  3, -2, -1},
};

int abs(int x) { return x > 0 ? x : -x; }
int calc(int lhs, int rhs) {
    int neg = 1;
    if (lhs < 0) neg *= -1;
    if (rhs < 0) neg *= -1;
    return neg * table[abs(lhs)][abs(rhs)];
}

int getijk() {
    char ch = getchar();
    while (ch < 'i' || ch > 'k') ch = getchar();
    return ch - 'i' + 2;
}

bool check_all() {
    int all = 1;
    for (int i = 0; i < (X % 4); i++)
        all = calc(all, period);
    return all == -1;
}

bool check_pre_suf() {
    int pre = 1;
    ll idx_pre = -1;
    for (int i = 0; i < min((ll)4, X); i++) {
        for (int j = 0; j < L; j++) {
            pre = calc(pre, S[j]);
            if (pre == 2) {
                idx_pre = (ll)i * L + j;
                break;
            }
        }
        if (pre == 2) break;
    }
    if (idx_pre == -1) return false;

    int suf = 1;
    ll idx_suf = -1;
    for (int i = 0; i < min((ll)4, X); i++) {
        for (int j = L - 1; j >= 0; j--) {
            suf = calc(S[j], suf);
            if (suf == 4) {
                idx_suf = (ll)(X - 1 - i) * L + j;
                break;
            }
        }
        if (suf == 4) break;
    }
    if (idx_suf == -1) return false;
    
    return idx_pre < idx_suf;
}

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &L);
        cin >> X;
        for (int i = 0; i < L; i++)
            S[i] = getijk();

        period = 1;
        for (int i = 0; i < L; i++)
            period = calc(period, S[i]);

        printf("Case #%d: %s\n", cas, check_all() && check_pre_suf() ? "YES" : "NO");
    }

    return 0;
}
