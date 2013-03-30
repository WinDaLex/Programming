// UVa 11549
// Calculator Conundrum
// by A Code Rabbit

#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int N, K;

int limit;

int next(int k) {
    LL res = (LL)k * k;
    while (res >= limit) res /= 10;
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);

        LL k1 = K, k2 = K, ans = K;
        limit = pow(10, N);
        do {
            k1 = next(k1);
            k2 = next(k2); ans = max(k2, ans);
            k2 = next(k2); ans = max(k2, ans);
        } while (k1 != k2);
        
        cout << ans << endl;
    }

    return 0;
}
