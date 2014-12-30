// CF500 B
// New Year Permutation

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 302;

int n;
int p[MAXN];
int A[MAXN][MAXN];

char get() {
    char ch = getchar();
    while (ch != '0' && ch != '1') ch = getchar();
    return ch;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = get() - '0';

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[i][j] |= A[i][k] & A[k][j];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i][j] && p[j] < p[i])
                swap(p[i], p[j]);

    for (int i = 0; i < n; i++)
        printf("%d%c", p[i], i < n - 1 ? ' ' : '\n');

    return 0;
}
