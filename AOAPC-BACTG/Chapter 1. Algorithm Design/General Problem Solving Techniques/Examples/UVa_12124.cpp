// UVa_12124
// Assemble
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 1002;
const int MAXQ = 1000000000;

struct Component {
    int p, q;
};

int N, B;
char type[22], name[22];
int price, quality;

map<string, int> id;
vector<Component> cpn[MAXN];
int cnt = 0;

bool check(int x) {
    int budget = B;

    for (int i = 0; i < cnt; i++) {
        int min_p = B + 1;
        for (int j = 0; j < cpn[i].size(); j++)
            if (cpn[i][j].q >= x) min_p = min(min_p, cpn[i][j].p);
        budget -= min_p;
        if (budget < 0) return false;
    }

    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < MAXN; i++)
            cpn[i].clear();
        id.clear();
        cnt = 0;

        scanf("%d%d", &N, &B);
        for (int i = 0; i < N; i++) {
            scanf("%s%s%d%d", type, name, &price, &quality);
            if (!id.count(type)) id[type] = cnt++;
            cpn[id[type]].push_back((Component){price, quality});
        }

        int l = 0, r = MAXQ;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (check(m)) l = m;
            else r = m - 1;
        }
        
        printf("%d\n", l);
    }

    return 0;
}
