// UVa 10763
// Foreign Exchange
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 500002;

struct Point {
    int x, y;
    bool operator<(Point rhs) const { return this->x < rhs.x || (this->x == rhs.x && this->y < rhs.y); }
    bool operator!=(Point rhs) const { return this->x != rhs.x || this->y != rhs.y; }
};

int N;
Point a[MAXN], b[MAXN];

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &a[i].x, &a[i].y);
            b[i] = (Point){a[i].y, a[i].x};
        }

        sort(a, a + N);
        sort(b, b + N);

        bool bo = false;
        for (int i = 0; i < N; i++) {
            if (a[i] != b[i]) {
                bo = true;
                break;
            }
        }

        puts(bo ? "NO" : "YES");
    }

    return 0;
}
