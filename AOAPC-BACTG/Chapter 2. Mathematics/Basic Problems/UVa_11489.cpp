// UVa 11489
// Integer Game
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 1002;

int T, N;
char S[MAXN];

int count[3];

int main() {
    scanf("%d", &T);
    getchar();
    for (int cas = 1; cas <= T; cas++) {
        N = 0;
        while ((S[N] = getchar()) != '\n')
            N++;
    
        memset(count, 0, sizeof(count));
        for (int i = 0; i < N; i++)
            count[(S[i] - '0') % 3]++;

        int sum = (count[1] + count[2] * 2) % 3;
        char ans = 'S';

        if (N > 1) {
            if (count[sum] == 0)
                ans = 'T';
            else
                count[sum]--;

            if (count[0] % 2 == 1)
                ans = 'T';
        }

        printf("Case %d: %c\n", cas, ans);
    }

    return 0;
}
