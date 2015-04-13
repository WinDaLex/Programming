// Google Code Jam 2015 Qualification Round B
// Infinite House of Pancakes

#include <cstdio>
#include <queue>

using namespace std;

const int INF = 1e9;
const int MAXD = 1002;

int T, D, P[MAXD];

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {

        scanf("%d", &D);
        for (int i = 0; i < D; i++)
            scanf("%d", &P[i]);

        int ans = INF;
        for (int i = 1; i < ans; i++) {
            int sum = 0;
            for (int j = 0; j < D; j++)
                sum += (P[j] + (i - 1)) / i - 1;
            ans = min(ans, sum + i);
        }

        printf("Case #%d: %d\n", cas, ans);
    }

    return 0;
}
