// UVa 11991
// Easy Problem from Rujia Liu?
// by A Code Rabbit

#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int N, M, E, K, V;

map<int, vector<int> > num;

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        num.clear();
        for (int i = 0; i < N; i++) {
            scanf("%d", &E);
            if (!num.count(E)) num[E] = vector<int>();
            num[E].push_back(i + 1);
        }

        for (int i = 0; i < M; i++) {
            scanf("%d%d", &K, &V);
            printf("%d\n", !num.count(V) || num[V].size() < K ? 0 : num[V][K - 1]);
        }
    }

    return 0;
}
