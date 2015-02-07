// Rockethon B
// Permutations

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 52;

int N;
ll M;

ll bin[MAXN];
bool bo[MAXN];

int ans[MAXN], top;

int main() {
    cin >> N >> M;

    for (int i = 1; i < N; i++)
        bin[i] = (ll)1 << (N - 1 - i);

    ll m = M - 1;
    int p = 1;
    while (true) {
        while (p <= N && m >= bin[p]) {
            m -= bin[p];
            p++;
        }
        if (p > N) break;
        ans[top++] = p;
        bo[p++] = true;
    }

    for (int i = N; i > 0; i--) 
        if (!bo[i]) ans[top++] = i;
    
    for (int i = 0; i < top; i++)
        printf("%d%c", ans[i], i < top - 1 ? ' ' : '\n');

    return 0;
}
