// CF 534D
// Handshakes

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 2;
typedef multimap<int, int>::iterator iter;

int N;
int A[MAXN];

multimap<int, int, greater<int> > m[3];
int ans[MAXN];

bool construct() {
    if (!m[0].count(0)) return false;
    iter it = m[0].find(0);
    ans[0] = it->second;
    m[0].erase(it);

    for (int i = 1; i < N; i++) {
        int last = A[ans[i - 1] - 1];
        int cur_mod = (last + 1) % 3;
        iter it = m[cur_mod].lower_bound(last + 1);
        if (it == m[cur_mod].end()) return false;
        ans[i] = it->second;
        m[cur_mod].erase(it);
    }

    return true;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < N; i++)
        m[A[i] % 3].insert(pair<int, int>(A[i], i + 1));

    if (construct()) {
        puts("Possible");
        for (int i = 0; i < N; i++)
            printf("%d%c", ans[i], i < N - 1 ? ' ' : '\n');
    } else {
        puts("Impossible");
    }

    return 0;
}
