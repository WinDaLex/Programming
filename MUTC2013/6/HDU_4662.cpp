// 1008
// Yang ZhenCCC

#include <cstdio>
#include <cstring>

const int LEN = 1000002;

int N;
char S[LEN];

int len;

int main() {
    scanf("%d", &N);
    getchar();
    while (N--) {
        gets(S);
        len = strlen(S);
    
        if (S[0] != 'M') {
            puts("No");
            continue;
        }

        if (!strcmp(S, "MI")) {
            puts("Yes");
            continue;
        }

        int cnt = 0;
        bool bo = false;
        for (int i = 1; i < len; i++) {
            if (S[i] == 'U') {
                cnt += 3;
            } else if (S[i] == 'I') {
                cnt += 1;
            } else {
                bo = true;
                break;
            }
        }

        puts(!bo && (cnt % 6 == 2 || cnt % 6 == 4) ? "Yes" : "No");
    }

    return 0;
}
