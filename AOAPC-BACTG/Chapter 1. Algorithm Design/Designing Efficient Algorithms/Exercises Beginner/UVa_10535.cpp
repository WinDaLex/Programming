// UVa 10535
// Shooter
// by A Code Rabbit

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 502;
const double PI = acos(-1.0);

struct Coord { double x, y; };

struct Point {
    double pos;
    bool left;
    bool operator<(Point rhs) const {
        return pos == rhs.pos ? left && !rhs.left : pos < rhs.pos;
    }
};

int N;
Coord a[MAXN], b[MAXN];
Coord shooter;

Point pt[MAXN * 4];
int top;

double get_rad(double x, double y) {
    if (x == 0) return y > 0 ? PI / 2.0 : PI * 3.0 / 2.0;
    if (y == 0) return x > 0 ? 0 : PI;
    double res = atan(y / x);
    res += res < 0 ? PI : 0;
    res += y > 0 ? 0 : PI;
    return res;
}

void push_segment(double l, double r) {
    pt[top++] = (Point){l, true};
    pt[top++] = (Point){r, false};
}

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++)
            scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
        scanf("%lf%lf", &shooter.x, &shooter.y);

        top = 0;
        for (int i = 0; i < N; i++) {
            double rad_a = get_rad(a[i].x - shooter.x, a[i].y - shooter.y);
            double rad_b = get_rad(b[i].x - shooter.x, b[i].y - shooter.y);
            double min_rad = min(rad_a, rad_b);
            double max_rad = max(rad_a, rad_b);
            if (max_rad - min_rad < PI) {
                push_segment(min_rad, max_rad);
            } else {
                push_segment(0, min_rad);
                push_segment(max_rad, PI * 2);
            }
        }

        sort(pt, pt + top);

        int ans = 0, cur = 0;
        for (int i = 0; i < top; i++) {
            cur += pt[i].left ? 1 : -1;
            ans = max(cur, ans);
        }

        printf("%d\n", ans);
    }

    return 0;
}
