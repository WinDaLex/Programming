// UVa 10131
// Is Bigger Smarter?
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1002;

struct Elephant {
    int W, S, id;
    bool operator<(Elephant rhs) const { return this->W < rhs.W; }
};

int N;
Elephant E[MAXN];

int f[MAXN], prev[MAXN];

int main() {
    N = 0;
    while (scanf("%d%d", &E[N].W, &E[N].S) != EOF) {
        E[N].id = N + 1;
        N++;
    }

    sort(E, E + N);

    for (int i = N - 1; i >= 0; i--) {
        int val = 0, idx = -1;
        for (int j = i + 1; j < N; j++)
            if (E[j].W > E[i].W && E[j].S < E[i].S && f[j] > val)
                val = f[idx = j];
    
        f[i] = val + 1;
        prev[i] = idx;
    }

    int last = 0;
    for (int i = 1; i < N; i++)
        if (f[i] > f[last])
            last = i;

    printf("%d\n", f[last]);
    while (last != -1) {
        printf("%d\n", E[last].id);
        last = prev[last];
    }

    return 0;
}
