// Codeforces 518C
// Anya and Smartphone

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 2;

int N, M, K;
int A[MAXN], B[MAXN];

int pos[MAXN];

int main() { _
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        pos[A[i]] = i;
    }

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
        ans += pos[B[i]] / K + 1;
        if (pos[B[i]] == 0) continue;
        int a = A[pos[B[i]] - 1];
        swap(A[pos[a]], A[pos[B[i]]]);
        swap(pos[a], pos[B[i]]);
    }

    cout << ans << endl;

    return 0;
}
