// UVa 10012
// How Big Is It?
// by A Code Rabbit

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 10;
const double INF = 1e20;

int N;
double a[MAXN];

int order[MAXN];
double r[MAXN];
double left[MAXN];

double dist(int p, int q) {
    return sqrt(pow(r[p] + r[q], 2) - pow(r[p] - r[q], 2));
}

double compute() {
    double res = 0;

    for (int i = 0; i < N; i++) {
        left[i] = r[i];
        for (int j = 0; j < i; j++)
            left[i] = max(left[j] + dist(j, i), left[i]);
        res = max(left[i] + r[i], res);
    }
    
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%lf", &a[i]);

        for (int i = 0; i < N; i++)
            order[i] = i;

        double ans = INF;
        do {
            for (int i = 0; i < N; i++)
                r[i] = a[order[i]];
            ans = min(compute(), ans);
        } while (next_permutation(order, order + N));

        printf("%.3lf\n", ans);
    }

    return 0;
}
