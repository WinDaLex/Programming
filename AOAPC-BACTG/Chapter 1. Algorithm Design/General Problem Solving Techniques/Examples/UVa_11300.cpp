// UVa 11300
// Spreading the Wealth
// by A Code Rabbit

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 1000002;

int N;
LL coin[MAXN];

LL num[MAXN];

int main() {
    while (scanf("%d", &N) != EOF) {
        LL tot = 0;
        for (int i = 0; i < N; i++) {
            cin >> coin[i];
            tot += coin[i];
        }
        LL avg = tot / N;

        num[0] = 0;
        for (int i = 1; i < N; i++)
            num[i] = num[i - 1] + coin[i] - avg;

        sort(num, num + N);
        LL med = num[N / 2], ans = 0;
        for (int i = 0; i < N; i++)
            ans += abs(med - num[i]);
        
        cout << ans << endl;
    }

    return 0;
}
