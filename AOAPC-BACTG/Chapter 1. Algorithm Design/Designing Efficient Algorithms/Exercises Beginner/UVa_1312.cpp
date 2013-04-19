// UVa 1312
// Cricket Field
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 102 + 4;

struct Coord { int x, y; };

int T;
int N, W, H;
Coord a[MAXN];

int ans;
int p, q;

bool cmp1(Coord a, Coord b) { return a.x < b.x; }
bool cmp2(Coord a, Coord b) { return a.y < b.y; }

void compute(int upper, int lower, int left, int right) {
    int l = min(upper - lower, right - left);
    if (l > ans) { ans = l; p = left; q = lower; }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &N, &W, &H);
        for (int i = 0; i < N; i++)
            scanf("%d%d", &a[i].x, &a[i].y);
        a[N++] = (Coord) {0, 0};
        a[N++] = (Coord) {W, 0};
        a[N++] = (Coord) {0, H};
        a[N++] = (Coord) {W, H};

        sort(a, a + N, cmp1);

        ans = 0;

        for (int i = 0; i < N; i++) {
            int upper = H, lower = 0;
            for (int j = i + 1; j < N; j++) {
                compute(upper, lower, a[i].x, a[j].x);
                a[j].y > a[i].y ? upper = min(a[j].y, upper) : lower = max(a[j].y, lower);
            }
        }
    
        for (int i = N - 1; i >= 0; i--) {
            int upper = H, lower = 0;
            for (int j = i - 1; j >= 0; j--) {
                compute(upper, lower, a[j].x, a[i].x);
                a[j].y > a[i].y ? upper = min(a[j].y, upper) : lower = max(a[j].y, lower);
            }
        }
 
        sort(a, a + N, cmp2);

        for (int i = 1; i < N; i++)
            compute(a[i].y, a[i - 1].y, 0, W);

        printf("%d %d %d\n", p, q, ans);
        printf("%s", T ? "\n" : "");
    }

    return 0;
}
