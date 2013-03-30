// UVa 1346
// Songs
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

struct Song {
    int id;
    int l;
    double f;
    bool operator<(Song rhs) const {return this->l * rhs.f < this->f * rhs.l; }
};

const int MAXN = 100000;

int N, S;
Song song[MAXN];

int main() {
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++)
            scanf("%d%d%lf", &song[i].id, &song[i].l, &song[i].f);
        scanf("%d", &S);

        for (int i = 0; i < S; i++)
            for (int j = N - 2; j >= i; j--)
                if (song[j + 1] < song[j])
                    swap(song[j], song[j + 1]);
        
        printf("%d\n", song[S - 1].id);
    }

    return 0;
}
