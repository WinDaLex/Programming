// UVa 11136
// Hoax or what
// by A Code Rabbit

// This code does not get AC yet, because UVa Online Judge will return SE to this problem.

#include <cstdio>
#include <set>
using namespace std;

int N, K, B;

int main() {
    while (scanf("%d", &N) == 1 && N) {
        multiset<int> s;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &K);
            for (int j = 0; j < K; j++) {
                scanf("%d", &B);
                s.insert(B);
            }
            ans += *(--s.end()) - *s.begin();
            s.erase(s.begin());
            s.erase(--s.end());
        }
    
        printf("%d\n", ans);
    }

    return 0;
}
