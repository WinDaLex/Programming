// HDU 4722
// Good Numbers
// by A Code Rabbit

#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

int T;
ll A, B;

ll f(ll x) {
    if (x < 0) return 0;

    ll ret = x / 10, sum = 0, num = x / 10;
    while (num) {
        sum += num % 10;
        num /= 10;
    }

    if (sum % 10 == 0 || ((x % 10) >= (10 - sum % 10))) ret++;
    return ret;
}

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        cin >> A >> B;
        cout << "Case #" << cas << ": " << f(B) - f(A - 1) << endl;
    }

    return 0;
}
