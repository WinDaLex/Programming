// UVa 10192
// Vacation
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int LEN = 102;

int T;
char S1[LEN], S2[LEN]; 

int n1, n2;
int f[LEN][LEN];

int main() {
    while (gets(S1) && S1[0] != '#') {
        gets(S2);

        n1 = strlen(S1);
        n2 = strlen(S2);

        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                f[i][j] = (S1[i - 1] == S2[j - 1] ? f[i - 1][j - 1] + 1 : max(f[i - 1][j], f[i][j - 1]));

        printf("Case #%d: you can visit at most %d cities.\n", ++T, f[n1][n2]);
    }
    
    return 0;
}
