// UVa 514
// Rails
// by A Code Rabbit

#include <cstdio>
#include <stack>
using namespace std;

const int MAXN = 1002;

int N;
int A[MAXN];

bool check() {
    stack<int> s;
    int cur = 1, pos = 0;
    while (pos < N) {
        if (cur == A[pos]) { cur++; pos++; }
        else if (!s.empty() && s.top() == A[pos]) { s.pop(); pos++; }
        else if (cur < A[pos]) { s.push(cur++); }
        else return false;
    }
    return true;
}

int main() {
    while (scanf("%d", &N) == 1 && N) {
        while (scanf("%d", &A[0]) == 1 && A[0]) {
            for (int i = 1; i < N; i++)
                scanf("%d", &A[i]);

            puts(check() ? "Yes" : "No");
       }
       puts("");
    }

    return 0;
}
