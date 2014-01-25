#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

const int MAXN = 100002;

struct Vehicle {
    int id, p;
    bool operator<(Vehicle rhs) const {
        return this->p > rhs.p;
    }
};

int N, V, T, P;
vector<Vehicle> v1, v2;

int main() {
    scanf("%d%d", &N, &V);
    v1.clear();
    v2.clear();
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &T, &P);
        if (T == 1) v1.push_back((Vehicle){i + 1, P});
        else v2.push_back((Vehicle){i + 1, P});
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans = 0, p1 = 0, p2 = 0, v = V;
    while (p1 < v1.size() && v > 0) {
        ans += v1[p1++].p;
        v--;
    }

    while (p2 < v2.size()) {
        if (v >= 2) {
            ans += v2[p2++].p;
            v -= 2;
        } else if (v == 1) {
            if (p1 >= 1 && v2[p2].p > v1[p1 - 1].p) {
                ans += v2[p2++].p - v1[p1 - 1].p;
                p1--;
                v -= 1;
            } else {
                break;
            }
        } else {
            if (p1 >= 2 && v2[p2].p > (v1[p1 - 1].p + v1[p1 - 2].p)) {
                ans += v2[p2++].p - v1[p1 - 1].p - v1[p1 - 2].p;
                p1 -= 2;
            } else {
                break;
            }
        }
    }

    printf("%d\n", ans);
    bool fst = true;
    for (int i = 0; i < p1; i++) printf("%s%d", (fst ? fst = false, "" : " "), v1[i].id);
    for (int i = 0; i < p2; i++) printf("%s%d", (fst ? fst = false, "" : " "), v2[i].id);
    printf("\n");

    return 0;
}
