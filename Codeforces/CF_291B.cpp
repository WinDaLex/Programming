// Codeforces #291 B
// Han Solo and Lazer Gun

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1002;

int N, X0, Y0;
int X[MAXN], Y[MAXN];

int bo[MAXN];
int ans;

bool collinear(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax - cx) * (by - cy) == (bx - cx) * (ay - cy);
} 

int main() {
    scanf("%d%d%d", &N, &X0, &Y0);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &X[i], &Y[i]);
    
    ans = 0;
    for (int i = 0; i < N; i++) {
        if (bo[i]) continue;
        ans++;
        for (int j = i + 1; j < N; j++)
            if (collinear(X0, Y0, X[i], Y[i], X[j], Y[j]))
                bo[j] = true;
    }

    printf("%d\n", ans);

    return 0;
}
