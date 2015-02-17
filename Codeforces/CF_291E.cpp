// Codeforces #291 E
// Darth Vader and Tree

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 100002;
const int MAXD = 102;
const int MOD = 1e9 + 7;

int N, X;
int D;

ll cnt[MAXD];
ll dp[MAXD];

struct matrix {
    ll elem[MAXD][MAXD];
    int ord;
    matrix(int o) : ord(o) {
        memset(elem, 0, sizeof(elem));
    }
    matrix operator*(matrix &rhs) {
        matrix res(ord);
        for (int i = 0; i < ord; i++)
            for (int j = 0; j < ord; j++)
                for (int k = 0; k < ord; k++)
                    res.elem[i][j] = (res.elem[i][j] + elem[i][k] * rhs.elem[k][j]) % MOD;
        return res;
    }
};

template<typename T>
T qpower(T x, int k) {
    k--;
    T b = x;
    while (k) {
        if (k & 1) x = x * b;
        b = b * b;
        k >>= 1;
    }
    return x;
}

int main() {
    scanf("%d%d", &N, &X);
    for (int i = 0; i < N; i++) {
        scanf("%d", &D);
        cnt[D]++;
    }

    dp[0] = 1;
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = (dp[i] + cnt[j] * dp[i - j]) % MOD;

    if (X <= 100) {
        ll ans = 0;
        for (int i = 0; i <= X; i++)
            ans = (ans + dp[i]) % MOD;
        cout << ans << endl;
        return 0;
    }

    matrix b(101);
    for (int i = 0; i < 99; i++)
        b.elem[i + 1][i] = 1;
    for (int i = 0; i <= 99; i++)
        b.elem[i][99] = b.elem[i][100] = cnt[100 - i];
    b.elem[100][100] = 1;

    matrix c = qpower(b, X - 100);

    for (int i = 0; i < 101; i++)
        dp[101] = (dp[101] + dp[i]) % MOD;

    ll ans = 0;
    for (int i = 0; i <= 100; i++)
        ans = (ans + dp[i + 1] * c.elem[i][100]) % MOD;
    cout << ans << endl;

    return 0;
}
