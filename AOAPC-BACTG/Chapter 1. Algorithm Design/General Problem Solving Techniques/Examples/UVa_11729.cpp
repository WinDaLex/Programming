// UVa 11729
// Commando War
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10002;

struct Soldier {
    int B, J;
    bool operator<(Soldier rhs) const {
        return this->J > rhs.J;
    }
};

int N;
Soldier soldier[MAXN];

int main() {
    int cas = 0;
    while (scanf("%d", &N), N) {
        for (int i = 0; i < N; i++) 
            scanf("%d%d", &soldier[i].B, &soldier[i].J);

        sort(soldier, soldier + N);
        int cur = soldier[0].B;
        int need = soldier[0].J;
        for (int i = 1; i < N; i++) {
            cur += soldier[i].B;
            need = max(need - soldier[i].B, soldier[i].J);
        }
        int ans = cur + need;

        printf("Case %d: %d\n", ++cas, ans);
    }

    return 0;
}
