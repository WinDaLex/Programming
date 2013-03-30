// UVa 1368
// DNA Consensus String
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 52;
const int MAXN = 1002;

int M, N;
char dna[MAXM][MAXN];

int a, t, c, g;

void count(char ch) {
    switch (ch) {
    case 'A': a++; break;
    case 'T': t++; break;
    case 'G': g++; break;
    case 'C': c++; break;
    }
}

void find_max(int &val, char &ch) {
    val = 0;
    if (a > val) { val = a; ch = 'A'; }
    if (c > val) { val = c; ch = 'C'; }
    if (g > val) { val = g; ch = 'G'; }
    if (t > val) { val = t; ch = 'T'; }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &M, &N);
        getchar();
        for (int i = 0; i < M; i++)
            gets(dna[i]);

        char ans_str[MAXN];
        int ans_cnt = 0;
        for (int i = 0; i < N; i++) {
            a = t = c = g = 0;
            for (int j = 0; j < M; j++)
                count(dna[j][i]);
            int val; char ch;
            find_max(val, ch);
            ans_str[i] = ch;
            ans_cnt += M - val;
        }
        ans_str[N] = '\0';

        printf("%s\n", ans_str);
        printf("%d\n", ans_cnt);
    }

    return 0;
}
