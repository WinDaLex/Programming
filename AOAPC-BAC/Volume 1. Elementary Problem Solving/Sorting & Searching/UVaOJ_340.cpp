// UVaOJ 340
// Master-Mind Hints
// by A Code Rabbit

#include <cstdio>
#include <set>
#include <vector>
using namespace std;

const int MAXN = 100000;

int n;
int code[MAXN];
int guess[MAXN];

int main() {
    int cnt_case = 0;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++)
            scanf("%d", &code[i]);
        printf("Game %d:\n", ++cnt_case);
        while (1) {
            for (int i = 0; i < n; i++)
                scanf("%d", &guess[i]);
            if (!guess[0]) break;
            int strong = 0, weak = 0;
            vector<int> que;
            multiset<int> ans;
            for (int i = 0; i < n; i++) {
                if (code[i] != guess[i]) {
                    que.push_back(code[i]);
                    ans.insert(guess[i]);
                } else {
                    strong++;
                }
            }
            for (int i = 0; i< que.size(); i++) {
                multiset<int>::iterator iter = ans.find(que[i]);
                if (iter != ans.end()) {
                    weak++;
                    ans.erase(iter);
                }
            }
            printf("    (%d,%d)\n", strong, weak);
        }
    }

    return 0;
}
