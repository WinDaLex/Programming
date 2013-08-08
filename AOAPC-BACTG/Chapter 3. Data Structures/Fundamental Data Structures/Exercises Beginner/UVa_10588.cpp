// UVa 10588
// Queuing at the doctors
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 1002;
const int MAXM = 1002;

struct Item {
    int id, t;
    Item(int id, int t) : id(id), t(t) { }
    bool operator<(Item rhs) const {
        return t > rhs.t || (t == rhs.t && id > rhs.id);
    }
};

int C, N, M;
int T[MAXN], K[MAXN];

int main() {
    scanf("%d", &C);
    while (C--) {
        scanf("%d%d", &N, &M);
        queue<int> G[MAXN];
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &T[i], &K[i]);
            int g;
            for (int j = 0; j < K[i]; j++) {
                scanf("%d", &g);
                G[i].push(g);
            }
        }
    
        priority_queue<Item> pq[MAXM];
        for (int i= 0; i < N; i++) {
            int x = G[i].front();
            G[i].pop();
            pq[x].push(Item(i, T[i]));
        }

        int num = 0, ans;
        for (ans = 0; num < N; ans++) {
            for (int i = 1; i <= M; i++) {
                if (pq[i].empty() || pq[i].top().t > ans) continue;
                int id = pq[i].top().id, t = pq[i].top().t;
                pq[i].pop();
                if (!G[id].empty()) {
                    int x = G[id].front();
                    G[id].pop();
                    pq[x].push(Item(id, ans + 1));
                } else {
                    num++;
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
