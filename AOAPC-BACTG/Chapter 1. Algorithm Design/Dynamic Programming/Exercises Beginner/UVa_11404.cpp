// UVa 11404
// Palindromic Subsequence
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 1002;

char S[MAXN], T[MAXN];
int N;

string f[MAXN][MAXN];

string max_str(string a, string b) {
    return a.length() > b.length() || (a.length() == b.length() && a < b) ? a : b;
}

int main() {
    while (gets(S)) {
        N = strlen(S);

        for (int i = 0; i < N; i++)
            T[i] = S[N - 1 - i];

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                f[i][j] = (S[i - 1] == T[j - 1] ? f[i - 1][j - 1] + S[i - 1] : max_str(f[i - 1][j], f[i][j - 1]));

        string cur, tmp, ans;

        for (int i = 1; i < N; i++) {
            tmp = f[i][N - i];
            cur = tmp;
            for (int j = tmp.length() - 1; j >= 0; j--)
                cur += tmp[j];
            ans = max_str(cur, ans);
        }

        for (int i = 0; i < N; i++) {
            if (S[i] != T[N - 1 - i]) continue;
            tmp = f[i + 1][N - i];
            cur = tmp;
            for (int j = tmp.length() - 2; j >= 0; j--)
                cur += tmp[j];
            ans = max_str(cur, ans);
        }

        puts(ans.c_str());
    }

    return 0;
}
