// HDU 4639
// Hehe
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 10088;
const int MOD = 10007;

int FB[MAXN];

int T, N;
char S[MAXN];

int main() {
    FB[0] = 1;
    FB[1] = 1;
    for (int i = 2; i < MAXN; i++)
        FB[i] = (FB[i - 2] + FB[i - 1]) % MOD;

    scanf("%d", &T);
    getchar();
    for (int cas = 1; cas <= T; cas++) {
        gets(S);
        N = strlen(S);

        int ans = 1, cnt = 0;
        for (int i = 0; i < N - 1; ) {
            if (S[i] == 'h' && S[i + 1] == 'e') {
                cnt++;
                i += 2;
            } else {
                ans = ans * FB[cnt] % MOD;
                cnt = 0;
                i += 1;
            }
        }
        ans = ans * FB[cnt] % MOD;
        
        printf("Case %d: %d\n", cas, ans);
    }

    return 0;
}
