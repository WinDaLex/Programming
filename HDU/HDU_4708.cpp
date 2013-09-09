// HDU 4708
// Rotation Lock Puzzle
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 11;

struct Item {
    int sum, t;
    Item(int sum, int t) : sum(sum), t(t) { }
    bool operator<(Item rhs) const {
        return sum > rhs.sum || (sum == rhs.sum && t < rhs.t);
    }
};

int N;
int A[MAXN][MAXN];

vector<Item> vec[5];

int main() {
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &A[i][j]);

        int ans_sum = A[(N + 1) / 2][(N + 1) / 2], ans_t = 0;
        for (int k = 0; k < N / 2; k++) {
            vec[k].clear();
            vec[k].push_back(Item(A[1 + k][1 + k] + A[1 + k][N - k] + A[N - k][1 + k] + A[N - k][N - k], 0));
            for (int i = 1; i <= N - 1 - k * 2; i++) {
                vec[k].push_back(Item(A[1 + k][1 + k + i] + A[1 + k + i][N - k] + A[N - k - i][1 + k] + A[N - k][N - k - i], i));
                vec[k].push_back(Item(A[1 + k + i][1 + k] + A[1 + k][N - k - i] + A[N - k][1 + k + i] + A[N - k - i][N - k], i));
            }
            sort(vec[k].begin(), vec[k].end());
            ans_sum += vec[k][0].sum;
            ans_t += vec[k][0].t;
        }

        printf("%d %d\n", ans_sum, ans_t);
    }

    return 0;
}
