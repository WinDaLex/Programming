// UVa 11134
// Fabled Rooks
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 5002;

struct Seq {
    int l, r, id;
    bool operator<(Seq rhs) const { return this->l < rhs.l; }
    bool operator>(Seq rhs) const { return this->r > rhs.r; }
};

int N;
Seq row[MAXN], col[MAXN];

int x[MAXN], y[MAXN];

bool place(Seq seq[], int res[]) {
    sort(seq, seq + N);

    priority_queue<Seq, vector<Seq>, greater<Seq> > pque;
    int p = 0;

    for (int i = 1; i <= N; i++) {
        while (p < N && seq[p].l <= i) pque.push(seq[p++]);
        if (pque.empty() || pque.top().r < i) return false;
        res[pque.top().id] = i;
        pque.pop();
    }
    return true;
}

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d%d", &row[i].l, &col[i].l, &row[i].r, &col[i].r);
            row[i].id = col[i].id = i;
        }

        if (place(row, x) && place(col, y)) {
            for (int i = 0; i < N; i++)
                printf("%d %d\n", x[i], y[i]);
        } else {
            puts("IMPOSSIBLE");
        }
    }

    return 0;
}
