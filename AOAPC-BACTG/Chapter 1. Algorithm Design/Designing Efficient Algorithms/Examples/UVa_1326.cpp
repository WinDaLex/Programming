// UVa 1326
// Jurassic Remains
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 26;
const int LEN = 1002;

int N;
int a[MAXN];

map<int, pii> dict;
int N1, N2;

pii compute(int x, int y, int z) {
    pii res(0, 0);
    for (int i = 0; i < z; i++) {
        if (x & 1 << i) {
            res.first ^= a[y + i];
            res.second++;
        }
    }
    return res;
}

int main() {
    while (scanf("%d", &N) != EOF) {
        getchar();
        memset(a, 0, sizeof(a));
        char str[LEN];
        for (int i = 0; i < N; i++) {
            gets(str);
            for (int j = 0; str[j]; j++)
                a[i] ^= 1 << str[j] - 'A';
        }

        dict.clear();
        N1 = N / 2;
        for (int i = 0; i < 1 << N1; i++) {
            pii ret = compute(i, 0, N1);
            int key = ret.first, val = ret.second;
            if (!dict.count(key) || val > dict[key].first) {
                dict[key].first = val;
                dict[key].second = i;
            }
        }

        int ans = 0, bit = 0;
        N2 = N - N / 2;
        for (int i = 0; i < 1 << N2; i++) {
            pii ret = compute(i, N1, N2);
            int key = ret.first, val = ret.second;
            if (dict.count(key) && (val + dict[key].first > bit)) {
                bit = val + dict[key].first;
                ans = (i << N1) + dict[key].second;
            }
        }

        printf("%d\n", bit);
        bool first = true;
        for (int i = 0; i < N; i++)
            if (ans & 1 << i)
                printf("%s%d", (first ? first = false, "" : " "), i + 1);
        printf("\n");
    }

    return 0;
}
