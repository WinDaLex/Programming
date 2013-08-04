// UVa 11997
// K Smallest Sums
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXK = 750;

struct Item {
    int s, b;
    Item(int s, int b) : s(s), b(b) { }
    bool operator<(Item rhs) const {
        return s > rhs.s;
    }
};

int K;
int A[MAXK][MAXK];

void merge(int *a, int *b, int *c, int n) {
    priority_queue<Item> pq;
    for (int i = 0; i < n; i++)
        pq.push(Item(a[i] + b[0], 0));

    for (int i = 0; i < n; i++) {
        Item item = pq.top();
        pq.pop();
        c[i] = item.s;

        int cur = item.b;
        if (cur + 1 < n) q.push(Item(item.s - b[cur] + b[cur + 1], cur + 1));
        // judge whether cur + 1 < n, avoid program trying to get b[n + 1].
    }
}

int main() {
    while (scanf("%d", &K) == 1) {
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                scanf("%d", &A[i][j]);

        for (int i = 0; i < K; i++)
            sort(A[i], A[i] + K);

        for (int i = 1; i < K; i++)
            merge(A[0], A[i], A[0], K);

        for (int i = 0; i < K; i++)
            printf("%d%c", A[0][i], i < K - 1 ? ' ' : '\n');
    }

    return 0;
}
