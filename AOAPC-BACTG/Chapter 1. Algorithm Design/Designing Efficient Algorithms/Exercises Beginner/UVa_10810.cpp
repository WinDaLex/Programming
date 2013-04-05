// UVa 10810
// Ultra-QuickSort
// by A Code Rabbit

#include <cstdio>

typedef long long LL;
const int MAXN = 500002;
const int INF = 1e9;

int N;
int a[MAXN];

int tmp[MAXN];
LL ans;

void merge(int p, int q, int r) {
    int top = 0, i = p, j = q;
    while (i < q && j < r) tmp[top++] = a[i] < a[j] ? ans += j - q, a[i++] : a[j++];
    while (i < q) tmp[top++] = (ans += j - q, a[i++]);
    while (j < r) tmp[top++] = a[j++];

    for (int i = p; i < r; i++)
        a[i] = tmp[i - p];
}

void merge_sort(int p, int r) {
    if (p + 1 >= r) return;
    int q = (p + r) / 2;
    merge_sort(p, q);
    merge_sort(q, r);
    merge(p, q, r);
}

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);

        ans = 0;
        merge_sort(0, N);
    
        printf("%lld\n", ans);
    }

    return 0;
}
