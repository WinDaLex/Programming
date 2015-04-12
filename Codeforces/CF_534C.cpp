// CF 534C
// Covered Path

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 2;

ll N, A, S;
ll D[MAXN];

int main() {
    cin >> N >> A;
    S = 0;
    for (int i = 0; i < N; i++) {
        cin >> D[i];
        S += D[i];
    }

    for (int i = 0; i < N; i++) {
        ll l = D[i] - S + A;
        ll r = A - N + 1;
        ll ans = max(l - 1, 0ll) + max(D[i] - r, 0ll);
        cout << ans;
        if (i < N - 1) cout << ' ';
        else cout << endl;
    }

    return 0;
}
