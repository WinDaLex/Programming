// HDU 4648
// Magic Pen 6
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100002;
const int MAXM = 10002;

int N, M;
int A[MAXN];

int least[MAXM];

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
    
        memset(least, -1, sizeof(least));
        least[0] = 0;

        int ans = 0, sum = 0;
        for (int i = 1; i <= N; i++) {
            sum = ((sum + A[i]) % M + M) % M;
            if (least[sum] != -1) ans = max(ans, i - least[sum]);
            else least[sum] = i;
        }

        printf("%d\n", ans);
    }

    return 0;
}
