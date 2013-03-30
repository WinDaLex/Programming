// UVa 1509
// Leet
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LEN = 47;
const int MAXK = 5;

int K;
char alpha[LEN], leet[LEN];

char map[26][MAXK];
bool bo[26];

bool got;

void search(int x, int y) {
    if (got) return;
    if (x == strlen(alpha)) {
        if (y == strlen(leet)) got = true;
        return;
    }

    int key = alpha[x] - 'a';
    char val[MAXK] = {0};
    for (int i = 0; i < K && y + i < strlen(leet); i++) {
        val[i] = leet[y + i];
        if (bo[key]) {
            if (strcmp(map[key], val) == 0)
                search(x + 1, y + i + 1);
        } else {
             strcpy(map[key], val);
             bo[key] = true;
             search(x + 1, y + i + 1);
             bo[key] = false;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &K);
        getchar();
        gets(alpha);
        gets(leet);

        memset(bo, false, sizeof(bo));
        got = false;
        search(0, 0);

        printf("%d\n", got ? 1 : 0);
    }

    return 0;
}
