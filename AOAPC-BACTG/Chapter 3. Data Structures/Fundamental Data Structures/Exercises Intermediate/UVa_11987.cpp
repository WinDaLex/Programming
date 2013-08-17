// UVa 11987
// Almost Union-Find
// by A Code Rabbit

#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 200002;

int N, M, O, P, Q;

int pa[MAXN], id[MAXN];
int num[MAXN], sum[MAXN];
int top;

int find(int x) {
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 1; i <= N; i++) {
            pa[i] = sum[i] = id[i] = i;
            num[i] = 1;
        }
        top = N + 1;

        for (int i = 0; i < M; i++) {
            scanf("%d", &O);
            if (O == 1) {
                scanf("%d%d", &P, &Q);
                int px = find(id[P]), py = find(id[Q]);
                if (px != py) {
                    pa[px] = py;
                    num[py] += num[px]; 
                    sum[py] += sum[px];
                }
            } else if (O == 2) {
                scanf("%d%d", &P, &Q);
                int px = find(id[P]), py = find(id[Q]);
                if (px != py) {
                    num[px]--;
                    sum[px] -= P;
                    pa[id[P] = top++] = py;
                    num[py]++;
                    sum[py] += P;
                }
            } else if (O == 3) {
                scanf("%d", &P);
                printf("%d %d\n", num[find(id[P])], sum[find(id[P])]);
            }
        }
    }

    return 0;
}
