// UVa 10881
// Piotr's Ants
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const char *MAP[] = {"L", "Turning", "R"};
const int MAXN = 10002;

struct Ant {
    int id;
    int pos;
    int dir;
};

bool cmp_pos(Ant a, Ant b) { return a.pos < b.pos; }
bool cmp_id(Ant a, Ant b) { return a.id < b.id; }

int L, T, N;
Ant ant[MAXN];

int order[MAXN];

int main() {
    int C;
    scanf("%d", &C);
    for (int cas = 1; cas <= C; cas++) {
        scanf("%d%d%d", &L, &T, &N);
        for (int i = 0; i < N; i++) {
            int pos, dir; char ch;
            scanf("%d %c", &pos, &ch);
            dir = (ch == 'L' ? -1 : 1);
            ant[i] = (Ant){i, pos, dir};
        }

        sort(ant, ant + N, cmp_pos);
        for (int i = 0; i < N; i++) {
            order[i] = ant[i].id;
            ant[i].pos += T * ant[i].dir;
        }
        sort(ant, ant + N, cmp_pos);
        for (int i = 0; i < N; i++)
            ant[i].id = order[i];

        for (int i = 0; i < N - 1; i++)
            if (ant[i].pos == ant[i + 1].pos)
                ant[i].dir = ant[i + 1].dir = 0;

        sort(ant, ant + N, cmp_id);

        printf("Case #%d:\n", cas);
        for (int i = 0; i < N; i++) {
            if (ant[i].pos < 0 || ant[i].pos > L) puts("Fell off");
            else printf("%d %s\n", ant[i].pos, MAP[ant[i].dir + 1]);
        }
        puts("");
    }

    return 0;
}
