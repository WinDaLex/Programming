// UVa 10895
// Matrix Transposeo
// by A Code Rabbit

#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 100002;

struct Element {
    int col, val;
    Element(int col, int val) : col(col), val(val) { }
};

int M, N, R;
int col[MAXN], val;

vector<Element> matrix[MAXN];

int main() {
    while (scanf("%d%d", &M, &N) == 2) {
        for (int i = 1; i <= N; i++)
            matrix[i].clear();

        for (int i = 1; i <= M; i++) {
            scanf("%d", &R);
            for (int j = 0; j < R; j++) scanf("%d", &col[j]);
            for (int j = 0; j < R; j++) {
                scanf("%d", &val);
                matrix[col[j]].push_back(Element(i, val));
            }
        }

        printf("%d %d\n", N, M);
        for (int i = 1; i <= N; i++) {
            int size = matrix[i].size();
            printf("%d", size);
            if (size) {
                for (int j = 0; j < size; j++)
                    printf(" %d", matrix[i][j].col);
                printf("\n");
                for (int j = 0; j < size - 1; j++)
                    printf("%d ", matrix[i][j].val);
                printf("%d\n", matrix[i][size - 1].val);
            } else {
                printf("\n\n");
            }
        }
    }

    return 0;
}
