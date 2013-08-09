// UVa 10410
// Tree Reconstruction
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1002;

struct Item {
    int l, r;
    Item(int l, int r) : l(l), r(r) { }
};

int N;
int BFS[MAXN], DFS[MAXN];

vector<int> child[MAXN];

int main() {
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) scanf("%d", &BFS[i]);
        for (int i = 0; i < N; i++) scanf("%d", &DFS[i]);

        for (int i = 1; i <= N; i++) child[i].clear();

        queue<Item> q;
        q.push(Item(0, N - 1));

        int pos = 1;
        while (!q.empty()) {
            int l = q.front().l, r = q.front().r;
            q.pop();
            if (l == r) continue;

            int root = DFS[l], last = 0;
            for (int i = l + 1; i <= r; i++) {
                if (BFS[pos] == DFS[i]) {
                    child[root].push_back(BFS[pos++]);
                    if (last) q.push(Item(last, i - 1));
                    last = i;
                }
            }
            q.push(Item(last, r));
        }

        for (int i = 1; i <= N; i++)
            sort(child[i].begin(), child[i].end());

        for (int i = 1; i <= N; i++) {
            printf("%d:", i);
            for (int j = 0; j < child[i].size(); j++)
                printf(" %d", child[i][j]);
            printf("\n");
        }
    }

    return 0;
}
