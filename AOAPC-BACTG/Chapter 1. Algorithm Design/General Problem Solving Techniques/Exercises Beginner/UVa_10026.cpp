// UVa 10026
// Shoemaker's Problem
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

struct Job {
    int id, t, f;
    bool operator<(Job rhs) const { return this->t * rhs.f < rhs.t * this->f; }
};

const int MAXN = 1002;

int N;
Job job[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &job[i].t, &job[i].f);
            job[i].id = i + 1;
        }
        
        stable_sort(job, job + N);

        for (int i = 0; i < N; i++)
            printf("%d%c", job[i].id, i < N - 1 ? ' ' : '\n');
        if (T) puts("");
    }

    return 0;
}
