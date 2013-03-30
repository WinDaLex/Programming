// UVaOJ 152
// Tree's a Crowd
// by A Code Rabbit

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 5002;
const int MAXR = 257;

struct Point {
    int x, y, z;
};

Point pt[MAXN];
bool bo[MAXR][MAXR][MAXR];
int ans[12];

int GetSqrDis(Point a, Point b);
void PushAns(int dis, int idx);

int main() {
    // Input.
    memset(bo, false, sizeof(bo));
    int top = 0;
    while (scanf("%d%d%d", &pt[top].x, &pt[top].y, &pt[top].z)) {
        if (pt[top].x || pt[top].y || pt[top].z) {
            bo[pt[top].x][pt[top].y][pt[top].z] = true;
            top++;
        } else {
            break;
        }
    }
    // Solve.
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < top; i++) {
        int min_sqr_dis = 100;
        for (int j = 0; j < top; j++)
            if (i != j) min_sqr_dis = min(GetSqrDis(pt[i], pt[j]), min_sqr_dis);
        PushAns(min_sqr_dis, 10);
    }
    // Output.
    for (int i = 0; i < 10; i++)
        printf("%4d", ans[i]);
    puts("");

    return 0;
}

int GetSqrDis(Point a, Point b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2);
}

void PushAns(int dis, int idx) {
    if (dis >= idx * idx)
        ans[idx]++;
    else
        PushAns(dis, idx - 1);
}
