// UVaOJ 10474
// Where is the Marble?
// by A Code Rabbit

#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 10002;

int n, q;
int marbles[MAXN];

int main() {
    int cnt_case = 0;
    while (scanf("%d%d", &n, &q) && (n || q)) {
        for (int i = 0; i < n; i++)
            scanf("%d", &marbles[i]);
        sort(marbles, marbles + n);
        printf("CASE# %d:\n", ++cnt_case);
        for (int i = 0; i < q; i++) {
            int num;
            scanf("%d", &num);
            if (binary_search(marbles, marbles + n, num))
                printf("%d found at %d\n",
                    num, lower_bound(marbles, marbles + n, num) - marbles + 1);
            else
                printf("%d not found\n", num);
        }
    }

    return 0;
}
