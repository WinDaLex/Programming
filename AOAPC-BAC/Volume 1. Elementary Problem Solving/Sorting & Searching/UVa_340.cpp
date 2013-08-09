// UVa 340
// Master-Mind Hints
// by A Code Rabbit

#include <cstdio>
#include <vector>
#include <set>
using namespace std;

typedef multiset<int>::iterator iter;

const int MAXN = 100002;

int N;
int code[MAXN];
int guess[MAXN];

int main() {
    int T = 0;
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++)
            scanf("%d", &code[i]);

        printf("Game %d:\n", ++T);
        while (1) {
            for (int i = 0; i < N; i++)
                scanf("%d", &guess[i]);

            if (!guess[0]) break;

            int strong = 0, weak = 0;
            vector<int> que;
            multiset<int> ans;

            for (int i = 0; i < N; i++) {
                if (code[i] != guess[i]) {
                    que.push_back(code[i]);
                    ans.insert(guess[i]);
                } else {
                    strong++;
                }
            }

            for (int i = 0; i < que.size(); i++) {
                iter it = ans.find(que[i]);
                if (it != ans.end()) {
                    weak++;
                    ans.erase(it);
                }
            }

            printf("    (%d,%d)\n", strong, weak);
        }
    }

    return 0;
}
