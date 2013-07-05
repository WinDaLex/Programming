// UVa 442
// Matrix Chain Multiplication
// by A Code Rabbit

#include <cstdio>
#include <cctype>
#include <cstring>

const int MAXN = 28;
const int ALPHA = 28;
const int LEN = 10002;

struct Mat { int r, c; };

const Mat UNIT = {0, 0};

int N;
Mat M[ALPHA];
char E[LEN];

Mat stack[MAXN];
int top;

char index(char ch) { return ch - 'A'; }

int mul(Mat a, Mat b, Mat &c) {
    if (a.r == 0 && a.c == 0) { c = b; return 0; }
    if (a.c != b.r) return -1;
    c = (Mat) {a.r, b.c};
    return a.r * a.c * b.c;
}

int main() {
    scanf("%d", &N);
    getchar();
    char ch; int r, c;
    for (int i = 0; i < N; i++) {
        scanf("%c %d %d", &ch, &r, &c);
        M[index(ch)] = (Mat) {r, c};
        getchar();
    }

    while (gets(E)) {
        stack[top = 0] = UNIT;

        Mat tmp;
        bool bo = false;
        int ans = 0, ret;

        for (int i = 0; i < strlen(E); i++) {
            if (E[i] == '(') {
                stack[++top] = UNIT;
                continue;
            }

            Mat lparam = (E[i] == ')' ? stack[top - 1] : stack[top]);
            Mat rparam = (E[i] == ')' ? stack[top--] : M[index(E[i])]);

            ret = mul(lparam, rparam, tmp);

            if (ret == -1) {
                bo = true;
                break;
            } else {
                ans += ret;
                stack[top] = tmp;
            }
        }

        if (bo) puts("error");
        else printf("%d\n", ans);
    }

    return 0;
}
