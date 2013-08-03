// UVa 11995
// I Can Guess the Data Structure!
// by A Code Rabbit

#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int N;
int T, X;

int main() {
    while (scanf("%d", &N) == 1) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        bool is_stack = true, is_queue = true, is_pqueue = true;
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &T, &X);
            if (T == 1) {
                s.push(X);
                q.push(X);
                pq.push(X);
            } else {
                if (s.empty() || s.top() != X) is_stack = false; else s.pop();
                if (q.empty() || q.front() != X) is_queue = false; else q.pop();
                if (pq.empty() || pq.top() != X) is_pqueue = false; else pq.pop();
            }
        }

        if (is_stack && !is_queue && !is_pqueue) puts("stack");
        else if (!is_stack && is_queue && !is_pqueue) puts("queue");
        else if (!is_stack && !is_queue && is_pqueue) puts("priority queue");
        else if (!is_stack && !is_queue && !is_pqueue) puts("impossible");
        else puts("not sure");
    }

    return 0;
}
