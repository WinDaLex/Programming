// UVa 12097
// Pie
// by A Code Rabbit

#include <cstdio>
#include <cmath>

const int MAXN = 10002;
const int MAXR = 10002;
const double PI = acos(-1.0);

int N, F;
int R[MAXN];

bool check(double x) {
    int cnt = 0;
    for (int i = 0; i < N; i++)
        cnt += R[i] * R[i] * PI / x;
    return cnt >= F + 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &F);
        for (int i = 0; i < N; i++)
            scanf("%d", &R[i]);
        
        double l = 0, r = MAXR * MAXR * PI;
        while (r - l > 1e-5) {
            double m = (l + r) / 2;
            if (check(m)) l = m;
            else r = m;
        }

        printf("%.4lf\n", l);
    }
    

    return 0;
}
