// HDU 4619
// Warm up 2
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Coord { int x, y; };

const int MAXX = 102;
const int MAXY = 102;

int N, M, X, Y;

int plane[MAXX][MAXY];
vector<Coord> wait;

int main() {
    while (scanf("%d%d", &N, &M) && (N || M)) {
        memset(plane, 0, sizeof(plane));
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &X, &Y);
            plane[X][Y] = 1;
            plane[X + 1][Y] = 2;
        }

        int ans = N;
        wait.clear();
        for (int i = 0; i < M; i++) {
            scanf("%d%d", &X, &Y);
            if (!plane[X][Y] && !plane[X][Y + 1]) {
                ans++;
                continue;
            } else if (plane[X][Y] && plane[X][Y + 1]) {
                Coord coord = (Coord){X, Y};
                wait.push_back(coord);
            } else if (plane[X][Y]) {
                if (plane[X][Y] == 1) plane[X + 1][Y] = 0;
                else plane[X - 1][Y] = 0;
            } else if (plane[X][Y + 1]) {
                if (plane[X][Y + 1] == 1) plane[X + 1][Y + 1] = 0;
                else plane[X - 1][Y + 1] = 0;
            }
        }

        for (int i = 0; i < wait.size(); i++) {
            X = wait[i].x;
            Y = wait[i].y;
            if (!plane[X][Y] && !plane[X][Y + 1]) {
                ans++;
                continue;
            } else if (plane[X][Y] && plane[X][Y + 1]) {
                continue;
            } else if (plane[X][Y]) {
                if (plane[X][Y] == 1) plane[X + 1][Y] = 0;
                else plane[X - 1][Y] = 0;
            } else if (plane[X][Y + 1]) {
                if (plane[X][Y + 1] == 1) plane[X + 1][Y + 1] = 0;
                else plane[X - 1][Y + 1] = 0;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
