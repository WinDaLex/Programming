// UVa 11078
// Open Credit System
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100002;

int N;
int d[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int last, cur;
        scanf("%d", &last);
        for (int i = 0; i < N - 1; i++) {
            scanf("%d", &cur);
            d[i] = last - cur;
            last = cur;
        }

        int sum = d[0], ans = d[0];
        for (int i = 1; i < N - 1; i++) {
            sum = sum > 0 ? d[i] + sum : d[i];
            ans = max(sum, ans);
        }

        printf("%d\n", ans);
    }
     

    return 0;
}
